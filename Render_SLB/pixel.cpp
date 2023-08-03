#include "pixel.h"

// Pixel definition

Pixel::Pixel(int brightnessFloor)
{
    // Generate random pixel color values from brightnessFloor to max of char
    random_device dev;
    mt19937 rng(dev());
    uniform_int_distribution<mt19937::result_type> dist(brightnessFloor, UCHAR_MAX);

    red = dist(rng);
    gre = dist(rng);
    blu = dist(rng);
}

unsigned char Pixel::getRed()
{
    return red;
}

unsigned char Pixel::getGre()
{
    return gre;
}

unsigned char Pixel::getBlu()
{
    return blu;
}
