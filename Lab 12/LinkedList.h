#pragma once
#include <exception>
#include <iostream>

using namespace std;

class LinkedList {

public:
	// Struct for node items
	struct Student {
		string mNumber, fName, lName;
	};

	// Struct to act as a node for the list
	struct ListNode {
		Student value;		// The value in this node
		ListNode* next;		// To point to the next node
		ListNode* prev;		// To point at the previous node

		ListNode(Student* inVal) {
			value = *inVal;
			next = nullptr;
			prev = nullptr;
		}
	};

	ListNode* head; //list head pointer
	ListNode* curr; //list iterator pointer
	int size;

	//constructor
	LinkedList()
	{
		head = nullptr;
		curr = head;
		size = 0;
	}

	//Destructor
	~LinkedList() {
		// Remove all the items from the list
		while (!IsEmpty())
		{
			Student* tempVal = &head->value;
			GetItem(tempVal);
		}
		head = nullptr;
	}

	//Linked list operations

	// Add the item in the correct order
	void AddItem(Student* inVal) {
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

		// Iterate through the rest of the list
		while (temp->next != nullptr) {
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
	Student GetItem(Student* key) {
		if (head == nullptr)
		{
			// Item is not in the list because the list is empty return NULL
			throw NotInList();
		}

		// Declare a temp node and a return value
		ListNode* temp;
		Student retVal;

		// check to see if the first item is the one we want to remove
		if (head->value.mNumber == key->mNumber) {
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
		while (temp->next != nullptr && !(temp->next->value.mNumber == key->mNumber)) {
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
	bool IsInList(Student* item) {
		// Make sure the head is not null
		if (head == nullptr)
		{
			// Item is not in the list because the list is empty return false
			return false;
		}

		// Declare a temp node and a return value
		ListNode* temp;

		// Check the head
		if (head->value.mNumber == item->mNumber) {
			return true;
		}

		// Initialize temp as the head to begin checking
		temp = head;

		// Iterate through each item in list until we reach the end or the key is found
		while (temp->next != nullptr && !(temp->next->value.mNumber == item->mNumber)) {
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
	Student SeeNext() {
		Student retVal;
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
	Student SeePrev() {
		Student retVal;
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
	Student SeeAt(int index) {
		Student retVal;
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

	// swaps data for two nodes in a linked list
	void swapNodes(ListNode* firstNode, ListNode* secondNode) {
		Student temp = firstNode->value;
		firstNode->value = secondNode->value;
		secondNode->value = temp;
	}

	// Sorts the linked list using a bubble sort
	void bubbleSort(bool ascending = true) {
		ListNode* temp1 = head;
		while (temp1 != nullptr && temp1->next != nullptr) {
			ListNode* temp2 = head;
			while (temp2 != nullptr && temp2->next != nullptr) {
				if (ascending) {
					if (temp2->value.fName > temp2->next->value.fName) {
						swapNodes(temp2, temp2->next);
					}
				}
				else {
					if (temp2->value.fName < temp2->next->value.fName) {
						swapNodes(temp2, temp2->next);
					}
				}
				temp2 = temp2->next;
			}
			temp1 = temp1->next;
		}
	}

	// Sorts the linked list using an insertion sort
	void insertionSort(bool ascending = true) {
		ListNode* temp1 = head;
		while (temp1 != nullptr) {
			Student key = temp1->value;
			ListNode* temp2 = temp1->prev;
			if (ascending) {
				while (temp2 != nullptr && key.lName < temp2->value.lName) {
					swapNodes(temp2, temp2->next);
					temp2 = temp2->prev;
				}
			}
			else {
				while (temp2 != nullptr && key.lName > temp2->value.lName) {
					swapNodes(temp2, temp2->next);
					temp2 = temp2->prev;
				}
			}
			if (temp2 != nullptr && temp2->next != nullptr)
				temp2->next->value = key;
			temp1 = temp1->next;
		}
	}

	ListNode* lastNode(ListNode* head) {
		while (head != nullptr && head->next != nullptr) head = head->next;
		return head;
	}

	void quickSort(bool ascending = true) {
		ListNode* last = lastNode(head);

		recQuickSort(ascending, head, last);
	}

	// Sorts the linked list using a radix sort
	void recQuickSort(bool ascending, ListNode* left, ListNode* right) {
		if (right != nullptr && left != right && left != right->next) {
			ListNode* pivot = setPivot(ascending, left, right);
			recQuickSort(ascending, left, pivot->prev);
			recQuickSort(ascending, pivot->next, right);
		}
	}

	ListNode* setPivot(bool ascending, ListNode* left, ListNode* right) {
		Student stud = right->value;

		ListNode* temp = left->prev;
		ListNode* temp2 = left;
		while (temp2 != right && temp2 != nullptr) {
			if (ascending) {
				if (temp2->value.mNumber <= stud.mNumber)
				{
					temp = (temp == nullptr) ? left : temp->next;
					swapNodes(temp, temp2);
				}
			}
			else {
				if (temp2->value.mNumber >= stud.mNumber)
				{
					temp = (temp == nullptr) ? left : temp->next;
					swapNodes(temp, temp2);
				}
			}
			temp2 = temp2->next;
		}

		temp = (temp == nullptr) ? left : temp->next;
		swapNodes(temp, right);
		return temp;
	}

	void PrintList() {
		ListNode* temp = head;
		if (size == 0) {
			cout << endl;
		}
		else if (size == 1) {
			if (temp != nullptr)
				cout << "| " << temp->value.lName << ", " << temp->value.fName << " (" << temp->value.mNumber << ") " << "|" << endl;
		}
		else {
			for (int i = 0; i < size - 1; i++) {
				if (temp != nullptr) {
					cout << "| " << temp->value.lName << ", " << temp->value.fName << " (" << temp->value.mNumber << ") " << "| -> " << endl;
					temp = temp->next;
				}
			}
			if (temp != nullptr)
				cout << "| " << temp->value.lName << ", " << temp->value.fName << " (" << temp->value.mNumber << ") " << "|" << endl;
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