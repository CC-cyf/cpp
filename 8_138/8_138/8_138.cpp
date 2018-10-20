#include<iostream>
#include<math.h>
using namespace std;

class Point
{
public:
	double x;
	double y;
	Point(double a, double b);
	double Distance(const Point &Point);
};
Point::Point(double a, double b)
{
	x = a;
	y = b;
};
double Point::Distance(const Point &Point)
{
	double delta_x, delta_y, result;
	delta_x = abs(x - Point.x);
	delta_y = abs(y - Point.y);
	result = sqrt(delta_x*delta_x + delta_y * delta_y);
	return result;
};

int main()
{
	double a, b, c, d;
	cin >> a >> b >> c >> d;
	Point A(a, b), B(c, d);
	cout << A.Distance(B) << endl;
	system("pause");
	return 0;
}