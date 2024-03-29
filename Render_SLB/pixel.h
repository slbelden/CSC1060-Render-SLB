#pragma once

// pixel.h
// Class defining an 8-bit color RGB pixel
// 2023-08-03
// Stephen L. Belden

#include <limits>
#include <random>

using namespace std;

class Pixel
{
private:
	// One byte (char) per color
	unsigned char red;
	unsigned char gre;
	unsigned char blu;

public:
	// Immutable. Standard constructor.
	Pixel(unsigned char r, unsigned char g, unsigned char b)
		: red(r), gre(g), blu(b) {};

	// Random constructor
	Pixel(int randBrightFloor);

	// Access functions
	unsigned char getRed();
	unsigned char getGre();
	unsigned char getBlu();
};

