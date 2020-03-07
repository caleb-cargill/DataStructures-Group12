#pragma once
#include <cstddef>


class Node {
public: 
	int data;
	Node* left;
	Node* right;

	Node(int d);
};

class Tree {
private:
	Node* root = nullptr;
public: 
	void AddNode(int d) {
		Node* nn = new Node(d);
		if (root == nullptr){
			root = nn;
			return;
		}
		Node* curr = root;
		while ((curr->left != nullptr && d < curr->data) || (curr->right != nullptr && d >= curr->data)) {
			if (d < curr->data)
				curr = curr->left;
			else
				curr = curr->right;
		}

		if (d < curr->data)
			curr->left = nn;
		else
			curr->right = nn;
	}

	int Find(int key) {
		if (root->data == key) {
			return root->data;
		}
		Node* temp = root;

		while ((temp->left != nullptr && temp->data > key) || (temp->right != nullptr && temp->data < key)) {
			if (key < temp->data)
				temp = temp->left;
			else
				temp = temp->right;
		}

		if (temp->data == key)
			return temp->data;

		// throw item not found exception
	}

	int Remove(int key) {
		Node* temp = root;

		while ((temp->left != nullptr && temp->data > key) || (temp->right != nullptr && temp->data < key)) {
			if (temp->left->data == key || temp->right->data == key)
				break;

			if (key < temp->data)
				temp = temp->left;
			else if (key > temp->data)
				temp = temp->right;
		}

		int retval;
		if (temp->data > key)
		{
			retval = temp->left->data;
			delete temp->left;
			temp->left = nullptr;
		}
		else {
			retval = temp->right->data;
			delete temp->right;
			temp->right = nullptr;
		}

		return retval;
	}

	void Print() {

	}
};