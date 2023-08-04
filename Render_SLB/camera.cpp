#include "camera.h"

// camera.cpp
// Definitions for Camera3d class
// 2023-08-03
// Stephen L. Belden

Point3d Camera3d::getPosition()
{
    return iposition;
}

camAxis Camera3d::getRotation()
{
    return irotation;
}
