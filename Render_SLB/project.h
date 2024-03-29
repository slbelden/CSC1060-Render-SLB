#pragma once

// project.h
// Class for projecting a 3d object onto a 2d plane
// 2023-08-02
// Stephen L. Belden

#include <vector>

#include "camera.h"
#include "points.h"
#include "sort.h"

using namespace std;

// Class for projecting a 3d object onto a 2d plane
class ProjectedObject
{
private:
    vector<Triangle2d> projectedTris;

public:
    // The functionality of this class is implemented in its constructor,
    // the class is intended to be instantiated and immediately used.
    ProjectedObject(SortedObject input, Camera3d camera);

    // Result access function
    vector<Triangle2d> getProjectedTris();
};