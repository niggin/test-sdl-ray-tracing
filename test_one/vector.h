#include "stdafx.h"
class Vector
{
public:
	float x_;
	float y_;
	float z_;
	Vector() {};
	Vector(float x, float y, float z);
	float Long();
	float Skalar(const Vector& v1, const Vector& v2);
	Vector Vectorn(const Vector& v1, const Vector& v2);
	Vector operator+(const Vector& v) const;
	Vector operator-(const Vector& v) const;
	Vector operator*(float c);
	bool operator!=(const Vector& v) const;
	bool operator==(const Vector& v) const;
	friend class Sphere;
};

class LightSource : public Vector
{
public:
	float density_;
	LightSource(float x,float y,float z,float density);
};

