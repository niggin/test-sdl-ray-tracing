#include "stdafx.h"
#include "color.h"

Color::Color()
{
	Red_=0;
	Blue_=0;
	Green_=0;
	Result_=0;
}

Color::Color(unsigned char Red, unsigned char Green, unsigned char Blue)
{
	Red_ = Red;
	Green_ = Green;
	Blue_ = Blue;
	Result_ = Red*65536 + Green*256 + Blue;
}

Uint32 Color::GetUint32()
{
	return Result_;
}

void Color::SetNewRed(const unsigned char& count)
{
	Red_=count;
	Result_ = Result_ -(Result_/65536)*65536 +count*65536;
}

void Color::SetNewGreen(const unsigned char& count)
{
	Green_=count;
	Result_ = Result_ -((Result_%65536)/256)*256 +count*256;
}

void Color::SetNewBlue(const unsigned char& count)
{
	Blue_=count;
	Result_ = Result_ -Result_%256 +count;
}

void Color::SetNewColor(const unsigned char& Red, const unsigned char& Green, const unsigned char& Blue)
{
	Red_ = Red;
	Green_ = Green;
	Blue_ = Blue;
	Result_ = Red*65536 + Green*256 + Blue;
}

Color Color::operator*(float c)
{
	Color temp(0,0,0);
	if(Red_*c<255) temp.Red_=Red_*c;
	else temp.Red_ = 255;
	if(Green_*c<255) temp.Green_=Green_*c;
	else temp.Green_ = 255;
	if(Blue_*c<255) temp.Blue_=Blue_*c;
	else temp.Blue_ = 255;
	temp.Result_ = temp.Red_*65536 + temp.Green_*256 + temp.Blue_;
	return temp;
}

Color Color::operator+(const Color& color)
{
	Color test = Color(0,0,0);
	if((unsigned int)Red_+(unsigned int)color.Red_<255) test.Red_=Red_+color.Red_;
	else test.Red_ = 255;
	if((unsigned int)Blue_+(unsigned int)color.Blue_<255) test.Blue_=Blue_+color.Blue_;
	else test.Blue_ = 255;
	if((unsigned int)Green_+(unsigned int)color.Green_<255) test.Green_=Green_+color.Green_;
	else test.Green_ = 255;
	test.Result_= test.Red_*65536 + test.Green_*256 + test.Blue_;
	return test;
}