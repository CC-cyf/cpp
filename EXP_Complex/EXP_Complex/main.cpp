#include<iostream>
using namespace std;

class Complex
{
private:
	double re, im;
public:
	Complex(double r = 0, double i = 0);
	Complex operator*(Complex c);
	friend Complex operator++(Complex& c, int);
	friend istream & operator >>(istream& is, Complex &com);
	// ≤‚ ‘ π”√
	friend ostream & operator <<(ostream& out, Complex &com);
};
Complex::Complex(double r, double i)
{
	re = r;
	im = i;
}
Complex Complex::operator*(Complex c)
{
	double result_r, result_i;
	result_r = re * c.re - im * c.im;
	result_i = re * c.im + im * c.re;
	Complex result(result_r, result_i);
	return result;
}
Complex operator++(Complex& c, int)
{
	Complex temp(c.re, c.im);
	++c.re;
	++c.im;
	return temp;
}
istream & operator >>(istream& is, Complex &com)
{
	double temp_r, temp_i;
	cin >> temp_r >> temp_i;
	com.re = temp_r;
	com.im = temp_i;
	return is;
}
ostream & operator <<(ostream& out, Complex &com)
{
	cout << com.re << '+' << com.im << 'i' << endl;
	return out;
}

int main()
{
	Complex c1;
	cout << c1;
	cin >> c1;
	c1++;
	cout << c1;
	Complex c2(1, 4);
	Complex c3 = (c1*c2);
	cout << c3;
	cout << c1;
	system("pause");
	return 0;
}