#pragma once

class CNumberFactory
{
public:
	virtual void Add(int number) {};
	virtual void Sub(int number) {};
	virtual int GetValue() { return -1; };
	virtual void SetValue(int number);
	CNumberFactory *Create();
};