#pragma once

// object.h
// Class for opening, reading, and storing an immutable 3d object
// 2023-07-31
// Stephen L. Belden

#include <cassert>
#include <fstream>
#include <string>
#include <vector>

#include "points.h"
#include "triangles.h"

using namespace std;

class Object3d
{
private:
    int vertCount = 0;
    string filename;
    vector<Triangle3d> triList;

public:
    // A 3d object is always constructed from a file.
    // A 3d object can not be modified after it has been created.
    Object3d(string inFile);

    // Data access functions
    string getInputFilename();
    vector<Triangle3d> getTriList();
    int getVertCount();
    int getTriCount();
};