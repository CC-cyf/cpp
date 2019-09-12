#include<iostream>
using namespace std;

class Table
{
protected:
	float high;
public:
	Table(float h) { high = h; };
	float GetHigh() { return high; };
};

class Circle
{
protected:
	float radius;
public:
	Circle(float r) { radius = r; };
	float GetArea() { return (3.14*radius*radius); };
};

class RoundTable :public Table, public Circle
{
protected:
	char color[20];
public:
	RoundTable(float r, float h, char *c) :Table(h), Circle(r)
	{
		for (int i = 0; i < 20; i++)
		{
			color[i] = c[i];
		}
	}
	char *GetColor() { return color; };
};

int main() {
	float radius, high;
	char color[20];
	cin >> radius >> high >> color;

	RoundTable RT(radius, high, color);
	cout << "Area:" << RT.GetArea() << endl;
	cout << "High:" << RT.GetHigh() << endl;
	cout << "Color:" << RT.GetColor() << endl;
	return 0;
}