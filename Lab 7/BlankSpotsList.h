
#pragma once
#include "BaseList.h"
#include <iostream>

template <class T> class BlankSpotsList : public BaseList<T> {
protected:
	int MAX_SIZE = 500;
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
		if (BaseList<T>::IsFull()) {
			throw BaseList<T>::ListOverflow();
		}

		if (BaseList<T>::size == 0) {
			BaseList<T>::list[0] = new T(inVal);
			BaseList<T>::size++;
			return;
		}

		for (int i = 0; i < BaseList<T>::size; i++) {
			if (i == 0 && BaseList<T>::size > 1  && *BaseList<T>::list[i + 1] >= inVal) {
				BaseList<T>::compareCount++;
				if (BaseList<T>::list[i] == nullptr) {
					BaseList<T>::list[i] = &inVal;
					replacedNull = true;
					break;
				}
				else if (*BaseList<T>::list[i] >= inVal) {
					BaseList<T>::compareCount++;
					itemIndex = i;
					break;
				}
				biggestItem = false;
				
			}
			/*else if (BaseList<T>::list[i]) {

			}*/
			else if (BaseList<T>::list[i] == nullptr && *BaseList<T>::list[i + 1] >= inVal && *BaseList<T>::list[i - 1] <= inVal) {
				BaseList<T>::compareCount++;
				BaseList<T>::list[i] = &inVal;
				replacedNull = true;
				biggestItem = false;
				break;
			}
			else if(*BaseList<T>::list[i] >= inVal){
				BaseList<T>::compareCount++;
				itemIndex = i;
				biggestItem = false;
				break;
			}
		}

		if (biggestItem) {
			BaseList<T>::list[BaseList<T>::size] = new T(inVal);
		}
		else if (!replacedNull) {
			for (int j = BaseList<T>::size; j > itemIndex - 1; j--) {
				BaseList<T>::moveCount++;
				BaseList<T>::list[j] = BaseList<T>::list[j - 1];
			}
			BaseList<T>::list[itemIndex] = new T(inVal);
		}
		BaseList<T>::size++;

	}

	// Removes the specified item from the list
	T RemoveItem(T& item) {
		bool itemfound = false;
		if (BaseList<T>::IsEmpty()) {
			throw BaseList<T>::ListUnderflow();
		}

		int s = BaseList<T>::size;

		for (int i = 0; i < s; i++) {
			if (BaseList<T>::list[i] != nullptr) {
				BaseList<T>::compareCount++;
				if (item == *BaseList<T>::list[i]) {
					itemfound = true;
					delete BaseList<T>::list[i];
					BaseList<T>::list[i] = nullptr;
					break;
				}
			}
			else {
				s += 1;
			}
		}

		if (!itemfound) {
			throw BaseList<T>::ItemNotFound();
		}
		BaseList<T>::size--;
	}

};
