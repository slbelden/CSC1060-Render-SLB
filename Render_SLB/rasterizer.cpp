#include "rasterizer.h"

// Rasterizer definition

// Private helper functions

// Write BMP header to the file
// Standard header implementation referenced from:
// https://dev.to/muiz6/c-how-to-write-a-bitmap-image-from-scratch-1k6m
int Rasterizer::writeHeader(ofstream& bmpFile)
{
    // Bitmap signature bytes
    const char B = 'B';
    const char M = 'M';
    bmpFile.write((char*)&B, sizeof(uint8_t));
    bmpFile.write((char*)&M, sizeof(uint8_t));

    // Bitmap file size in bytes
    const uint32_t bytesInHeader = 54;
    const uint32_t bytesPerPixel = 3;
    uint32_t bytesInBody = result.getWidth() * result.getHeight() * bytesPerPixel;
    uint32_t size = bytesInHeader + bytesInBody;
    bmpFile.write((char*)&size, sizeof(uint32_t));

    // Data offset information
    uint32_t reservedBytes = 0;
    bmpFile.write((char*)&reservedBytes, sizeof(uint32_t));
    uint32_t offset = bytesInHeader;
    bmpFile.write((char*)&offset, sizeof(uint32_t));

    // Info header section
    const uint32_t sizeOfInfoHeader = 40;
    bmpFile.write((char*)&sizeOfInfoHeader, sizeof(uint32_t));

    // Image dimensions
    int32_t width = result.getWidth();
    int32_t height = result.getHeight();
    bmpFile.write((char*)&width, sizeof(int32_t));
    bmpFile.write((char*)&height, sizeof(int32_t));

    // Color settings
    const uint16_t numberOfColorPlanes = 1; // must be 1
    const uint16_t colorDepth = 24; // 3 byes per pixel
    bmpFile.write((char*)&numberOfColorPlanes, sizeof(uint16_t));
    bmpFile.write((char*)&colorDepth, sizeof(uint16_t));

    // Image data settings
    const uint32_t compressionMethod = 0; // no compression
    const uint32_t rawBitmapDataSize = 0; // generally ignored
    bmpFile.write((char*)&compressionMethod, sizeof(uint32_t));
    bmpFile.write((char*)&rawBitmapDataSize, sizeof(uint32_t));

    // Real-world size (for printing)
    const int32_t horizontalResolution = 3780; // in pixel per meter
    const int32_t verticalResolution = 3780; // in pixel per meter
    bmpFile.write((char*)&horizontalResolution, sizeof(int32_t));
    bmpFile.write((char*)&verticalResolution, sizeof(int32_t));

    // Color palate lookup table information (unused)
    const uint32_t colorTableEntries = 0; // not used in this implementation
    const uint32_t importantColors = 0; // not used in this implementation
    bmpFile.write((char*)&colorTableEntries, sizeof(uint32_t));
    bmpFile.write((char*)&importantColors, sizeof(uint32_t));

    return bytesInHeader;
}

int Rasterizer::writePixels(ofstream& bmpFile)
{
    // writing pixel data
    int numberOfPixels = result.getWidth() * result.getHeight();
    for (int i = 0; i < numberOfPixels; i++)
    {
        unsigned char red = 100u;
        unsigned char gre = 200u;
        unsigned char blu = 255u;
        bmpFile.write((char*)&red, sizeof(uint8_t));
        bmpFile.write((char*)&gre, sizeof(uint8_t));
        bmpFile.write((char*)&blu, sizeof(uint8_t));
    }

    return numberOfPixels * 3;
}



// Public functions

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

int Rasterizer::saveToBMP(string outfile)
{
    int byteCount = 0;

    // open file
    // Capstone Requirement 6 - File I/O
    ofstream bmpFile;
    bmpFile.open(outfile.c_str());

    // check for valid file
    if (!bmpFile.is_open())
    {
        return 0;
    }

    // Write header first
    byteCount += writeHeader(bmpFile);

    // Write pixels after header
    byteCount += writePixels(bmpFile);

    // Close the file
    bmpFile.close();

    return byteCount;
}
