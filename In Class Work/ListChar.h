#include "NodeChar.h"
#include <exception>
#pragma once

class ListChar {
private:
	NodeChar* head;
	int size = 0;

public:
	void Insert(char letter) {
		NodeChar* newNode = new NodeChar;
		newNode->data = letter;
		newNode->next = head;
		head = newNode;
		size++;
	}

	char Remove(char key) {
		if (head == nullptr)
		{
			// throw exception
		}

		NodeChar* temp;
		char retVal;
		if (head->data == key) {
			temp = head->next;
			head = head->next;
			retVal = temp->data;
			delete temp;
			size--;
			return retVal;
		}

		temp = head;
		while (temp->next != nullptr && temp->next->data != key) {
			temp = temp->next;
		}

		if (temp->next == nullptr)
		{
			// throw an exception
		}

		NodeChar* del = temp->next;
		retVal = temp->next->data;
		temp->next = temp->next->next;
		delete del;
		size--;
		return retVal;
	}

	int Length() {
		return size;
	}

	void MakeEmpty() {
		
	}
};