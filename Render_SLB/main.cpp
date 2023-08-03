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

    // Default included scenes
    const sceneDescriptor triangleScene = {
        // Camera Positions
        0.0,
        10.0,
        0.0,
        // Camera Rotation
        camAxis::Y,
        // Input file
        "twotri.obj",
        // Screen dimensions and scale
        640,
        480,
        12.0
    };
    const sceneDescriptor flippedScene = {
        // Camera Positions
        0.0,
        -10.0,
        0.0,
        // Camera Rotation
        camAxis::Y,
        // Input file
        "twotri.obj",
        // Screen dimensions and scale
        640,
        480,
        12.0
    };
    const sceneDescriptor bunnyScene = {
        // Camera Positions
        -0.02,
        0.115,
        3.0,
        // Camera Rotation
        camAxis::Z,
        // Input file
        "bunny.obj",
        // Screen dimensions and scale
        640,
        480,
        0.27
    };
    const sceneDescriptor teapotScene = {
        // Camera Positions
        0.15,
        1.5,
        -10.0,
        // Camera Rotation
        camAxis::Z,
        // Input file
        "teapot.obj",
        // Screen dimensions and scale
        320,
        240,
        7.0
    };

    // Begin program
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

// Interactively ask the user for info to build a new scene
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
void printSceneInfo(Scene& scene)
{
    cout << bunchOfChars('#', 24) << " Scene Info "
        << bunchOfChars('#', 24) << endl;
    cout << scene.getInfoBlockText();
    cout << bunchOfChars('#', 60) << endl;
    cout << endl;
}
