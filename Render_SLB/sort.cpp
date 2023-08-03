#include "sort.h"

// The functionality of this class is implemented in its constructor,
// the class is intended to be instantiated and immediately used.

SortedObject::SortedObject(Object3d object, Camera3d camera)
{
    // parallel array alongside vector<Triangle3d> depthSortedTris;
    vector<double> triDepths;

    for (Triangle3d tri : object.getTriList())
    {
        // calculate average position of triangle's verticies
        double xAvg = (tri.getVertA().getX() + tri.getVertB().getX() + tri.getVertC().getX()) / 3;
        double yAvg = (tri.getVertA().getY() + tri.getVertB().getY() + tri.getVertC().getY()) / 3;
        double zAvg = (tri.getVertA().getZ() + tri.getVertB().getZ() + tri.getVertC().getZ()) / 3;

        // calculate distance from camera using 3d Pythagorean theorem
        double sideX = xAvg - camera.getPosition().getX();
        double sideY = yAvg - camera.getPosition().getY();
        double sideZ = zAvg - camera.getPosition().getZ();
        double hypotenuse = sqrt((sideX * sideX) + (sideY * sideY) + (sideZ * sideZ));

        // add current element to end of parallel lists
        // this creates room for the insertion sort shifting in the next loop
        depthSortedTris.push_back(tri);
        triDepths.push_back(hypotenuse);
        steps++;

        // shift into correct place in list based on calculated distance
        for (size_t i = depthSortedTris.size() - 1; i > 0; i--)
        {
            // starting at the back of the list, shift deeper elements right
            // until the proper place for the current element is found
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
                // element has been moved to is correct place, we're done
                break;
            }
        }
    }
}

// Result access function

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
