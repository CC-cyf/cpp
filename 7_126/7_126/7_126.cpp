#include <iostream>
using namespace std;

long long  factor(int n);

int main()
{
	int n;
	long long result;
	cin >> n;
	if (n >= 13) n=12;
	cout << n << "!=" << factor(n) << endl;
	return 0;
}

long long factor(int n)
{
	if (n == 0) return 1;
	long long result=1;
	for (int i = 1; i <= n; i++)
	{
		result *= i;
	}
	return result;
}