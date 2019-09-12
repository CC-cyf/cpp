#pragma once
#include<iostream>
#include<fstream>
#include"student.h"
using namespace std;

#define STU_NUM 50  //一个班级50个学生
#define FULL_SCORE 100  //满分100
#define PASS_SCORE 60  //及格分60

enum
{
	exit_p,
	print_notpass,
	print_above,
	print_section,
	sort_class,
	print_rank,
	f_search
};

class the_class
{
protected:
	student stu[STU_NUM];
	int stu_have;
	float class_average;
public:
	the_class();
	bool add(student &stu_in);
	void above();
	void not_pass();
	void section(int diff = 10);  //输入区间宽度
	void bubble_sort();
	void rank_table();
	student *search(int id_in);
	void read_file();
	bool function_select();
};
the_class::the_class()
{
	stu_have = 0;
	class_average = 0;
};
bool the_class::add(student &stu_in)
{
	if (stu_have == STU_NUM)return false;
	stu[stu_have].change_to(stu_in);
	stu_have++;
	float temp = 0;;
	for (int i = 0; i < stu_have; i++)
	{
		temp += stu[i].average;
	}
	class_average = temp / stu_have;
	return true;
}
void the_class::above()
{
	int above_num = 0;
	for (int i = 0; i < stu_have; i++)
	{
		if (stu[i].average >= class_average)
		{
			stu[i].show();
			above_num++;
		}
	}
	cout << "共有" << above_num << "人分数在班级平均分之上。" << endl;
	system("pause");
}
void the_class::not_pass()
{
	int not_pass_num = 0;
	for (int i = 0; i < stu_have; i++)
	{
		if (stu[i].average < PASS_SCORE)
		{
			stu[i].show();
			not_pass_num++;
		}
	}
	cout << "共有" << not_pass_num << "人平均分未及格。" << endl;
	system("pause");
}
void the_class::section(int diff)
{
	int temp_num;
	for (int i = 0; i*diff < FULL_SCORE; i++)
	{
		cout << i * diff << "~";
		if ((i + 1)*diff >= FULL_SCORE)
		{
			cout << FULL_SCORE << ":";
		}
		else
		{
			cout << (i + 1)*diff << ":";
		}
		temp_num = 0;
		for (int j = 0; j < stu_have; j++)
		{
			if ((i*diff) < stu[j].average&&stu[j].average < ((i + 1)*diff))
			{
				temp_num++;
			}
		}
		cout << (100 * ((float)temp_num) / (float)stu_have) << "%" << endl;
	}
	system("pause");
}
void the_class::bubble_sort()
{
	for (int i = 0; i < stu_have - 1; i++)
	{
		for (int j = 0; j < stu_have - 1 - i; j++)
		{
			if (stu[j].sum < stu[j + 1].sum)
			{
				swap(stu[j], stu[j + 1]);
			}
		}
	}
}
void the_class::rank_table()
{
	bubble_sort();
	for (int i = 0; i < stu_have; i++)
	{
		cout << "名次：" << (i + 1);
		stu[i].show_detail();
	}
	system("pause");
}
student *the_class::search(int id_in)
{
	bubble_sort();
	for (int i = 0; i < stu_have; i++)
	{
		if (stu[i].id == id_in)
		{
			cout << "名次：" << i + 1;
			stu[i].show_detail();
			system("pause");
			return &stu[i];
		}
	}
	cout << "未找到对应学号的记录。" << endl;
	system("pause");
	return NULL;
}

bool the_class::function_select()
{
	int mode;
reinput:
	cout << "0.退出。" << endl;
	cout << "1.打印不及格名单。" << endl;
	cout << "2.打印班级平均分及以上名单。" << endl;
	cout << "3.打印各分数段百分比。" << endl;
	cout << "4.按总分从高到低排序。" << endl;
	cout << "5.打印名次表。" << endl;
	cout << "6.按学号查找。" << endl;
	cout << "请输入代号:";
	cin >> mode;
	switch (mode)
	{
	case exit_p:
		return false;
	case print_notpass:
		not_pass();
		break;
	case print_above:
		above();
		break;
	case print_section:
		int diff;
		cout << endl;
		cout << "请输入区间大小：";
		cin >> diff;
		cout << endl;
		section(diff);
		break;
	case sort_class:
		bubble_sort();
		break;
	case print_rank:
		rank_table();
		break;
	case f_search:
		int id_in;
		cout << endl;
		cout << "请输入要查找的学号：";
		cin >> id_in;
		cout << endl;
		search(id_in);
		break;
	default:
		cout << endl;
		cout << "输入错误，请重新输入。" << endl;
		goto reinput;
	}
	return true;
}

void the_class::read_file()
{
	const char *filename = "scores.txt";
	ifstream file;
	file.open(filename, ios::in);
	if (file.is_open() == false)
	{
		cout << "打开文件失败。" << endl;
		system("pause");
		return;
	}
	int id_read;
	float chinese_read;
	float math_read;
	float english_read;
	student s_temp;
	while (file.eof() == false)
	{
		file >> id_read >> chinese_read >> math_read >> english_read;
		s_temp.set_info(id_read, chinese_read, math_read, english_read);
		add(s_temp);
	}
	file.close();
	return;
}
