#pragma once

// scene.h
// Stores and manages all information for rendering one scene
// 2023-08-02
// Stephen L. Belden

#include <iostream>
#include <string>

#include "camera.h"
#include "grid.h"
#include "object.h"
#include "points.h"
#include "project.h"
#include "rasterize.h"
#include "sort.h"
#include "triangles.h"

using namespace std;

struct sceneDescriptor
{
	double camPosX = 0;
	double camPosY = 0;
	double camPosZ = 0;
	camAxis camRot = X;
	string objName = "";
	int screenWidth = 640;
	int screenHeight = 480;
	double screenScale = 1.0;
};

class Scene
{
private:
	Camera3d cam;
	Object3d obj;
	RasterGrid screen;

public:
	// Construct immutable Scene from sceneDescriptor
	Scene(sceneDescriptor desc) :
		cam(Camera3d(Point3d(desc.camPosX, desc.camPosY, desc.camPosZ),
			desc.camRot, desc.screenScale)),
		obj(desc.objName),
		screen(desc.screenWidth, desc.screenHeight, desc.screenScale)
	{}

	// Return info string for use in menu
	string getInfoBlockText();

	// DO THE THING
	void renderToFile(string outFile);
};

