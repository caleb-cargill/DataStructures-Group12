#pragma once
#include <exception>
#include <string>
#include <iostream>

using namespace std;

template <class T> class BaseList
{
protected:
	const static int MAX_SIZE = 500; // maximum size of the array
	T* list[MAX_SIZE]; // array of pointers
	int size = 0; // size of array
	int compareCount = 0; // number of comparisons made
	int moveCount = 0; // number of moves made

public:
	// Default constructor for the class
	BaseList() {
		for (int i = 0; i < MAX_SIZE; i++) {
			list[i] = nullptr;
		}
	}


	// Destructor for the class, deletes all pointers to prevent memory leaks
	~BaseList() {
		MakeEmpty();
	}

	// overload of the > operator
	bool operator>(const T& rhs) {
		return this > rhs;
	}

	// overload of the < operator
	bool operator<(const T& rhs) {
		return this < rhs;
	}

	// overload of the == operator
	bool operator==(const T& rhs) {
		return this == rhs;
	}

	// adds item at correct location
	void AddItem(T &inVal) {
		int itemIndex = 0;
		bool biggestItem = true;
		if (IsFull()) {
			throw ListOverflow();
		}

		if (size == 0) {
			list[0] = new T(inVal);
			size++;
			return;
		}

		for (int i = 0; i < size; i++) {
			compareCount++;
			if (*list[i] >= inVal) {
				itemIndex = i;
				biggestItem = false;
				break;
			}
		}

		if (biggestItem) {
			list[size] = new T(inVal);
		}
		else {
			for (int j = size; j > itemIndex; j--) {
				moveCount++;
				list[j] = list[j - 1];
			}
			list[itemIndex] = new T(inVal);
		}
		size++;
	}

	// removes specified item
	T RemoveItem(T &item) {
		bool itemfound = false;
		int itemIndex = 0;
		T* temp = nullptr;
		if (IsEmpty()) {
			throw ListUnderflow();
		}

		compareCount++;
		if (item == *list[size - 1]) {
			delete list[size - 1];
			itemfound = true;
		}
		else {
			for (int i = 0; i < size; i++) {
				compareCount++;
				if (item == *list[i]) {
					itemfound = true;
					itemIndex = i;
					delete list[itemIndex];
					for (int j = itemIndex; j < size - 1; j++) {
						moveCount++;
						list[j] = list[j + 1];
					}
					list[size - 1] = nullptr;
					break;
				}
			}
		}

		if (!itemfound) {
			throw ItemNotFound();
		}
		size--;
	}


	// returns boolean denoting whether the list is empty or not
	bool IsEmpty() {
		return size == 0;
	}

	// returns boolean denoting whether the list is full or not
	bool IsFull() {
		return size == MAX_SIZE;
	}

	// Empties the list
	void MakeEmpty() {
		for (int i = 0; i < size; i++)
			delete list[i];
		size = 0;
	}

	// Prints the array of pointers
	void PrintListPointers() {
		cout << "Pointer array" << endl;
		for (int i = 0; i < size; i++) {
			cout << list[i] << " ";
		}
		cout << endl << endl;
	}

	// prints the list of values in the array
	void PrintListValues() {
		cout << "Pointer array values" << endl;
		int s = size;
		for (int i = 0; i < s; i++) {
			if (list[i] != nullptr) {
				cout << *list[i] << " ";
			}
			else {
				s += 1;
			}
		}
		cout << endl << endl;
	}

	// getter for comparison count
	int getCompareCount() {
		return compareCount;
	}

	// getter for move count
	int getMoveCount() {
		return moveCount;
	}

	// Custom exception for when user tries to overfill the list
	class ListOverflow : public exception {
	public:
		string msg = "The list is full.";
	};

	// Custom exception for when the user tries to remove from an emppty list
	class ListUnderflow : public exception {
	public:
		string msg = "The list is empty.";
	};

	// Custom exception for when the requested item cannot be found 
	class ItemNotFound : public exception {
	public:
		string msg = "The item is not in the list.";
	};
};