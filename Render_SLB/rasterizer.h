#pragma once

// rasterizer.h
// Class for rasterizing a projected object into a raster grid
// 2023-07-31
// Stephen L. Belden

#include "grid.h"
#include "project.h"

class Rasterizer
{
private:
    RasterGrid result;

public:
    // The functionality of this class is implemented in its constructor,
    // the class is intended to be instantiated and immediately used.
    Rasterizer(ProjectedObject input, RasterGrid output);

    // Result access function
    RasterGrid getRasterizedGrid();

    // Final output function
    void saveToBMP(string outfile);
};