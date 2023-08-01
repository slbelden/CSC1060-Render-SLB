#include "triangles.h"

// Triangle3d definition

Triangle3d::Triangle3d(Point3d A, Point3d B, Point3d C)
{
    iA = A;
    iB = B;
    iC = C;
}

Point3d Triangle3d::getVert1()
{
    return iA;
}

Point3d Triangle3d::getVert2()
{
    return iB;
}

Point3d Triangle3d::getVert3()
{
    return iC;
}



// Triangle2d definition

Triangle2d::Triangle2d(Point3d A, Point3d B)
{
    iA = A;
    iB = B;
}

Point3d Triangle2d::getVert1()
{
    return iA;
}

Point3d Triangle2d::getVert2()
{
    return iB;
}
