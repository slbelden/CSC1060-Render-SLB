#include "points.h"

// Point3d definition

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



// Point2d definition

Point2d::Point2d(double X, double Y)
{
    iX = X;
    iY = Y;
}

double Point2d::getX()
{
    return iX;
}

double Point2d::getY()
{
    return iY;
}
