#include<iostream>
using namespace std;

int main()
{
	char num1[1000], num2[1000];
	int len_num1, len_num2;
	cin >> num1;
	cin >> num2;
	len_num1 = strlen(num1);
	len_num2 = strlen(num2);
	if (len_num1 == len_num2)
	{
		for (int i = 0; i < len_num1; i++)
		{
			if (num1[i] > num2[i])goto num1_big;
			else if (num1[i] < num2[i])goto num2_big;
		}
	}
	if (len_num1 >= len_num2)
	{
	num1_big:
		while (len_num2 > 0)
		{
			if (num1[len_num1 - 1] >= num2[len_num2 - 1])
			{
				num1[len_num1 - 1] = num1[len_num1 - 1] - num2[len_num2 - 1] + '0';
				len_num1--;
				len_num2--;
			}
			else
			{
				if (len_num1 - 2 >= 0)
				{
					num1[len_num1 - 2] -= 1;
				}
				else
				{
					num1[len_num1 - 1] -= 10;
				}
				num1[len_num1 - 1] = num1[len_num1 - 1] - num2[len_num2 - 1] + '0' + 10;
				len_num1--;
				len_num2--;
			}
		}
		for (int i = 0; num1[i] != '\0'; i++)
		{
			if (num1[i] != '0') goto not_the_same1;
		}
		cout << '0';
		return 0;
	not_the_same1:
		cout << '+' << num1;
	}
	else
	{
	num2_big:
		while (len_num1 > 0)
		{
			if (num2[len_num2 - 1] >= num1[len_num1 - 1])
			{
				num2[len_num2 - 1] = num2[len_num2 - 1] - num1[len_num1 - 1] + '0';
				len_num1--;
				len_num2--;
			}
			else
			{
				num2[len_num2 - 2] -= 1;
				num2[len_num2 - 1] = num2[len_num2 - 1] - num1[len_num1 - 1] + '0' + 10;
				len_num1--;
				len_num2--;
			}
		}
		cout << '-' << num2;
	}
	return 0;
}