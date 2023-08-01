#pragma once

// project.h
// Class for projecting a 3d object onto a 2d plane
// 2023-07-31
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
    vector<Point2d> projectedPointsList;

public:
    // The functionality of this class is implemented in its constructor,
    // the class is intended to be instantiated and immediately used.
    ProjectedObject(SortedObject input, Camera3d camera);

    // Result access function
    vector<Point2d> getProjectedTris();
};