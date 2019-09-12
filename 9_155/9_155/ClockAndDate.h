#pragma once
#include<iostream>
using namespace std;
class Clock
{
private:
	int hour;
	int minute;
	int second;
public:
	Clock(int h, int m, int s);
	virtual void run();
	virtual void showTime();
	int getHour() { return hour; };
	int getMinute() { return minute; };
	int getSecond() { return second; };
	Clock * createClockWithDate(int h, int m, int s, int year, int month, int day);
};
Clock::Clock(int h, int m, int s)
{
	hour = (h > 23 ? 0 : h);
	minute = (m > 59 ? 0 : m);
	second = (s > 59 ? 0 : s);
}
void Clock::run()
{
	second++;
	if (second > 59)
	{
		second = 0;
		minute++;
	}
	if (minute > 59)
	{
		minute = 0;
		hour++;
	}
	if (hour > 23)
	{
		hour = 0;
	}
}
void Clock::showTime()
{
	cout << "Now:" << hour << ":" << minute << ":" << second << endl;
}

class Date
{
private:
	int year;
	int month;
	int day;
public:
	Date(int y = 199, int m = 1, int d = 1);
	int days(int year, int month);
	void NewDay();
	void display();
};
Date::Date(int y, int m, int d)
{
	day = d;
	month = m;
	year = y;
	if (m > 12 || m < 1)
	{
		month = 1;
	}
	if (d > days(y, m))
	{
		day = 1;
	}
}
void Date::display()
{
	cout << year << "-" << month << "-" << day << endl;
}