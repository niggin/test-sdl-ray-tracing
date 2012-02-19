#include "stdafx.h"
#include "color.h"
class Sphere
{
	friend class Color;
public:
	float r_;
	Vector center_;
	Color color_;
	Sphere(float x, float y, float z, float r, Color color);
	Sphere(Vector center, Color color, float r);
	Vector Solution(Vector v, Vector source);
};

Color Shadow(const LightSource& light, const Vector& dotonsphere, Sphere sp);