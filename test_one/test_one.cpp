// test_one.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
//#include "vector.h"
#include "sphere.h"
#include "sdl_functions.h"


void DrawScreen(SDL_Surface* screen, int width, int height, Color color)
{
	for (int x=0;x<width;++x) for (int y=0;y<height;++y) putpixel(screen,x,y,color.GetUint32());
	SDL_UpdateRect(screen,0,0,1024,600);
}

void DrawSphere(SDL_Surface* screen, Sphere s, int width, int height, LightSource light)
{
	for (int x=0;x<width;x++) for (int y=0;y<height;y++)
	{
		if (x>width/2+70) if (y>height/2+20) 
			s=s;
		Vector sol = Solution(Vector(x-width/2,1000,y-height/2),Vector(0,0,0),s);
		if (sol!=Vector(0,0,0))
		{
			Color c1=s.color_;
			putpixel(screen,x,y,Shadow(light,sol,s).GetUint32());
			SDL_UpdateRect(screen,x,y,1,1);
		}
	}
	//SDL_UpdateRect(screen,0,0,1024,600);
}

void SmartDrawSphere(SDL_Surface* screen, LightSource light, Sphere S, int width, int height)
{
	for (int y=S.center_.z_-S.r_;y<=S.center_.z_+S.r_;++y)
		for (int x=-(int)sqrt(S.r_*S.r_-(y-S.center_.x_)*(y-S.center_.x_))-1;x<(int)sqrt(S.r_*S.r_-(y-S.center_.x_)*(y-S.center_.x_))+1;++x)
		{
			Vector sol = Solution(Vector(x*5,1000,y*5),Vector(0,0,0),S);
		if (sol!=Vector(0,0,0))
		{
			Color c1=S.color_;
			//sol=sol*5;
			putpixel(screen,width/2+x*5,y*5+height/2,Shadow(light,sol,S).GetUint32());
			SDL_UpdateRect(screen,width/2+x*5,sol.z_+height/2,1,1);
		}
		}
}


int _tmain(int argc, _TCHAR* argv[])
{
	/*int width = 1024,height=600;
	SDL_Surface* screen = enableScreen(width,height,24);
	Color white = Color(255,255,255);
	float red=255,green=255,blue=255,posx=200,posy=200;
	white.SetNewColor(red,green,blue);
	while (true) 
		{
				SDL_Event keyEvent ; SDL_PollEvent(&keyEvent);
			for (int x=posx;x<posx+100;x++) for (int y=posy;y<posy+100;y++)
				{
					putpixel(screen,x,y,Color(0,0,0).GetUint32());
				}
			if(keyEvent.type == SDL_KEYDOWN) switch (keyEvent.key.keysym.sym)
			{
			case SDLK_ESCAPE: return 0;
			case SDLK_1: if(red<255) red+=1; break;
			case SDLK_2: if(red>0) red-=1; break;
			case SDLK_3: if(green<255) green+=1; break;
			case SDLK_4: if(green>0) green-=1; break;
			case SDLK_5: if(blue<255) blue+=1; break;
			case SDLK_6: if(blue>0) blue-=1; break;
			case SDLK_UP: posy-=1; break;
			case SDLK_DOWN: posy+=1; break;
			case SDLK_LEFT: posx-=1; break;
			case SDLK_RIGHT: posx+=1; break;
			}
			white.SetNewColor(red,green,blue);
			for (int x=posx;x<posx+100;x++) for (int y=posy;y<posy+100;y++)
				{
					putpixel(screen,x,y,white.GetUint32());
				}
			SDL_UpdateRect(screen,0,0,width,height);





		}*/

	Sphere s1 = Sphere(Vector(0,200,0),Color(255,0,0),20);
	SDL_Surface* screen = enableScreen(1024,600,24);
	LightSource light(150,50,0,20000);
	DrawSphere(screen,s1,1024,600,light);
	//SmartDrawSphere(screen,light,s1,1024,600);
	float a = Skalar(s1.center_,s1.center_);
	int b = Long(s1.center_);
	while (true) 
		{
			SDL_Event keyEvent ; SDL_PollEvent(&keyEvent);
			if(keyEvent.type == SDL_KEYDOWN) switch (keyEvent.key.keysym.sym)
				{
					case SDLK_ESCAPE: return 0;
					case SDLK_LEFT: 
						{
							DrawScreen(screen,1024,600,Color(0,0,0));
							light.x_-=5;
							DrawSphere(screen,s1,1024,600,light);
							break;
						}
					case SDLK_RIGHT: 
						{
							DrawScreen(screen,1024,600,Color(0,0,0));
							light.x_+=5;
							DrawSphere(screen,s1,1024,600,light);
							break;
						}
					case SDLK_UP: 
						{
							DrawScreen(screen,1024,600,Color(0,0,0));
							light.y_+=5;
							DrawSphere(screen,s1,1024,600,light);
							break;
						}
					case SDLK_DOWN: 
						{
							DrawScreen(screen,1024,600,Color(0,0,0));
							light.y_-=5;
							DrawSphere(screen,s1,1024,600,light);
							break;
						}
					case SDLK_PAGEUP:
						{
							DrawScreen(screen,1024,600,Color(0,0,0));
							light.density_+=1000;
							DrawSphere(screen,s1,1024,600,light);
							break;
						}
					case SDLK_PAGEDOWN:
						{
							DrawScreen(screen,1024,600,Color(0,0,0));
							light.density_-=1000;
							DrawSphere(screen,s1,1024,600,light);
							break;
						}
				}
			//DrawScreen(screen,1024,600,Color(0,0,0));
			//DrawSphere(screen,s1,1024,600,light);
		}
	return 0;
}

