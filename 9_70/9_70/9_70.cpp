#include<iostream>
using namespace std;

class PersonFactory
{
private:
	int id;
	char name[50];
	int age;
public:
	PersonFactory(int i = 0, char *nm = 0, int a = 15);
	virtual ~PersonFactory() {};
	virtual void PrintInfo()
	{
		cout << id << endl;
		cout << name << endl;
		cout << age << endl;
	}
	PersonFactory * CreateStudent(int i, char *nm, int a, float s);
	PersonFactory * CreateTeacher(int i, char *nm, int a, float m);
};
PersonFactory::PersonFactory(int i, char *nm, int a)
{
	id = i;
	for (int i = 0; i < 50; i++)
	{
		name[i] = nm[i];
	}
	age = a;
}

PersonFactory *PersonFactory::CreateStudent(int i, char *nm, int a, float s)
{
	PersonFactory *p = new Student(i, nm, a, s);
	return p;
}

PersonFactory *PersonFactory::CreateTeacher(int i, char *nm, int a, float m)
{
	return new Teacher(i, nm, a, m);
}

class Student :public PersonFactory
{
private:
	float score;
public:
	void PrintInfo()
	{
		PersonFactory::PrintInfo();
		cout << score << endl;
	}
	Student(int i, char *nm, int a, float s) :PersonFactory(i, nm, a)
	{
		score = s;
	}
};

class Teacher :public PersonFactory
{
private:
	float money;
public:
	void PrintInfo()
	{
		PersonFactory::PrintInfo();
		cout << money << endl;
	}
	Teacher(int i, char *nm, int a, float m) :PersonFactory(i, nm, a)
	{
		money = m;
	}
};