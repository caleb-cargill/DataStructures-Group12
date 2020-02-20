#include "Shelf.h"
#include <iostream>

using namespace std;

int getValidInput();
void ShowDetails(BoardGame *bg);
BoardGame getGameDetails();

int main() {
	int input = 0;
	Shelf thisShelf;

	while (input != 4) {
		input = getValidInput();

		switch (input) {
		case 1: {
			BoardGame bg = getGameDetails();
			try {
				thisShelf.Push(bg);
			}
			catch (Shelf :: FullShelf& exFull) {
				cout << exFull.Message << endl << endl;
			}
		}
			  break;
		case 2: {
			try {
				BoardGame bg = thisShelf.Pop();
				ShowDetails(&bg);
			}
			catch (Shelf::EmptyShelf& exEmpty) {
				cout << exEmpty.Message << endl << endl;
			}
		}
			  break;
		case 3: {
			cout << "Number of board games on the shelf: " << thisShelf.Length() << endl << endl;
		}
			  break;
		case 4: {
			cout << "Terminating the program." << endl << endl;
			break;
		}
		}
	}

	cout << "Terminating the program." << endl << endl;
	return 0;
}

int getValidInput() {
	int inp = 0;
	cout << "Press 1 to add a board game to the shelf" << endl;
	cout << "Press 2 to remove a board game from the shelf" << endl;
	cout << "Press 3 to see how many board games are currently on the shelf" << endl;
	cout << "Press 4 to quit" << endl;
	cout << "Input: ";
	cin >> inp;
	while (inp != 1 && inp != 2 && inp != 3 && inp != 4) {
		system("CLS");
		if (!cin >> inp) {
			cin.clear();
			cin.ignore(100000, '/n');
		}
		cout << "Sorry, that was not a valid input. Try again" << endl << endl;
		cout << "Press 1 to add a board game to the shelf" << endl;
		cout << "Press 2 to remove a board game from the shelf" << endl;
		cout << "Press 3 to see how many board games are currently on the shelf" << endl;
		cout << "Press 4 to quit" << endl;
		cout << "Input: ";
		cin >> inp;
	}

	cout << endl;

	return inp;
}

void ShowDetails(BoardGame* bg) {
	cout << "Game Title: " << bg->getTitle() << endl;
	cout << "Game Description: " << bg->getDescription() << endl;
}

BoardGame getGameDetails() {
	BoardGame *bg = new BoardGame();
	string input;

	cout << "Enter a title for the game: " << endl;
	cin >> input;
	bg->setTitle(input);
	cout << "Enter a description for the game: " << endl;
	cin >> input;
	bg->setDescription(input);

	return *bg;
}


