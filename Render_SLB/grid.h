#pragma once

// grid.h
// Class representing the output result, a grid of pixels
// 2023-07-31
// Stephen L. Belden

#include <string>
#include <vector>

#include "pixel.h"
#include "points.h"

using namespace std;

class RasterGrid {
private:
    int iwidth;
    int iheight;
    double iscreenScale;
    vector<vector<Pixel>> values;

public:
    // Constructor specifies width, height, and scale, which can not be changed
    RasterGrid(int width, int height, double screenScale);

    // Returns the 2d point on the plane corresponding to the center of a
    // given raster cell (pixel), used for calculations during rasterization.
    Point2d getGridPointOffsets(int x, int y);

    // Member access functions
    int getWidth();
    int getHeight();
    Pixel getValue(int x, int y);

    // Member setters
    void setValue(int x, int y, Pixel value);
};