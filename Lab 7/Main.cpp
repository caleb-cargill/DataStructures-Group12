#include "BaseList.h"
#include "MiddleIndexList.h"
#include "BlankSpotsList.h"
#include <iostream>
#include <stdlib.h> // srand() and rand()
#include <time.h> // time()

using namespace std;

void TestBaseList(int item1, int item2, int item3, int item4, int item5);
void TestMiddleIndexList(int item1, int item2, int item3, int item4, int item5);
void TestBlankSpotsList(int item1, int item2, int item3, int item4, int item5);
void TestFill100Times();

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

	// Task 4
	TestFill100Times();

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

// Testing filling the three lists 100 times, printing average move and compare counts at the end
void TestFill100Times() {

	int sumCompareBase = 0;
	int sumMoveBase = 0;
	int sumCompareMiddle = 0;
	int sumMoveMiddle = 0;
	int sumCompareBlank = 0;
	int sumMoveBlank = 0;

	for (int j = 0; j < 100; j++) {

		BaseList<int>* orderedList = new BaseList<int>();
		MiddleIndexList<int>* middleList = new MiddleIndexList<int>();
		BlankSpotsList<int>* blankList = new BlankSpotsList<int>();
		int store1[50];
		int store2[50];
		int store3[50];

		for (int i = 0; i < 50; i++) {
			srand(i * j);
			int r1 = rand() % 9 + 1;
			int r2 = rand() % 9 + 1;
			int r3 = rand() % 9 + 1;
			store1[i] = r1;
			store2[i] = r2;
			store3[i] = r3;

			orderedList->AddItem(r1);
			middleList->AddItem(r2);
			blankList->AddItem(r3);
		}

		for (int i = 0; i < 25; i++) {
			orderedList->RemoveItem(store1[i]);
			middleList->RemoveItem(store2[i]);
			blankList->RemoveItem(store3[i]);
		}

		sumCompareBase += orderedList->getCompareCount();
		sumMoveBase += orderedList->getMoveCount();
		sumCompareMiddle += middleList->getCompareCount();
		sumMoveMiddle += middleList->getMoveCount();
		sumCompareBlank += blankList->getCompareCount();
		sumMoveBlank += blankList->getMoveCount();

	}

	cout << "Array Size: 50" << endl;
	cout << "Efficiency Results, Averages: " << endl << endl;
	cout << "Base List Compare Averagee: " << sumCompareBase / 100 << endl;
	cout << "Base List Move Average: " << sumMoveBase / 100 << endl << endl;
	cout << "Middle List Compare Average: " << sumCompareMiddle / 100 << endl;
	cout << "Middle List Move Average: " << sumMoveMiddle / 100 << endl << endl;
	cout << "Blank List Compare Average: " << sumCompareBlank / 100 << endl;
	cout << "Blank List Move Average: " << sumMoveBlank / 100 << endl;
}
