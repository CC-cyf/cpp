#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include"CString.h"
using namespace std;

int EditString::IsSubString(int start, const char *str)
{
	for (int i = 0; i < len - start; i++)
	{
		for (int j = 0; (str[j] != 0) && (start + j < len); j++)
		{
			if (mystr[i + start + j] != str[j])goto next;
		}
		return i;
	next:;
	}
	return -1;
}

void EditString::EditChar(char s, char d)
{
	for (int i = 0; i < len; i++)
	{
		if (mystr[i] == s)mystr[i] = d;
	}
}

void EditString::EditSub(char * subs, char *subd)
{
	char *temp = new char[2*len];
	int count = 0;
	for (int i = 0; i < len; i++)
	{
		for (int k = 0; k < strlen(subs); k++)
		{
			if (mystr[i + k] != subs[k])
			{
				temp[count + k] = mystr[i + k];
				count++;
				goto next;
			}
		}
		for (int k = 0; k < strlen(subd); k++)
		{
			temp[count + k] = subd[k];
		}
		count += strlen(subd);
		i += strlen(subs)-1;
	next:;
	}
	temp[count] = '\0';
	len = count;
	delete mystr;
	mystr = temp;
}

void EditString::DeleteChar(char ch)
{
	char *temp = new char[len];
	int count = 0;
	for (int i = 0; i < len; i++)
	{
		if (mystr[i] != ch)
		{
			temp[count] = mystr[i];
			count++;
		}
	}
	temp[count] = '\0';
	len = count;
	delete mystr;
	mystr = temp;
}

void EditString::DeleteSub(char *sub)
{
	char *temp = new char[len];
	int count = 0;
	for (int i = 0; i < len; i++)
	{
		for (int k = 0; k < strlen(sub); k++)
		{
			if (mystr[i + k] != sub[k])
			{
				temp[count + k] = mystr[i + k];
				count++;
				goto next;
			}
		}
		count += strlen(sub);
		i += strlen(sub) - 1;
	next:;
	}
	temp[count] = '\0';
	len = count;
	delete mystr;
	mystr = temp;
}

int main()
{
	EditString es("this is a test text,this is a test text,asdasdasd,");
	cout << es.IsSubString(3, "is");
	cout << es.IsSubString(3, "this");
	cout << es.IsSubString(3, "zxc");
	cout << endl;
	es.EditChar('a', 's');
	es.showStr();
	cout << endl;
	char t1[3] = { 'i','s','\0' };
	char t2[4] = { 'w','a','s','\0' };
	es.EditSub(t1, t2);
	es.showStr();
	cout << endl;
	es.EditSub(t2, t1);
	es.showStr();
	cout << endl;
	es.DeleteChar('h');
	es.showStr();
	cout << endl;
	es.DeleteSub(t1);
	es.showStr();
	system("pause");
}