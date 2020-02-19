#pragma once
#include "Wheel.h"

class HardWheel : public Wheel {
public:
	HardWheel();

	int Spin(int userScore);

	void setMinRange(int newMinRange) {
		minRange = newMinRange;
	}

protected:
	int winstreak = 0;
	int minRange = 0;
};
