#include "Player.h"
#include <iostream>
using namespace std;

// Function declarations
int getValidPointRange();
int getValidBetAmount(Player player);
int getValidBetChoice();
bool getHardMode();
bool getQuitGame();
bool scoreComparison(int userscore, int housescore);
void updateBalance(bool win, Player& player, int betAmount);

int main() {

	// Initialize user and house players and wheels
	Player user;
	Player house;
	Wheel userWheel;
	Wheel houseWheel;
	HardWheel hardHouseWheel;

	// Set up values with defaults
	bool userQuit = false;
	bool hardMode = false;
	bool userWon = false;
	bool zeroBalance = false;
	int userPointRange = 0;
	int housePointRange = 0;
	int betValue = 0;
	int userScore = 0;
	int houseScore[2] = { 0, 0 };
	int userBetChoice = 0;

	// Get point range for the wheel to start the game
	userPointRange = getValidPointRange();

	housePointRange = userPointRange;

	// Update the wheels to the user inputted range then update the wheels of the players
	userWheel.setRange(userPointRange);
	houseWheel.setRange(housePointRange);
	user.setWheel(userWheel);
	house.setWheel(houseWheel);

	// Determines whether the game is in hard mode or not
	// If it is in hardmode, it will set the values for the hardHouseWheel accordingly
	hardMode = getHardMode();
	if (hardMode) {
		hardHouseWheel.setMinRange(userPointRange);
		hardHouseWheel.setRange(housePointRange);
		house.setHardWheel(hardHouseWheel);
		cout << "You are playing in hard mode" << endl << endl;
	}
	else {
		cout << "You are playing in normal mode" << endl << endl;
	}

	// While the user has a positive balance or they have not quit
	while (user.getBalance() > 0 && !userQuit) {

		// Gets a valid bet amount from the user
		betValue = getValidBetAmount(user);

		// Spins the user wheel and updates the user on result
		userScore = user.getWheel().Spin();
		cout << "You scored " << userScore << " points" << endl << endl;

		// Gets a valid bet choice from the user
		userBetChoice = getValidBetChoice();


		switch (userBetChoice) {
		case 1: // Bet remains the same
			// Will call the appropriate spin() function for the house based on if it's in hardmode or not
			if (!hardMode) {
				houseScore[0] = house.getWheel().Spin();
			}
			else {
				houseScore[0] = house.getHardWheel().Spin(userScore);
			}
			cout << "The house scored " << houseScore[0] << " points" << endl << endl;
			userWon = scoreComparison(userScore, houseScore[0]); // Sets userWon to the correct bool based on scores
			updateBalance(userWon, user, betValue); // Updates user balance

			break;
		case 2: // Bet is doubled
			betValue *= 2; // Doubles the bet amount
			// House spins twice
			for (int i = 0; i < 2; i++) {
				// Will call the appropriate spin() function based on if it's in hardmode or not
				if (!hardMode) {
					houseScore[i] = house.getWheel().Spin();
				}
				else {
					houseScore[i] = house.getHardWheel().Spin(userScore);
				}
				cout << "The house scored " << houseScore[i] << " points" << endl << endl;
				userWon = scoreComparison(userScore, houseScore[i]); // Sets userWon to the correct bool based on scores
				// Since only 1 win is needed when the bet is doubled, if the house wins, the for loop will break and not spin the second time
				if (!userWon) {
					break;
				}
			}
			updateBalance(userWon, user, betValue); // Updates user balance

			break;
		case 3: // Bet is halved
			betValue /= 2; // Halves the bet amount
			int houseWinningSpinCount = 0;
			// House spins twice
			for (int i = 0; i < 2; i++) {
				// Will call the appropriate spin() function based on if it's in hardmode or not
				if (!hardMode) {
					houseScore[i] = house.getWheel().Spin();
				}
				else {
					houseScore[i] = house.getHardWheel().Spin(userScore);
				}
				cout << "The house scored " << houseScore[i] << " points" << endl << endl;
				userWon = scoreComparison(userScore, houseScore[i]);
				// House has to win twice for the player to lose the bet. This counts the number of house wins
				if (!userWon) {
					houseWinningSpinCount += 1;
				}
			}
			// If the house doesn't win, player gets half their original bet value
			if (houseWinningSpinCount == 0) {
				updateBalance(true, user, betValue);
			}
			// If the house wins once, player gets nothing and loses nothing
			else if (houseWinningSpinCount == 1) {
				updateBalance(true, user, 0);
			}
			// If the house wins twice, player loses original bet value
			else {
				updateBalance(false, user, betValue * 2);
			}
			houseWinningSpinCount = 0; // Resets houseWinningSpinCount to 0

			break;
		}

		// Displays a result of the spin and updated balance
		if (userWon) {
			cout << "You beat the house this spin. You won $" << betValue << endl;
			cout << "Your balance is now $" << user.getBalance() << endl << endl;
		}
		else {
			cout << "You were defeating by house this spin. You lost $" << betValue << endl;
			cout << "Your balance is now $" << user.getBalance() << endl << endl;
		}

		// Resets all values to defaults
		userScore = 0;
		houseScore[0] = 0;
		houseScore[1] = 0;
		userWon = false;
		betValue = 0;

		// If the user has a positive balance, will prompt the user if they want to continue. Else it will display a message then exit the loop
		if (user.getBalance() > 0) {
			userQuit = getQuitGame();
		}
		else {
			cout << "You are out of money. You can no longer continue playing" << endl;
		}
	}

	return 0;
}

// Gets a valid point range from the user and returns the int value
// Makes sure the number is greater than or equal to 6 and less than or 20
// Makes sure that the input is an integer
int getValidPointRange() {
	int input = 0;
	cout << "What would you like the maximum point value to be?" << endl;
	cout << "Your value must be between 6 and 20" << endl << endl;
	cout << "Max point value: ";
	cin >> input;
	cout << endl;
	if (input <= 6 || input >= 20) {
		while (input <= 6 || input >= 20) {
			if (!cin >> input) { // Will execute if input is not an integer
				cin.clear(); // Clears cin stream
				cin.ignore(10000, '\n'); // Ignores 10,000 characters until enter is hit
			}
			cout << "That value was not between 6 and 20. Try again" << endl << endl;
			cout << "Max point value: ";
			cin >> input;
			cout << endl;
		}
	}
	return input;
}

// Gets a valid bet amount from the user and returns the int value
// Makes sure the number is greater than 0 and less than the balance
// Makes sure that the input is an integer
int getValidBetAmount(Player player) {
	int input = 0;
	cout << "Your current balance is $" << player.getBalance() << endl;
	cout << "How much would you like to bet?" << endl << endl;
	cout << "Bet amount: $";
	cin >> input;
	cout << endl;
	if (input > player.getBalance()) {
		while (input > player.getBalance()) {
			if (!cin >> input) { // Will execute if input is not an integer
				cin.clear(); // Clears cin stream
				cin.ignore(10000, '\n'); // Ignores 10,000 characters until enter is hit
			}
			cout << "Sorry, you cannot bet more than your balance. Try again" << endl;
			cout << "How much would you like to bet?" << endl << endl;
			cout << "Bet amount: $";
			cin >> input;
			cout << endl;
		}
	}
	if (input < 0) {
		while (input > player.getBalance()) {
			if (!cin >> input) { // Will execute if input is not an integer
				cin.clear(); // Clears cin stream
				cin.ignore(10000, '\n'); // Ignores 10,000 characters until enter is hit
			}
			cout << "Sorry, you cannot bet a negative amount. Try again" << endl;
			cout << "How much would you like to bet?" << endl << endl;
			cout << "Bet amount: $";
			cin >> input;
			cout << endl;
		}
	}
	return input;
}

// Gets a valid bet choice from the user and returns the int value
// Makes sure the number is either 1, 2, or 3
// Makes sure that the input is an integer
int getValidBetChoice() {
	int input = 0;
	cout << "Would you like to change your bet?" << endl << endl;
	cout << "Options:" << endl;
	cout << "Enter 1 for the bet to remain the same" << endl;
	cout << "Enter 2 to double the bet" << endl;
	cout << "Enter 3 to half the bet" << endl << endl;
	cout << "Enter your choice: ";
	cin >> input;
	cout << endl;
	while (input != 1 && input != 2 && input != 3) {
		if (!cin >> input) { // Will execute if input is not an integer
			cin.clear(); // Clears cin stream
			cin.ignore(10000, '\n'); // Ignores 10,000 characters until enter is hit
		}
		cout << "Sorry that was not one of the options. Try again" << endl << endl;
		cout << "Options:" << endl;
		cout << "Enter 1 for the bet to remain the same" << endl;
		cout << "Enter 2 to double the bet" << endl;
		cout << "Enter 3 to half the bet" << endl << endl;
		cout << "Enter your choice: ";
		cin >> input;
		cout << endl;
	}
	return input;
}

// Prompts the user whether they want to play in hard mode
// If a 'y' is inputted, returns true. Otherwise, it returns false
bool getHardMode() {
	char input = 'n';
	cout << "Would you like to play in hard mode?" << endl;
	cout << "This will increase the house's point range every time they lose and decreases the point range every time they win two in a row" << endl;
	cout << "Enter 'y' for yes, any other character for no" << endl << endl;
	cout << "Hard mode? ";
	cin >> input;
	cout << endl;
	if (input == 'y') {
		return true;
	}
	else {
		return false;
	}
}

// Prompts the user whether they want to quit playing
// If a 'y' is inputted, returns true. Otherwise, it returns false
bool getQuitGame() {
	char input = 'n';
	cout << "Would you like to spin again?" << endl;
	cout << "Enter 'y' for yes. Enter any other character to quit" << endl << endl;
	cout << "Spin again? ";
	cin >> input;
	cout << endl;
	if (input == 'y') {
		return false;
	}
	else {
		return true;
	}
}

// Takes the userScore and houseScore variables as parameters
// Returns true if the user won
// Returns false if the house won
bool scoreComparison(int userscore, int housescore) {
	if (userscore > housescore) {
		return true;
	}
	else {
		return false;
	}
}

// Takes in a bool for whether the user won or not
// Takes in a reference to the player that is getting their balance changed
// Takes in the betAmount from the spin
// Updates the player's balance by the betAmount from the turn based on whether they won or lost the bet
void updateBalance(bool win, Player& player, int betAmount) {
	if (win) {
		player.setBalance(player.getBalance() + betAmount);
	}
	else {
		player.setBalance(player.getBalance() - betAmount);
	}
}