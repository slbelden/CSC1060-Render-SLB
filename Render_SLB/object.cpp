#include "object.h"

// object.cpp
// Definitions for Object3d class
// 2023-08-02
// Stephen L. Belden

Object3d::Object3d(string inFile) : filename(inFile)
{
    // Local variable declarations
    // Capstone Requirement 4 - Variables
    string line;
    vector<Point3d> verts;

    // Open file
    // Capstone Requirement 6 - File I/O
    ifstream objFile;
    objFile.open(filename.c_str());

    // Check for valid file
    if (!objFile.is_open())
    {
        return;
    }

    // Process until end of file
    // Capstone Requirement 7 - Iteration (loops)
    while (!objFile.eof())
    {
        // Read the first character of the line
        // Capstone Requirement 3 - Input/Output
        char next = '#';
        objFile.get(next);

        // The first character of a line determines what it defines,
        // v for vertex and f for face. Other lines are ignored.
        // Capstone Requirement 9 - Control
        if (next == 'v')
        {
            // Read vertex coordinates into a new Point3d object
            // Capstone Requirement 3 - Input
            double x, y, z;
            objFile >> x >> y >> z;
            Point3d newPoint(x, y, z);

            // Add the new vertex to the array
            // Capstone Requirement 5 - Arrays
            verts.push_back(newPoint);
        }
        else if (next == 'f')
        {
            // Read vertex numbers
            // Capstone Requirement 3 - Input
            int a, b, c;
            objFile >> a >> b >> c;

            // Lookup the vertices in the array, and create a new
            // Triangle3d object. Because .obj files start with index 1
            // instead of 0, we subtract 1 during array access.
            // Capstone Requirement 5 - Arrays
            Triangle3d newTri(verts[a - 1], verts[b - 1], verts[c - 1]);

            // Add the new triangle to the array
            triList.push_back(newTri);
        }

        // After processing, clear the line from input stream
        string discard;
        getline(objFile, discard);
    }

    // Set internal vertex counter,
    // since this information will be lost out of this scope
    vertCount = verts.size();
}

string Object3d::getInputFilename()
{
    return filename;
}

vector<Triangle3d> Object3d::getTriList()
{
    return triList;
}

size_t Object3d::getVertCount()
{
    return vertCount;
}

size_t Object3d::getTriCount()
{
    return triList.size();
}

