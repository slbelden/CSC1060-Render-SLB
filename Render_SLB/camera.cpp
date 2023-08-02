#include "camera.h"

// Camera3d definition

Camera3d::Camera3d(Point3d position, Point3d rotation, double scale)
    : iposition(position), irotation(rotation), iscale(scale)
{
}

Point3d Camera3d::getPosition()
{
    return iposition;
}

Point3d Camera3d::getRotation()
{
    return irotation;
}
