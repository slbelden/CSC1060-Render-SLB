#include "triangles.h"

// triangles.cpp
// Definitions for Triangle3d and Triangle2d classes
// 2023-08-02
// Stephen L. Belden

// Triangle3d

Point3d Triangle3d::getVertA()
{
    return iA;
}

Point3d Triangle3d::getVertB()
{
    return iB;
}

Point3d Triangle3d::getVertC()
{
    return iC;
}



// Triangle2d

// Barycentric Coordinate System Method referenced from:
// https://totologic.blogspot.com/2014/01/accurate-point-in-triangle-test.html
bool Triangle2d::pointIsInTri(Point2d p)
{
    // local declarations
    double x1 = iA.getX();
    double y1 = iA.getY();

    double x2 = iB.getX();
    double y2 = iB.getY();

    double x3 = iC.getX();
    double y3 = iC.getY();

    double x = p.getX();
    double y = p.getY();

    // Hardcore math.
    // Triangle intersection is a solved problem; I didn't invent this.
    double denominator = (x1 * (y2 - y3) + y1 * (x3 - x2) + x2 * y3 - y2 * x3);
    double a = ((y2 - y3) * (x - x3) + (x3 - x2) * (y - y3)) / denominator;
    double b = ((y3 - y1) * (x - x3) + (x1 - x3) * (y - y3)) / denominator;
    double c = 1 - a - b;

    return 0 <= a && a <= 1 && 0 <= b && b <= 1 && 0 <= c && c <= 1;
}

Point2d Triangle2d::getVertA()
{
    return iA;
}

Point2d Triangle2d::getVertB()
{
    return iB;
}

Point2d Triangle2d::getVertC()
{
    return iB;
}
