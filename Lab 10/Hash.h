#pragma once
#include <string>
#include <iostream>

using namespace std;

template <class T>
class HashTable {
protected:
	const static int arraySize = 100;
	T* table[arraySize];
	int itemCount = 0;
	int comparisonCount = 0;

	// Outputs an int of the sum of all the ASCII values in the string characters and takes the modulus of the sum with the array size
	// This int is used as the hash value for added items
	// Requires the items to have string() overloaded if the item is not a string itself
	int Hash(string input) {
		int hashValue = 0;
		for (int c = 0; c < input.size(); c++) {
			hashValue += input[c];
		}
		return hashValue % arraySize;
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
	void AddItem(T* item) {
		int hashIndex = Hash(string(*item)); // Assigns hash value to item
		if (table[hashIndex] == nullptr) { // If the assigned spot in the array is empty, it will add the item
			table[hashIndex] = item;
		}
		else if (itemCount < arraySize){ // If the array is not full, it will look for the next open spot in the array and then add it when it finds one
			while (table[hashIndex] != nullptr) {
				hashIndex++;
				hashIndex %= arraySize;
			}
			table[hashIndex] = item;
		}
		else {
			return;
		}
		itemCount++;
	}

	// Removes an item from the array
	// Returns nullptr if the item is not in the hash table
	T* RemoveItem(T* item) {
		int hashIndex = Hash(string(*item)); // Assigns hash value to item
		if (table[hashIndex] != nullptr && *table[hashIndex] == *item) { // If item is in hash table at it's hash index
			T* temp = table[hashIndex];
			delete table[hashIndex];
			table[hashIndex] = nullptr;
			itemCount--;
			return temp;
		}
		else { // If not in hash index spot, look through the rest of the hash table to see if it is in the table
			for (int i = 0; i < arraySize - 1; i++) {
				hashIndex++;
				hashIndex %= arraySize;
				if (table[hashIndex] != nullptr && *table[hashIndex] == *item) {
					T* temp = table[hashIndex];
					delete table[hashIndex];
					table[hashIndex] = nullptr;
					itemCount--;
					return temp;
				}
			}
			return nullptr;
		}
	}

	// Returns a pointer to the item if it is in the hash table
	// Returns nullptr if the item is not in the hash table
	T* GetItem(T* item) {
		int hashIndex = Hash(string(*item));
		if (table[hashIndex] != nullptr && *table[hashIndex] == *item) { // If item is in hash table at it's hash index
			comparisonCount++;
			return item;
		}
		else { // If not in hash index spot, look through the rest of the hash table
			for (int i = 0; i < arraySize - 1; i++) {
				hashIndex++;
				hashIndex %= arraySize;
				comparisonCount++;
				if (table[hashIndex] != nullptr && *table[hashIndex] == *item) {
					return item;
				}
			}
			return nullptr;
		}
	}

	// Returns the amount of items in the hash table
	int GetLength() {
		return itemCount;
	}

	// Returns the number of comparisons when using GetItem()
	int GetComparisons() {
		return comparisonCount;
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