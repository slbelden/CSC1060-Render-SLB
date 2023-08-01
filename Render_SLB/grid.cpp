#include "grid.h"

// RasterGrid definition

RasterGrid::RasterGrid(int width, int height, double pixelScale)
{
    iwidth = width;
    iheight = height;
    ipixelScale = pixelScale;
}

int RasterGrid::getWidth()
{
    return iwidth;
}

int RasterGrid::getHeight()
{
    return iheight;
}

int RasterGrid::getValue(int x, int y)
{
    return values[x][y];
}

Point2d RasterGrid::getRasterPointCoords(int x, int y)
{
    double col = ipixelScale * x;
    double row = ipixelScale * y;
    return Point2d(x, y);
}

void RasterGrid::setValue(int x, int y, int value)
{
    values[x][y] = value;
}
