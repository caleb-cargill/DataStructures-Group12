#pragma once
#include "LinkedList.h"

using namespace std;

template<class T> class Deck {
private:
	LinkedList<T> list;
	int size = 0;
public:
	void Enqueue(T inVal) {
		list.Insert(inVal);
		size++;
	}

	T Dequeue() {
		if (!isEmpty())
		{
			size--;
			return list.RemoveFirst();
		}
		else
			throw QueueUnderflow();
	}

	T Peek() {
		if (!isEmpty())
			return list.GetHead();
		else
			throw QueueUnderflow();
	}

	int Length() {
		return size;
	}

	bool isEmpty() {
		return size == 0;
	}

	void MakeEmpty() {
		list.MakeEmpty();
	}

	class QueueUnderflow : public exception {
	public:
		string msg = "The queue is empty.";
	};

};
