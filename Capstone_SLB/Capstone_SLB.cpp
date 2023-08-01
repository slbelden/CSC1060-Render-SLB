// CSC1060C03
// M4 Capstone Project: Capstone Preparation
// 2023-07-22
// Stephen L. Belden

// This project has been condensed into a single file to adhere to the
// assignment submission criteria.

// Capstone project requirements are commented starting on lines 162 and 453.

#include <cassert>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

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
    string filename;
    vector<Triangle3d> triList;

public:
    // A 3d object is always constructed from a file.
    // A 3d object can not be modified after it has been created.
    Object3d(string inFile)
    {
        filename = inFile;

        // local variable declarations
        // Capstone Requirement 4 - Variables
        string line;
        vector<Point3d> verts;

        // open file
        // Capstone Requirement 6 - File I/O
        ifstream objFile;
        objFile.open(filename.c_str());

        // check for valid file
        assert(objFile.is_open());

        // process until end of file
        // Capstone Requirement 7 - Iteration (loops)
        while (!objFile.eof())
        {
            // read the first character of the line
            char next = '#';
            objFile.get(next);

            // The first character of a line determines what it defines,
            // v for vertex and f for face. Other lines are ignored.
            // Capstone Requirement 9 - Control
            if (next == 'v')
            {
                // read vertex coordinates into a new Point3d object
                // Capstone Requirement 3 - Input
                double x, y, z;
                objFile >> x >> y >> z;
                Point3d newPoint(x, y, z);

                // add the new vertex to the array
                // Capstone Requirement 5 - Arrays
                verts.push_back(newPoint);
            }
            else if (next == 'f')
            {
                // read vertex numbers
                // Capstone Requirement 3 - Input
                int a, b, c;
                objFile >> a >> b >> c;
                
                // Lookup the vertices in the array, and create a new
                // Triangle3d object. Because .obj files start with index 1
                // instead of 0, we subtract 1 during array access.
                // Capstone Requirement 5 - Arrays
                Triangle3d newTri(verts[a - 1], verts[b - 1], verts[c - 1]);

                // add the new triangle to the array
                triList.push_back(newTri);
            }

            // after processing, clear the line from input stream
            string discard;
            getline(objFile, discard);
        }
        
        // Print some info messages
        // Capstone Requirement 3 - Output
        cout << "Loaded " << verts.size() << " vertices." << endl;
        cout << "Loaded " << triList.size() << " triangles." << endl;
    }

    vector<Triangle3d> getTriList()
    {
        return triList;
    }

    string getInputFilename()
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
    vector<vector<int>> values;

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
    vector<Triangle3d> depthSortedTris;

public:
    // The functionality of this class is implemented in its constructor,
    // the class is intended to be instantiated and immediately used.
    SortedObject(Object3d object, Camera3d camera)
    {
        // parallel array alongside vector<Triangle3d> depthSortedTris;
        vector<double> triDepths;

        for (Triangle3d tri : object.getTriList())
        {
            // calculate average position of triangle's verticies
            double xAvg = (tri.getVert1().getX() + tri.getVert2().getX() + tri.getVert3().getX()) / 3;
            double yAvg = (tri.getVert1().getY() + tri.getVert2().getY() + tri.getVert3().getY()) / 3;
            double zAvg = (tri.getVert1().getZ() + tri.getVert2().getZ() + tri.getVert3().getZ()) / 3;

            // calculate distance from camera using 3d Pythagorean theorem
            double sideX = xAvg - camera.getPosition().getX();
            double sideY = yAvg - camera.getPosition().getY();
            double sideZ = zAvg - camera.getPosition().getZ();
            double hypotenuse = sqrt((sideX * sideX) + (sideY * sideY) + (sideZ * sideZ));

            // add current element to end of parallel lists
            // this creates room for the insertion sort shifting in the next loop
            depthSortedTris.push_back(tri);
            triDepths.push_back(hypotenuse);

            // shift into correct place in list based on calculated distance
            for (int i = depthSortedTris.size() - 1; i > 0; i--)
            {
                // starting at the back of the list, shift deeper elements right
                // until the proper place for the current element is found
                if (triDepths[i - 1] > hypotenuse)
                {
                    // shift
                    depthSortedTris[i] = depthSortedTris[i - 1];
                    triDepths[i] = triDepths[i - 1];

                    // insert
                    depthSortedTris[i - 1] = tri;
                    triDepths[i - 1] = hypotenuse;
                }
                else
                {
                    // element has been moved to is correct place, we're done
                    break;
                }
            }
        }

        // debug output
        for (int i = 0; i < triDepths.size(); i++)
        {
            cout << setprecision(16) << i << ": " << triDepths[i] << endl;
        }

        // Progress Output
        cout << "Sorted " << depthSortedTris.size() << " tris" << endl;
    }

    // Result access function
    vector<Triangle3d> getDepthSortedTris() {
        return depthSortedTris;
    }
};

// Class for projecting a 3d object onto a 2d plane
class ProjectedObject
{
private:
    vector<Point2d> projectedPointsList;

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

        // Temp: for demonstration
        cout << "Projecting..." << endl;
    }

    // Result access function
    vector<Point2d> getProjectedTris()
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

        // Temp: for demonstration
        cout << "Rasterizing..." << endl;
    }

    // Result access function
    RasterGrid getRasterizedGrid() {
        return result;
    }

    // Final output function
    void saveToBMP(string outfile)
    {
        // This is where the rasterized data will be saved to a file

        // First, check that outfile is a valid filename, and that it can be
        // written to. If not, assert an error.

        // Open the file at outfile for writing.
        // Write the BMP header to the file.
            // Most of the header is fixed.
            // A few bytes represent the height and width of the image.

        // In a loop, for every column in the result RasterGrid:
            // In a loop, for every row in the result RasterGrid:
                // Convert the int value of the current cell of the grid to
                // R, G and B colors. This can be done by mapping a subset of
                // integer values (such as 0 - 255) to a set of colors.
                // The specific color is not important, as what matters
                // is that each value has the same unique color.
                // Append the R, G, and B bytes to the output file.
            // At the end of each row, if the number of bytes written is not
            // divisible by 4, add blank (all zero) bytes to the file
            // until the number of bytes in the row is divisible by 4.

        // Temp: for demonstration
        cout << "Writing to file..." << endl;
    }
};

int main()
{
    // variable declarations
    // Capstone Requirement 4 - Variables
    double cameraPosX;
    double cameraPosY;
    double cameraPosZ;

    double cameraRotX;
    double cameraRotY;
    double cameraRotZ;

    int width;
    int height;

    string inputOBJ;
    string outputBMP;

    // fixed constants
    double pixelScale = 0.001;

    // get input from user
    // Capstone Requirement 3 - Input
    // Capstone Requirement 8 - Interaction
    cout << "SLB Software Rasterizer" << endl << endl;

    cout << "Provide camera position as three floating point numbers." << endl;
    cout << "X, Y, Z, separated by blanks (eg: 0.0 10.0 2.0): ";
    cin >> cameraPosX >> cameraPosY >> cameraPosZ;
    cout << endl;

    cout << "Provide camera rotation as three floating point numbers." << endl;
    cout << "X, Y, Z, separated by blanks (eg: 0.0 1.0 -0.2): ";
    cin >> cameraRotX >> cameraRotY >> cameraRotZ;
    cout << endl;

    cout << "Provide the filename of the input .obj file: ";
    cin >> inputOBJ;
    cout << endl;

    cout << "Provide a name for the .bmp file to output: ";
    cin >> outputBMP;
    cout << endl;

    cout << "Provide the width and height of the output image in pixels"
        << endl;
    cout << "as two integer values, separated by a blank (eg: 640 480): ";
    cin >> width >> height;
    cout << endl;

    // construct objects from input
    Point3d cameraPos = Point3d(cameraPosX, cameraPosY, cameraPosZ);
    Point3d cameraRot = Point3d(cameraRotX, cameraRotY, cameraRotZ);
    Camera3d camera = Camera3d(cameraPos, cameraRot);
    Object3d object = Object3d(inputOBJ);
    RasterGrid screen = RasterGrid(width, height, pixelScale);

    // summarize variables for this render from constructed objects
    // Capstone Requirement 3 - Output
    cout << endl << "The 3d Object: " << object.getInputFilename() << endl;
    cout << "Will be rendered to the image: " << outputBMP << endl;
    cout << "With the resolution (w by h): " << screen.getWidth() 
        << " by " << screen.getHeight() << endl;
    cout << showpoint;
    cout << "With a camera located at (X, Y, Z): "
        << camera.getPosition().getX() << " "
        << camera.getPosition().getY() << " "
        << camera.getPosition().getZ() << endl;
    cout << "looking in the direction of (X, Y, Z): "
        << camera.getRotation().getX() << " "
        << camera.getRotation().getY() << " "
        << camera.getRotation().getZ() << endl
        << endl;

    // do the math (not yet implemented)
    SortedObject sortObj = SortedObject(object, camera);
    ProjectedObject projection = ProjectedObject(sortObj, camera);
    Rasterizer rasterizer = Rasterizer(projection, screen);

    // output the result to a file (not yet implemented)
    rasterizer.saveToBMP(outputBMP);

    // Temp: for demonstration
    cout << "Done." << endl;
}
