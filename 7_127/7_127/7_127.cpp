#include<iostream>
using namespace std;

int main()
{
	for (int i = 100; i <= 200; i++)
	{
		if (i % 3 && i % 7) cout << i;
	}
	return 0;
}