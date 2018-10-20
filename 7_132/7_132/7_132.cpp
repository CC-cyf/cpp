#include<iostream>
using namespace std;

int main()
{
	char s1[1000], s2[1000];
	cin >> s1;
	int i;
	for (i = 0; s1[i] != '\0'; i++)
	{
		s2[i] = s1[i];
	}
	s2[i] = s1[i];
	cout << s2 <<'\\'<<'0';
	return 0;
}