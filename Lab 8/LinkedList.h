#pragma once
#include <exception>
#include <iostream>

using namespace std;

template <class T> class Placeholder {

private:
	// Struct to act as a node for the list
	struct ListNode {
		T value;					// The value in this node
		ListNode* next;		// To point to the next node
		ListNode* prev;		// To point at the previous node

		ListNode(T *inVal) {
			value = *inVal;
			next = nullptr;
			prev = nullptr;
		}
	};

	ListNode* head; //list head pointer
	ListNode* curr; //list iterator pointer
	int size;
public:
	//constructor
	Placeholder()
	{
		head = nullptr;
		curr = head;
		size = 0;
	}

	//Destructor
	~Placeholder() {
		// Remove all the items from the list
		while (!IsEmpty())
		{
			T* tempVal = &head->value;
			GetItem(tempVal);
		}
		head = nullptr;
	}

	// overload of the > operator
	bool operator>(const T& rhs) {
		return this > rhs;
	}

	// overload of the < operator
	bool operator<(const T& rhs) {
		return this < rhs;
	}

	// overload of the == operator
	bool operator==(const T& rhs) {
		return this == rhs;
	}

	//Linked list operations

	// Add the item in the correct order
	void AddItem(T* inVal) {
		// Increment size
		size++;

		//Creates a node and gives it the input value
		ListNode* newNode = new ListNode(inVal);

		// If the list is empty, go ahead and add the item as the head and return
		if (head == nullptr)
		{
			//Head points to new Node 
			head = newNode;
			curr = head;
			return;
		}

		ListNode* temp = head;

		// Check the head value
		if (newNode->value < head->value) {
			newNode->prev = nullptr;
			newNode->next = temp;
			temp->prev = newNode;
			head = newNode;
			return;
		}

		// Iterate through the rest of the list
		while (temp->next != nullptr && temp->next->value < newNode->value) {
			temp = temp->next;
		}

		// Set connections
		if (temp->next != nullptr) {
			temp->next->prev = newNode;
			newNode->next = temp->next;

		}
		newNode->prev = temp;
		temp->next = newNode;

	}

	// if the provided item is in the list, remove it from the list and return the value
	T GetItem(T* key) {
		if (head == nullptr)
		{
			// Item is not in the list because the list is empty return NULL
			throw NotInList();
		}

		// Declare a temp node and a return value
		ListNode* temp;
		T retVal;

		// check to see if the first item is the one we want to remove
		if (head->value == *key) {
			// Check to see if the head is the curr
			if (curr == head)
			{
				retVal = head->value;
				curr = head->next;
			}

			if (head->next == nullptr)
			{
				retVal = head->value;
				delete head;
				head = nullptr;
			}
			else
			{
				// Store temp values
				temp = head;

				// Set the new head
				head = head->next;

				// get the return value
				retVal = temp->value;

				// delete the return pointer
				delete temp;
			}

			// decrement size
			size--;

			// return the value
			return retVal;
		}

		// Initialize temp as the head to begin checking
		temp = head;

		// Iterate through each item in list until we reach the end or the key is found
		while (temp->next != nullptr && !(temp->next->value == *key)) {
			temp = temp->next;
		}

		if (temp->next == nullptr)
		{
			// value is not in the list
			throw NotInList();
		}

		// Store the node to be deleted
		ListNode* del = temp->next;

		// Get the return value
		retVal = temp->next->value;

		// Set connections
		temp->next = temp->next->next;
		if (temp->next != nullptr)
			temp->next->prev = temp;

		// Check if we are deleting curr
		if (curr == del) {
			curr = temp;
		}

		// Delete the found value
		delete del;

		// Decrement the size
		size--;

		// Return the found value
		return retVal;
	}

	// Returns a boolean denoting whether the item is in the list or not
	bool IsInList(T* item) {
		// Make sure the head is not null
		if (head == nullptr)
		{
			// Item is not in the list because the list is empty return false
			return false;
		}

		// Declare a temp node and a return value
		ListNode* temp;

		// Check the head
		if (head->value == *item) {
			return true;
		}

		// Initialize temp as the head to begin checking
		temp = head;

		// Iterate through each item in list until we reach the end or the key is found
		while (temp->next != nullptr && !(temp->next->value == *item)) {
			temp = temp->next;
		}

		if (temp->next == nullptr)
		{
			// value is not in the list, return false
			return false;
		}

		return true;
	}

	// returns a boolean denoting whether the list is empty
	bool IsEmpty() {
		return size == 0;
	}

	// returns the size of the list
	int Size() {
		return size;
	}

	// Gets the next item in the list
	T SeeNext() {
		T retVal;
		if (IsEmpty()) {
			throw OutOfBounds();
		}
		else if (curr == nullptr) {
			return retVal;
		}
		else if (curr->next != nullptr) {
			retVal = curr->value;
			curr = curr->next;
		}
		else {
			retVal = curr->value;
		}
		return retVal;
	}

	// Gets the previous item in the list
	T SeePrev() {
		T retVal;
		if (IsEmpty()) {
			throw OutOfBounds();
		}
		else if (curr == nullptr) {
			return retVal;
		}
		else if (curr->prev != nullptr) {
			retVal = curr->value;
			curr = curr->prev;
		}
		else {
			retVal = curr->value;
		}
		return retVal;
	}

	// Gets the item at the specified index
	T SeeAt(int index) {
		T retVal;
		ListNode* temp = head;
		if (IsEmpty() || index >= size) {
			throw OutOfBounds();
		}
		for (int i = 0; i < index; i++) {
			temp = temp->next;
		}
		retVal = temp->value;
		curr = temp;
		return retVal;
	}

	// Resets the current spot of the list
	void Reset() {
		curr = head;
	}

	void PrintList() {
		ListNode* temp = head;
		if (size == 0) {
			cout << endl;
		}
		else if (size == 1) {
			cout << "|" << temp->value.GetPartInfo() << "|" << endl;
		}
		else {
			for (int i = 0; i < size - 1; i++) {
				cout << "|" << temp->value.GetPartInfo() << "| -> ";
				temp = temp->next;
			}
			cout << "|" << temp->value.GetPartInfo() << "|" << endl;
		}
	}

	class OutOfBounds : public exception {
	public:
		string Message = "The operation is out of range of the list";
	};

	class NotInList : public exception {
	public:
		string Message = "The item is not in the list";
	};
};