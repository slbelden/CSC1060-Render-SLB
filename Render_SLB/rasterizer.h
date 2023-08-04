#pragma once

// rasterizer.h
// Class for rasterizing a projected object into a raster grid
// 2023-08-03
// Stephen L. Belden

#include <cstdint>
#include <fstream>
#include <iostream>

#include "camera.h"
#include "grid.h"
#include "pixel.h"
#include "project.h"

class Rasterizer
{
private:
    RasterGrid result;

    // Helper functions for code organization
    int writeHeader(ofstream& bmpFile);
    int writePixels(ofstream& bmpFile);
    void writePadByte(ofstream& bmpFile);
    void writeBlock(ofstream& bmpFile); // DEBUG

public:
    // The functionality of this class is implemented in its constructor,
    // the class is intended to be instantiated and immediately used.
    Rasterizer(Camera3d cam, ProjectedObject input, RasterGrid output);

    // Result access function
    RasterGrid getRasterizedGrid();

    // Final output function, returns number of bytes written
    int saveToBMP(string outfile);
};