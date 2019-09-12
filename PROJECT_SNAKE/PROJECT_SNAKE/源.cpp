#include"acllib.h"
#include"snake.h"

void press_key(int key, int event)
{
	if (snake1.life == true)
	{
		if (key == 0x26 && snake1.direction != ddown)//up
		{
			snake1.next_direction = dup;
		}
		if (key == 0x28 && snake1.direction != dup)//down
		{
			snake1.next_direction = ddown;
		}
		if (key == 0x25 && snake1.direction != dright)//left
		{
			snake1.next_direction = dleft;
		}
		if (key == 0x27 && snake1.direction != dleft)//right
		{
			snake1.next_direction = dright;
		}
	}
	if (snake2.life == true)
	{
		if (key == 0x57 && snake2.direction != ddown)//w
		{
			snake2.next_direction = dup;
		}
		if (key == 0x53 && snake2.direction != dup)//s
		{
			snake2.next_direction = ddown;
		}
		if (key == 0x41 && snake2.direction != dright)//a
		{
			snake2.next_direction = dleft;
		}
		if (key == 0x44 && snake2.direction != dleft)//d
		{
			snake2.next_direction = dright;
		}
	}
	if (key == 0x52)
	{
		snake1.revive(1);
		snake2.revive(2);
	}
}

void timerEvent(int tid)
{
	beginPaint();
	clearDevice();
	endPaint();
	if (snake1.life == true && snake2.life == true)
	{
		snake1.move();
		snake2.move();
	}
	snake1.draw(1);
	snake2.draw(2);
	food1.draw();
	snake1.winner();
}

int Setup()
{
	initWindow("Snake", 100, 100, 500, 500);
	registerKeyboardEvent(press_key);
	registerTimerEvent(timerEvent);
	startTimer(0, 100);
	return 0;
}