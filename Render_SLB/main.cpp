// main.cpp

// CSC1060C03
// M5 Capstone Project: Final
// 2023-08-03
// Stephen L. Belden

#include <iostream>

#include "scene.h"

using namespace std;

// function prototypes
sceneDescriptor buildScene();
string bunchOfChars(char c, int n);
char menuPrompt();
void printSceneInfo(Scene& scene);

int main()
{
    // Capstone Requirement 4 - Variables
    Scene scene = Scene(sceneDescriptor());

    // Included scenes
    const sceneDescriptor triangleScene = {
        0.0, 10.0, 0.0,     // Camera Position
        camAxis::Y,         // Camera Rotation
        "twotri.obj",       // Input file
        640, 480, 12.0      // Screen dimensions and scale
    };
    const sceneDescriptor flippedScene = {
        0.0, -10.0, 0.0,    // Camera Position
        camAxis::Y,         // Camera Rotation
        "twotri.obj",       // Input file
        640, 480, 12.0      // Screen dimensions and scale
    };
    const sceneDescriptor bunnyScene = {
        -0.02, 0.115, 3.0,  // Camera Position
        camAxis::Z,         // Camera Rotation
        "bunny.obj",        // Input file
        640, 480, 0.27      // Screen dimensions and scale
    };
    const sceneDescriptor teapotScene = {
        0.15, 1.5, -10.0,   // Camera Position
        camAxis::Z,         // Camera Rotation
        "teapot.obj",       // Input file
        320, 240, 7.0       // Screen dimensions and scale
    };

    // Begin program
    // Capstone Requirement 3 - Input/Output
    cout << "SLB Software Rasterizer - CCD.edu CSC1060C03 Capstone Project"
        << endl << endl;
    cout << "Loading default scene..." << endl;

    // Interactive terminal menu system
    // Capstone Requirement 3 - Input/Output
    // Capstone Requirement 7 - Iteration (loops)
    // Capstone Requirement 8 - Interaction
    for (char option = 'S'; option != 'E'; option = menuPrompt())
    {
        cout << endl;

        // Capstone Requirement 9 - Control
        switch (option) {
        case 'B':
            scene = Scene(bunnyScene);
            printSceneInfo(scene);
            break;

        case 'T':
            scene = Scene(teapotScene);
            printSceneInfo(scene);
            break;

        case 'S':
            scene = Scene(triangleScene);
            printSceneInfo(scene);
            break;

        case 'F':
            scene = Scene(flippedScene);
            printSceneInfo(scene);
            break;

        case 'C':
            scene = Scene(buildScene());
            printSceneInfo(scene);
            break;

        case 'P':
            printSceneInfo(scene);
            break;

        case 'R':
        {
            // Ask user for output filename.
            // Capstone Requirement 3 - Input/Output
            string outFile = "";
            cout << "Specify output filename (without spaces): ";
            cin >> outFile;

            string discardNewLine;
            getline(cin, discardNewLine);

            // This is the function call that does it all!
            scene.renderToFile(outFile);
        }
            break;

        default:
            cout << "Unrecognized option." << endl;
            cout << endl;
        }
    }    
}

// Ask the user for info to build a new scene.
// Capstone Requirement 3 - Input/Output
sceneDescriptor buildScene()
{
    sceneDescriptor newScene;

    cout << "Provide camera position as three floating point numbers." << endl;
    cout << "X, Y, Z, separated by blanks (eg: 0.0 10.0 2.0): ";
    cin >> newScene.camPosX >> newScene.camPosY >> newScene.camPosZ;
    cout << endl;

    cout << "Provide camera rotation as one character, X, Y, or Z: ";
    // store input
    char temp;
    cin >> temp;
    // convert to enum and allow lowercase input
    (toupper(temp) == 'X') ? newScene.camRot = camAxis::X : 
        ((toupper(temp) == 'Y') ? newScene.camRot = camAxis::Y :
            newScene.camRot = camAxis::Z);
    cout << endl;

    cout << "Provide the filename of the input .obj file: ";
    cin >> newScene.objName;
    cout << endl;

    cout << "Provide the width and height of the output image in pixels" << endl;
    cout << "as two integer values, separated by a blank (eg: 640 480): ";
    cin >> newScene.screenWidth >> newScene.screenHeight;
    cout << endl;

    string discardNewLine;
    getline(cin, discardNewLine);

    return newScene;
}

// Return a string containing n copies of c
// Capstone Requirement 7 - Iteration (loops)
string bunchOfChars(char c, int n)
{
    string result = "";

    for (int i = 0; i < n; i++)
    {
        result += c;
    }

    return result;
}

// Present the user with options and return only one choice
// Capstone Requirement 3 - Input/Output
char menuPrompt()
{
    char c;

    cout << "Menu Options:" << endl;
    cout << "    B - load the Stanford Bunny scene (VERY slow)" << endl;
    cout << "    T - load the Utah Teapot scene (slow)" << endl;
    cout << "    S - load a Simple triangle scene (fastest)" << endl;
    cout << "    F - load a Flipped version of the simple scene" << endl;
    cout << "    C - specify a Custom scene to load" << endl;
    cout << "    P - Print info about the currently loaded scene" << endl;
    cout << "    R - Render the currently loaded scene" << endl;
    cout << "    E - Exit the program" << endl;
    cout << endl;
    cout << "Enter the letter of your choice: ";

    cin.get(c);

    string discardNewLine;
    getline(cin, discardNewLine);

    return toupper(c);
}

// Show info about the currently loaded scene to the user in a formated block
// Capstone Requirement 3 - Input/Output
void printSceneInfo(Scene& scene)
{
    cout << bunchOfChars('#', 24) << " Scene Info "
        << bunchOfChars('#', 24) << endl;
    cout << scene.getInfoBlockText();
    cout << bunchOfChars('#', 60) << endl;
    cout << endl;
}
