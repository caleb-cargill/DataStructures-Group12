#pragma once
#include "BaseList.h"
#include <iostream>

template <class T> class MiddleList : public BaseList<T> {
protected:
	int MAX_SIZE = 25;
	int size = 0;
	int front = 12;
	int back = 12;
public:

	// This is the default constructor.
	MiddleList() : BaseList<T>() {

	}

	//This is to add items to the middle of the list
	void AddItem(T* inVal) {
		if (IsFull()) {
			throw ListOverflow();
		}

		if (size == 0) {
			list[front] = *inVal;
		}

		for (int i = 0; i < size; i++) {
			if (i == 0 && list[i] > * inVal) {
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
			else if (list[i] < *inVal && list[i + 1] >* inVal) {
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
};
