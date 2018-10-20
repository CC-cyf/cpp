#include<iostream>
using namespace std;
int SubStrNum(char * str, char * substr)
{
	int show_up_times = 0;
	for (int i = 0, j = 0; str[i] != '\0'; i++)
	{
		for (j = 0; substr[j] != '\0'; j++)
		{
			if (str[i + j] != substr[j]) goto next_char;
		}
		show_up_times++;
		i += j-1;
	next_char:;
	}
	cout << "match times=" << show_up_times;
	return 0;
}
int main()
{
	char a[7], b[3];
	a[0] = 'h';
	a[1] = 'h';
	a[2] = 'h';
	a[3] = 'h';
	a[4] = 'h';
	a[5] = 'h';
	a[6] = '\0';
	b[0] = 'h';
	b[1] = 'h';
	b[2] = '\0';
	SubStrNum(a, b);
	system("pause");
	return 0;
}