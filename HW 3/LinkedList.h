#pragma once
#include <exception>
#include <string>

using namespace std;

template <class T>
class node {
public:
	T data;
	node* next;

	node(T dataVal) {
		data = dataVal;
		next = nullptr;
	}
};

template <class T>
class LinkedList {
private:
	node<T>* head;
public:
	LinkedList() {
		head = nullptr;
	}

	// Points head to newNode if empty, else puts the new node at the end and has teh previous node point to it
	void Insert(T inVal) {
		node<T>* newNode = new node<T>(inVal);
		if (head == nullptr) {
			head = newNode;
		}
		else {
			node<T>* temp = head;
			while (temp->next != nullptr) {
				temp = temp->next;
			}
			temp->next = newNode;
		}
	}

	// Removes the first item in the list, aka what the head is pointing too and then points the head to the next value if there is one
	T RemoveFirst() {
		T retVal = head->data;
		if (head->next != nullptr) {
			node<T>* temp = head;
			head = head->next;
			delete temp;
		}
		else {
			delete head;
			head = nullptr;
		}
		return retVal;
	}

	T GetHead() {
		if (head != nullptr) {
			return head->data;
		}
	}

	void MakeEmpty() {
		node* temp = head;
		while (temp != nullptr) {
			temp = temp->next;
			delete head;
			head = temp;
		}
	}


	class NotFound : public exception {
	public:
		string msg = "The item is not in the list.";
	};
};