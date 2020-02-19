#pragma once
using namespace std;

class Wheel {

public:

	Wheel();

	Wheel(int newRange);

	int Spin();

	int getRange() {
		return range;
	}

	void setRange(int newRange) {
		range = newRange;
	}

protected:
	int range;
};