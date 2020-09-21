
#include <iostream>
#include "Image.h"
#include "Scene.h"
#include "Sphere.h"
#include "Shader.h"
#include "Triangle.h"

#include <cmath>

//adapted from https://github.com/cemuyuk/RayTracing

// GLM Mathematics
#define GLM_FORCE_RADIANS // force everything in radian
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

using namespace std;
using namespace Raytracer148;
using namespace Eigen;

int main() {
	Image im(400, 400);

	Scene scene;

	Vector3d center, kAmb, kDif, kSpec, t1v0, t1v1, t1v2, t2v0, t2v1, t2v2;
	/////////////////////////////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////////////////////////////
	//Sphere 1
	kAmb[0] = 0.1;
	kAmb[1] = 0.1;
	kAmb[2] = 0;

	kDif[0] = 0.5;
	kDif[1] = 0.5;
	kDif[2] = 0;

	kSpec[0] = 1.0;
	kSpec[1] = 1.0;
	kSpec[2] = 1.0;

	center[0] = 0;
	center[1] = 0;
	center[2] = 4;
	scene.addShape(new Sphere(center, 2, kAmb, kDif, kSpec));
	/////////////////////////////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////////////////////////////
	//Sphere 2
	kAmb[0] = 0.05;
	kAmb[1] = 0;
	kAmb[2] = 0.2;

	kDif[0] = 0.25;
	kDif[1] = 0;
	kDif[2] = 0.5;

	center[0] = -.5;
	center[1] = 1;
	center[2] = 2.5;
	scene.addShape(new Sphere(center, .5, kAmb, kDif, kSpec));
	/////////////////////////////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////////////////////////////
	//Sphere 3
	kAmb[0] = 0.1;
	kAmb[1] = 0;
	kAmb[2] = 0.1;

	kDif[0] = 0.5;
	kDif[1] = 0;
	kDif[2] = 0.5;

	center[0] = 0.5;
	center[1] = 1.25;
	center[2] = 2.75;
	scene.addShape(new Sphere(center, .5, kAmb, kDif, kSpec));
	/////////////////////////////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////////////////////////////
	//Triangle
	kAmb[0] = 0;
	kAmb[1] = 0.1;
	kAmb[2] = 0;

	kDif[0] = 0;
	kDif[1] = 0.5;
	kDif[2] = 0;

	t1v0[0] = -0.5;
	t1v0[1] = 0;
	t1v0[2] = 0.5;

	t1v1[0] = 0.5;
	t1v1[1] = -1;
	t1v1[2] = 1.5;

	t1v2[0] = 0;
	t1v2[1] = 0.5;
	t1v2[2] = 1.8;
	scene.addShape(new Triangle(t1v0, t1v1, t1v2, kAmb, kDif, kSpec));

	/////////////////////////////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////////////////////////////
	scene.render(im);
	im.writePNG("test.png");
	return 0;
}
