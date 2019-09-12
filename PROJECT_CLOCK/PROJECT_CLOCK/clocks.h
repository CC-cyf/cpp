#pragma once
#include<iostream>
#include<math.h>
#include"acllib.h"
using namespace std;

#define RAD(x) ((x)/360.0*2*3.1415926535)

class clock
{
protected:
	int hour;
	int minute;
	int second;
public:
	clock(int h = 0, int m = 0, int s = 0);
	void set_time(int h = 0, int m = 0, int s = 0);
	virtual void run();
	int getHour() { return hour; };
	int getMinute() { return minute; };
	int getSecond() { return second; };
};
clock::clock(int h, int m, int s)
{
	hour = (((h > 23) | (h < 0)) ? 0 : h);
	minute = (((m > 59) | (m < 0)) ? 0 : m);
	second = (((s > 59) | (s < 0)) ? 0 : s);
}
void clock::set_time(int h, int m, int s)
{
	hour = (((h > 23) | (h < 0)) ? 0 : h);
	minute = (((m > 59) | (m < 0)) ? 0 : m);
	second = (((s > 59) | (s < 0)) ? 0 : s);
}
void clock::run()
{
	second++;
	if (second == 60)
	{
		second = 0;
		minute++;
	}
	if (minute == 60)
	{
		minute = 0;
		hour++;
	}
	if (hour == 24)
	{
		hour = 0;
	}
}

class circle_clock :virtual public clock
{
public:
	circle_clock(int h, int m, int s) :clock(h, m, s) {};
	void draw();
	void run();
};
void circle_clock::draw()
{
	beginPaint();
	//»­Ô²
	setPenColor(RGB(0, 0, 0));
	setBrushColor(RGB(255, 255, 255));
	setPenWidth(5);
	ellipse(10, 10, 410, 410);
	//»­¿Ì¶È
	setPenWidth(2);
	setPenColor(RGB(0, 0, 0));
	for (int i = 0; i < 12; ++i)
	{
		moveTo(210 + 190 * sin(RAD(180 - i * 30)), 210 + 190 * cos(RAD(180 - i * 30)));
		lineTo(210 + 200 * sin(RAD(180 - i * 30)), 210 + 200 * cos(RAD(180 - i * 30)));
	}
	//Ê±Õë
	setPenWidth(8);
	setPenColor(RGB(80, 160, 240));
	moveTo(210, 210);
	lineTo(210 + 70 * sin(RAD(180 - hour * 30)), 210 + 70 * cos(RAD(180 - hour * 30)));
	//·ÖÕë
	setPenWidth(4);
	setPenColor(RGB(160, 240, 80));
	moveTo(210, 210);
	lineTo(210 + 120 * sin(RAD(180 - minute * 6)), 210 + 120 * cos(RAD(180 - minute * 6)));
	//ÃëÕë
	setPenWidth(2);
	setPenColor(RGB(240, 80, 160));
	moveTo(210, 210);
	lineTo(210 + 180 * sin(RAD(180 - second * 6)), 210 + 180 * cos(RAD(180 - second * 6)));
	endPaint();
}
void circle_clock::run()
{
	clock::run();
	draw();
}


class rec_clock :virtual public clock
{
public:
	rec_clock(int h, int m, int s) :clock(h, m, s) {};
	void draw();
	void run();
};
void rec_clock::draw()
{
	beginPaint();
	//»­Õý·½ÐÎ
	setPenColor(RGB(0, 0, 0));
	//setBrushColor(RGB(255, 255, 255));
	setPenWidth(5);
	rectangle(430, 10, 830, 410);
	//»­¿Ì¶È
	float x, y;
	setPenWidth(2);
	setPenColor(RGB(0, 0, 0));
	for (int i = 0; i < 12; i++)
	{
		if (i >= 11 || i < 2)
		{
			moveTo(630 + 200 * tan(RAD(i * 30)), 10);
			lineTo(630 + 190 * tan(RAD(i * 30)), 20);
		}
		if (i >= 2 && i < 5)
		{
			moveTo(830, 210 + 200 / tan(RAD(i * 30)));
			lineTo(820, 210 + 190 / tan(RAD(i * 30)));
		}
		if (i >= 5 && i < 8)
		{
			moveTo(630 + 200 * tan(RAD(i * 30)), 410);
			lineTo(630 + 190 * tan(RAD(i * 30)), 400);
		}
		if (i >= 8 && i < 11)
		{

			moveTo(430, 210 + 200 / tan(RAD(i * 30)));
			lineTo(440, 210 + 190 / tan(RAD(i * 30)));
		}
	}
	//Ê±Õë
	setPenWidth(8);
	setPenColor(RGB(80, 160, 240));
	moveTo(630, 210);
	lineTo(630 + 70 * sin(RAD(180 - hour * 30)), 210 + 70 * cos(RAD(180 - hour * 30)));
	//·ÖÕë
	setPenWidth(4);
	setPenColor(RGB(160, 240, 80));
	moveTo(630, 210);
	lineTo(630 + 120 * sin(RAD(180 - minute * 6)), 210 + 120 * cos(RAD(180 - minute * 6)));
	//ÃëÕë
	setPenWidth(2);
	setPenColor(RGB(240, 80, 160));
	moveTo(630, 210);
	lineTo(630 + 180 * sin(RAD(180 - second * 6)), 210 + 180 * cos(RAD(180 - second * 6)));
	endPaint();
}
void rec_clock::run()
{
	clock::run();
	draw();
}
