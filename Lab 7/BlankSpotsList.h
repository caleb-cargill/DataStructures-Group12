
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
		if (BaseList<T>::IsFull()) {
			throw BaseList<T>::ListOverflow();
		}

		if (BaseList<T>::size == 0) {
			BaseList<T>::list[0] = new T(inVal);
			BaseList<T>::size++;
			return;
		}

		for (int i = 0; i < BaseList<T>::size; i++) {
			if (i == 0 && BaseList<T>::size > 1  && *BaseList<T>::list[i + 1] <= inVal) {
				if (BaseList<T>::list[i] == nullptr) {
					BaseList<T>::list[i] = &inVal;
					replacedNull = true;
				}
				else {
					itemIndex = i;
				}
				biggestItem = false;
				break;
			}
			else if (BaseList<T>::list[i] == nullptr && *BaseList<T>::list[i + 1] >= inVal && *BaseList<T>::list[i - 1] <= inVal) {
				BaseList<T>::list[i] = &inVal;
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
			BaseList<T>::list[BaseList<T>::size] = new T(inVal);
		}
		else if (!replacedNull) {
			for (int j = BaseList<T>::size; j > itemIndex; j--) {
				BaseList<T>::list[j] = BaseList<T>::list[j - 1];
			}
			BaseList<T>::list[itemIndex] = new T(inVal);
		}
		BaseList<T>::size++;

	}

	T RemoveItem(T& item) {
		bool itemfound = false;
		if (BaseList<T>::IsEmpty()) {
			throw BaseList<T>::ListUnderflow();
		}

		for (int i = 0; i < BaseList<T>::size; i++) {
			if (item == *BaseList<T>::list[i]) {
				itemfound = true;
				delete BaseList<T>::list[i];
				BaseList<T>::list[i] = nullptr;
				break;
			}
		}

		if (!itemfound) {
			throw BaseList<T>::ItemNotFound();
		}
		BaseList<T>::size--;
	}

};
