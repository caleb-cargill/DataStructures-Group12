#include "EntertainmentCollection.h"

using namespace std;

template <class T>
EntertainmentCollection<T>::EntertainmentCollection() {
	top = 0;
}

template <class T>
void EntertainmentCollection<T>::Push(T inVal) {
	if (!isFull()) {
		shelf[top] = inVal;
		top++;
	}
	else {
		throw FullShelf(); 
	}
}

template <class T>
T EntertainmentCollection<T>::Pop() {
	if (!isEmpty()) {
		top--;
		return shelf[top];
	}
	throw EmptyShelf(); 
}

template <class T>
T EntertainmentCollection<T>::Peek() {
	if (!isEmpty())
		return shelf[top - 1];
	throw EmptyShelf(); 
}

template <class T>
bool EntertainmentCollection<T>::isFull() {
	return top == MAX_SIZE;
}

template <class T>
bool EntertainmentCollection<T>::isEmpty() {
	return top == 0;
}

template <class T>
void EntertainmentCollection<T>::MakeEmpty() {
	top = 0;
}

template <class T>
int EntertainmentCollection<T>::GetCapacity() {
	return MAX_SIZE - top;
}
