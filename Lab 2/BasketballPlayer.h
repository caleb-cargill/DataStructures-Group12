#pragma once
#include <iostream>
#include <iomanip>
using namespace std;

class BasketballPlayer
{
public:
	// member function letting the user pass a ball, returns a bool for pass success
	bool PassBall() {
		bool isPassSuccessful = false;

		// increment Passes attempted
		PassesAttempted++;

		// Get passing percentages
		int passSuccessPerc = rand() % 100 + 1;
		int passingPerc = 0;
		if (PassesAttempted != 0)
			passingPerc = (PassesMade / PassesAttempted) * 100;

		if (passSuccessPerc > passingPerc)
		{
			// if the success percentage is higher than passing percentage, set bool to true and increment passes made
			isPassSuccessful = true;
			PassesMade++;
		}

		// return bool denoting whether the pass is successful
		return isPassSuccessful;
	}

	// member function to allow the user to take a shot, returns points scored if any
	int TakeShot(int shotVal) {
		int pointsScored = 0;

		// increment shots taken
		ShotsTaken++; /// THERE IS AN ISSUE HERE< READ ACCESS VIOLATION

		// get shot percentage
		int shotSuccess = 0;
		int shotPerc = 0;
		if (ShotsTaken != 0)
			shotPerc = (ShotsMade / ShotsTaken) * 100;

		// check shot weight
		if (shotVal == 1)
			shotSuccess = rand() % 80 + 1;
		else if (shotVal == 2)
			shotSuccess = rand() % 100 + 1;
		else if (shotVal == 3)
			shotSuccess = rand() % 120 + 1;
		return pointsScored;

		if (shotSuccess < shotPerc)
		{
			// if shot weight is less than shot percentage, assign points scored and increment shots made
			ShotsMade++;
			pointsScored = shotVal;
		}

		// return points scored
		return pointsScored;
	}

	// Constructor for class to easily initialize values
	BasketballPlayer() {
		Name = "default";
		ShotsTaken = 0;
		ShotsMade = 0;
		PassesAttempted = 0;
		PassesMade = 0;
	}

	BasketballPlayer(string name, int shotsTaken, int shotsMade, int passesAttempted, int passesMade) {
		Name = name;
		ShotsTaken = shotsTaken;
		ShotsMade = shotsMade;
		PassesAttempted = passesAttempted;
		PassesMade = passesMade;
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



	void getStats() {
		cout << "Name: " << Name << endl;
		cout << "Shots Taken: " << ShotsTaken << endl;
		cout << "Shots Made: " << ShotsMade << endl;
		cout << "Passes Attempted: " << PassesAttempted << endl;
		cout << "Passes Made: " << PassesMade << endl << endl;
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


