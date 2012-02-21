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

Sphere::Sphere(Vector center, Color color, float r)
{
	center_ = center;
	r_=r;
	color_=color;
}

/*Vector Sphere::Solution(Vector v, Vector source)
{
	float d;
	d = (Skalar(center_-source,v));
	d = d*d;
	d= d-((Long(center_-source))*(Long(center_-source)) - r_*r_)*((Long(v))*(Long(v)));
	if (d<0) return Vector(0,0,0);
	float t;
	d = sqrt(d);
	t = ((Skalar((center_-source),v)) - d)/((Long(v))*(Long(v)));
	return v*t;
}*/

Vector Solution(Vector v, Vector source, Sphere s)
{
	float d;
	d = (Skalar(s.center_-source,v));
	d = d*d;
	d= d-((Long(s.center_-source))*(Long(s.center_-source)) - s.r_*s.r_)*((Long(v))*(Long(v)));
	if (d<0) return Vector(0,0,0);
	float t;
	d = sqrt(d);
	t = ((Skalar((s.center_-source),v)) - d)/((Long(v))*(Long(v)));
	return v*t;
}

Color Shadow(const LightSource& light, const Vector& dotonsphere, Sphere sp)
{
	Color temp = sp.color_;
	Vector v1 = Solution(dotonsphere-light, light,sp);	
	v1 = v1+light;
	if(v1!=dotonsphere) return Color(0,0,0);
	else
	{
		float r = pow(Long(v1-light),2);
		float c=light.density_/(r+10*sqrt(r));
		float c1=Skalar(v1-sp.center_,light-v1)/(Long(v1-sp.center_)*Long(light-v1));
		c1=pow(c1,1);
		c*=abs(c1);
		//if (c>1) 
		{
			{
				temp = sp.color_*c1;
				Color temp2 = (Color(100,100,100)*pow(c,1));
				Color temp3 = temp + temp2 ;
				return temp;
			}
		}
		//else return sp.color_*c;
	}
}
