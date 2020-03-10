#include "LinkedList.h"
#include <iostream>

using namespace std;

char getMenuChoice();

int main() {
	char menuInput = getMenuChoice();

	// Runs for duration of the program
	while (true) {
		switch (menuInput) {
		case '1': { // AddItem()

		}
		case '2': { // GetItem()

		}
		case '3': { // IsInList()

		}
		case '4': { // IsEmpty()

		}
		case '5': { // Size()

		}
		case '6': { // SeeNext()

		}
		case '7': { // SeePrev()

		}
		case '8': { // SeeAt()

		}
		case '9': { // Reset()

		}
		default: { // Invalid Input
			cout << "Invalid choice" << endl << endl;
			menuInput = getMenuChoice();
		}
		}
	}

	return 0;
}

char getMenuChoice() {
	char input;
	cout << "Linked List Menu:" << endl << endl;
	cout << "1: AddItem()" << endl;
	cout << "2: GetItem()" << endl;
	cout << "3: IsInList()" << endl;
	cout << "4: IsEmpty()" << endl;
	cout << "5: Size()" << endl;
	cout << "6: SeeNext()" << endl;
	cout << "7: SeePrev()" << endl;
	cout << "8: SeeAt()" << endl;
	cout << "9: Reset()" << endl << endl;
	cout << "Input: ";
	cin >> input;
	return input;
}
