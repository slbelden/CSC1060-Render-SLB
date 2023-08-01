#include "project.h"

// ProjectedObject definition

ProjectedObject::ProjectedObject(SortedObject input, Camera3d camera)
{
    // This is where projection occurs

    // First, define the projection plane.
    // The plane is determined by the position and rotation of the
    // camera. A 2d plane in 3d space can be defined by 3 points.
    // Conveniently, we already have a class for that. A Triangle3d
    // can be used to define the plane.
    // The  plane is defined to be a small fixed distance in front of
    // the camera, tangent to the rotation vector of the camera.

    // In a loop, for each Triangle3d in input, until all tris are read:
    // In a loop, for each of the three Point3d objects in a triangle:
    // Project the point onto the projection plane.
    // Store the result in a Point2d.
    // Store the three Point2d objects in a Triangle2d.
    // Add each Triangle2d to projectedPointsList.
}

vector<Point2d> ProjectedObject::getProjectedTris()
{
    return projectedPointsList;
}
