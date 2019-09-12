#pragma once
#include<iostream>
#include"acllib.h"
using namespace std;

enum { dup, ddown, dleft, dright };
/*
x,y~[0,49]
*/

class node
{
public:
	node *previous;
	node *next;
	int x;
	int y;
	node();
	node(int x_in, int y_in);
};
class food
{
public:
	int x;
	int y;
	bool eated;
	food();
	void change();
	void draw();
};
class snake_base
{
public:
	node *head;
	node *tail;
	int direction;
	int next_direction;
	int length;
	bool life;
	bool eated;
};
class snake:public snake_base
{
public:
	snake(int id);
	void move();
	void move_detail(node *nhead);
	bool if_alife(node *nhead);
	void draw(int id);
	void revive(int id);
	void winner();
};

food food1;
snake snake1(1);
snake snake2(2);

node::node()
{
	x = 0;
	y = 0;
	previous = NULL;
	next = NULL;
}
node::node(int x_in, int y_in)
{
	x = x_in;
	y = y_in;
	next = NULL;
	previous = NULL;
}

food::food()
{
	x = 10;
	y = 10;
	eated = false;
}
void food::change()
{
	int tempx;
	int tempy;
	node *temp;
	temp = snake1.head;
	bool not_ok = true;
	while (not_ok)
	{
		tempx = rand() % 50;
		tempy = rand() % 50;
		not_ok = false;
		for (int i = 0; i < snake1.length; i++)
		{
			if (temp->x == tempx && temp->y == tempy)
			{
				not_ok = true;
				break;
			}
		}
	}
	x = tempx;
	y = tempy;
}
void food::draw()
{
	beginPaint();
	setPenColor(RGB(73, 90, 128));
	setBrushColor(RGB(73, 90, 128));
	rectangle(10 * x, 10 * y, 10 * (x + 1), 10 * (y + 1));
	endPaint();
}

snake::snake(int id)
{
	length = 2;
	head = new node;
	tail = new node;
	head->next = tail;
	head->previous = NULL;
	tail->next = NULL;
	tail->previous = head;
	life = true;
	eated = false;
	if (id == 1)
	{
		direction = dleft;
		next_direction = dleft;
		head->x = 35;
		head->y = 25;
		tail->x = 36;
		tail->y = 25;
	}
	if (id == 2)
	{
		direction = dright;
		next_direction = dright;
		head->x = 14;
		head->y = 25;
		tail->x = 13;
		tail->y = 25;
	}
}
void snake::move()
{
	direction = next_direction;
	node *temp = new node;
	if (direction == dup)
	{
		temp->x = head->x;
		temp->y = (head->y) - 1;
	}
	else if (direction == ddown)
	{
		temp->x = head->x;
		temp->y = (head->y) + 1;
	}
	else if (direction == dleft)
	{
		temp->x = (head->x) - 1;
		temp->y = head->y;
	}
	else if (direction == dright)
	{
		temp->x = (head->x) + 1;
		temp->y = head->y;
	}
	life = if_alife(temp);
	if (life == false)
	{
		return;
	}
	move_detail(temp);
	return;
}
void snake::move_detail(node *nhead)
{
	head->previous = nhead;
	nhead->next = head;
	nhead->previous = NULL;
	head = nhead;
	if (eated == true)
	{
		length++;
		eated = false;
	}
	else
	{
		node * ttemp;
		ttemp = tail;
		tail = tail->previous;
		delete ttemp;
		tail->next = NULL;
	}
	return;
}
bool snake::if_alife(node *nhead)
{
	node * temp;
	snake *another_snake;
	temp = head;
	if (nhead->x < 0 || nhead->x>49)return false;
	if (nhead->y < 0 || nhead->y>49)return false;
	for (int i = 0; i < length; i++)
	{
		if ((temp->x) == (nhead->x) && (temp->y) == (nhead->y))return false;
		temp = temp->next;
	}
	if (this == &snake2)
	{
		another_snake = &snake1;
	}
	else
	{
		another_snake = &snake2;
	}
	temp = another_snake->head;
	for (int i = 0; i < another_snake->length; i++)
	{
		if ((temp->x) == (nhead->x) && (temp->y) == (nhead->y))return false;
		temp = temp->next;
	}
	if (nhead->x == food1.x&&nhead->y == food1.y)
	{
		eated = true;
		food1.change();
	}
	return true;
}
void snake::draw(int id)
{
	beginPaint();
	if (id == 1)
	{
		setPenColor(RGB(76, 180, 231));
		setBrushColor(RGB(76, 180, 231));
	}
	else
	{
		setPenColor(RGB(241, 124, 103));
		setBrushColor(RGB(241, 124, 103));
	}
	node *temp = new node;
	temp = head;
	for (int i = 0; i < length; i++)
	{
		rectangle(10 * (temp->x), 10 * (temp->y), 10 * (temp->x + 1), 10 * (temp->y + 1));
		temp = temp->next;
	}
	endPaint();
}
void snake::revive(int id)
{
	node *temp = head;
	for (int i = 0; i < length; i++)
	{
		head = head->next;
		delete temp;
		temp = head;
	}
	length = 2;
	head = new node;
	tail = new node;
	head->next = tail;
	head->previous = NULL;
	tail->next = NULL;
	tail->previous = head;
	life = true;
	eated = false;
	if (id == 1)
	{
		direction = dleft;
		next_direction = dleft;
		head->x = 35;
		head->y = 25;
		tail->x = 36;
		tail->y = 25;
	}
	if (id == 2)
	{
		direction = dright;
		next_direction = dright;
		head->x = 14;
		head->y = 25;
		tail->x = 13;
		tail->y = 25;
	}
}
void snake::winner()
{
	beginPaint();
	if (snake1.life == false && snake2.life == true)
	{
		setTextColor(RGB(76, 180, 231));
		setTextSize(100);
		paintText(100, 200, "WASTED");
		setTextSize(50);
		paintText(175, 300, "你输了");
		paintText(125, 350, "按R键重玩");
	}
	if (snake1.life == true && snake2.life == false)
	{
		setTextColor(RGB(241, 124, 103));
		setTextSize(100);
		paintText(100, 200, "WASTED");
		setTextSize(50);
		paintText(175, 300, "你输了");
		paintText(125, 350, "按R键重玩");
	}
	if(snake1.life == false && snake2.life == false)
	{
		setTextColor(RGB(163, 159, 147));
		setTextSize(100);
		paintText(100, 200, "WASTED");
		setTextSize(50);
		paintText(200, 300, "平局");
		paintText(125, 350, "按R键重玩");
	}
	endPaint();
}