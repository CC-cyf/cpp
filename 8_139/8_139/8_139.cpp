#include<iostream>
#include"CDate.h"
using namespace std;
/*
class Date
{
public:
	Date(int y = 1996, int m = 1, int d = 1);
	int days(int year, int month);
	void NewDay();
	void display()
	{
		cout << year << "-" << month << "-" << day << endl;
	}
private:
	int year; //Äê
	int month; //ÔÂ
	int day;  // ÈÕ
};
*/
Date::Date(int y, int m, int d)
{
	year = y;
	if (m < 1 || m>12)
	{
		m = 1;
		cout << "Invalid month!" << endl;
	}
	if(d<1||d>days(y,m))
	{
		d = 1;
		cout << "Invalid day!" << endl;
	}
	month = m;
	day = d;
	//display();
};
int Date::days(int year, int month)
{
	if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) return 31;
	if (month == 4 || month == 6 || month == 9 || month == 11)return 30;
	if (year % 400 == 0) return 29;
	else if (year % 4 == 0 && year % 100 != 0) return 29;
	else return 28;
};
void Date::NewDay()
{
	day++;
	if (day > days(year, month))
	{
		day -= days(year, month);
		month++;
	}
	if (month > 12)
	{
		month -= 12;
		year++;
	}
};

int main()
{
	int y, m, d;
rein:
	cin >> y >> m >> d;
	Date date(y, m, d);
	cout << date.days(y, m)<<endl;
	date.NewDay();
	date.display();
	goto rein;
	return 0;
}