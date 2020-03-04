#include "BaseList.h"
#include "MiddleIndexList.h"
#include "BlankSpotsList.h"
#include <iostream>

using namespace std;

void TestBaseList(int item1, int item2, int item3, int item4, int item5);
void TestMiddleIndexList(int item1, int item2, int item3, int item4, int item5);
void TestBlankSpotsList(int item1, int item2, int item3, int item4, int item5);

int main() {

	int item1 = 1;
	int item2 = 2;
	int item3 = 3;
	int item4 = 4;
	int item5 = 5;

	// Test task 1
	TestBaseList(item1, item2, item3, item4, item5);

	// Test task 2
	TestMiddleIndexList(item1, item2, item3, item4, item5);

	// Test task 3
	TestBlankSpotsList(item1, item2, item3, item4, item5);

	return 0;
}

// Testing the BaseList class as an ordered list
void TestBaseList(int item1, int item2, int item3, int item4, int item5) {
	BaseList<int>* orderedList = new BaseList<int>();

	orderedList->AddItem(item4);
	orderedList->AddItem(item1);
	orderedList->AddItem(item3);
	orderedList->AddItem(item2);
	orderedList->AddItem(item5);

	cout << "Testing Task 1" << endl << endl;

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
}

// Testing the MiddleIndexList class as an ordered list searching from middle of array
void TestMiddleIndexList(int item1, int item2, int item3, int item4, int item5) {
	MiddleIndexList<int>* middleList = new MiddleIndexList<int>();

	middleList->AddItem(item4);
	middleList->AddItem(item1);
	middleList->AddItem(item3);
	middleList->AddItem(item2);
	middleList->AddItem(item5);

	cout << "Testing Task 2" << endl << endl;

	cout << "Test of Adding: " << endl;
	middleList->PrintListPointers();
	middleList->PrintListValues();


	middleList->RemoveItem(item2);
	middleList->RemoveItem(item5);

	cout << "Test of Removing:" << endl;
	middleList->PrintListPointers();
	middleList->PrintListValues();

	middleList->MakeEmpty();

	cout << "Test of Make Empty: " << endl;
	middleList->PrintListPointers();
	middleList->PrintListValues();
}

// Testing the BlankSpotsList class as an ordered list leaving blank spots when applicable
void TestBlankSpotsList(int item1, int item2, int item3, int item4, int item5) {
	BlankSpotsList<int>* blankSpotList = new BlankSpotsList<int>();

	blankSpotList->AddItem(item4);
	blankSpotList->AddItem(item1);
	blankSpotList->AddItem(item3);
	blankSpotList->AddItem(item2);
	blankSpotList->AddItem(item5);

	cout << "Testing Task 3" << endl << endl;

	cout << "Test of Adding: " << endl;
	blankSpotList->PrintListPointers();
	blankSpotList->PrintListValues();


	blankSpotList->RemoveItem(item2);
	blankSpotList->RemoveItem(item5);

	cout << "Test of Removing:" << endl;
	blankSpotList->PrintListPointers();
	blankSpotList->PrintListValues();

	blankSpotList->MakeEmpty();

	cout << "Test of Make Empty: " << endl;
	blankSpotList->PrintListPointers();
	blankSpotList->PrintListValues();
	
}
