#include<iostream>
using namespace std;

int main()
{
	long double pi = 0;
	long long step;
	for (step = 1; 2 * step - 1 <= 100000000; step++)
	{
		if (step % 2)
		{
			pi = pi + 1 / (2 * (long double)step - 1);
		}
		else
		{
			pi = pi - 1 / (2 * (long double)step - 1);
		}
	}
	cout << "steps=" << step << ' ' << "PI=";
	printf("%.5f", 4*pi);
	system("pause");
	return 0;
}