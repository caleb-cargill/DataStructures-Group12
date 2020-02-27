#pragma once
#include <exception>
#include <string>

using namespace std;

template<class T> class TowerStack {
private:
	int MAX_SIZE = 5;
	T *stack;
	int top = 0; // first open spot
public:
	TowerStack() {
		stack = new T[MAX_SIZE];
	}

	TowerStack(int arraySize) {
		top = 0;
		MAX_SIZE = arraySize;
		stack = new T[MAX_SIZE];
	}; // Default constructor

	~TowerStack() {
		delete stack;
	}

	// Function definition to put an item on the stack
	void Push(T *inVal) {
		if (!isFull()) {
			stack[top] = *inVal;
			top++;
		}
		else
			throw FullStack();
	};

	// Function definition to remove the last item from the stack (top item) and return it to caller
	T *Pop() {
		if (!isEmpty()) {
			top--;
			return &stack[top];
		}
		throw EmptyStack();
	};

	// Shows the top item in the stack without removing it
	T *Peek() {
		if (!isEmpty())
			return stack[top - 1];
		throw EmptyStack();
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
		for (int i = 0; i < Length(); i++)
			delete stack[i];
		top = 0;
	};

	// Returns the capacity of the stack
	int GetCapacity() {
		return MAX_SIZE - top;
	};

	// Exception for when the stack is full
	class FullStack :public exception {
	public:
		string msg = "The stack is full";
	};

	// Exception for when the stack is empty
	class EmptyStack :public exception {
	public:
		string msg = "The stack is empty";
	};
};
