// CSC1060C03
// M5 Capstone Project: Final
// 2023-08-02
// Stephen L. Belden

#include <iostream>

#include "scene.h"

using namespace std;

// function prototypes
sceneDescriptor buildScene();

int main()
{
    // Interactive terminal menu system
    // Capstone Requirement 3 - Input/Output
    // Capstone Requirement 8 - Interaction
    cout << "SLB Software Rasterizer" << endl << endl;
    Scene scene = Scene(buildScene());
    cout << scene.getInfoBlockText();

    // temp
    string outFile;
    cout << "Specify Outfile: ";
    cin >> outFile;

    scene.renderToFile(outFile);
}

// Interactively ask the user for info to build a new scene
// Capstone Requirement 3 - Input/Output
sceneDescriptor buildScene()
{
    sceneDescriptor newScene;

    cout << "Provide camera position as three floating point numbers." << endl;
    cout << "X, Y, Z, separated by blanks (eg: 0.0 10.0 2.0): ";
    cin >> newScene.camPosX >> newScene.camPosY >> newScene.camPosZ;
    cout << endl;

    cout << "Provide camera rotation as three floating point numbers." << endl;
    cout << "X, Y, Z, separated by blanks (eg: 0.0 1.0 -0.2): ";
    cin >> newScene.camRotX >> newScene.camRotY >> newScene.camRotZ;
    cout << endl;

    cout << "Provide the filename of the input .obj file: ";
    cin >> newScene.objName;
    cout << endl;

    cout << "Provide the width and height of the output image in pixels" << endl;
    cout << "as two integer values, separated by a blank (eg: 640 480): ";
    cin >> newScene.screenWidth >> newScene.screenHeight;
    cout << endl;

    return newScene;
}
