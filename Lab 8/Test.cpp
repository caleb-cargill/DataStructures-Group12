#include "LinkedList.h"
#include "Item.h"
#include <iostream>

using namespace std;

char getMenuChoice();

int main() {
	Placeholder<Item> list;

	char menuInput = ' ';
	char QOHinput = ' ';
	int SKU = 0;
	string description = "";
	double price = 0.0;
	string UOM = "";
	int quantityOnHand = 0;
	int listIndex = 0;

	// Runs for duration of the program
	while (true) {
		cout << "List: ";
		list.PrintList();
		cout << endl;

		menuInput = getMenuChoice();
		system("CLS");

		switch (menuInput) {
		case '1': { // AddItem()
			cout << "Enter a stock keeping number: ";
			cin >> SKU;
			cout << "Enter a description: ";
			cin >> description;
			cout << "Enter a price: $";
			cin >> price;
			cout << "Enter a unit of measurement: ";
			cin >> UOM;
			cout << "Would you like to enter a quantity on hand value? (y/n): ";
			cin >> QOHinput;
			cout << endl;
			if (QOHinput == 'y') {
				cout << "Enter quantity on hand value: ";
				cin >> quantityOnHand;
				list.AddItem(new Item(SKU, description, price, UOM, quantityOnHand));
			}
			else {
				list.AddItem(new Item(SKU, description, price, UOM));
			}
			cout << endl;
			break;
		}
		case '2': { // GetItem()
			cout << "Enter a stock keeping number: ";
			cin >> SKU;
			cout << endl;
			try {
				list.GetItem(new Item(SKU, "", 0.0, ""));
			}
			catch (Placeholder<Item>::NotInList& dne) {
				cout << dne.Message << endl << endl;
			}
			break;
		}
		case '3': { // IsInList()
			cout << "Enter a stock keeping number: ";
			cin >> SKU;
			cout << endl;
			if (list.IsInList(new Item(SKU, "", 0.0, ""))) {
				cout << "IsInList = True" << endl << endl;
			}
			else {
				cout << "IsInList = False" << endl << endl;
			}
			break;
		}
		case '4': { // IsEmpty()
			if (list.IsEmpty()) {
				cout << "IsEmpty = True" << endl << endl;
			}
			else {
				cout << "IsEmpty = False" << endl << endl;
			}
			break;
		}
		case '5': { // Size()
			cout << "Size: " << list.Size() << endl << endl;
			break;
		}
		case '6': { // SeeNext()
			try {
				cout << "Next: " << list.SeeNext().GetPartInfo() << endl << endl;
			}
			catch (Placeholder<Item>::OutOfBounds& ex) {
				cout << ex.Message << endl << endl;
			}
			break;
		}
		case '7': { // SeePrev()
			try {
				cout << "Prev: " << list.SeePrev().GetPartInfo() << endl << endl;
			}
			catch (Placeholder<Item>::OutOfBounds& ex) {
				cout << ex.Message << endl << endl;
			}
			break;
		}
		case '8': { // SeeAt()
			cout << "Which index would you like to look at: ";
			cin >> listIndex;
			try {
				cout << "Item " << listIndex << ": " << list.SeeAt(listIndex-1).GetPartInfo() << endl << endl;
			}
			catch (Placeholder<Item>::OutOfBounds& ex) {
				cout << ex.Message << endl << endl;
			}
			break;
		}
		case '9': { // Reset()
			cout << "The list curr pointer has been set to the beginning" << endl << endl;
			list.Reset();
			break;
		}
		default: {
			cout << "Not a valid input. Try again" << endl << endl;
			break;
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
