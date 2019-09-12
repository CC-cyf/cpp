#pragma once
#include<iostream>
using namespace std;

class student
{
protected:
	int id;
	float chinese;
	float math;
	float english;
	float average;
	float sum;
public:
	friend class the_class;
	friend void swap(student &stu1, student &stu2);
	student();
	virtual ~student() {};
	void change_to(student &stu);
	void set_info(int id_in, float c, float m, float e);
	void show_detail();
	void show();
	bool pass;
};
student::student()
{
	id = 0;
	chinese = 0;
	math = 0;
	english = 0;
	average = 0;
	sum = 0;
	pass = false;
}
void student::set_info(int id_in, float c, float m, float e)
{
	id = id_in;
	chinese = c;
	math = m;
	english = e;
	sum = chinese + english + math;
	average = sum / 3;
	if (average >= 60)
	{
		pass = true;
	}
	else
	{
		pass = false;
	}
}
void student::show_detail()
{
	cout << "学号:" << id;
	cout << " 语文:" << chinese;
	cout << " 数学:" << math;
	cout << " 英语:" << english;
	cout << " 平均分:" << average;
	cout << " 总分:" << sum << endl;		
}
void student::show()
{
	cout << "学号:" << id << endl;
}
void student::change_to(student &stu)
{
	id = stu.id;
	chinese = stu.chinese;
	math = stu.math;
	english = stu.english;
	average = stu.average;
	sum = stu.sum;
	pass = stu.pass;
}

void swap(student &stu1, student &stu2)
{
	student temp;
	temp.change_to(stu1);
	stu1.change_to(stu2);
	stu2.change_to(temp);
	temp.~student();
}