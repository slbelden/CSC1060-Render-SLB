#pragma once

// triangles.h
// 3d and 2d classes for immutable triangles
// 2023-07-31
// Stephen L. Belden

#include "points.h"

// Class representing a single triangle, or face, in 3d space
class Triangle3d
{
private:
    Point3d iA;
    Point3d iB;
    Point3d iC;

public:
    // A triangle is created through this constructor.
    // A triangle can not be modified after it has been created.
    Triangle3d(Point3d A, Point3d B, Point3d C);

    // Member access functions
    Point3d getVert1();
    Point3d getVert2();
    Point3d getVert3();
};

// Class representing a single triangle, or face, in 2d space
class Triangle2d
{
private:
    Point3d iA;
    Point3d iB;

public:
    // A triangle is created through this constructor.
    // A triangle can not be modified after it has been created.
    Triangle2d(Point3d A, Point3d B);

    // Member access functions
    Point3d getVert1();
    Point3d getVert2();
};