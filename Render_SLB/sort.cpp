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
        double xAvg = (tri.getVert1().getX() + tri.getVert2().getX() + tri.getVert3().getX()) / 3;
        double yAvg = (tri.getVert1().getY() + tri.getVert2().getY() + tri.getVert3().getY()) / 3;
        double zAvg = (tri.getVert1().getZ() + tri.getVert2().getZ() + tri.getVert3().getZ()) / 3;

        // calculate distance from camera using 3d Pythagorean theorem
        double sideX = xAvg - camera.getPosition().getX();
        double sideY = yAvg - camera.getPosition().getY();
        double sideZ = zAvg - camera.getPosition().getZ();
        double hypotenuse = sqrt((sideX * sideX) + (sideY * sideY) + (sideZ * sideZ));

        // add current element to end of parallel lists
        // this creates room for the insertion sort shifting in the next loop
        depthSortedTris.push_back(tri);
        triDepths.push_back(hypotenuse);

        // shift into correct place in list based on calculated distance
        for (int i = depthSortedTris.size() - 1; i > 0; i--)
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
