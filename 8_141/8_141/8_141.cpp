#include<iostream>
using namespace std;

class Student
{
public:
	char name[12];
	char num[11];
	int grade1;
	int grade2;
	int grade3;
	Student(char * name1, char*num1, int g1, int g2, int g3)
	{
		for (int i = 0; name1[i] != '\0'; i++)
		{
			name[i] = name1[i];
			name[i + 1] = '\0';
		}
		for (int i = 0; num1[i] != '\0'; i++)
		{
			num[i] = num1[i];
			num[i + 1] = '\0';
		}
		grade1 = g1;
		grade2 = g2;
		grade3 = g3;
	}
	
	void display()
	{
		cout << num << ' ' << name << ' ' << grade1 << ' ' << grade2 << ' ' << grade3 << endl;
	}

	double average1()
	{
		double sum;
		sum = grade1;
		return sum / 3;
	}
	double average2()
	{
		double sum;
		sum = grade2;
		return sum / 3;
	}
	double average3()
	{
		double sum;
		sum = grade3;
		return sum / 3;
	}
};

int main() {
	Student *stu1, *stu2, *stu3;
	char name1[10], name2[10], name3[10];
	char num1[12], num2[12], num3[12];
	int grade1[3], grade2[3], grade3[3];
	cin >> num1 >> name1 >> grade1[0] >> grade1[1] >> grade1[2];
	cin >> num2 >> name2 >> grade2[0] >> grade2[1] >> grade2[2];
	cin >> num3 >> name3 >> grade3[0] >> grade3[1] >> grade3[2];
	stu1 = new Student(name1, num1, grade1[0], grade1[1], grade1[2]);
	stu2 = new Student(name2, num2, grade2[0], grade2[1], grade2[2]);
	stu3 = new Student(name3, num3, grade3[0], grade3[1], grade3[2]);

	stu1->display();
	stu2->display();
	stu3->display();

	cout << "The average grade of course1:" << stu2->average1() + stu1->average1() + stu3->average1() << endl;
	cout << "The average grade of course2:" << stu2->average2() + stu1->average2() + stu3->average2() << endl;
	cout << "The average grade of course3:" << stu2->average3() + stu1->average3() + stu3->average3() << endl;
	system("pause");
	return 0;
}