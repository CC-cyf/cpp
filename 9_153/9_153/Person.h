#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<string.h>
using namespace std;
class Person {
public:
	Person(char *name, char sex, char *ID, char *birthday) {
		strcpy(this->name, name);
		this->sex = sex;
		strcpy(this->ID, ID);
		strcpy(this->birthday, birthday);
	}
	virtual void display() {
		cout << "Name:" << name << endl;
		cout << "Sex:" << sex << endl;
		cout << "ID:" << ID << endl;
		cout << "Birthday:" << birthday << endl;
	}
	Person* createStu_Techer(char *name, char sex, char *ID, char *birthday, char *position, char *major);
	Person* createStudent(char *name, char sex, char *ID, char *birthday, char *major);
	Person* createTeacher(char *name, char sex, char *ID, char *birthday, char *position);
private:
	char name[20];
	char sex;
	char ID[20];
	char birthday[12];
};