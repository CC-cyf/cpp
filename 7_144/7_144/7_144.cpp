#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;
	if ((n+1) % 2||n>80||n<1)
	{
		cout << "error" << endl;
		return 0;
	}
	for (int i = n; i > 0; i -= 2)
	{
		for (int j = 0; j < n - i; j += 2)
		{
			cout << ' ';
		}
		for (int k = 0; k < i; k++)
		{
			cout << '*';
		}
		cout << endl;
	}
	return 0;
}