#include<iostream>
using namespace std;

class Set
{
private:
	int *p;
	int size;
public:
	Set();
	Set(const Set &t);
	~Set();
	bool is_in(int num);
	bool add(int num);
	bool delete_num(int num);
	Set operator +(Set t);
	Set operator *(Set t);
	friend void operator<<(ostream & scout, Set set);
	void clear();
};
Set::Set()
{
	p = NULL;
	size = 0;
}
Set::Set(const Set &t)
{
	size = t.size;
	if (size == 0)
	{
		p = NULL;
		return;
	}
	p = new int[size];
	for (int i = 0; i < size; i++)
	{
		p[i] = t.p[i];
	}
}
Set::~Set()
{
	delete[]p;
}
bool Set::is_in(int num)
{
	for (int i = 0; i < size; i++)
	{
		if (num == p[i])return true;
	}
	return false;
}
bool Set::add(int num)
{
	if (is_in(num))return false;
	size++;
	int *temp = new int[size];
	for (int i = 0; i < size - 1; i++)
	{
		temp[i] = p[i];
	}
	temp[size - 1] = num;
	delete[]p;
	p = temp;
	return true;
}
bool Set::delete_num(int num)
{
	if (is_in(num) == false)return false;
	size--;
	int *temp = new int[size];
	for (int i = 0, j = 0; i <= size; i++)
	{
		if (p[i] != num)
		{
			temp[j] = p[i];
			j++;
		}
	}
	delete[]p;
	p = temp;
	return true;
}
Set Set::operator+(Set t)
{
	int count = size, *temp;
	for (int i = 0; i < t.size; i++)
	{
		if (is_in(t.p[i]) == false)count++;
	}
	temp = new int[count];
	for (int i = 0; i < size; i++)
	{
		temp[i] = p[i];
	}
	for (int i = 0, j = size; i < t.size; i++)
	{
		if (is_in(t.p[i]) == false)
		{
			temp[j] = t.p[i];
			j++;
		}
	}
	Set result;
	result.size = count;
	result.p = temp;
	return result;
}
Set Set::operator*(Set t)
{
	int count = 0, *temp;
	for (int i = 0; i < t.size; i++)
	{
		if (is_in(t.p[i]) == true)count++;
	}
	if (count == 0)
	{
		temp = NULL;
		count = 0;
		goto end;
	}
	temp = new int[count];
	for (int i = 0, j = 0; i < t.size; i++)
	{
		if (is_in(t.p[i]) == true)
		{
			temp[j] = t.p[i];
			j++;
		}
	}
end:
	Set result;
	result.size = count;
	result.p = temp;
	return result;
}
void operator << (ostream & scout, Set set)
{
	cout << '{';
	for (int i = 0; i < set.size; i++)
	{
		cout << set.p[i] << ' ';
	}
	cout << '}';
}
void Set::clear()
{
	if (p)
	{
		delete[]p;
		p = NULL;
		size = 0;
	}
}

int main()
{
	Set s1, s2;
	s1.add(1);
	s1.add(3);
	s1.add(5);
	s1.add(7);
	s2.add(1);
	s2.add(2);
	s2.add(3);
	s2.add(4);
	cout << s1;
	cout << endl;
	cout << s2;
	cout << endl;
	Set s3 = (s1 + s2);
	Set s4 = (s1 * s2);
	cout << s3;
	cout << endl;
	cout << s4;
	cout << endl;
	s1.delete_num(1);
	s2.delete_num(4);
	s2.delete_num(5);
	cout << s1;
	cout << endl;
	cout << s2;
	cout << endl;
	system("pause");
	return 0;
}