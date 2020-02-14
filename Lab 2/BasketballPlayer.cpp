#include "BasketballPlayer.h"
#include <stdlib.h> // Used https://mathbits.com/MathBits/CompSci/Introduction/clear.htm to figure out how to clear the console for clean output
using namespace std;

bool BasketballPlayer::PassBall() {
	bool isPassSuccessful = false;

	// increment Passes attempted
	PassesAttempted++;

	// Get passing percentages
	int passSuccessPerc = rand() % 100 + 1;
	int passingPerc = 0;
	if (PassesAttempted != 0)
		passingPerc = (1.0 * PassesMade / PassesAttempted) * 100.0;

	if (passSuccessPerc > passingPerc)
	{
		// if the success percentage is higher than passing percentage, set bool to true and increment passes made
		isPassSuccessful = true;
		PassesMade++;
	}

	// return bool denoting whether the pass is successful
	return isPassSuccessful;
}

int BasketballPlayer::TakeShot(int shotVal) {
	int pointsScored = 0;

	// increment shots taken
	ShotsTaken++; /// THERE IS AN ISSUE HERE< READ ACCESS VIOLATION 

	// get shot percentage
	int shotSuccess = 0;
	int shotPerc = 0;
	if (ShotsTaken != 0)
		shotPerc = (1.0 * ShotsMade / ShotsTaken) * 100;

	// check shot weight
	if (shotVal == 1)
		shotSuccess = rand() % 80 + 1;
	else if (shotVal == 2)
		shotSuccess = rand() % 100 + 1;
	else if (shotVal == 3)
		shotSuccess = rand() % 120 + 1;

	if (shotSuccess < shotPerc)
	{
		// if shot weight is less than shot percentage, assign points scored and increment shots made
		ShotsMade++;
		pointsScored = shotVal;
	}

	// return points scored
	return pointsScored;
}

// Displays scores and possessions of both teams
void displayScore(int team1score, int team2score, int team1possessions, int team2possessions) {
	cout << "Score" << endl << endl;
	cout << "Team 1: " << team1score << endl;
	cout << "Team 2: " << team2score << endl << endl;
	cout << "Team 1 Possessions Remaining: " << (20 - team1possessions) << endl;
	cout << "Team 2 Possessions Remaining: " << (20 - team2possessions) << endl << endl;
}

// Returns a value 0-4 different than the starting value
// Used to make sure player doesn't pass to themselves when passing
int changePlayer(int playerToPassTo) {
	int newPlayer = rand() % 5;
	while (newPlayer != playerToPassTo) {
		newPlayer = rand() % 5;
	}
	return newPlayer;
}

// Gets valid pass target from user
// Used http://www.cplusplus.com/forum/general/207458/ to handle non integer input because it was causing the while loop to go infinitely (!cin >> input)
int passToPlayer(int currentPlayer) {
	int input = 0;
	cout << "You have chosen to pass." << endl;
	cout << "Enter who you would like to pass to." << endl;
	cout << "Options:" << endl;
	cout << "1 = Keith" << endl;
	cout << "2 = Caleb" << endl;
	cout << "3 = Brandon" << endl;
	cout << "4 = Manvith" << endl;
	cout << "5 = Chuck" << endl;
	cout << "Choice: ";
	cin >> input;
	cout << endl;
	while (input != 1 && input != 2 && input != 3 && input != 4 && input != 5) {
		system("CLS"); // Clears console after input so it doesnt get to cluttered
		if (!cin >> input) { // If the input is not an integer
			cin.clear(); // Clears cin stream
			cin.ignore(10000, '\n'); // Ignores 10,000 characters until enter is hit
		}
		cout << "Sorry, that was not a valid input. Try again" << endl;
		cout << "Enter who you would like to pass to." << endl;
		cout << "Options:" << endl;
		cout << "1 = Keith" << endl;
		cout << "2 = Caleb" << endl;
		cout << "3 = Brandon" << endl;
		cout << "4 = Manvith" << endl;
		cout << "5 = Chuck" << endl;
		cout << "Choice: ";
		cin >> input;
		cout << endl;

	}
	system("CLS"); // Clears console after input so it doesnt get to cluttered
	return input - 1;
}

// Gets valid point value from user
// Used http://www.cplusplus.com/forum/general/207458/ to handle non integer input because it was causing the while loop to go infinitely (!cin >> input)
int getPointValue() {
	int input = 0;
	cout << "You have chosen to shoot the ball." << endl;
	cout << "Enter where you would like to shoot the ball from." << endl;
	cout << "Options:" << endl;
	cout << "1 = 1 point" << endl;
	cout << "2 = 2 points" << endl;
	cout << "3 = 3 points" << endl << endl;
	cout << "Choice: ";
	cin >> input;
	cout << endl;
	while (input != 1 && input != 2 && input != 3) {
		system("CLS"); // Clears console after input so it doesnt get to cluttered
		if (!cin >> input) { // If the input is not an integer
			cin.clear(); // Clears cin stream
			cin.ignore(10000, '\n'); // Ignores 10,000 characters until enter is hit
		}
		cout << "Sorry, that was not a valid input. Try again" << endl;
		cout << "Options:" << endl;
		cout << "1 = 1 point" << endl;
		cout << "2 = 2 points" << endl;
		cout << "3 = 3 points" << endl << endl;
		cout << "Choice: ";
		cin >> input;
		cout << endl;
	}
	system("CLS"); // Clears console after input so it doesnt get to cluttered
	return input;
}


// Determines if team 1 or team 2 rebounds a missed shot
bool rebound(int pointsScored) {
	if (pointsScored == 0) {
		int reboundSuccess = rand() % 100;
		if (reboundSuccess < 50) {
			return true;
		}
		else
			return false;
	}
}


// Gets a valid input from the user
// Used http://www.cplusplus.com/forum/general/207458/ to handle non integer input because it was causing the while loop to go infinitely (!cin >> input)
int getInput() {
	int input = 0;
	cout << "Your turn. Enter what you would like to do: " << endl;
	cout << "Options:" << endl;
	cout << "1 = Shoot" << endl;
	cout << "2 = Pass" << endl;
	cout << "3 = Show Player Stats" << endl;
	cout << "4 = Show Score" << endl << endl;
	cout << "Choice: ";
	cin >> input;
	cout << endl;
	while (input != 1 && input != 2 && input != 3 && input != 4) {
		system("CLS"); // Clears console after input so it doesnt get to cluttered	
		if (!cin >> input) { // If the input is not an integer
			cin.clear(); // Clears cin stream
			cin.ignore(10000, '\n'); // Ignores 10,000 characters until enter is hit
		}
		cout << "Sorry, that was not a valid input. Try again" << endl;
		cout << "Options:" << endl;
		cout << "1 = Shoot" << endl;
		cout << "2 = Pass" << endl;
		cout << "3 = Show Player Stats" << endl;
		cout << "4 = Show Score" << endl << endl;
		cout << "Choice: ";
		cin >> input;
		cout << endl;
	}
	system("CLS"); // Clears console after input so it doesnt get to cluttered
	return input;
}

// Displays the teams stats
// Used http://faculty.cs.niu.edu/~mcmahon/CS241/c241man/node83.html as a refresher on cout formatting
void displayStats(BasketballPlayer players[5]) {
	cout << right << setw(20) << "Name" << right << setw(20) << "Passing" << right << setw(20) << "Shooting" << endl << endl;
	for (int i = 0; i < 5; i++) {
		BasketballPlayer player = players[i];
		int passPerc = (int)(1.0 * player.getPassesMade() / player.getPassesAttempted() * 100);
		int shotPerc = (int)(1.0 * player.getShotsMade() / player.getShotsTaken() * 100);
		cout << setw(20) << player.getName();
		if (passPerc < 10)
			cout << setw(13) << player.getPassesMade() << "/" << player.getPassesAttempted();
		else
			cout << setw(12) << player.getPassesMade() << "/" << player.getPassesAttempted();
		cout << " (" << passPerc << "%)";
		if (shotPerc < 10)
			cout << setw(13) << player.getShotsMade() << "/" << player.getShotsTaken();
		else
			cout << setw(12) << player.getShotsMade() << "/" << player.getShotsTaken();
		cout << " (" << shotPerc << "%)" << endl;
	}
	cout << endl;
}

int main() {
	// Got from https://www.geeksforgeeks.org/rand-and-srand-in-ccpp/ after we noticed rand() always had the same values
	srand(time(0)); // Randomly seeds rand() function

	// Team 1 - randomly generates ShotsTaken and PassesMade from 10-19 and ShotsMade and PassesMade from 0-9
	// This makes the game playable because if all the values were 0, the no one would ever make a shot or pass
	BasketballPlayer teamOnePlayers[5];
	teamOnePlayers[0].setStats("Keith", rand() % 10 + 10, rand() % 10, rand() % 10 + 10, rand() % 10);
	teamOnePlayers[1].setStats("Caleb", rand() % 10 + 10, rand() % 10, rand() % 10 + 10, rand() % 10);
	teamOnePlayers[2].setStats("Brandon", rand() % 10 + 10, rand() % 10, rand() % 10 + 10, rand() % 10);
	teamOnePlayers[3].setStats("Manvith", rand() % 10 + 10, rand() % 10, rand() % 10 + 10, rand() % 10);
	teamOnePlayers[4].setStats("Chuck", rand() % 10 + 10, rand() % 10, rand() % 10 + 10, rand() % 10);

	// Team 2 - randomly generates ShotsTaken and PassesMade from 10-19 and ShotsMade and PassesMade from 0-9
	// This makes the game playable because if all the values were 0, the no one would ever make a shot or pass
	BasketballPlayer teamTwoPlayers[5];
	teamTwoPlayers[0].setStats("Louie", rand() % 10 + 10, rand() % 10, rand() % 10 + 10, rand() % 10);
	teamTwoPlayers[1].setStats("Bill", rand() % 10 + 10, rand() % 10, rand() % 10 + 10, rand() % 10);
	teamTwoPlayers[2].setStats("James", rand() % 10 + 10, rand() % 10, rand() % 10 + 10, rand() % 10);
	teamTwoPlayers[3].setStats("CPU", rand() % 10 + 10, rand() % 10, rand() % 10 + 10, rand() % 10);
	teamTwoPlayers[4].setStats("Placeholder", rand() % 10 + 10, rand() % 10, rand() % 10 + 10, rand() % 10);

	// Score variables
	int teamOneScore = 0;
	int teamTwoScore = 0;

	// Possession variables
	int playerWithPossession = rand() % 5;
	int teamOnePossessions = 0;
	int teamTwoPossessions = 0;
	int teamWithPossession = 1;

	// Input variables
	int playerChoice = 0;
	int pointValue = 0;
	int pointsScored = 0;
	int randomNum = 0;

	// Opponent variables
	int oppShotPerc = 0;
	int oppReboundPerc = 0;

	// Will run until both teams have had 20 possessions
	while (teamOnePossessions <= 20 && teamTwoPossessions <= 20) {
		// If team 1 has possession
		if (teamWithPossession == 1) {

			playerChoice = getInput();

			switch (playerChoice) {
			case 1:
				pointValue = getPointValue();
				pointsScored = teamOnePlayers[playerWithPossession].TakeShot(pointValue);
				// If they miss a shot (pointsScored == 0), then rebound is called. If rebound() returns true, this team gets the rebound. If rebound() return false, the other team gets the rebound
				if (pointsScored == 0) {
					if (rebound(pointsScored) && pointsScored == 0) {
						playerWithPossession = rand() % 5;
						cout << "The shot missed. Your team got the rebound." << endl << endl;
					}
					else {
						cout << "Your team missed the shot. The other team got the rebound." << endl << endl;
						playerWithPossession = rand() % 5;
						teamWithPossession = 2;
						teamOnePossessions++;
					}
				}
				else {
					if (pointsScored == 1)
						cout << "Your team scored " << pointsScored << " point!" << endl << endl;
					else
						cout << "Your team scored " << pointsScored << " points!" << endl << endl;
					playerWithPossession = rand() % 5;
					teamOneScore += pointsScored;
					teamWithPossession = 2;
					teamOnePossessions++;
				}
				break;
			case 2:
				// If pass is successful it will change players, else it will change possession to the other team
				playerWithPossession = passToPlayer(playerWithPossession);
				if (teamOnePlayers[playerWithPossession].PassBall()) {
					cout << "The basketball was passed to " << teamOnePlayers[playerWithPossession].getName() << endl << endl;
				}
				else {
					cout << "The pass was incomplete. Turneover to the other team" << endl << endl;
					playerWithPossession = rand() % 5;
					teamWithPossession = 2;
					teamOnePossessions++;
				}
				break;
			case 3:
				displayStats(teamOnePlayers);
				break;
			case 4:
				displayScore(teamOneScore, teamTwoScore, teamOnePossessions, teamTwoPossessions);
				break;
			}
		}
		// If team 2 has possession
		// Opponent has a 60% chance to make a shot and 50% chance to get a rebound if they miss
		// Point value is randomly chosen between 1-3
		else {
			playerWithPossession = rand() % 5;
			oppShotPerc = rand() % 100 + 1;
			pointsScored = rand() % 3 + 1;

			if (oppShotPerc < 60) {

				oppReboundPerc = rand() % 100 + 1;

				if (oppReboundPerc < 50) {
					playerWithPossession = rand() % 5;
					cout << "The opponent shot missed. Their team got the rebound." << endl << endl;
				}
				else {
					cout << "The oppenent missed the shot. Your team got the rebound." << endl << endl;
					playerWithPossession = rand() % 5;
					teamWithPossession = 1;
					teamTwoPossessions++;
				}
			}
			else {
				if (pointsScored == 1)
					cout << "The other team scored " << pointsScored << " point." << endl << endl;
				else
					cout << "The other team scored " << pointsScored << " points." << endl << endl;
				playerWithPossession = rand() % 5;
				teamTwoScore += pointsScored;
				teamWithPossession = 1;
				teamTwoPossessions++;
			}
		}
	}

	// Outputs the final score after the game with appropriate output based on the result
	cout << "Game Over." << endl;
	cout << "Final Score:" << endl << endl;
	cout << "Team 1: " << teamOneScore << endl;
	cout << "Team 2: " << teamTwoScore << endl << endl;
	if (teamOneScore > teamTwoScore) {
		cout << "Congratulation, your team won!" << endl;
	}
	else if (teamOneScore == teamTwoScore) {
		cout << "Tie game." << endl;
	}
	else {
		cout << "Sorry, yout team lost. Better luck next time" << endl;
	}
}