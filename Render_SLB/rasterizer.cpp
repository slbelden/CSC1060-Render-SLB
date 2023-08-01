#include "rasterizer.h"

// Rasterizer definition

Rasterizer::Rasterizer(ProjectedObject input, RasterGrid output) : result(output)
{
    // This is where rasterization occurs

    // In a loop, for each Triangle2d in input, until all tris are read:
    // Generate a random int value, representing a color for this tri.
    // In a loop, for each row of the output RasterGrid:
    // In a loop, for each column of the output RasterGrid:
    // Get the centerpoint of the current pixel from the
    // RasterGrid.
    // Compare that Point2d to the 2d coordinates of the
    // Triangle2d:
    // If they intersect, set the value of the RasterGrid
    // at the current coordinates to the random color for
    // this Triangle.
    // If they do not intersect, do nothing.
}


RasterGrid Rasterizer::getRasterizedGrid() {
    return result;
}

void Rasterizer::saveToBMP(string outfile)
{
    // This is where the rasterized data will be saved to a file

    // First, check that outfile is a valid filename, and that it can be
    // written to. If not, assert an error.

    // Open the file at outfile for writing.
    // Write the BMP header to the file.
    // Most of the header is fixed.
    // A few bytes represent the height and width of the image.

    // In a loop, for every column in the result RasterGrid:
    // In a loop, for every row in the result RasterGrid:
    // Convert the int value of the current cell of the grid to
    // R, G and B colors. This can be done by mapping a subset of
    // integer values (such as 0 - 255) to a set of colors.
    // The specific color is not important, as what matters
    // is that each value has the same unique color.
    // Append the R, G, and B bytes to the output file.
    // At the end of each row, if the number of bytes written is not
    // divisible by 4, add blank (all zero) bytes to the file
    // until the number of bytes in the row is divisible by 4.
}
