#pragma once
#include <exception>
#include <string>

using namespace std;

template <class T> class BaseList
{
protected:
	int MAX_SIZE = 25;
	
	int size = 0;

public:
	T* list;

	BaseList() {
		list = new T[MAX_SIZE];
	}

	~BaseList() {
		delete list;
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
	void AddItem(T *inVal) {
		if (IsFull()) {
			throw ListOverflow();
		}
			
		if (size == 0){
			list[0] = *inVal;
		}

		for (int i = 0; i < size; i++) {
			if (i == 0 && list[i] > *inVal){
				// add item at i and move everything back 
				for (int j = size; j > i; j--) {
					list[j] = list[j - 1];
				}

				// put item at i
				list[i] = *inVal;
				break;
			}
			else if (i + 1 == size)
			{
				// add item to back of list, no need to move anything back
				list[i + 1] = *inVal;
			}
			else if (list[i] < *inVal && list[i + 1] > *inVal) {
				// iterate through the list from the back and move items back
				for (int j = size; j > i + 1; j--) {
					list[j] = list[j - 1];
				}

				// put item at i + 1
				list[i + 1] = *inVal;
				break;
			}
			else if (list[i] == *inVal)
			{
				// add item at i and move other items back
				for (int j = size; j > i; j--) {
					list[j] = list[j - 1];
				}

				// put item at i
				list[i] = *inVal;
				break;
			}
			
		}
		size++;
	}

	// removes specified item
	T RemoveItem(T *item) {
		bool itemfound = false;
		int itemIndex = 0;
		if (IsEmpty()) {
			throw ListUnderflow();
		}

		if (*item == list[size - 1]) {
			list[size - 1] = NULL;
			itemfound = true;
		}
		else {
			for (int i = 0; i < size; i++) {
				if (*item == list[i]) {
					itemfound = true;
					itemIndex = i;
					for (int j = itemIndex; j < size - 1; j++) {
						list[j] = list[j+1];
					}
					list[size - 1] = NULL;
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
			list[i] = NULL;
		size = 0;
	}

	void PrintList() {
		for (int i = 0; i < size; i++) {
			/*cout << list[i] << " ";*/
		}
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