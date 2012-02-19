#include "stdafx.h"
#include "sphere.h"

Sphere::Sphere(float x, float y, float z, float r, Color color)
{
	center_.x_=x;
	center_.y_=y;
	center_.z_=z;
	r_=r;
	color_=color;
}

Sphere::Sphere(Vector center,Color color, float r)
{
	center_ = center;
	r_=r;
	color_=color;
}

Vector Sphere::Solution(Vector v, Vector source)
{
	float d;
	d = (center_.Skalar(center_-source,v));
	d = d*d;
	d= d-(((center_-source).Long())*((center_-source).Long()) - r_*r_)*((v.Long())*(v.Long()));
	if (d<0) return Vector(0,0,0);
	float t;
	d = sqrt(d);
	t = (((center_-source).Skalar((center_-source),v)) - d)/((v.Long())*(v.Long()));
	return v*t;
}

Color Shadow(const LightSource& light, const Vector& dotonsphere, Sphere sp)
{
	Color temp = sp.color_;
	Vector v1 = sp.Solution(dotonsphere-light, light);	
	v1 = v1+light;
	if(v1!=dotonsphere) return Color(0,0,0);
	else
	{
		float r = pow((v1-light).Long(),2);
		float c=light.density_/r;
		float c1=v1.Skalar(v1-sp.center_,light-v1)/((v1-sp.center_).Long()*(light-v1).Long());
		c1=pow(c1,1);
		c*=abs(c1);
		//if (c>1) 
		{
			{
				temp = sp.color_*c1;
				Color temp2 = (Color(100,100,100)*pow(c,1));
				Color temp3 = temp + temp2;
				return temp3;
			}
		}
		//else return sp.color_*c;
	}
}
