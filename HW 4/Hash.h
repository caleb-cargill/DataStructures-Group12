#pragma once
#include <string>
#include <iostream>

using namespace std;

template <class T>
class HashTable {
protected:
	const static int arraySize = 500;
	T* table[arraySize];
	int itemCount = 0;

	// Returns the modulo of the int and the array size
	int Hash(T input) {
		return input % arraySize;
	}

public:
	// Sets all values in the array to nulltpr
	HashTable() {
		for (int i = 0; i < arraySize; i++) {
			table[i] = nullptr;
		}
	}

	// Deletes all the pointers in the array and sets them to nullptr
	~HashTable() {
		for (int i = 0; i < arraySize; i++) {
			delete table[i];
			table[i] = nullptr;
		}
	}

	// Adds an item to the array
	// Doesn't do anything if the array is full
	// Returns the number of spots checked when adding an item
	int AddItem(T* item) {
		int comparisonCount = 0;
		int hashIndex = Hash(*item); // Assigns hash value to item
		if (table[hashIndex] == nullptr) { // If the assigned spot in the array is empty, it will add the item
			table[hashIndex] = item;
			comparisonCount++;
		}
		else if (itemCount < arraySize) { // If the array is not full, it will look for the next open spot in the array and then add it when it finds one
			while (table[hashIndex] != nullptr) {
				hashIndex++;
				hashIndex %= arraySize;
				comparisonCount++;
			}
			table[hashIndex] = item;
		}
		else {
			return comparisonCount;
		}
		itemCount++;
		return comparisonCount;
	}

	// Removes an item from the array
	// Returns the number of spots checked to remove the item
	int RemoveItem(T* item) {
		int comparisonCount = 0;
		int hashIndex = Hash(*item); // Assigns hash value to item
		if (table[hashIndex] != nullptr && *table[hashIndex] == *item) { // If item is in hash table at it's hash index
			delete table[hashIndex];
			table[hashIndex] = nullptr;
			itemCount--;
			comparisonCount++;
			return comparisonCount;
		}
		else { // If not in hash index spot, look through the rest of the hash table to see if it is in the table
			for (int i = 0; i < arraySize - 1; i++) {
				hashIndex++;
				hashIndex %= arraySize;
				comparisonCount++;
				if (table[hashIndex] != nullptr && *table[hashIndex] == *item) {
					delete table[hashIndex];
					table[hashIndex] = nullptr;
					itemCount--;
				}
			}
			return comparisonCount;
		}
	}

	// Returns the number of spots checked to find an item
	int Find(T* item) {
		int comparisonCount = 0;
		int hashIndex = Hash(string(*item));
		if (table[hashIndex] != nullptr && *table[hashIndex] == *item) { // If item is in hash table at it's hash index
			comparisonCount++;
		}
		else { // If not in hash index spot, look through the rest of the hash table
			for (int i = 0; i < arraySize - 1; i++) {
				hashIndex++;
				hashIndex %= arraySize;
				comparisonCount++;
				if (table[hashIndex] != nullptr && *table[hashIndex] == *item) {
					break;
				}
			}
		}
		return comparisonCount;
	}

	// Returns the amount of items in the hash table
	int GetLength() {
		return itemCount;
	}

	// Prints the contents of the hash table in a readible manner
	void Print() {
		cout << endl;
		for (int i = 0; i < arraySize; i++) {
			cout << i + 1 << ": ";
			if (table[i] == nullptr) {
				cout << "-empty-" << endl;
			}
			else {
				cout << *table[i] << endl;
			}
		}
	}

};