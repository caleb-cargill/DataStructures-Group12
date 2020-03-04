#include "BaseList.h"
#include "MiddleIndexList.h"
#include "BlankSpotsList.h"
#include <iostream>

using namespace std;

int main() {
	BaseList<int>* orderedList = new BaseList<int>();
	MiddleIndexList<int>* middleList = new MiddleIndexList<int>();
	BlankSpotsList<int>* blankSpotList = new BlankSpotsList<int>();

	int item1 = 1;
	int item2 = 2;
	int item3 = 3;
	int item4 = 4;
	int item5 = 5;

	// Testing Task 1

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

	// Testing Task 2

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

	// Testing Task 3

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

	return 0;
}