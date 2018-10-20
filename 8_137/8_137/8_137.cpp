#include<iostream>
#include<math.h>
using namespace std;

class Ctriangle
{
private:
	int a;
	int b;
	int c;
public:
	Ctriangle(int x, int y, int z);
	int GetPerimeter();
	int GetArea();
	void display();
};
Ctriangle::Ctriangle(int x, int y, int z)
{
	a = x;
	b = y;
	c = z;
};
int Ctriangle::GetPerimeter()
{
	return a + b + c;
};
int Ctriangle::GetArea()
{
	int p = (a + b + c) / 2;
	int s = (p*(p - a)*(p - b)*(p - c));
	int i;
	for (i = 0; i*i < s; i++);
	return i;
};
void Ctriangle::display()
{
	cout << "Ctriangle:a=" << a << ",b=" << b << ",c=" << c << endl;
};

int main()
{
	double a, b, c;
	cin >> a >> b >> c;
	Ctriangle T(a, b, c);
	T.display();
	cout << "Perimeter:" << T.GetPerimeter() << endl;
	cout << "Area:" << T.GetArea() << endl;
	system("pause");
	return 0;
}