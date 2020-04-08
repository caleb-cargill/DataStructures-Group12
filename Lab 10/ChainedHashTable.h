#pragma once
#include "Hash.h"
#include "LinkedList.h"

template <class T>
class ChainedHashTable : public HashTable<T> {
protected:
	LinkedList<T>* table[HashTable<T>::arraySize];

public:
	ChainedHashTable() {
		for (int i = 0; i < HashTable<T>::arraySize; i++) {
			table[i] = new LinkedList<T>;
		}
	}

	~ChainedHashTable() {
		for (int i = 0; i < HashTable<T>::arraySize; i++) {
			delete table[i];
			table[i] = nullptr;
		}
	}

	void AddItem(T* item) {
		int hashIndex = HashTable<T>::Hash(string(*item));
		table[hashIndex]->AddItem(item);
		HashTable<T>::itemCount++;
	}

	T* RemoveItem(T* item) {
		int hashIndex = HashTable<T>::Hash(string(*item));
		if (table[hashIndex]->IsInList(item) == false) {
			return nullptr;
		}
		else {
			table[hashIndex]->GetItem(item);
			HashTable<T>::itemCount--;
		}
	}

	T* GetItem(T* item) {
		int hashIndex = HashTable<T>::Hash(string(*item));
		if (table[hashIndex]->IsInList(item) == false) {
			HashTable<T>::comparisonCount++;
			return nullptr;
		}
		else {
			HashTable<T>::comparisonCount += table[hashIndex]->GetComparison();
			return table[hashIndex]->Find(item);
		}
	}

	void Print() {
		for (int i = 0; i < HashTable<T>::arraySize; i++) {
			cout << endl;
			cout << i + 1 << ": ";
			table[i]->PrintList();
		}
	}


};