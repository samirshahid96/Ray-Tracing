/*
#ifndef SPHERE_H
#define SPHERE_H

#include "Shape.h"

namespace Raytracer148 {
class Sphere : public Shape {
public:
    Sphere(Eigen::Vector3d &center, double radius) : c(center), r(radius) {}

    virtual HitRecord intersect(const Ray &ray);

private:
    Eigen::Vector3d c;
    double r;
};
}

#endif
*/
/////////////////////////kurei
/*
#ifndef SPHERE_H
#define SPHERE_H

#include "Shape.h"

namespace Raytracer148 {
	class Sphere : public Shape {
	public:
		Sphere(Eigen::Vector3d &center, double radius, Eigen::Vector3d &color, bool mir) : c(center), r(radius), Objectcolor(color), mirror(mir) {}

		virtual HitRecord intersect(const Ray &ray);

	private:
		Eigen::Vector3d c;
		Eigen::Vector3d Objectcolor;
		bool mirror = false;
		double r;
	};
}

#endif
*/
/////////////////////////eliwisso
#ifndef SPHERE_H
#define SPHERE_H

#include "Shape.h"

//adapted from https://github.com/cemuyuk/RayTracing

namespace Raytracer148 {
	class Sphere : public Shape {
	public:
		Sphere(Eigen::Vector3d &center, float radius, Eigen::Vector3d &kamb, Eigen::Vector3d &kdif, Eigen::Vector3d &kspec) :
			c(center), r(radius) {
			ka = kamb;
			kd = kdif;
			ks = kspec;
		}
		virtual HitRecord intersect(const Ray &ray);
	private:
		Eigen::Vector3d c;
		double r;
	};
}

#endif
