#include "points.h"

// points.cpp
// Definitions for Point3d and Point2d classes
// 2023-07-31
// Stephen L. Belden

// Point3d

Point3d::Point3d(double X, double Y, double Z)
{
    iX = X;
    iY = Y;
    iZ = Z;
}

double Point3d::getX()
{
    return iX;
}

double Point3d::getY()
{
    return iY;
}

double Point3d::getZ()
{
    return iZ;
}



// Point2d

Point2d::Point2d(double X, double Y)
{
    iX = X;
    iY = Y;
}

double Point2d::getX() const
{
    return iX;
}

double Point2d::getY() const
{
    return iY;
}
