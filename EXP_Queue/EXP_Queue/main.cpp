#include<iostream>
using namespace std;

class node
{
	friend class Queue;
	node *next;
	int item;
};

class Queue
{
private:
	node *head;
	int node_num;
public:
	Queue();
	~Queue();
	bool is_in(int numb);
	void IN(int numb);
	int OUT();
	void clear();
};

Queue::Queue()
{
	node_num = 0;
	head = new node;
	head->next = NULL;
}
Queue::~Queue()
{
	node *temp = head;
	for (int i = 0; i < node_num; i++)
	{
		temp = head->next;
		delete head;
		head = temp;
	}
	delete head;
}
bool Queue::is_in(int numb)
{
	node *temp = head->next;
	for (int i = 0; i < node_num; i++)
	{
		if (temp->item == numb)return true;
		temp = temp->next;
	}
	return false;
}
void Queue::IN(int numb)
{
	node *temp = head;
	for (int i = 0; i < node_num; i++)
	{
		temp = temp->next;
	}
	temp->next = new node;
	temp->next->item = numb;
	temp->next->next = NULL;
	node_num++;
}
int Queue::OUT()
{
	node *temp = head;
	int result = head->next->item;
	head = head->next;
	delete temp;
	node_num--;
	return result;
}
void Queue::clear()
{
	node *temp = head;
	for (int i = 0; i < node_num; i++)
	{
		temp = head->next;
		delete head;
		head = temp;
	}
	node_num = 0;
}

int main()
{
	Queue q1;
	q1.IN(1);
	q1.IN(3);
	q1.IN(2);
	q1.IN(5);
	q1.IN(4);
	cout << q1.is_in(5);
	cout << q1.is_in(4);
	cout << q1.is_in(3);
	cout << q1.is_in(2);
	cout << q1.is_in(1);
	cout << endl;
	cout << q1.OUT() << endl;
	cout << q1.OUT() << endl;
	cout << q1.OUT() << endl;
	q1.clear();
	q1.IN(9);
	q1.IN(13);
	q1.IN(16);
	q1.IN(8);
	cout << q1.OUT() << endl;
	cout << q1.OUT() << endl;
	cout << q1.OUT() << endl;
	cout << q1.OUT() << endl;
	system("pause");
	return 0;
}