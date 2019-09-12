#include<iostream>
#include"ClockAndDate.h"
using namespace std;

int Date::days(int year, int month)
{
	if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
	{
		return 31;
	}
	if (month == 4 || month == 6 || month == 9 || month == 11)
	{
		return 30;
	}
	if (year % 400 == 0)return 29;
	if (year % 100 != 0 && year % 4 == 0)return 29;
	return 28;
}
void Date::NewDay()
{
	day++;
	if (day > days(year, month))
	{
		day = 1;
		month++;
	}
	if (month > 12)
	{
		month = 1;
		year++;
	}
}

class ClockWithDate :public Clock, public Date
{
public:
	ClockWithDate(int h, int m, int s, int year, int month, int day);
	void showTime();
	void run();
};
ClockWithDate::ClockWithDate(int h, int m, int s, int year, int month, int day) :
	Clock(h, m, s),
	Date(year, month, day)
{};
void ClockWithDate::showTime()
{
	Clock::showTime();
	Date::display();
}
void ClockWithDate::run()
{
	int temp = 0;
	if (getHour() == 23)temp++;
	Clock::run();
	if (getHour() == 0)temp++;
	if (temp == 2)NewDay();
}

Clock* Clock::createClockWithDate(int h, int m, int s, int year, int month, int day)
{
	return new ClockWithDate(h, m, s, year, month, day);
}