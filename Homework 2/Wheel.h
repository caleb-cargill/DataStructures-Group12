#pragma once
using namespace std;

class Wheel {

public:
	// Declaration of default constructor
	Wheel();

	// Declaration of constructor accepting an integer as an argument
	Wheel(int newRange);

	// Declaration of spin function
	int Spin();

	// Definition of getter method range
	int getRange() {
		return range;
	}

	// Definition of setter method for range
	void setRange(int newRange) {
		range = newRange;
	}

protected:
	int range;
};