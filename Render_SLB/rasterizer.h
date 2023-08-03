#pragma once

// rasterizer.h
// Class for rasterizing a projected object into a raster grid
// 2023-07-31
// Stephen L. Belden

#include <cstdint>
#include <fstream>

#include "grid.h"
#include "project.h"

class Rasterizer
{
private:
    RasterGrid result;

    // Helper functions for code organization
    int writeHeader(ofstream& bmpFile);
    int writePixels(ofstream& bmpFile);

public:
    // The functionality of this class is implemented in its constructor,
    // the class is intended to be instantiated and immediately used.
    Rasterizer(ProjectedObject input, RasterGrid output);

    // Result access function
    RasterGrid getRasterizedGrid();

    // Final output function, returns number of bytes written
    int saveToBMP(string outfile);
};