// CSC1060C03
// M5 Capstone Project: Final
// 2023-08-02
// Stephen L. Belden

#include <float.h>
#include <iomanip>
#include <iostream>
#include <string>

#include "camera.h"
#include "grid.h"
#include "object.h"
#include "points.h"
#include "project.h"
#include "rasterizer.h"
#include "sort.h"
#include "triangles.h"

using namespace std;

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

    // Print some info messages
    // Capstone Requirement 3 - Output
    cout << "Loaded " << object.getVertCount() << " vertices." << endl;
    cout << "Loaded " << object.getTriCount() << " triangles." << endl;

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

    // do the math
    SortedObject sortObj = SortedObject(object, camera);
    cout << "Sorted " << sortObj.getDepthSortedTris().size() << " tris" << endl;
    ProjectedObject projection = ProjectedObject(sortObj, camera);
    Rasterizer rasterizer = Rasterizer(projection, screen);

    // output the result to a file (not yet implemented)
    rasterizer.saveToBMP(outputBMP);

    // Temp: for demonstration
    cout << "Done." << endl;
}
