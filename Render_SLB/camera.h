#pragma once

// camera.h
// Class representing a planar camera in 3d space
// 2023-08-03
// Stephen L. Belden

#include "points.h"

// Camera facing direction, used during projection.
// The specified axis is normal to the camera plane.
enum camAxis {X, Y, Z};

class Camera3d
{
private:
    Point3d iposition;
    camAxis irotation;
    double iscale;

public:
    // A camera is created through this constructor.
    // A camera can not be modified after it has been created.
    Camera3d(Point3d position, camAxis rotation, double scale)
        : iposition(position), irotation(rotation), iscale(scale) {};

    // Member access functions
    Point3d getPosition();
    camAxis getRotation();
};