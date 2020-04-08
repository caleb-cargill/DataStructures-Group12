#include "Hash.h"
#include "Tree.h"
#include <time.h>

using namespace std;

void AddRandomInts(int arr[], int size);

int main() {
	HashTable<int> hashTable;
	Tree<int> tree;

	// Randomly seeds rand()
	srand(time(0));

	// Create an array for the randomly generated int values
	const static int arraySize = 100;
	int intValues[arraySize];
	AddRandomInts(intValues, arraySize);

	int hashTableSpotsChecked = 0;
	int treeSpotsChecked = 0;

	// Adds first 50 ints into the tree and hash table
	for (int i = 0; i < arraySize / 2; i++) {
		hashTableSpotsChecked += hashTable.AddItem(new int(intValues[i]));
		treeSpotsChecked += tree.Insert(intValues[i]);
	}

	cout << "Number of spots checked after adding the first 50 values" << endl << endl;
	cout << "Hash Table: " << hashTableSpotsChecked << endl;
	cout << "Binary Tree: " << treeSpotsChecked << endl << endl;

	// Reset count values
	hashTableSpotsChecked = 0;
	treeSpotsChecked = 0;

	// Remove i % 7 == 0 values
	for (int i = 0; i < arraySize; i++) {
		if (i % 7 == 0) {
			hashTableSpotsChecked += hashTable.RemoveItem(new int(intValues[i]));
			tree.Remove(intValues[i]);
			treeSpotsChecked += tree.RemoveCount();
		}
	}

	cout << "Number of spots checked after removing i % 7 == 0 values" << endl << endl;
	cout << "Hash Table: " << hashTableSpotsChecked << endl;
	cout << "Binary Tree: " << treeSpotsChecked << endl << endl;

	// Reset count values
	hashTableSpotsChecked = 0;
	treeSpotsChecked = 0;

	// Adds last 50 ints into the tree and hash table
	for (int i = arraySize / 2; i < arraySize; i++) {
		hashTableSpotsChecked += hashTable.AddItem(new int(intValues[i]));
		treeSpotsChecked += tree.Insert(intValues[i]);
	}

	cout << "Number of spots checked after adding the last 50 values" << endl << endl;
	cout << "Hash Table: " << hashTableSpotsChecked << endl;
	cout << "Binary Tree: " << treeSpotsChecked << endl << endl;

	// Reset count values
	hashTableSpotsChecked = 0;
	treeSpotsChecked = 0;

	// Remove i % 9 == 0 values
	for (int i = 0; i < arraySize; i++) {
		if (i % 9 == 0 && i % 7 != 0) {
			hashTableSpotsChecked += hashTable.RemoveItem(new int(intValues[i]));
			tree.Remove(intValues[i]);
			treeSpotsChecked += tree.RemoveCount();
		}
	}

	cout << "Number of spots checked after removing i % 9 == 0 values" << endl << endl;
	cout << "Hash Table: " << hashTableSpotsChecked << endl;
	cout << "Binary Tree: " << treeSpotsChecked << endl << endl;

	return 0;
}

// Adds randomly generated ints to arr between 1 - 100
void AddRandomInts(int arr[], int size) {
	for (int i = 0; i < size; i++) {
		arr[i] = (int)rand() % 100 + 1;
	}
}