#pragma once
#include <iostream>
#include <cstdlib>

#ifndef HashHead // include guard
#define Hashhead

using namespace std;
const int SIZE = 500;


class Table {
private:	

	int Hash[SIZE];

	int* ptr[SIZE] = {};
	
public:
	Table(){

	}

	//~Table(){}

	int insert(int key) {
		//Checks to see if the spot in the hash table is true
		bool hashFull = true;
		//Counter for the amount of collisions
		int fullHash = 0;

		int hashIndex = 0;

		//This determines the location of the variable in the list for the hash tree
		hashIndex = key % SIZE;

		while (hashFull) {

			if (ptr[hashIndex] != nullptr) {
				//Pushes the key to a location that is not full.
				++hashIndex;
				++fullHash;
			}

			else {
				//inserts the key into the location when the hash table is not full.
				Hash[hashIndex] = key;


				ptr[hashIndex] = &Hash[hashIndex];
				
				//Exists the loop once the key has been inserted
				hashFull = false;
			}

		}
		return fullHash + 1;
	}

	int find(int key) {
		int i;
		int hashIndex = key % SIZE;
		int collisions = 0;

		//If the collisions exceede the array then the p

		while (Hash[hashIndex] != key || collisions == 500 - key) {
			//Iterating the index, and increasing the collisions
			hashIndex++;

			collisions++;

		}
		if (collisions >= 500) {
			cout << " Data not found" << endl;
		}

		return collisions;

	}

	int remove(int key) {
		//Checks to see if the spot in the hash table is true
		bool hashFull = true;
		//Counter for the amount of collisions
		int fullHash = 0;

		int hashIndex = 0;

		//This determines the location of the variable in the list for the hash tree
		hashIndex = key % SIZE;

		while (hashFull) {

			if (ptr[hashIndex] != nullptr || Hash[hashIndex] == key) {
				//Pushes the key to a location that is not full.
				++hashIndex;
				++fullHash;
			}

			else {
				//Deletes the key 
				delete ptr[hashIndex];
				ptr[hashIndex] = nullptr;


				//Exits the loop once the key has been inserted
				hashFull = false;
			}

		}
		return fullHash + 1;
	}

	void Print() {
		int i = 0;
		while (i != 500) {
			if (ptr[i] == nullptr) {
				++i;

				cout << " This is empty" << endl;
			}
			else {
				++i;
				cout << Hash[i] << endl;
			}
		}
	}
};






#endif  