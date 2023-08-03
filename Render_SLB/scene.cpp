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
			((cam.getRotation() == camAxis::X) ? "X" :
				(cam.getRotation() == camAxis::Y) ? "Y" : "Z") + " " + "\n" +
			"\n" +
			"Image Dimensions: " +
			to_string(screen.getWidth()) + " x " +
			to_string(screen.getHeight()) + "\n";
}

void Scene::renderToFile(string outFile)
{
	cout << endl;

	// Check for valid input file
	if (obj.getTriCount() <= 0)
	{
		cout << "ERROR: Nothing to render." << endl;
		cout << "Input object \"" << obj.getInputFilename() << "\" has no triangles."
			<< endl;
		cout << "Is it a valid .obj file? Does the file exist?" << endl;
		cout << endl;
		return;
	}

	// Sort
	SortedObject sortObj = SortedObject(obj, cam);
	cout << "Sorted " << sortObj.getSortedTrisCount() <<
		" triangles by depth in " << sortObj.getSortingSteps() << " steps."
		<< endl;

	// Project
	ProjectedObject projection = ProjectedObject(sortObj, cam);
	cout << "Projected " << projection.getProjectedTris().size() * 3 <<
		" 3d points into 2d orthogonal to the " <<
		((cam.getRotation() == camAxis::X) ? "X" :
			(cam.getRotation() == camAxis::Y) ? "Y" : "Z") << " axis." << endl;

	// Rasterize
	Rasterizer rasterizer = Rasterizer(projection, screen);

	// Output
	int bytes = rasterizer.saveToBMP(outFile);
	cout << "Wrote " << bytes << " bytes to file \"" << outFile << "\"." << endl;
	cout << "Files are saved in Visual Studio solution folder." << endl;
	cout << endl;
}
