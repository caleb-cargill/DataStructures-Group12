#pragma once
#include <exception>
#include <string>

using namespace std;

class QueueOfInts {
private:
	static const int MAX_SIZE = 10;
	int data[MAX_SIZE];
	int back = 0;
	int front = 0;
	int size = 0;
public:
	void Enqueue(int inVal) {
		if (!isFull())
		{
			data[back] = inVal;
			back = (back + 1) % MAX_SIZE;
			size++;
		}
		else
			throw new QueueOverflow();
	}

	int Dequeue() {
		if (!isEmpty())
		{
			int retVal = data[front];
			front = (front + 1) % MAX_SIZE;
			size--;
			return retVal;
		}
		else
			throw new QueueUnderflow();
	}

	int Peek() {
		if (!isEmpty())
			return data[front];
		else
			throw new QueueUnderflow();
	}

	int Length() {
		return size;
	}

	bool isFull() {
		return size == MAX_SIZE;
	}

	bool isEmpty() {
		return size == 0;
	}

	void MakeEmpty() {
		size = 0;
		back = front;
	}

	class QueueOverflow : public exception {
	public: 
		string msg = "The queue is full.";
	};

	class QueueUnderflow : public exception {
	public: 
		string msg = "The queue is empty.";
	};

};