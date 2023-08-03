#pragma once

#include "points.h"

// points.h
// Class representing a camera in 3d space
// 2023-07-31
// Stephen L. Belden

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
    Camera3d(Point3d position, camAxis rotation, double scale);

    // Member access functions
    Point3d getPosition();
    camAxis getRotation();
};