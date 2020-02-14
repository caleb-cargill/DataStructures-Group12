#pragma once
#include <iostream>
#include <iomanip>
using namespace std;

class BasketballPlayer
{
public:
	// member function letting the user pass a ball, returns a bool for pass success
	bool PassBall();

	// member function to allow the user to take a shot, returns points scored if any
	int TakeShot(int shotVal);

	// Constructor for class to easily initialize values
	BasketballPlayer() {
		Name = "default";
		ShotsTaken = 0;
		ShotsMade = 0;
		PassesAttempted = 0;
		PassesMade = 0;
	}

	string getName() {
		return Name;
	}

	int getShotsTaken() {
		return ShotsTaken;
	}

	int getShotsMade() {
		return ShotsMade;
	}

	int getPassesAttempted() {
		return PassesAttempted;
	}

	int getPassesMade() {
		return PassesMade;
	}

	void setStats(string name, int shotsTaken, int shotsMade, int passesAttempted, int passesMade) {
		Name = name;
		ShotsTaken = shotsTaken;
		ShotsMade = shotsMade;
		PassesAttempted = passesAttempted;
		PassesMade = passesMade;
	}


private:
	string Name;
	int ShotsTaken, ShotsMade, PassesAttempted, PassesMade;
};