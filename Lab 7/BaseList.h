#pragma once
#include <exception>
#include <string>
#include <iostream>

using namespace std;

template <class T> class BaseList
{
protected:
	const static int MAX_SIZE = 25;
	T* list[MAX_SIZE];
	int size = 0;

public:
	BaseList() {
		for (int i = 0; i < MAX_SIZE; i++) {
			list[i] = nullptr;
		}
	}

	~BaseList() {
		MakeEmpty();
	}

	bool operator>(const T& rhs) {
		return this > rhs;
	}

	bool operator<(const T& rhs) {
		return this < rhs;
	}

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

		if (item == *list[size - 1]) {
			delete list[size - 1];
			itemfound = true;
		}
		else {
			for (int i = 0; i < size; i++) {
				if (item == *list[i]) {
					itemfound = true;
					itemIndex = i;
					delete list[itemIndex];
					for (int j = itemIndex; j < size - 1; j++) {
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

	void PrintListPointers() {
		cout << "Pointer array" << endl;
		for (int i = 0; i < size; i++) {
			cout << list[i] << " ";
		}
		cout << endl << endl;
	}

	void PrintListValues() {
		cout << "Pointer array values" << endl;
		for (int i = 0; i < size; i++) {
			cout << *list[i] << " ";
		}
		cout << endl << endl;
	}

	class ListOverflow : public exception {
	public:
		string msg = "The list is full.";
	};

	class ListUnderflow : public exception {
	public:
		string msg = "The list is empty.";
	};

	class ItemNotFound : public exception {
	public:
		string msg = "The item is not in the list.";
	};
};