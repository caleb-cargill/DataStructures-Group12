#pragma once
#include <exception>
#include <string>

using namespace std;

template<class T> class EntertainmentCollection {
private:
	static const int MAX_SIZE = 10;
	T shelf[MAX_SIZE];
	int top = 0; // first open spot
public:
	EntertainmentCollection() {
		top = 0;
	}; // Default constructor

	// Function definition to put an item on the stack
	void Push(T inVal) {
		if (!isFull()) {
			shelf[top] = inVal;
			top++;
		}
		else 
			throw FullShelf();
	};

	// Function definition to remove the last item from the stack (top item) and return it to caller
	T Pop() {
		if (!isEmpty()) {
			top--;
			return shelf[top];
		}
		throw EmptyShelf();
	};

	// Shows the top item in the stack without removing it
	T Peek() {
		if (!isEmpty())
			return shelf[top - 1];
		throw EmptyShelf();
	};

	// Shows the number of items in the stack
	int Length() {
		return top;
	}

	// Returns boolean stating whether the stack is full
	bool isFull() {
		return top == MAX_SIZE;
	};

	// Returns boolean stating whether the stack is empty
	bool isEmpty() {
		return top == 0;
	};

	// Empties out the stack
	void MakeEmpty() {
		top = 0;
	};

	// Returns the capacity of the stack
	int GetCapacity() {
		return MAX_SIZE - top;
	};

	// Exception for when the stack is full
	class FullShelf :public exception {
	public:
		string msg = "The shelf is full";
	};

	// Exception for when the stack is empty
	class EmptyShelf :public exception {
	public:
		string msg = "The shelf is Empty";
	};
};
