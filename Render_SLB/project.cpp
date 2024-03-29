#include "project.h"

// project.cpp
// Definitions for ProjectedObject class
// 2023-08-02
// Stephen L. Belden

ProjectedObject::ProjectedObject(SortedObject input, Camera3d camera)
{
    // Projecting from 3d to 2d involves discarding one 3d axis,
    // the camera rotation defines which axis to remove.
    // Capstone Requirement 9 - Control
    switch (camera.getRotation()) {
    case camAxis::X:
        // Discard X coordinate in all triangles of object
        // Capstone Requirement 5 - Arrays
        // Capstone Requirement 7 - Iteration (loops)
        for (Triangle3d tri : input.getDepthSortedTris())
        {
            // Project each point of the triangle
            Point2d newA = Point2d(tri.getVertA().getZ(), tri.getVertA().getY());
            Point2d newB = Point2d(tri.getVertB().getZ(), tri.getVertB().getY());
            Point2d newC = Point2d(tri.getVertC().getZ(), tri.getVertC().getY());

            // Save projected point into internal private class list
            projectedTris.push_back(Triangle2d(newA, newB, newC));
        }
        break;

    case camAxis::Y:
        // Discard Y coordinate in all points of object
        // Capstone Requirement 5 - Arrays
        // Capstone Requirement 7 - Iteration (loops)
        for (Triangle3d tri : input.getDepthSortedTris())
        {
            // Project each point of the triangle
            Point2d newA = Point2d(tri.getVertA().getX(), tri.getVertA().getZ());
            Point2d newB = Point2d(tri.getVertB().getX(), tri.getVertB().getZ());
            Point2d newC = Point2d(tri.getVertC().getX(), tri.getVertC().getZ());

            // Save projected point into internal private class list
            projectedTris.push_back(Triangle2d(newA, newB, newC));
        }
        break;

    case camAxis::Z:
        // Discard Z coordinate in all points of object
        // Capstone Requirement 5 - Arrays
        // Capstone Requirement 7 - Iteration (loops)
        for (Triangle3d tri : input.getDepthSortedTris())
        {
            // Project each point of the triangle
            Point2d newA = Point2d(tri.getVertA().getX(), tri.getVertA().getY());
            Point2d newB = Point2d(tri.getVertB().getX(), tri.getVertB().getY());
            Point2d newC = Point2d(tri.getVertC().getX(), tri.getVertC().getY());

            // Save projected point into internal private class list
            projectedTris.push_back(Triangle2d(newA, newB, newC));
        }
        break;

    }
}

vector<Triangle2d> ProjectedObject::getProjectedTris()
{
    return projectedTris;
}
