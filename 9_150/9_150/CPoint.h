#pragma once
#include<iostream>
using namespace std;

class Point
{
private:
	float x;
	float y;
public:
	Point(float xx, float yy)
	{
		x = xx;
		y = yy;
	}
};

class Rectangle :public Point
{
private:
	float width;
	float high;
public:
	Rectangle(float xx, float yy, float w, float h);
	float Area();
};

class Circle :public Point
{
private:
	float radius;
public:
	Circle(float xx, float yy, float r);
	float Area();
};