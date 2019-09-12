#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<Windows.h>
int main()
{
	double maximum = 0;
	double temp = 0;
	printf("Enter a number:");
	scanf("%lf", &temp);
	while (temp > 0)
	{
		maximum = temp > maximum ? temp : maximum;
		printf("Enter a number:");
		scanf("%lf", &temp);
	}
	printf("The largest number entered was %lf", maximum);
	system("pause");
	return 0;
}