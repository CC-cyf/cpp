#include"the_class.h"
#include"student.h"
#include<iostream>
using namespace std;

int main()
{
	the_class cls;
	cls.read_file();
	int close = 1;
	while (close == true)
	{
		cout << "****************************************" << endl;
		cout << "@                                      @" << endl;
		cout << "@                                      @" << endl;
		cout << "@             成绩管理系统             @" << endl;
		cout << "@                                      @" << endl;
		cout << "@                                      @" << endl;
		cout << "****************************************" << endl;
		close = cls.function_select();
		system("cls");
	}
	system("pause");
	return 0;
}