#pragma once
#include "BaseList.h"

using namespace std;

template <class T> 
class MiddleIndexList : public BaseList<T>
{
protected:
	int MAX_SIZE = 25;
	int size = 0;
	int lowerIndex = 0;
	int higherIndex = 0;

public:
	MiddleIndexList() : BaseList<T>(){

	}

	~MiddleIndexList() {
		BaseList<T>::MakeEmpty();
	}

	// adds item at correct location
	void AddItem(T& inVal) {
		int itemIndex = 0;
		if (this->IsFull()) {
			throw BaseList<T>::ListOverflow();
		}

		// If list is empty, start in middle
		if (BaseList<T>::size == 0) {
			BaseList<T>::list[BaseList<T>::MAX_SIZE / 2] = new T(inVal);
			BaseList<T>::size++;
			lowerIndex = BaseList<T>::MAX_SIZE / 2;
			higherIndex = lowerIndex;
			return;
		}
		else {
			// If inVal is smaller or equal to the smallest value in the list and the first index in the list is not 0, then add inVal to the beginning of the list
			if (*BaseList<T>::list[lowerIndex] >= inVal && lowerIndex > 0) {
				BaseList<T>::list[lowerIndex - 1] = new T(inVal);
				lowerIndex--;
			}
			// If inVal is greater than or equal to the biggest value in the list and the last index in the list is not at the furthest right, then add inVal to the end
			else if (*BaseList<T>::list[higherIndex] <= inVal && higherIndex < BaseList<T>::MAX_SIZE - 1) {
				BaseList<T>::list[higherIndex + 1] = new T(inVal);
				higherIndex++;
			}
			// If inVal is less than the middle value, go left
			// If left side is at the first index, shift right first
			else if (inVal < *BaseList<T>::list[BaseList<T>::MAX_SIZE / 2]) {
				if (lowerIndex == 0) {
					for (int i = higherIndex; i > 0; i--) {
						BaseList<T>::list[i + 1] = BaseList<T>::list[i];
					}
					lowerIndex++;
					higherIndex++;
					BaseList<T>::list[0] = nullptr;
				}
				for (int i = BaseList<T>::MAX_SIZE / 2 - 1; i > 0; i--) {
					if (inVal >= *BaseList<T>::list[i]) {
						itemIndex = i;
						for (int j = lowerIndex - 1; j < itemIndex; j++) {
							BaseList<T>::list[j] = BaseList<T>::list[j + 1];
						}
						BaseList<T>::list[itemIndex] = new T(inVal);
						break;
					}
				}
				lowerIndex--;
			}
			// If inVal is greater than or equal to the middle value, go right
			// If right side is at the max index, shift left first
			else if (inVal >= *BaseList<T>::list[BaseList<T>::MAX_SIZE / 2]) {
				if (higherIndex == BaseList<T>::MAX_SIZE - 1) {
					for (int i = 0; i < BaseList<T>::MAX_SIZE - 1; i++) {
						BaseList<T>::list[i] = BaseList<T>::list[i + 1];
					}
					lowerIndex--;
					higherIndex--;
					BaseList<T>::list[BaseList<T>::MAX_SIZE - 1] = nullptr;
				}
				for (int i = BaseList<T>::MAX_SIZE / 2; i < BaseList<T>::MAX_SIZE - 1; i++) {
					if (inVal <= *BaseList<T>::list[i]) {
						itemIndex = i;
						for (int j = higherIndex + 1; j > itemIndex; j--) {
							BaseList<T>::list[j] = BaseList<T>::list[j - 1];
						}
						BaseList<T>::list[itemIndex] = new T(inVal);
						break;
					}
				}
				higherIndex++;
			}
		}
		BaseList<T>::size++;
	}

	// removes specified item
	T RemoveItem(T& item) {
		bool itemfound = false;
		int itemIndex = 0;
		if (this->IsEmpty()) {
			throw BaseList<T>::ListUnderflow();
		}

		if (item == *BaseList<T>::list[higherIndex]) {
			delete BaseList<T>::list[higherIndex];
			itemfound = true;
		}
		else {
			for (int i = lowerIndex; i < higherIndex; i++) {
				if (item == *BaseList<T>::list[i]) {
					itemfound = true;
					itemIndex = i;
					delete BaseList<T>::list[itemIndex];
					for (int j = itemIndex; j < higherIndex; j++) {
						BaseList<T>::list[j] = BaseList<T>::list[j + 1];
					}
					BaseList<T>::list[higherIndex] = nullptr;
					higherIndex--;
					break;
				}
			}
		}

		if (!itemfound) {
			throw BaseList<T>::ItemNotFound();
		}
		BaseList<T>::size--;
	}

	// Empties the list, starts from lowerIndex and goes to loq
	void MakeEmpty() {
		for (int i = lowerIndex; i < lowerIndex + BaseList<T>::size; i++)
			delete BaseList<T>::list[i];
		BaseList<T>::size = 0;
	}

	void PrintListPointers() {
		cout << "Pointer array" << endl;
		for (int i = lowerIndex; i < lowerIndex + BaseList<T>::size; i++) {
			cout << BaseList<T>::list[i] << " ";
		}
		cout << endl << endl;
	}

	void PrintListValues() {
		cout << "Pointer array values" << endl;
		for (int i = lowerIndex; i < lowerIndex + BaseList<T>::size; i++) {
			cout << *BaseList<T>::list[i] << " ";
		}
		cout << endl << endl;
	}

};
