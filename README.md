# CSC1060 - Render_SLB
Final Capstone Project for CCD.edu Summer 2023 CSC1060C03. A very simple software rasterizer for a subset of .obj files. Built with Visual Studio 2022.

![example output, Stanford Bunny](https://raw.githubusercontent.com/slbelden/CSC1060/main/Render_SLB/bunny.bmp)

## Design
This is an educational project I created to explore the fundamentals of graphics data processing. The goal was to clearly code the math and data handling operations, so fancy things like GPU acceleration and optimization are avoided. Simple .obj files are supported (vertices and faces only). Projection is limited to camera planes strictly orthogonal to an axis. Arbitrary rotation of the camera is a future goal. Output is bitmap images.

## Usage
Clone the repo. Open the Solution. Run. Menu options are explained in the terminal.

## More Info
See REPORT.pdf

## References

Bourke, P. (n.d.). Object Files (.obj). paulbourke.net. <http://paulbourke.net/dataformats/obj/>

Hassan, M. M. (2020, June 28). C++: How to Write a Bitmap Image from Scratch. dev.to.
<https://dev.to/muiz6/c-how-to-write-a-bitmap-image-from-scratch-1k6m>

Newell, M. (1975). teapot.obj. Utah Graphics Lab.
<https://graphics.cs.utah.edu/courses/cs6620/fall2013/prj05/teapot.obj>

Totologic: Accurate point in triangle test. (2014, January 25). Totologic.
<https://totologic.blogspot.com/2014/01/accurate-point-in-triangle-test.html>

Turk, G., & Levoy, M. (1994, July 29). bunny.obj. Computer Graphics at Stanford University.
<https://graphics.stanford.edu/~mdfisher/Data/Meshes/bunny.obj>
