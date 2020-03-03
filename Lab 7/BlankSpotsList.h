#pragma once
#include "BaseList.h"
#include <iostream>

template <class T> class BlankSpotsList : public BaseList<T> {
protected:
	int MAX_SIZE = 25;
	int size = 0;
public:

	// This is the default constructor.
	BlankSpotsList() : BaseList<T>() {

	}

	//This is to add items to the middle of the list
	void AddItem(T& inVal) {

		int itemIndex = 0;
		bool biggestItem = true;
		bool replacedNull = false;
		if (IsFull()) {
			throw ListOverflow();
		}

		if (size == 0) {
			list[0] = new T(inVal);
			size++;
			return;
		}

		for (int i = 0; i < size; i++) {
			if (i == 0 && *list[i + 1] <= inVal) {
				if (list[i] == nullptr) {
					list[i] = inVal;
					replacedNull = true;
				}
				else {
					itemIndex = i;
				}
				biggestItem = false;
				break;
			}
			else if (list[i] == nullptr && *list[i + 1] >= inVal && *list[i - 1] <= inVal) {
				list[i] = inVal;
				replacedNull = true;
				biggestItem = false;
				break;
			}
			else {
				itemIndex = i;
				break;
			}
		}

		if (biggestItem) {
			list[size] = new T(inVal);
		}
		else if(!replacedNull) {
			for (int j = size; j > itemIndex; j--) {
				list[j] = list[j - 1];
			}
			list[itemIndex] = new T(inVal);
		}
		size++;

	}

	T RemoveItem(T& item) {
		bool itemfound = false;
		if (IsEmpty()) {
			throw ListUnderflow();
		}

		for (int i = 0; i < size; i++) {
			if (item == *list[i]) {
				itemfound = true;
				list[i] = nullptr;
				break;
			}
		}

		if (!itemfound) {
			throw ItemNotFound();
		}
		size--;
	}

};