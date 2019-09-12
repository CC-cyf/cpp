#include<iostream>
#include"CNumberFactory.h"
using namespace std;

class CNumber :public CNumberFactory
{
private:
	int value;
public:
	CNumber() {};
	void Add(int number);
	void Sub(int number);
	int GetValue();
	void SetValue(int number);
};

CNumberFactory *CNumberFactory::Create()
{
	return new CNumber();
}

void CNumber::Add(int number)
{
	value += number;
}
void CNumber::Sub(int number)
{
	value -= number;
}
int CNumber::GetValue()
{
	return value;
}
void CNumber::SetValue(int number)
{
	value = number;
}