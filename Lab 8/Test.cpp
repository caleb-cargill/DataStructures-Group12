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

	// Runs for duration of the program
	while (true) {
		menuInput = getMenuChoice();

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
			if (QOHinput == 'y') {
				cout << "Enter quantity on hand value: ";
				cin >> quantityOnHand;
				list.AddItem(new Item(SKU, description, price, UOM, quantityOnHand));
			}
			else {
				list.AddItem(new Item(SKU, description, price, UOM));
			}
			cout << endl;
			list.PrintList();
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
