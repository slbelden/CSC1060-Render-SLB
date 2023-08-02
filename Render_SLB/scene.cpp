#include "scene.h"

// Scene definitions

string Scene::getInfoBlockText()
{
	return	"Object: " + obj.getInputFilename() + "\n" +
			"Vertices Loaded: " + to_string(obj.getVertCount()) + "\n" +
			"Triangles Loaded: " + to_string(obj.getTriCount()) + "\n" +
			"\n" +
			"Camera Position: " +
			to_string(cam.getPosition().getX()) + " " +
			to_string(cam.getPosition().getY()) + " " +
			to_string(cam.getPosition().getY()) + " " + "\n" +
			"Camera Rotation: " +
			to_string(cam.getRotation().getX()) + " " +
			to_string(cam.getRotation().getY()) + " " +
			to_string(cam.getRotation().getY()) + " " + "\n" +
			"\n" +
			"Image Dimensions: " +
			to_string(screen.getWidth()) + " x " +
			to_string(screen.getHeight()) + "\n";
}

void Scene::renderToFile(string outFile)
{
	// Sort
	SortedObject sortObj = SortedObject(obj, cam);
	cout << "Sorted " << sortObj.getSortedTrisCount() <<
		" triangles by depth in " << sortObj.getSortingSteps() << " steps."
		<< endl;

	// Project
	ProjectedObject projection = ProjectedObject(sortObj, cam);

	// Rasterize
	Rasterizer rasterizer = Rasterizer(projection, screen);

	// Output
	rasterizer.saveToBMP(outFile);
}
