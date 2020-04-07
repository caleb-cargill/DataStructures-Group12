#pragma once
#include <string>
#include <iostream>

using namespace std;

template <class T>
class HashTable {
private:
	const static int arraySize = 5;
	T* table[arraySize];
	int itemCount = 0;

	int Hash(string input) {
		int hashValue = 0;
		for (int c = 0; c < input.size(); c++) {
			hashValue += input[c];
		}
		return hashValue % arraySize;
	}

public:
	HashTable() {
		for (int i = 0; i < arraySize; i++) {
			table[i] = nullptr;
		}
	}

	~HashTable() {
		for (int i = 0; i < arraySize; i++) {
			delete table[i];
			table[i] = nullptr;
		}
	}

	void AddItem(T* item) {
		int hashIndex = Hash(string(*item));
		if (table[hashIndex] == nullptr) {
			table[hashIndex] = item;
		}
		else if (itemCount < arraySize){
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

	T* RemoveItem(T* item) {
		int hashIndex = Hash(string(*item));
		if (table[hashIndex] != nullptr && *table[hashIndex] == *item) { // If item is in hash table at it's hash index
			T* temp = table[hashIndex];
			delete table[hashIndex];
			table[hashIndex] = nullptr;
			itemCount--;
			return temp;
		}
		else { // If not in hash index spot, look through the rest of the hash table
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

	T* GetItem(T* item) {
		int hashIndex = Hash(string(*item));
		if (table[hashIndex] != nullptr && *table[hashIndex] == *item) { // If item is in hash table at it's hash index
			return item;
		}
		else { // If not in hash index spot, look through the rest of the hash table
			for (int i = 0; i < arraySize - 1; i++) {
				hashIndex++;
				hashIndex %= arraySize;
				if (table[hashIndex] != nullptr && *table[hashIndex] == *item) {
					return item;
				}
			}
			return nullptr;
		}
	}

	int GetLength() {
		return itemCount;
	}

	void Print() {
		for (int i = 0; i < arraySize; i++) {
			if (table[i] == nullptr) {
				cout << "-empty-, ";
			}
			else {
				cout << *table[i] << ", ";
			}
		}
	}

};