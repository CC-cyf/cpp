#include<iostream>
#include"CSet.h"
using namespace std;

Set &Set::operator +=(int e)
{
	int count = n;
	if (IsElement(e) == false)count++;
	int * temp = new int[count + 1];
	for (int i = 1; i <= n; i++)
	{
		temp[i] = pS[i];
	}
	if (IsElement(e) == false)temp[count] = e;
	n = count;
	if (count = 0)temp = NULL;
	pS = temp;
	return *this;
}

Set &Set::operator -=(int e)
{
	int count = n;
	if (IsElement(e) == true)count--;
	int * temp = new int[count + 1];
	for (int i = 1, j = 1; i <= n; i++)
	{
		if (pS[i] != e)
		{
			temp[j] = pS[i];
			j++;
		}
	}
	n = count;
	if (count = 0)temp = NULL;
	pS = temp;
	return *this;
}

bool Set::operator <=(const Set &s)const
{
	if (n > s.n)return false;
	for (int i = 1; i <= n; i++)
	{
		if (s.IsElement(pS[i]) == false)return false;
	}
	return true;
}

bool Set::operator == (const Set &s)const
{
	if (n != s.n)return false;
	for (int i = 1; i <= n; i++)
	{
		if (s.IsElement(pS[i]) == false)return false;
	}
	for (int i = 1; i <= n; i++)
	{
		if (IsElement(s.pS[i]) == false)return false;
	}
	return true;
}

Set Set::operator |(const Set &s)const
{
	int count = n, *temp;
	for (int i = 1; i <= s.n; i++)
	{
		if (IsElement(s.pS[i]) == false)count++;
	}
	temp = new int[count + 1];
	for (int i = 1; i <= n; i++)
	{
		temp[i] = pS[i];
	}
	for (int i = 1, j = 1; i <= s.n; i++)
	{
		if (IsElement(s.pS[i]) == false)
		{
			pS[n + j] = s.pS[i];
			j++;
		}
	}
	Set *fake = (Set *)(this);
	fake->n = count;
	if (count = 0)temp = NULL;
	fake->pS = temp;
	return *fake;
}

Set Set::operator &(const Set &s)const
{
	int count = 0, *temp;
	for (int i = 1; i <= s.n; i++)
	{
		if (IsElement(s.pS[i]) == true)count++;
	}
	temp = new int[count + 1];
	for (int i = 1, j = 1; i <= s.n; i++)
	{
		if (IsElement(s.pS[i]) == true)
		{
			temp[j] = s.pS[i];
			j++;
		}
	}
	Set *fake = (Set *)(this);
	fake->n = count;
	if (count = 0)temp = NULL;
	fake->pS = temp;
	return *fake;
}

Set Set::operator -(const Set &s)const
{
	int count = n, *temp;
	for (int i = 1; i <= s.n; i++)
	{
		if (IsElement(s.pS[i]) == true)count--;
	}
	temp = new int[count + 1];
	for (int i = 1, j = 1; i <= n; i++)
	{
		if (s.IsElement(pS[i]) == false)
		{
			temp[j] = pS[i];
			j++;
		}
	}
	Set *fake = (Set *)(this);
	fake->n = count;
	if (count = 0)temp = NULL;
	fake->pS = temp;
	return *fake;
}

int main()
{
	Set s1, s2;
	s1 += 2;
	s2 += 2;
	s1.ShowElement();
	s2.ShowElement();
	cout << (s2 <= s1);
	cout << (s1 == s2);
	//(s1 | s2).ShowElement();
	//(s1 & s2).ShowElement();
	(s1 - s2).ShowElement();
	system("pause");
	return 0;


}