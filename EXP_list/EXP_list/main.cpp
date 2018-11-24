#include<iostream>
using namespace std;

enum { male, female };
enum { stu, sta, tea };

class Person
{
protected:
	char *name;
	int age;
	bool sex;
public:
	void get_inf(char *name_in, int age_in, bool sex_in);
	void out_base_inf()
	{
		cout << name << age << sex;
	}
	virtual void out_self_inf() = 0;
	virtual ~Person() {};
};
void Person::get_inf(char *name_in, int age_in, bool sex_in)
{
	int name_len = strlen(name_in);
	name = new char[name_len + 1];
	for (int i = 0; i < name_len; i++)
	{
		name[i] = name_in[i];
	}
	name[name_len] = 0;
	age = age_in;
	sex = sex_in;
};

class student :virtual public Person
{
protected:
	int grade;
public:
	student(char *name_in, int age_in, bool sex_in, int grade_in);
	~student() {};
	void out_self_inf();
};
student::student(char *name_in, int age_in, bool sex_in, int grade_in)
{
	get_inf(name_in, age_in, sex_in);
	grade = grade_in;

}
void student::out_self_inf()
{
	cout << grade;
};

class staff :virtual public Person
{
protected:
	int department_id;
public:
	staff(char *name_in, int age_in, bool sex_in, int d_id_in);
	~staff() {};
	void out_self_inf();
};
void staff::out_self_inf()
{
	cout << department_id;
};
staff::staff(char *name_in, int age_in, bool sex_in, int d_id_in)
{
	get_inf(name_in, age_in, sex_in);
	department_id = d_id_in;
};

class teacher :virtual public Person
{
protected:
	int course_id;
public:
	teacher(char *name_in, int age_in, bool sex_in, int c_id_in);
	~teacher() {};
	void out_self_inf();
};
void teacher::out_self_inf()
{
	cout << course_id;
};
teacher::teacher(char *name_in, int age_in, bool sex_in, int c_id_in)
{
	get_inf(name_in, age_in, sex_in);
	course_id = c_id_in;
}

class Node
{
	friend class List;
	Node *next;
	int object_kind;
	Person *object_pointer;
};

class List
{
private:
	Node *head;
	int Node_num;
public:
	List();
	void append(Person *p_person, int kind);
	void show_all();
};
List::List()
{
	head = new Node;
	head->next = NULL;
	Node_num = 0;
};
void List::append(Person *p_person, int kind)
{
	Node *temp;
	temp = head;
	for (int i = 0; i < Node_num; i++)
	{
		temp = temp->next;
	}
	temp->object_kind = kind;
	temp->object_pointer = p_person;
	temp->next = new Node;
	temp->next->next = NULL;
	Node_num++;
}
void List::show_all()
{
	Node *temp = head;
	for (int i = 0; i < Node_num; i++)
	{
		temp->object_pointer->out_base_inf();
		temp->object_pointer->out_self_inf();
		cout << endl;
		temp = temp->next;
	}
};

int main()
{
	List l1;
	char name1[7] = "lalala";
	char name2[7] = "asasas";
	char name3[7] = "qwqwqw";
	student s1(name1, 15, male, 95);
	staff s2(name2, 16, male, 5);
	teacher s3(name3, 19, female, 6);
	l1.append(&s1, stu);
	l1.append(&s2, sta);
	l1.append(&s3, tea);
	l1.show_all();
	system("pause");
	return 0;
}