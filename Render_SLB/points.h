#pragma once

// points.h
// 3d and 2d classes for immutable points
// 2023-07-31
// Stephen L. Belden

// Class for storing and using a point in 3d space.
class Point3d
{
private:
    double iX;
    double iY;
    double iZ;

public:
    // A point is created through this constructor.
    // A point can not be modified after it has been created.
    Point3d(double X = 0.0, double Y = 0.0, double Z = 0.0);

    // Member access functions
    double getX();
    double getY();
    double getZ();
};

// Class for storing and using a point in 2d space.
class Point2d
{
private:
    double iX;
    double iY;

public:
    // A point is created through this constructor.
    // A point can not be modified after it has been created.
    Point2d(double X = 0.0, double Y = 0.0);

    // Member access functions
    double getX() const;
    double getY() const;
};