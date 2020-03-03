#include "BaseList.h"
#include <iostream>

using namespace std;

int main() {
	BaseList<int>* orderedList = new BaseList<int>();

	int item1 = 1;
	cout << "item1 memory address: " << &item1 << endl;
	int item2 = 2;
	cout << "item2 memory address: " << &item2 << endl;
	int item3 = 3;
	cout << "item3 memory address: " << &item3 << endl;
	int item4 = 4;
	cout << "item4 memory address: " << &item4 << endl;
	int item5 = 5;
	cout << "item5 memory address: " << &item5 << endl;

	orderedList->AddItem(item5);
	orderedList->AddItem(item1);
	orderedList->AddItem(item3);
	orderedList->AddItem(item2);
	orderedList->AddItem(item4);

	cout << "Test of Adding: " << endl;
	orderedList->PrintListPointers();
	orderedList->PrintListValues();

	orderedList->RemoveItem(item2);
	orderedList->RemoveItem(item5);

	cout << "Test of Removing:" << endl;
	orderedList->PrintListPointers();
	orderedList->PrintListValues();

	orderedList->MakeEmpty();

	cout << "Test of Make Empty: " << endl;
	orderedList->PrintListPointers();
	orderedList->PrintListValues();

	return 0;
}