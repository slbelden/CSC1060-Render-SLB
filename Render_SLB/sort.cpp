#include "sort.h"

// sort.cpp
// Definitions for SortedObject class
// 2023-08-02
// Stephen L. Belden

SortedObject::SortedObject(Object3d object, Camera3d camera)
{
    // Parallel array alongside vector<Triangle3d> depthSortedTris;
    // Capstone Requirement 5 - Arrays
    vector<double> triDepths;

    // Sort every triangle in the list
    // Capstone Requirement 7 - Iteration (loops)
    for (Triangle3d tri : object.getTriList())
    {
        // Calculate average position of triangle's verticies
        double xAvg = (tri.getVertA().getX() + tri.getVertB().getX() + tri.getVertC().getX()) / 3;
        double yAvg = (tri.getVertA().getY() + tri.getVertB().getY() + tri.getVertC().getY()) / 3;
        double zAvg = (tri.getVertA().getZ() + tri.getVertB().getZ() + tri.getVertC().getZ()) / 3;

        // Calculate distance from camera using 3d Pythagorean theorem
        double sideX = xAvg - camera.getPosition().getX();
        double sideY = yAvg - camera.getPosition().getY();
        double sideZ = zAvg - camera.getPosition().getZ();
        double hypotenuse = sqrt((sideX * sideX) + (sideY * sideY) + (sideZ * sideZ));

        // Add current element to end of parallel lists,
        // this creates room for the insertion sort shifting in the next loop.
        // Capstone Requirement 5 - Arrays
        depthSortedTris.push_back(tri);
        triDepths.push_back(hypotenuse);
        steps++;

        // Shift into correct place in list based on calculated distance
        // Capstone Requirement 7 - Iteration (loops)
        for (size_t i = depthSortedTris.size() - 1; i > 0; i--)
        {
            // Starting at the back of the list, shift deeper elements right
            // until the proper place for the current element is found.
            // Capstone Requirement 5 - Arrays
            // Capstone Requirement 9 - Control
            if (triDepths[i - 1] > hypotenuse)
            {
                // shift
                depthSortedTris[i] = depthSortedTris[i - 1];
                triDepths[i] = triDepths[i - 1];

                // insert
                depthSortedTris[i - 1] = tri;
                triDepths[i - 1] = hypotenuse;

                // count
                steps++;
            }
            else
            {
                // Element has been moved to is correct place, we're done
                break;
            }
        }
    }
    // We sorted from least depth to greatest depth.
    // Later we'll need greatest depth to least depth.
    reverse(depthSortedTris.begin(), depthSortedTris.end());
}

vector<Triangle3d> SortedObject::getDepthSortedTris() {
    return depthSortedTris;
}

size_t SortedObject::getSortedTrisCount()
{
    return depthSortedTris.size();
}

int SortedObject::getSortingSteps()
{
    return steps;
}
