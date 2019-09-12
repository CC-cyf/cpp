#include<iostream>
using namespace std;

class Clock {
public:
	Clock(int h, int m, int s) {
		hour = (h > 23 ? 0 : h);
		minute = (m > 59 ? 0 : m);
		second = (s > 59 ? 0 : s);
	}
	virtual void run() {
		second = second + 1;
		if (second > 59)
		{
			second = 0;
			minute += 1;
		}
		if (minute > 59)
		{
			minute = 0;
			hour += 1;
		}
		if (hour > 23)
		{
			hour = 0;
		}
	}
	virtual void showTime() {
		cout << "Now:" << hour << ":" << minute << ":" << second << endl;
	}
	int getHour() { return hour; }
	int getMinute() { return minute; }
	int getSecond() { return second; }

	Clock * createNewClock(int h, int m, int s);
private:
	int hour;
	int minute;
	int second;
};

class NewClock :public Clock
{
public:
	NewClock(int h, int m, int s);
	void showTime();
};
NewClock::NewClock(int h, int m, int s) :Clock(h, m, s) {};
void NewClock::showTime()
{
	cout << "Now:";
	if (getHour() >= 12)
	{
		cout << getHour() - 12;
	}
	else
	{
		cout << getHour();
	}
	cout << ":" << getMinute() << ":" << getSecond();
	if (getHour() >= 12)
	{
		cout << "PM";
	}
	else
	{
		cout << "AM";
	}
	cout << endl;
}
Clock* Clock::createNewClock(int h, int m, int s) 
{
	return new NewClock(h, m, s);
}

int main()
{
	NewClock nc(23, 4, 5);
	nc.showTime();
	nc.run();
	nc.showTime();
	Clock c1(23, 4, 5);
	c1.showTime();
	Clock *p = c1.createNewClock(23, 4, 5);
	p->run();
	p->showTime();
	system("pause");
	return 0;
}