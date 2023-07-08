// CSC1060C03
// M3 Capstone Project: Design-Draft a Program
// 2023-07-08
// Stephen L. Belden

// This project is organized using a structural design. With only a few
// modifications, it closely matches the UML Class Diagram from the previous
// assignment.

// Please note, because the Submission Instructions request a single .cpp file,
// all classes are be defined before main(). In the final solution, classes
// will be well-organized into their own files.

// List of control structures for iteration and processing:
//  1. File Input - Line 173
//      * No return, result is accessed through class function
//  2. Triangle Sorting - Line 283
//      * Result is passed on to Projection
//  3. Projection - Line 312
//      * Result is passed on to Rasterization
//  4. Rasterization - Line 348
//      * Result is used in the final file output



#include <iostream>
#include <string>
#include <vector>

// Class for storing and using a point in 3d space.
// This class is also used for rotation, because a separate rotation class
// would be implemented identically. Rotation can be considered a vector from
// the origin pointing to the Point3d.
class Point3d
{
private:
    double iX;
    double iY;
    double iZ;

public:
    // A point is created through this constructor.
    // A point can not be modified after it has been created.
    Point3d(double X = 0.0, double Y = 0.0, double Z = 0.0)
    {
        iX = X;
        iY = Y;
        iZ = Z;
    }

    // Member access functions
    double getX()
    {
        return iX;
    }

    double getY()
    {
        return iY;
    }

    double getZ()
    {
        return iZ;
    }
};

// Class for storing and using a point in 2d space.
class Point2d
{
private:
    double iX;
    double iY;

public:
    // A point is created through this constructor.
    // A point can not be modified after it has been created.
    Point2d(double X = 0.0, double Y = 0.0)
    {
        iX = X;
        iY = Y;
    }

    // Member access functions
    double getX()
    {
        return iX;
    }

    double getY()
    {
        return iY;
    }
};

// Class representing a single triangle, or face, in 3d space
class Triangle3d
{
private:
    Point3d iA;
    Point3d iB;
    Point3d iC;

public:
    // A triangle is created through this constructor.
    // A triangle can not be modified after it has been created.
    Triangle3d(Point3d A, Point3d B, Point3d C)
    {
        iA = A;
        iB = B;
        iC = C;
    }

    // Member access functions
    Point3d getVert1()
    {
        return iA;
    }

    Point3d getVert2()
    {
        return iB;
    }

    Point3d getVert3()
    {
        return iC;
    }
};

// Class representing a single triangle, or face, in 2d space
class Triangle2d
{
private:
    Point3d iA;
    Point3d iB;

public:
    // A triangle is created through this constructor.
    // A triangle can not be modified after it has been created.
    Triangle2d(Point3d A, Point3d B)
    {
        iA = A;
        iB = B;
    }

    // Member access functions
    Point3d getVert1()
    {
        return iA;
    }

    Point3d getVert2()
    {
        return iB;
    }
};

// Class for opening, reading, and storing an entire 3d object
class Object3d
{
private:
    std::string filename;
    std::vector<Triangle3d> triList;

public:
    // A 3d object is always constructed from a file.
    // A 3d object can not be modified after it has been created.
    Object3d(std::string inFile)
    {
        filename = inFile;

        // This is where a .obj file will be read

        // First, try to open the file, and assert an error if that fails
        
        // In a loop, get a line from the .obj file until end-of-file.
            // If the line starts with an #, ignore it and go to the next line
            // If the line starts with a v, parse 3 numbers into a Point3d
            // If the line starts with a f, parse 3 numbers, then
            // create a Triangle3d from the three points specified
    }

    std::vector<Triangle3d> getTriList()
    {
        return triList;
    }

    std::string getInputFilename()
    {
        return filename;
    }
};

// Class representing a camera
class Camera3d
{
private:
    Point3d iposition;
    Point3d irotation;

public:
    // A camera is created through this constructor.
    // A camera can not be modified after it has been created.
    Camera3d(Point3d position, Point3d rotation)
    {
        iposition = position;
        irotation = rotation;
    }

    // Member access functions
    Point3d getPosition()
    {
        return iposition;
    }

    Point3d getRotation()
    {
        return irotation;
    }
};

// Class representing the output result, a grid of pixels
class RasterGrid {
private:
    int iwidth;
    int iheight;
    double ipixelScale;
    std::vector<std::vector<int>> values;

public:
    // Constructor specifies width, height, and scale, which can not be changed
    RasterGrid(int width, int height, double pixelScale)
    {
        iwidth = width;
        iheight = height;
        ipixelScale = pixelScale;
    }

    // Member access functions
    int getWidth()
    {
        return iwidth;
    }

    int getHeight()
    {
        return iheight;
    }

    int getValue(int x, int y)
    {
        return values[x][y];
    }

    // Returns the 2d point on the plane corresponding to the center of a
    // given raster cell (pixel), used for calculations during rasterization
    Point2d getRasterPointCoords(int x, int y)
    {
        double col = ipixelScale * x;
        double row = ipixelScale * y;
        return Point2d(x, y);
    }

    // Member setters
    void setValue(int x, int y, int value)
    {
        values[x][y] = value;
    }
};

// Class for sorting triangles by depth relative to a camera
class SortedObject
{
private:
    std::vector<Triangle3d> depthSortedTris;

public:
    // The functionality of this class is implemented in its constructor,
    // the class is intended to be instantiated and immediately used.
    SortedObject(Object3d object, Camera3d camera)
    {
        // This is where triangles will be sorted

        // In a loop, for each Triangle3d in object, until all tris are read:
            // Calculate the average position of the triangle by averaging its
            // three coordinates.
            // Calculate the distance between that average and the position of
            // the camera, this is the value considered the "depth".
            // Insert the triangle into depthSortedTris based on it's depth,
            // maintaining the sorted order of that list as triangles are
            // inserted.
    }

    // Result access function
    std::vector<Triangle3d> getDepthSortedTris() {
        return depthSortedTris;
    }
};

// Class for projecting a 3d object onto a 2d plane
class ProjectedObject
{
private:
    std::vector<Point2d> projectedPointsList;

public:
    // The functionality of this class is implemented in its constructor,
    // the class is intended to be instantiated and immediately used.
    ProjectedObject(SortedObject input, Camera3d camera)
    {
        // This is where projection occurs

        // First, define the projection plane.
            // The plane is determined by the position and rotation of the
            // camera. A 2d plane in 3d space can be defined by 3 points.
            // Conveniently, we already have a class for that. A Triangle3d
            // can be used to define the plane.
            // The  plane is defined to be a small fixed distance in front of
            // the camera, tangent to the rotation vector of the camera.

        // In a loop, for each Triangle3d in input, until all tris are read:
            // In a loop, for each of the three Point3d objects in a triangle:
                // Project the point onto the projection plane.
                // Store the result in a Point2d.
            // Store the three Point2d objects in a Triangle2d.
            // Add each Triangle2d to projectedPointsList.
    }

    // Result access function
    std::vector<Point2d> getProjectedTris()
    {
        return projectedPointsList;
    }
};

// Class for rasterizing a projected object into a raster grid
class Rasterizer
{
private:
    RasterGrid result;

public:
    // The functionality of this class is implemented in its constructor,
    // the class is intended to be instantiated and immediately used.
    Rasterizer(ProjectedObject input, RasterGrid output) : result(output)
    {
        // This is where rasterization occurs

        // In a loop, for each Triangle2d in input, until all tris are read:
            // Generate a random int value, representing a color for this tri.
            // In a loop, for each row of the output RasterGrid:
                // In a loop, for each column of the output RasterGrid:
                    // Get the centerpoint of the current pixel from the
                    // RasterGrid.
                    // Compare that Point2d to the 2d coordinates of the
                    // Triangle2d:
                        // If they intersect, set the value of the RasterGrid
                        // at the current coordinates to the random color for
                        // this Triangle.
                        // If they do not intersect, do nothing.
    }

    // Result access function
    RasterGrid getRasterizedGrid() {
        return result;
    }
};

int main()
{
    // variable declarations
    double cameraPosX;
    double cameraPosY;
    double cameraPosZ;

    double cameraRotX;
    double cameraRotY;
    double cameraRotZ;

    std::string inputOBJ;
    std::string outputBMP;

    // get input from user
    std::cout << "SLB Software Rasterizer" << std::endl << std::endl;

    std::cout << "Provide camera position as three floating point numbers." << std::endl;
    std::cout << "X, Y, Z, separated by blanks (eg: 0.0 10.0 2.0): ";
    std::cin >> cameraPosX >> cameraPosY >> cameraPosZ;
    std::cout << std::endl;

    std::cout << "Provide camera rotation as three floating point numbers." << std::endl;
    std::cout << "X, Y, Z, separated by blanks (eg: 0.0 0.1 0.0): ";
    std::cin >> cameraRotX >> cameraRotY >> cameraRotZ;
    std::cout << std::endl;

    std::cout << "Provide the filename of the input .obj file: ";
    std::cin >> inputOBJ;
    std::cout << std::endl;

    std::cout << "Provide a name for the .bmp file to output: ";
    std::cin >> outputBMP;
    std::cout << std::endl;

    // construct objects from input
    Point3d cameraPos = Point3d(cameraPosX, cameraPosY, cameraPosZ);
    Point3d cameraRot = Point3d(cameraRotX, cameraRotY, cameraRotZ);
    Camera3d camera = Camera3d(cameraPos, cameraRot);
    Object3d object = Object3d(inputOBJ);

    // summarize variables for this render from constructed objects
    std::cout << "The 3d Object: " << object.getInputFilename() << std::endl;
    std::cout << "Will be rendered to the image: " << outputBMP << std::endl;
    std::cout << "With a camera located at (X, Y, Z): "
        << camera.getPosition().getX() << " "
        << camera.getPosition().getY() << " "
        << camera.getPosition().getZ() << std::endl;
    std::cout << "and looking in the direction of (X, Y, Z): "
        << camera.getRotation().getX() << " "
        << camera.getRotation().getY() << " "
        << camera.getRotation().getZ() << std::endl;

}
