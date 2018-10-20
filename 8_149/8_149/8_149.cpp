#include<iostream>
//#include"CString.h"
using namespace std;
//#define _CRT_SECURE_NO_WARNINGS
//#pragma warning(disable:4996)

class String {
private:
	char *mystr;    //×Ö·û´®
	int len;    //×Ö·û´®³¤¶È
public:
	String() {
		len = 0;
		mystr = NULL;
	}
	String(const char* p) {
		len = strlen(p);
		mystr = new char[len + 1];
		strcpy(mystr, p);
	}
	String(String &s) {
		len = s.len;
		if (len != 0)
		{
			mystr = new char[len + 1];
			strcpy(mystr, s.mystr);
		}
	}
	~String() {
		if (mystr != NULL)
		{
			delete[]mystr;
			mystr = NULL;
			len = 0;
		}
	}

	char *GetStr()const { return mystr; }
	void ShowStr() { cout << mystr; }

	bool IsSubstring(const char *str);
	bool IsSubstring(const String &str);
	int str2num();
	void toUppercase();
};

bool String::IsSubstring(const char *str)
{
	for (int i = 0; i <= len; i++)
	{
		for (int j = i; j <= len; j++)
		{
			if (str[j - i] == '\0')return true;
			if (str[j-i] != mystr[j])break;
		}
	}
	return false;
}

bool String::IsSubstring(const String &str)
{
	//String &str1 = str;
	char *str_temp = str.GetStr();
	for (int i = 0; i <= len; i++)
	{
		for (int j = i; j <= len; j++)
		{
			if (str_temp[j-i] == '\0')return true;
			if (str_temp[j - i] != mystr[j])break;
		}
	}
	return false;
}

int String::str2num()
{
	int step=1, res=0;
	for (int i = 0; mystr[i] != '\0'; i++)
	{
		if (mystr[i] >= '0'&&mystr[i] <= '9')
		{
			step *= 10;
		}
	}
	for (int i = 0; mystr[i] != '\0'; i++)
	{
		if (mystr[i] >= '0'&&mystr[i] <= '9')
		{
			step /= 10;
			res += step * (mystr[i] - '0');
		}
	}
	return res;
}

void String::toUppercase()
{
	for (int i = 0; i < len; i++)
	{
		if (mystr[i] <= 'z'&&mystr[i] >= 'a')mystr[i] += 'A' - 'a';
	}
}
/*
int main()
{
	char a[100], b[20];
	cin >> a >> b;
	String abc(a);
	cout << abc.IsSubstring(b) << endl;
	cout << abc.str2num() << endl;
	abc.toUppercase();
	abc.ShowStr();
	system("pause");
	return 0;
}*/