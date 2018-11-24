#include<iostream>
using namespace std;

int main()
{
	int temp = 0, max_v = 0;
	for (int i = 0; i < 100000; i++)
	{
		temp = rand();
		if (max_v < temp)max_v = temp;
	}
	cout << max_v;
	system("pause");
	return 0;
}