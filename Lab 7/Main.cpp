#include "BaseList.h"
#include <iostream>

using namespace std;

int main() {
	BaseList<int> *orderedList = new BaseList<int>();
	
	int item1 = 1;
	int *item1ptr = &item1;
	int item2 = 2;
	int* item2ptr = &item2;
	int item3 = 3;
	int* item3ptr = &item3;
	int item4 = 4;
	int* item4ptr = &item4;
	int item5 = 5;
	int* item5ptr = &item5;

	orderedList->AddItem(item5ptr);
	orderedList->AddItem(item1ptr);
	orderedList->AddItem(item3ptr);
	orderedList->AddItem(item2ptr);
	orderedList->AddItem(item4ptr);

	//orderedList.PrintList();

	cout << "Test of Adding: " << endl;
	cout << orderedList->list[0] << endl;
	cout << orderedList->list[1] << endl;
	cout << orderedList->list[2] << endl;
	cout << orderedList->list[3] << endl;
	cout << orderedList->list[4] << endl;

	orderedList->RemoveItem(item1ptr);
	orderedList->RemoveItem(item3ptr);
	
	cout << "Test of Removing (Removed 1 and 3):" << endl;
	cout << orderedList->list[0] << endl;
	cout << orderedList->list[1] << endl;
	cout << orderedList->list[2] << endl;
	cout << orderedList->list[3] << endl;
	cout << orderedList->list[4] << endl;

	orderedList->MakeEmpty();

	cout << "Test of Make Empty: " << endl;
	cout << orderedList->list[0] << endl;
	cout << orderedList->list[1] << endl;
	cout << orderedList->list[2] << endl;
	cout << orderedList->list[3] << endl;
	cout << orderedList->list[4] << endl;

	return 0;
}