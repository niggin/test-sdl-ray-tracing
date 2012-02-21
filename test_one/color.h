#include "stdafx.h"
#include "vector.h"
class Color
{
	unsigned char Red_;
	unsigned char Green_;
	unsigned char Blue_;
	Uint32 Result_;
public:
	Color();
	Color(unsigned char Red, unsigned char Green, unsigned char Blue);
	Uint32 GetUint32();
	void SetNewRed(const unsigned char& count);
	void SetNewGreen(const unsigned char& count);
	void SetNewBlue(const unsigned char& count);
	void SetNewColor(const unsigned char& Red, const unsigned char& Green, const unsigned char& Blue);
	Color operator*(float c);
	Color operator+(const Color& color);
};