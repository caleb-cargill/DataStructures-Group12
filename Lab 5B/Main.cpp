#include "EntertainmentCollection.h"
#include "Show.h"

using namespace std;

int getValidInput();
Show getDetails();

int main() {
	int input = 0;
	EntertainmentCollection<Show> thisShelf;

	while (input != 4) {
		input = getValidInput();

		switch (input) {
		case 1: {
			Show show = getDetails();
			try {
				thisShelf.Push(show);
			}
			catch (EntertainmentCollection<Show>::FullShelf& exFull) {
				cout << exFull.msg << endl << endl;
			}
		}
			  break;
		case 2: {
			try {
				Show show = thisShelf.Pop();
				show.Details();
			}
			catch (EntertainmentCollection<Show>::EmptyShelf& exEmpty) {
				cout << exEmpty.msg << endl << endl;
			}
		}
			  break;
		case 3: {
			cout << "Number of shows on the shelf: " << thisShelf.Length() << endl << endl;
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
	cout << "Press 1 to add a show to the shelf" << endl;
	cout << "Press 2 to remove a show from the shelf" << endl;
	cout << "Press 3 to see how many shows are currently on the shelf" << endl;
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
		cout << "Press 1 to add a show to the shelf" << endl;
		cout << "Press 2 to remove a show from the shelf" << endl;
		cout << "Press 3 to see how many shows are currently on the shelf" << endl;
		cout << "Press 4 to quit" << endl;
		cout << "Input: ";
		cin >> inp;
	}

	cout << endl;

	return inp;
}


Show getDetails() {
	Show *show = new Show();
	string input;

	cout << "Enter a title for the show: " << endl;
	cin >> input;
	show->setTitle(input);
	cout << "Enter a description for the show: " << endl;
	cin >> input;
	show->setDescription(input);

	return *show;
}

