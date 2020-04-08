//#include "Hash.h"
//#include "Item.h"
//#include <iostream>
//
//using namespace std;
//
//char getMenuChoice();
//
//int main() {
//	HashTable<Item> table;
//
//	char menuInput = ' ';
//	char QOHinput = ' ';
//	int SKU = 0;
//	string description = "";
//	double price = 0.0;
//	string UOM = "";
//	int quantityOnHand = 0;
//	int listIndex = 0;
//
//	// Runs for duration of the program
//	while (true) {
//		cout << "Hash Table: ";
//		table.Print();
//		cout << endl;
//
//		menuInput = getMenuChoice();
//		system("CLS");
//
//		switch (menuInput) {
//		case '1': { // AddItem()
//			if (table.GetLength() < 100) {
//				cout << "Enter a stock keeping number: ";
//				cin >> SKU;
//				cout << "Enter a description: ";
//				cin >> description;
//				cout << "Enter a price: $";
//				cin >> price;
//				cout << "Enter a unit of measurement: ";
//				cin >> UOM;
//				cout << "Would you like to enter a quantity on hand value? (y/n): ";
//				cin >> QOHinput;
//				cout << endl;
//				if (QOHinput == 'y') {
//					cout << "Enter quantity on hand value: ";
//					cin >> quantityOnHand;
//					table.AddItem(new Item(SKU, description, price, UOM, quantityOnHand));
//				}
//				else {
//					table.AddItem(new Item(SKU, description, price, UOM));
//				}
//				cout << endl;
//			}
//			else {
//				cout << "The hash table is full" << endl << endl;
//			}
//			break;
//		}
//		case '2': { // RemoveItem()
//			if (table.GetLength() > 0) {
//				cout << "Enter a stock keeping number: ";
//				cin >> SKU;
//				cout << endl;
//				Item* remove = new Item(SKU, "", 0.0, "");
//				if (table.GetItem(remove) == nullptr) {
//					cout << "The item is not in the hash table" << endl << endl;
//				}
//				else {
//					table.RemoveItem(remove);
//				}
//			}
//			else {
//				cout << "The hash table is empty" << endl << endl;
//			}
//			break;
//		}
//		case '3': { // GetItem()
//			cout << "Enter a stock keeping number: ";
//			cin >> SKU;
//			cout << endl;
//			if (table.GetItem(new Item(SKU, "", 0.0, "")) != nullptr) {
//				cout << *table.GetItem(new Item(SKU, "", 0.0, "")) << endl << endl;
//			}
//			else {
//				cout << "The item is not in the hash table" << endl << endl;
//			}
//			break;
//		}
//		case '4': { // GetLength()
//			cout << "Length: " << table.GetLength() << endl << endl;
//			break;
//		}
//		default: {
//			cout << "Not a valid input. Try again" << endl << endl;
//			break;
//		}
//		}
//	}
//
//	return 0;
//}
//
//char getMenuChoice() {
//	char input;
//	cout << "Hash Table Menu:" << endl << endl;
//	cout << "1: AddItem()" << endl;
//	cout << "2: RemoveItem()" << endl;
//	cout << "3: GetItem()" << endl;
//	cout << "4: GetLength()" << endl;
//	cout << "Input: ";
//	cin >> input;
//	return input;
//}