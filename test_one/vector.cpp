#include "stdafx.h"
#include "vector.h"

Vector::Vector()
{
	x_=0;
	y_=0;
	z_=0;
}

Vector::Vector(float x, float y, float z)
{
	x_=x;
	y_=y;
	z_=z;
}

float Long(const Vector& v)
{
	return sqrt(v.x_*v.x_+v.y_*v.y_+v.z_*v.z_);
}

/*float Vector::Long()
{
	return sqrt(x_*x_+y_*y_+z_*z_);
}*/

/*float Vector::Skalar(const Vector& v1, const Vector& v2)
{
	return v1.x_*v2.x_ + v1.y_*v2.y_ + v1.z_*v2.z_;
}*/


float Skalar(const Vector& v1, const Vector& v2)
{
	return v1.x_*v2.x_ + v1.y_*v2.y_ + v1.z_*v2.z_;
}
Vector Vector::Vectorn(const Vector& v1, const Vector& v2)
{
	return Vector(v1.y_*v2.z_-v1.z_*v2.y_,v1.z_*v2.x_-v1.x_*v2.z_,v1.x_*v2.y_-v1.y_*v2.x_);
}

Vector Vector::operator+(const Vector& v) const
{
	Vector temp;
	temp.x_=x_+v.x_;
	temp.y_=y_+v.y_;
	temp.z_=z_+v.z_;
	return temp;
}
Vector Vector::operator-(const Vector& v) const
{
	Vector temp;
	temp.x_=x_-v.x_;
	temp.y_=y_-v.y_;
	temp.z_=z_-v.z_;
	return temp;
}

Vector Vector::operator*(float c)
{
	Vector temp;
	temp.x_=x_*c;
	temp.y_=y_*c;
	temp.z_=z_*c;
	return temp;
}

bool Vector::operator!=(const Vector& v) const
{
	//if(this==&v) return false;
	//else return true;
	if((abs(x_-v.x_)<0.01f) && (abs(y_ - v.y_)<0.01f) && (abs(z_ - v.z_)<0.01f)) return false;
	else return true;
}

bool Vector::operator==(const Vector& v) const
{
	if(this!=&v) return false;
	else return true;
	/*if((abs(x_-v.x_)<1.0f) && (abs(y_ - v.y_)<1.0f) && (abs(z_ - v.z_)<1.0f)) return true;
	else return false;*/
}

LightSource::LightSource(float x, float y, float z,float density)
{
	x_=x;
	y_=y;
	z_=z;
	density_=density;
}