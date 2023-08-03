#include "grid.h"

// RasterGrid definition

RasterGrid::RasterGrid(int width, int height, double screenScale)
    : iwidth(width), iheight(height), iscreenScale(screenScale)
{
    // Initialize values to all black
    values = vector<vector<Pixel>>(height,
        std::vector<Pixel>(width, Pixel(0, 0, 0)));
}

Point2d RasterGrid::getGridPointOffsets(int x, int y)
{
    // Divide horizontal scale into pixel-sized increments
    double stepHor = iscreenScale / iwidth;

    // Determine vertical scale from aspect ratio
    double aspect = static_cast<double>(iwidth) / static_cast<double>(iheight);
    double stepVer = stepHor / aspect;

    // Calculate offsets
    double offsetHor = stepHor * x;
    double offsetVer = stepVer * y;

    // Because it is desirable for the camera coordinates to represent the
    // center of the screen, not the corner, shift offsets by half the screen
    double shiftOffH = offsetHor - (iscreenScale / 2);
    double shiftOffV = offsetVer - ((iscreenScale / aspect)) / 2;

    // Construct the "point" to return two values
    return Point2d(shiftOffH, shiftOffV);
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
