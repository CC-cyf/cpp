#include<iostream>
using namespace std;

int main()
{
	int i, j;
	for (i = 0; i < 10; i++)
	{
		j = i * 10 + 6;
		if (j % 3)continue;
		cout << j;
	}
	system("pause");
	return 0;
}