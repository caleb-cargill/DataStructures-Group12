#pragma once
#include "Wheel.h"
#include "HardWheel.h"
using namespace std;

class Player {

public:

	Player();

	Player(int initialBalance, int wheelRange);

	int getBalance() {
		return balance;
	}

	void setBalance(int newBalance) {
		balance = newBalance;
	}

	Wheel getWheel() {
		return wheel;
	}

	HardWheel getHardWheel() {
		return hardWheel;
	}

	void setWheel(Wheel newWheel) {
		wheel = newWheel;
	}

	void setHardWheel(HardWheel newHardWheel) {
		hardWheel = newHardWheel;
	}

private:
	int balance;
	Wheel wheel;
	HardWheel hardWheel;
};