#pragma once
#include <exception>
using namespace std;

class StackOfInts {
private:
	static const int MAX_SIZE = 5;
	int nums[MAX_SIZE];
	int top = 0; // first open spot
public:
	// Function definition to put an item on the stack
	void Push(int inVal) {
		if (!isFull()) {
			nums[top] = inVal;
			top++;
		}
		else {
			throw new exception(); // make this a specific exception (stack over flow exception)
		}
	}

	// Function definition to remove the last item from the stack (top item) and return it to caller
	int Pop() {
		if (!isEmpty()) {
			top--;
			return nums[top];
		}
		throw new exception(); // make this a specific exception (stack under flow exception)
	}

	// Shows the top item in the stack without removing it
	int Peek() {
		if (!isEmpty())
			return nums[top - 1];
		throw new exception(); // make this a specific exception (stack under flow exception)
	}

	// Shows the number of items in the stack
	int Length() {
		return top;
	}

	// Returns boolean stating whether the stack is full
	bool isFull() {
		return top == MAX_SIZE;
	}

	// Returns boolean stating whether the stack is empty
	bool isEmpty() {
		return top == 0;
	}

	// Empties out the stack
	void MakeEmpty() {
		top = 0;
	}

	// Returns the capacity of the stack
	int GetCapacity() {
		return MAX_SIZE - top;
	}
};
