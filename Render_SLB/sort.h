#pragma once

// sort.h
// Class for sorting triangles by depth relative to a camera
// 2023-07-31
// Stephen L. Belden

#include <vector>

#include "camera.h"
#include "object.h"
#include "triangles.h"

using namespace std;

// Class for sorting triangles by depth relative to a camera
class SortedObject
{
private:
    vector<Triangle3d> depthSortedTris;

public:
    // The functionality of this class is implemented in its constructor,
    // the class is intended to be instantiated and immediately used.
    SortedObject(Object3d object, Camera3d camera);

    // Result access function
    vector<Triangle3d> getDepthSortedTris();
};