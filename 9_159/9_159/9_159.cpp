#include<iostream>
using namespace std;

class base
{
public:
	virtual int func() { return 0; }
};
class derived:public base
{
public:
	int a, b, c;
	void setValue(int x, int y, int z) { a = x; b = y; c = z; }
	int func() { return (a + b)*c; }
};
int main()
{
	base b;
	derived d;
	int x, y, z;
	cin >> x >> y >> z;
	cout << b.func() << ",";
	d.setValue(x, y, z);
	cout << d.func() << ",";
	base& pb = d;
	cout << pb.func() << endl;
	system("pause");
	return 0;
}