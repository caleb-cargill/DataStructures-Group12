#pragma once
#include "Wheel.h"
#include "HardWheel.h"
using namespace std;

class Player {

public:
	// Declaration of default constructor
	Player();

	// Declaration of constructor accepting integer arguments
	Player(int initialBalance, int wheelRange);

	// Defintion of getter for balance
	int getBalance() {
		return balance;
	}

	// Definition of setter for balance
	void setBalance(int newBalance) {
		balance = newBalance;
	}

	// Definition of getter for wheel
	Wheel getWheel() {
		return wheel;
	}

	// Definition getter for hard version of wheel
	HardWheel getHardWheel() {
		return hardWheel;
	}

	// definition of setter for wheel
	void setWheel(Wheel newWheel) {
		wheel = newWheel;
	}

	// Definition of setter for hard version of wheel
	void setHardWheel(HardWheel newHardWheel) {
		hardWheel = newHardWheel;
	}

private:
	int balance;
	Wheel wheel;
	HardWheel hardWheel;
};