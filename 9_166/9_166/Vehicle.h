#pragma once
#include <iostream>
using namespace std;
class Vehicle {
public:
	Vehicle() {
		cout << "Vehicle constructor..." << endl;
	}
	~Vehicle() {
		cout << "Vehicle destructor..." << endl;
	}
	virtual void display() const = 0;
	static Vehicle * createCar();
	static Vehicle * createTruck();
	static Vehicle * createBoat();
};