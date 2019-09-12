#include"acllib.h"
#include"clocks.h"
#include<Windows.h>
circle_clock c1(0, 0, 0);
rec_clock c2(0, 0, 0);
ACL_Sound di;
ACL_Sound zdbs;
void timerEvent(int tid)
{
	beginPaint();
	clearDevice();
	endPaint();
	c1.run();
	c2.run();
	if (c1.getSecond() == 0)
	{
		if (c1.getMinute() == 0)
		{
			playSound(zdbs, 0);
		}
		else
		{
			playSound(di, 0);
		}
	}
}

int Setup()
{
	loadSound("di.mp3", &di);
	loadSound("zdbs.mp3", &zdbs);
	SYSTEMTIME sys;
	GetLocalTime(&sys);
	initWindow("clocks", DEFAULT, DEFAULT, 840, 420);
	c1.set_time((int)sys.wHour, (int)sys.wMinute, (int)sys.wSecond);
	c2.set_time((int)sys.wHour, (int)sys.wMinute, (int)sys.wSecond);
	registerTimerEvent(timerEvent);
	startTimer(0, 1000);
	return 0;
}