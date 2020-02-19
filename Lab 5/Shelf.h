#pragma once
#include <exception>
#include "BoardGame.h"

using namespace std;

class Shelf {
private:
	static const int MAX_SIZE = 10;
	BoardGame games[MAX_SIZE];
	int top = 0; // first open spot
public:
	Shelf(); // Default constructor

	// Function definition to put an item on the stack
	void Push(BoardGame inVal);

	// Function definition to remove the last item from the stack (top item) and return it to caller
	BoardGame Pop();

	// Shows the top item in the stack without removing it
	BoardGame Peek();

	// Shows the number of items in the stack
	int Length() {
		return top;
	}

	// Returns boolean stating whether the stack is full
	bool isFull();

	// Returns boolean stating whether the stack is empty
	bool isEmpty();

	// Empties out the stack
	void MakeEmpty();

	// Returns the capacity of the stack
	int GetCapacity();

	// Exception for when the stack is full
	class FullShelf :public exception {
	public:
		string Message = "The shelf is full";
	};

	// Exception for when the stack is empty
	class EmptyShelf :public exception {
	public:
		string Message = "The shelf is empty";
	};
};




