#include "BasketballPlayer.h"
using namespace std;

void displayScore(int team1score, int team2score, int team1possessions, int team2possessions) {
	cout << "Score" << endl << endl;
	cout << "Team 1: " << team1score << endl;
	cout << "Team 2: " << team2score << endl << endl;
	cout << "Team 1 Possessions Remaining: " << team1possessions << endl;
	cout << "Team 2 Possessions Remaining: " << team2possessions << endl;
}

int passBasketball(int playerWithPossession) {
	int playerToPassTo = playerWithPossession;
	while (playerToPassTo == playerWithPossession) {
		playerToPassTo = rand() % 5;
	}
	return playerToPassTo;
}

int PlayersTurn(BasketballPlayer(&players)[5], int& playerWithPossession, bool& teamOneHasPossession, int& teamOneScore, int& teamTwoScore, int& playerChoice, int team1possessions, int team2possessions)
{

	switch (playerChoice) {
	case 1: {
		cout << "Enter where you want to take the shot from (1 for 1 point, 2 for 2 points, 3 for 3 points): " << endl;
		int inputValue;
		cin >> inputValue;
		int shotScore = players[playerWithPossession].TakeShot(inputValue);
		if (shotScore == 0) {
			int reboundSuccess = rand() % 100;

			if (reboundSuccess < 50)
				teamOneHasPossession = false;
			else
				playerWithPossession = rand() % 5;
		}
		else {
			teamOneScore = teamOneScore + shotScore;
			teamOneHasPossession = false;
		}
	}
		  break;

	case 2: {
		if (players[playerWithPossession].PassBall())
			playerWithPossession = passBasketball(playerWithPossession);
		else
			teamOneHasPossession = false;
	}
		  break;

	case 3: {
		players[playerWithPossession].getStats();
	}
		  break;

	case 4: {
		displayScore(teamOneScore, teamTwoScore, 20 - team1possessions, 20 - team2possessions);
	}
		  break;	default: {
		cout << "Not a valid input. Try again: ";
	}

		   return playerWithPossession;
	}
}

int main() {
	BasketballPlayer teamOnePlayers[5];
	BasketballPlayer teamTwoPlayers[5];

	teamOnePlayers[0].setStats("Keith", 0, 0, 0, 0);
	teamOnePlayers[1].setStats("Caleb", 0, 0, 0, 0);
	teamOnePlayers[2].setStats("Brandon", 0, 0, 0, 0);
	teamOnePlayers[3].setStats("Manvith", 0, 0, 0, 0);
	teamOnePlayers[4].setStats("Chuck", 0, 0, 0, 0);

	teamTwoPlayers[0].setStats("Louie", 0, 0, 0, 0);
	teamTwoPlayers[1].setStats("Bill", 0, 0, 0, 0);
	teamTwoPlayers[2].setStats("James", 0, 0, 0, 0);
	teamTwoPlayers[3].setStats("CPU", 0, 0, 0, 0);
	teamTwoPlayers[4].setStats("Placeholder", 0, 0, 0, 0);

	int teamOnePossessions = 0;
	int teamTwoPossessions = 0;
	int teamOneScore = 0;
	int teamTwoScore = 0;
	int playerWithPossession = 0;
	bool teamOneHasPosses = true;

	int teamOnePlayer = rand() % 5;	int teamTwoPlayer = rand() % 5;	int playerChoice = 0;	while (teamOnePossessions <= 20 && teamTwoPossessions <= 20) {		if (teamOneHasPosses) {
			bool rightChoice = true;
			while (rightChoice)
			{
				cout << "Choose an option (1 for Shoot, 2 for Pass, 3 for See Player Stats, 4 for See Score): ";
				cin >> playerChoice;

				if (playerChoice != 1 || playerChoice != 2 || playerChoice != 3 || playerChoice != 4) {
					rightChoice = false;
				}
			}

			teamOnePlayer = PlayersTurn(teamOnePlayers, teamOnePlayer, teamOneHasPosses, teamOneScore, teamTwoScore, playerChoice, teamOnePossessions, teamTwoPossessions);
			if (!teamOneHasPosses)
			{
				teamOnePossessions++;
			}
		}

		else {
			playerChoice = rand() % 2 + 1;
			teamTwoPlayer = PlayersTurn(teamTwoPlayers, teamTwoPlayer, teamOneHasPosses, teamOneScore, teamTwoScore, playerChoice, teamOnePossessions, teamTwoPossessions);
			teamTwoPossessions++;
		}
	}
}

