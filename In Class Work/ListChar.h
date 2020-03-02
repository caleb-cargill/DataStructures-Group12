#include "NodeChar.h"
#include <exception>
#pragma once

// Linked list of chars
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
		NodeChar* temp = head;
		while (temp != nullptr) {
			temp = temp->next;
			delete head;
			head = temp;
		}
	}
};

// Double linked list of chars
class DListChar {
private:
	DNodeChar* head;
	int size = 0;

public:
	void Insert(char letter) {
		DNodeChar* newNode = new DNodeChar;
		newNode->data = letter;
		if (head == nullptr)
		{
			head = newNode;
			size++;
			return;
		}
		newNode->next = head;
		head->prev = newNode;
		head = newNode;
		size++;
	}

	// not updated for double
	char Remove(char key) {
		if (head == nullptr)
		{
			// throw exception
		}

		DNodeChar* temp;
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

		DNodeChar* del = temp->next;
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
		DNodeChar* temp = head;
		while (temp != nullptr) {
			temp = temp->next;
			delete head;
			head = temp;
		}
	}
};

// ordered link list of chars
class OrderedListChar {
private:
	NodeChar* head;
	int size;
public:
	void Insert(char val) {
		NodeChar* newNode = new NodeChar();
		newNode->data = val;
		if (head == nullptr) {
			head = newNode;
			return;
		}
		if (newNode->data < head->data)
		{
			newNode->next = head;
			head = newNode;
			return;
		}

		NodeChar* temp = head;
		while (temp->next != nullptr && temp->next->data < newNode->data) {
			temp = temp->next;
		}


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
		NodeChar* temp = head;
		while (temp != nullptr) {
			temp = temp->next;
			delete head;
			head = temp;
		}
	}
};

// Circular Double linked list of chars
class CircularDListChar {
private:
	DNodeChar* head;
	int size = 0;

public:
	void Insert(char letter) {
		DNodeChar* newNode = new DNodeChar;
		newNode->data = letter;
		if (head == nullptr)
		{
			head = newNode;
			head->next = head; // only one item, should point at itself for circular
			head->prev = head;
			size++;
			return;
		}
		newNode->next = head;
		head->prev->next = newNode;
		newNode->prev = head->prev;
		head->prev = newNode;
		head = newNode;
		size++;
	}

	// not updated for circular or double
	char Remove(char key) {
		if (head == nullptr)
		{
			// throw exception
		}

		DNodeChar* temp;
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

		DNodeChar* del = temp->next;
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
		DNodeChar* temp = head;
		while (temp != nullptr) {
			temp = temp->next;
			delete head;
			head = temp;
		}
	}
};