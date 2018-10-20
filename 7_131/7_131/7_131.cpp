#include <iostream>
using namespace std;

void sort(int arr[], int length);

int main()
{
	int arr_odd[10], arr_even[10], temp, odd = 0, even = 0;
	for (int i = 0; i < 10; i++)
	{
		cin >> temp;
		if (temp < 0)break;
		else if (temp % 2)
		{
			arr_odd[odd++] = temp;
		}
		else
		{
			arr_even[even++] = temp;
		}
	}
	sort(arr_odd,odd);
	sort(arr_even,even);
	for (int i = 0; i < odd; i++)
	{
		cout << arr_odd[i] << ' ';
	}
	for (int i = 0; i < even; i++)
	{
		cout << arr_even[i] << ' ';
	}
	return 0;
}

void sort(int arr[], int length)
{
	int temp;
	for (int i = 0; i < length - 1; i++)
	{
		for (int j = 0; j < length - 1 - i; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}