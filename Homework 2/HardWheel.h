#pragma once
#include "Wheel.h"

class HardWheel : public Wheel {
public:
	// Declaration of default constructor
	HardWheel();

	// Declaration of Spin function
	int Spin(int userScore);

	// Definition of setter for minRange
	void setMinRange(int newMinRange) {
		minRange = newMinRange;
	}

protected:
	int winstreak = 0;
	int minRange = 0;
};