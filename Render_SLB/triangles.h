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
    Triangle3d(Point3d A, Point3d B, Point3d C) : iA(A), iB(B), iC(C) {};

    // Member access functions
    Point3d getVertA();
    Point3d getVertB();
    Point3d getVertC();
};

// Class representing a single triangle, or face, in 2d space
class Triangle2d
{
private:
    Point2d iA;
    Point2d iB;
    Point2d iC;

public:
    // A triangle is created through this constructor.
    // A triangle can not be modified after it has been created.
    Triangle2d(Point2d A, Point2d B, Point2d C) : iA(A), iB(B), iC(C) {};

    // Intersection test
    bool pointIsInTri(Point2d p);

    // Member access functions
    Point2d getVertA();
    Point2d getVertB();
    Point2d getVertC();
};