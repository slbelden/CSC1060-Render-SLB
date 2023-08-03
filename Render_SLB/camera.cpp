#include "camera.h"

// Camera3d definition

Camera3d::Camera3d(Point3d position, camAxis rotation, double scale)
    : iposition(position), irotation(rotation), iscale(scale)
{
}

Point3d Camera3d::getPosition()
{
    return iposition;
}

camAxis Camera3d::getRotation()
{
    return irotation;
}
