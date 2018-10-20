#include <iostream>
using namespace std;
class Clock {
public:
	Clock(int h, int m, int s);
	void SetAlarm(int h, int m, int s);
	void run();
	void ShowTime() {
		cout << "Now:" << hour << ":" << minute << ":" << second << endl;
	}
private:
	int hour;   //Ê±
	int minute;  //·Ö
	int second;  //Ãë

	int Ahour;   //Ê±£¨ÄÖÖÓ£©
	int Aminute;  //·Ö£¨ÄÖÖÓ£©
	int Asecond;   //Ãë£¨ÄÖÖÓ£©
};

Clock::Clock(int h, int m, int s)
{
	if (h >= 24 || h < 0)h = 0;
	if (m >= 60 || m < 0)m = 0;
	if (s >= 60 || s < 0)s = 0;
	hour = h;
	minute = m;
	second = s;
}

void Clock::SetAlarm(int h, int m, int s)
{
	if (h >= 24)h = 0;
	if (m >= 60)m = 0;
	if (s >= 60)s = 0;
	Ahour = h;
	Aminute = m;
	Asecond = s;
}

void Clock::run()
{
	second++;
	if (second >= 60)
	{
		second -= 60;
		minute++;
	}
	if (minute >= 60)
	{
		minute -= 60;
		hour++;
	}
	if (hour >= 24)
	{
		hour -= 24;
	}
	if (hour == Ahour && minute == Aminute && second == Asecond)
	{
		cout << "Plink!plink!plink!..." << endl;
	}
}