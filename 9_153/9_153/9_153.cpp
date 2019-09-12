#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include"Person.h"
using namespace std;

class Student :virtual public Person
{
protected:
	char major[20];
public:
	Student(char *name, char sex, char *ID, char *birthday, char *major);
	virtual void display();
};
Student::Student(char *name, char sex, char *ID, char *birthday, char *major) :
	Person(name, sex, ID, birthday)
{
	if (major != NULL)
	{
		for (int i = 0; i < 20; i++)
		{
			this->major[i] = major[i];
		}
	}
}
void Student::display()
{
	cout << "Major:" << major << endl;
}

class Teacher :virtual public Person
{
protected:
	char position[20];
public:
	Teacher(char *name, char sex, char *ID, char *birthday, char *position);
	virtual void display();
};
Teacher::Teacher(char *name, char sex, char *ID, char *birthday, char *position) :
	Person(name, sex, ID, birthday)
{
	if (position != NULL)
	{
		for (int i = 0; i < 20; i++)
		{
			this->position[i] = position[i];
		}
	}
}
void Teacher::display()
{
	cout << "Position:" << position << endl;
}

class Stu_Techer :public Student, public Teacher
{
public:
	Stu_Techer(char *name, char sex, char *ID, char *birthday, char *position, char *major);
	void display();
};
Stu_Techer::Stu_Techer(char *name, char sex, char *ID, char *birthday, char *position, char *major) :
	Student(name, sex, ID, birthday, major),
	Teacher(name, sex, ID, birthday, position),
	Person(name,sex,ID,birthday)
{};
void Stu_Techer::display()
{
	Person::display();
	cout << "Major:" << major << endl;
	cout << "Position:" << position << endl;
}

Person* Person::createStudent(char *name, char sex, char *ID, char *birthday, char *major) {
	return new Student(name, sex, ID, birthday, major);
}
Person* Person::createTeacher(char *name, char sex, char *ID, char *birthday, char *position) {
	return new Teacher(name, sex, ID, birthday, position);
}
Person* Person::createStu_Techer(char *name, char sex, char *ID, char *birthday, char *position, char *major) {
	return new Stu_Techer(name, sex, ID, birthday, position, major);
}

int main()
{
	char name[20], sex, ID[20], birthday[12], position[20], major[20];
	cin >> name >> sex >> ID >> birthday >> position >> major;
	Person p1(name, sex, ID, birthday);
	p1.display();
	Student s1(name, sex, ID, birthday, major);
	s1.display();
	Teacher t1(name, sex, ID, birthday, position);
	t1.display();
	Stu_Techer st1(name, sex, ID, birthday, position, major);
	st1.display();
	system("pause");
	return 0;
}