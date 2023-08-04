#include "grid.h"

// grid.cpp
// Definitions for RasterGrid class
// 2023-08-03
// Stephen L. Belden

RasterGrid::RasterGrid(int width, int height, double screenScale)
    : iwidth(width), iheight(height), iscreenScale(screenScale)
{
    // Initialize values to all black
    values = vector<vector<Pixel>>(height,
        std::vector<Pixel>(width, Pixel(0, 0, 0)));
}

Point2d RasterGrid::getGridPointOffsets(int x, int y)
{
    // Divide scale into pixel-sized increments
    const double step = iscreenScale / iwidth;

    // Calculate offsets
    const double offsetX = step * x;
    const double offsetY = step * y;

    // Because it is desirable for the camera coordinates to represent the
    // center of the screen, not the corner, shift offsets by half the screen
    const double aspect = static_cast<double>(iwidth) / static_cast<double>(iheight);
    const double shiftOffX = offsetX - (iscreenScale / 2);
    const double shiftOffY = offsetY - ((iscreenScale / aspect) / 2);

    // Construct the "point" to return two values
    return Point2d(shiftOffX, shiftOffY);
}

int RasterGrid::getWidth()
{
    return iwidth;
}

int RasterGrid::getHeight()
{
    return iheight;
}

Pixel RasterGrid::getValue(int x, int y)
{
    return values[x][y];
}

void RasterGrid::setValue(int x, int y, Pixel value)
{
    values[x][y] = value;
}
