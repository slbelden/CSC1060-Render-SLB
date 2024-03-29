#include "rasterize.h"

// rasterizer.cpp
// Definitions for Rasterizer class
// 2023-08-03
// Stephen L. Belden

// Private Helper Functions

// Write BMP header to the file
// Standard header implementation referenced from:
// https://dev.to/muiz6/c-how-to-write-a-bitmap-image-from-scratch-1k6m
// Capstone Requirement 6 - File I/O
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
    // Each row is padded out to a multiple of 4 bytes.
    uint32_t bytesInRow = result.getWidth() * bytesPerPixel;
    while (bytesInRow % 4 > 0) bytesInRow++;
    uint32_t bytesInBody = bytesInRow * result.getHeight();
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

// Transfer pixel data from RasterGrid result to output file
// Capstone Requirement 6 - File I/O
int Rasterizer::writePixels(ofstream& bmpFile)
{
    // Capstone Requirement 4 - Variables
    int byteCount = 0;

    // write pixel data for every pixel in the 2d vector
    // Capstone Requirement 7 - Iteration (loops)
    for (int row = 0; row < result.getHeight(); row++)
    {
        int rowBytes = 0;

        for (int col = 0; col < result.getWidth(); col++)
        {
            unsigned char red = result.getValue(row, col).getRed();
            unsigned char gre = result.getValue(row, col).getGre();
            unsigned char blu = result.getValue(row, col).getBlu();
            bmpFile.write((char*)&red, sizeof(uint8_t));
            bmpFile.write((char*)&gre, sizeof(uint8_t));
            bmpFile.write((char*)&blu, sizeof(uint8_t));

            rowBytes += 3;
            byteCount += 3;
        }

        // The length of each row of a valid BMP file must be a multiple of 4
        // bytes. Add null chars (bytes) to reach that multiple.
        while(rowBytes % 4 > 0)
        {
            writePadByte(bmpFile);
            rowBytes++;
            byteCount++;
        }
    }

    return byteCount;
}

// Write a single padding byte to the end of the file
// Capstone Requirement 3 - Input/Output
void Rasterizer::writePadByte(ofstream& bmpFile)
{
    unsigned char blank = 0u;
    bmpFile.write((char*)&blank, sizeof(uint8_t));
}

// Testing function: write pixel data to upper left quarter of screen
void Rasterizer::writeBlock(ofstream& bmpFile)
{
    for (int row = 0; row < result.getHeight(); row++)
    {
        for (int col = 0; col < result.getWidth(); col++)
        {
            if (row < (result.getHeight() / 2) && col < (result.getWidth() / 2))
            {
                unsigned char red = 100u;
                unsigned char gre = 200u;
                unsigned char blu = 255u;
                bmpFile.write((char*)&red, sizeof(uint8_t));
                bmpFile.write((char*)&gre, sizeof(uint8_t));
                bmpFile.write((char*)&blu, sizeof(uint8_t));
            }
            else
            {
                unsigned char red = 0u;
                unsigned char gre = 0u;
                unsigned char blu = 0u;
                bmpFile.write((char*)&red, sizeof(uint8_t));
                bmpFile.write((char*)&gre, sizeof(uint8_t));
                bmpFile.write((char*)&blu, sizeof(uint8_t));
            }
        }
    }
}



// Public Functions

Rasterizer::Rasterizer(Camera3d cam, ProjectedObject input, RasterGrid output)
    : result(output)
{
    // Capstone Requirement 4 - Variables
    int hitCounter = 0;
    int missCounter = 0;
    int triCounter = 0;

    double screenLocalX = 0.0;
    double screenLocalY = 0.0;

    // Determine which camera axes make up the screen
    // Capstone Requirement 9 - Control
    switch (cam.getRotation()) {
    case camAxis::X:
        screenLocalX = cam.getPosition().getY();
        screenLocalY = cam.getPosition().getZ();
        break;

    case camAxis::Y:
        screenLocalX = cam.getPosition().getX();
        screenLocalY = cam.getPosition().getZ();
        break;

    case camAxis::Z:
        screenLocalX = cam.getPosition().getX();
        screenLocalY = cam.getPosition().getY();
        break;
    }

    // Give feedback to the user
    // Capstone Requirement 3 - Input/Output
    Point2d topLeft = result.getGridPointOffsets(0, 0);
    Point2d botRight = result.getGridPointOffsets(result.getWidth(), result.getHeight());
    cout << "Rasterizing screen from (" <<
        screenLocalX + topLeft.getX() << ", " <<
        screenLocalY + topLeft.getY() << ") to (" <<
        screenLocalX + botRight.getX() << ", " <<
        screenLocalY + botRight.getY() << ")" << endl;

    // Rasterize each Triangle from back to front
    // Capstone Requirement 7 - Iteration (loops)
    for (Triangle2d& tri : input.getProjectedTris())
    {
        // Give occasional feedback to the user
        // Capstone Requirement 3 - Input/Output
        if (triCounter % 250 == 0)
        {
            cout << "Rendered " << triCounter << " out of " <<
                input.getProjectedTris().size() << " triangles..." << endl;
        }

        // Generate a random color to use for this triangle.
        // Use a minimum brightness of 100 for contrast on black background.
        Pixel color = Pixel(100);

        // Check every pixel in the grid
        // Capstone Requirement 7 - Iteration (loops)
        for (int row = 0; row < result.getHeight(); row++)
        {
            for (int col = 0; col < result.getWidth(); col++)
            {
                // Shift points by camera coordinates
                Point2d testOfsets = result.getGridPointOffsets(col, row);
                Point2d screenPoint =
                    Point2d(screenLocalX + testOfsets.getX(),
                        screenLocalY + testOfsets.getY());

                // Test for intersection with triangle at current pixel and
                // set pixel color according to intersection test.
                // Capstone Requirement 9 - Control
                if (tri.pointIsInTri(screenPoint))
                {
                    result.setValue(row, col, color);
                    hitCounter++;
                }
                else
                {
                    missCounter++;
                }
            }
        }

        triCounter++;
    }

    // Output stats
    // Capstone Requirement 3 - Input/Output
    cout << "Rendered " << triCounter << " out of " <<
        input.getProjectedTris().size() << " triangles." << endl;
    cout << "Found " << hitCounter << " pixel-triangle intersections with " <<
        missCounter << " misses." << endl;
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

    // DEBUG
    // writeBlock(bmpFile);

    // Close the file
    bmpFile.close();

    return byteCount;
}

RasterGrid Rasterizer::getRasterizedGrid() {
    return result;
}
