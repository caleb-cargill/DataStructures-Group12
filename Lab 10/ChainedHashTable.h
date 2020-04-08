#pragma once
#include "Hash.h"
#include "LinkedList.h"

template <class T>
class ChainedHashTable : public HashTable<T> {
protected:
	LinkedList<T>* table[HashTable<T>::arraySize];

public:
	// Assigns each value in the array to a pointer to a linked list
	ChainedHashTable() {
		for (int i = 0; i < HashTable<T>::arraySize; i++) {
			table[i] = new LinkedList<T>;
		}
	}

	// Deletes all the pointers in the array and sets them to nullptr
	~ChainedHashTable() {
		for (int i = 0; i < HashTable<T>::arraySize; i++) {
			delete table[i];
			table[i] = nullptr;
		}
	}

	// Adds and item to the appropriate linked list in the hash table
	void AddItem(T* item) {
		int hashIndex = HashTable<T>::Hash(string(*item)); // Assigns hash value to item
		table[hashIndex]->AddItem(item); 
		HashTable<T>::itemCount++;
	}

	// Removes an item from the appropriate linked list in the hash table
	// If the item is not in the hash table, it returns nullptr
	T* RemoveItem(T* item) {
		int hashIndex = HashTable<T>::Hash(string(*item)); // Assigns hash value to item
		if (table[hashIndex]->IsInList(item) == false) { // If item is not in hash table
			return nullptr;
		}
		else { // If item is in hash table
			HashTable<T>::itemCount--;
			return &table[hashIndex]->GetItem(item);
		}
	}

	// Returns a pointer to the desired item
	// Returns nullptr if the item is not in the hash table
	T* GetItem(T* item) {
		int hashIndex = HashTable<T>::Hash(string(*item)); // Assigns hash value to item
		if (table[hashIndex]->IsInList(item) == false) { // If item is not in hash table
			HashTable<T>::comparisonCount++;
			return nullptr;
		}
		else { // If item is in hash table
			HashTable<T>::comparisonCount += table[hashIndex]->GetComparison();
			return table[hashIndex]->Find(item);
		}
	}

	// Prints hash table in readible format
	void Print() {
		cout << endl;
		for (int i = 0; i < HashTable<T>::arraySize; i++) {
			cout << i + 1 << ": ";
			table[i]->PrintList();
		}
	}


};