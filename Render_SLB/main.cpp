// CSC1060C03
// M5 Capstone Project: Final
// 2023-08-02
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
    const sceneDescriptor bunnyScene = {
        // Camera Positions
        1.0,
        2.0,
        3.0,
        // Camera Rotations
        4.0,
        5.0,
        6.0,
        // Input file
        "bunny.obj",
        // Screen dimensions
        640,
        480
    };
    const sceneDescriptor teapotScene = {
        // Camera Positions
        1.0,
        2.0,
        3.0,
        // Camera Rotations
        4.0,
        5.0,
        6.0,
        // Input file
        "teapot.obj",
        // Screen dimensions
        640,
        480
    };

    // Begin program
    cout << "SLB Software Rasterizer - CCD.edu CSC1060C03 Capstone Project"
        << endl << endl;
    cout << "Loading default scene, Stanford Bunny..." << endl;

    // Interactive terminal menu system
    // Capstone Requirement 3 - Input/Output
    // Capstone Requirement 7 - Iteration (loops)
    // Capstone Requirement 8 - Interaction
    for (char option = 'B'; option != 'E'; option = menuPrompt())
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
            cout << option;
            return -1;
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

char menuPrompt()
{
    char c;

    cout << "Menu Options:" << endl;
    cout << "    B - load the Stanford Bunny scene" << endl;
    cout << "    T - load the Utah Teapot scene" << endl;
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

void printSceneInfo(Scene& scene)
{
    cout << bunchOfChars('#', 24) << " Scene Info "
        << bunchOfChars('#', 24) << endl;
    cout << scene.getInfoBlockText();
    cout << bunchOfChars('#', 60) << endl;
    cout << endl;
}
