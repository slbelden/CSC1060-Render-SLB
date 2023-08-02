#pragma once

#include "points.h"

// points.h
// Class representing a camera in 3d space
// 2023-07-31
// Stephen L. Belden

class Camera3d
{
private:
    Point3d iposition;
    Point3d irotation;
    double iscale;

public:
    // A camera is created through this constructor.
    // A camera can not be modified after it has been created.
    Camera3d(Point3d position, Point3d rotation, double scale);

    // Member access functions
    Point3d getPosition();
    Point3d getRotation();
};