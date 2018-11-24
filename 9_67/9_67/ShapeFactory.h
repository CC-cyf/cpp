#pragma once
class ShapeFactory
{
public:
	ShapeFactory() {};
	virtual ~ShapeFactory() {};
	virtual float Circumstance() { return 0; };
	ShapeFactory *Create(float a, float b, float c);
	ShapeFactory *Create(float a, float b, float c, float d);
	ShapeFactory *Create(float r);
};

class Triangle :public ShapeFactory
{
public:
	int x, y, z;
	Triangle(int a = 0, int b = 0, int c = 0)
	{
		x = a;
		y = b;
		z = c;
	}
	~Triangle() {};
	float Circumstance() { return (x + y + z); }
};

class Quadrangle :public ShapeFactory
{
public:
	int x, y, z, w;
	Quadrangle(int a = 0, int b = 0, int c = 0, int d = 0)
	{
		x = a;
		y = b;
		z = c;
		w = d;
	};
	~Quadrangle() {};
	float Circumstance() { return (x + y + z + w); };
};

class Circle :public ShapeFactory
{
public:
	int r;
	Circle(int a = 0) { r = a; };
	~Circle() {};
	float Circumstance() { return (2 * 3.14 * r); };
};

ShapeFactory * ShapeFactory::Create(float a, float b, float c)
{
	ShapeFactory *p = new Triangle(a, b, c);
	return p;
}
ShapeFactory * ShapeFactory::Create(float a, float b, float c, float d)
{
	ShapeFactory *p = new Quadrangle(a, b, c, d);
	return p;
}
ShapeFactory * ShapeFactory::Create(float r)
{
	ShapeFactory *p = new Circle(r);
	return p;
}