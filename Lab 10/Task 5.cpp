#include "Hash.h"
#include "ChainedHashTable.h"
#include "Item.h"
#include <time.h>

using namespace std;

void AddSKUs(int arr[], int size);

int main() {
	ChainedHashTable<Item> chainedHashTable;
	HashTable<Item> linearHashTable;

	// Randomly seeds rand()
	srand(time(0));

	// Create an array for the randomly generated SKU values
	const static int arraySize = 50;
	int SKUvalues[arraySize];
	AddSKUs(SKUvalues, arraySize);

	int chainedHashComparisons = 0;
	int linearHashComparisons = 0;
	
	// Add items into the two tables and calls GetItem() on the added items
	for (int i = 0; i < arraySize; i++) {
		chainedHashTable.AddItem(new Item(SKUvalues[i], "", 0.0, ""));
		chainedHashTable.GetItem(new Item(SKUvalues[i], "", 0.0, ""));
		linearHashTable.AddItem(new Item(SKUvalues[i], "", 0.0, ""));
		linearHashTable.GetItem(new Item(SKUvalues[i], "", 0.0, ""));
	}

	cout << "Chained Hash Table Comparisons: " << chainedHashTable.GetComparisons() << endl << endl;
	cout << "Linear Hash Table Comparisons: " << linearHashTable.GetComparisons() << endl << endl;

	return 0;
}

// Adds randomly generated ints to arr - generates SKU values
void AddSKUs(int arr[], int size) {
	for (int i = 0; i < size; i++) {
		arr[i] = (int)rand();
	}
}