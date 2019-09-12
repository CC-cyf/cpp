#include<iostream>
#include"Building.h"
using namespace std;

class TeachBuilding :public Building
{
public:
	char function[20];
	TeachBuilding(char *name, int floor, int room, int area, char *function);
	void display();
};
TeachBuilding::TeachBuilding(char *name, int floor, int room, int area, char *function):
	Building(name,floor,room,area)
{
	strcpy(this->function, function);
}
void TeachBuilding::display()
{
	cout << "Name:" << name << endl;
	cout << "Floor:" << floor << endl;
	cout << "Room:" << room << endl;
	cout << "Area:" << area << endl;
	cout << "Function:" << function << endl;
}

class DormBuilding :public Building
{
public:
	int people;
	DormBuilding(char *name, int floor, int room, int area, int peoples);
	void display();
};
DormBuilding::DormBuilding(char *name, int floor, int room, int area, int peoples) :
	Building(name, floor, room, area)
{
	people = peoples;
}
void DormBuilding::display()
{
	cout << "Name:" << name << endl;
	cout << "Floor:" << floor << endl;
	cout << "Room:" << room << endl;
	cout << "Area:" << area << endl;
	cout << "People:" << people << endl;
}

Building* Building::createTeachBuilding(char *name, int floor, int room, int area, char *function)
{
	return  new TeachBuilding(name, floor, room, area, function);
}
Building * Building::creatDormBuilding(char *name, int floor, int room, int area, int peoples) 
{
	return new DormBuilding(name, floor, room, area, peoples);
}