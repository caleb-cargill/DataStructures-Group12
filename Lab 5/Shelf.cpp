#include "Shelf.h"
#include "BoardGame.h"

using namespace std;

Shelf::Shelf() {
	top = 0;
}

void Shelf::Push(BoardGame inVal) {
	if (!isFull()) {
		games[top] = inVal;
		top++;
	}
	else {
		throw FullShelf(); // make this a specific exception (stack over flow exception)
	}
}

BoardGame Shelf::Pop() {
	if (!isEmpty()) {
		top--;
		return games[top];
	}
	throw EmptyShelf(); // make this a specific exception (stack under flow exception)
}

BoardGame Shelf::Peek() {
	if (!isEmpty())
		return games[top - 1];
	throw EmptyShelf(); // make this a specific exception (stack under flow exception)
}

bool Shelf::isFull() {
	return top == MAX_SIZE;
}

bool Shelf::isEmpty() {
	return top == 0;
}

void Shelf::MakeEmpty() {
	top = 0;
}

int Shelf::GetCapacity() {
	return MAX_SIZE - top;
}
