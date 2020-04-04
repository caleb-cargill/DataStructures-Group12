#pragma once
#include <exception>
#include <iostream>
#include <cstdlib>

using namespace std;

template <class T>
class Tree {

private:
	struct Node {
		T data;
		Node* left;
		Node* right;
		Node* parent;

		Node(T val) {
			data = val;
			left = nullptr;
			right = nullptr;
			parent = nullptr;
		}
	};
	
	Node* root;
	int nodeCount;

public:
	Tree() {
		root = nullptr;
		nodeCount = 0;
	}

	~Tree() {
		EmptyTree(root);
		root = nullptr;
	}

	// Inserts a new node into the tree with the selected value
	// If the value is already in the tree, it throws an exception
	// Keeps the tree balanced when adding new nodes
	void Insert(T value) {
		Node* newNode = new Node(value);
		if (root == nullptr) {
			root = newNode;
			nodeCount++;
			return;
		}
		if (Find(value) != nullptr) {
			return;
		}
		Node* curr = root;
		while ((curr->left != nullptr && value < curr->data) || (curr->right != nullptr && value >= curr->data)) {
			if (value < curr->data) {
				curr = curr->left;
			}
			else {
				curr = curr->right;
			}
		}
		if (value < curr->data) {
			curr->left = newNode;
			newNode->parent = curr;
		}
		else {
			curr->right = newNode;
			newNode->parent = curr;
		}
		nodeCount++;

		// Balancing section

		if (GetHeight(root) > 2) {
			BalanceTree(newNode);
		}
	}

	// Starts at a node and traverses up through its parents to check if it needs balancing
	// If so, it will balance appropriately
	void BalanceTree(Node* curr) {
		Node* grandparent = nullptr;
		Node* parent = nullptr;
		if (curr == nullptr) {
			return;
		}
		if (curr->parent != nullptr) {
			parent = curr->parent;
		}
		if (parent != nullptr && curr->parent->parent != nullptr) {
			grandparent = curr->parent->parent;
		}
		if (parent != nullptr && (abs(GetLeftHeight(parent) - GetRightHeight(parent))) >= 2) {
			if (curr->data > curr->parent->data) {
				RotateRight(grandparent, parent);
			}
			else {
				RotateLeft(grandparent, parent);
			}
		}
		else {
			BalanceTree(curr->parent);
		}
	}

	// Returns a pointer to the node with the desired value
	// Returns nullptr if the value is not found in the tree
	Node* Find(T key) {
		if (root != nullptr && root->data == key) {
			return root;
		}
		Node* temp = root;
		while ((temp->left != nullptr && key < temp->data) || (temp->right != nullptr & key > temp->data)) {
			if (key < temp->data) temp = temp->left;
			else temp = temp->right;
		}
		if (temp->data == key) {
			return temp;
		}
		else {
			return nullptr;
		}
	}

	// Returns the number of nodes in the tree
	int Size() {
		return nodeCount;
	}

	// Displays all the values of a subtree in ascending order
	void GetAllAscending(Node* curr) {
		if (curr == nullptr) {
			return;
		}
		GetAllAscending(curr->left);
		cout << curr->data << " ";
		GetAllAscending(curr->right);
	}

	// Displays all the values in the tree in ascending order
	void GetAllAscendingPrint() {
		if (root != nullptr) {
			GetAllAscending(root);
		}
	}

	// Displays all the values of a subtree in descending order
	void GetAllDescending(Node* curr) {
		if (curr == nullptr) {
			return;
		}
		GetAllDescending(curr->right);
		cout << curr->data << " ";
		GetAllDescending(curr->left);
	}

	// Displays all the values in the tree in descending order
	void GetAllDescendingPrint() {
		if (root != nullptr) {
			GetAllDescending(root);
		}
	}

	// Removes all nodes from a subtree
	void EmptyTree(Node* curr) {
		if (curr == nullptr) {
			return;
		}
		EmptyTree(curr->left);
		EmptyTree(curr->right);
		delete curr;
		nodeCount--;
	}

	// Removes all nodes from the whole tree
	void Empty() {
		if (root != nullptr) {
			EmptyTree(root);
		}
		root = nullptr;
	}

	// Returns the node from the tree with the selected value
	// If there is not a node with the selected value, it will throw an exception
	// Removes the node from the tree with the selected value
	// Keeps the tree balanced when removing nodes
	T Remove(T key) {
		Node* temp = root;
		// While temp is not the parent of the key node
		while (((temp->left != nullptr) && (key < temp->data)) || ((temp->right != nullptr) & (key > temp->data))) {
			if (key < temp->data && temp->left->data != key) temp = temp->left;
			else if (key > temp->data&& temp->right->data != key) temp = temp->right;
			else break;
		}
		T retVal;
		Node* delNode;
		if (temp->left != nullptr && temp->left->data == key) { // If the key node is on the left of the parent
			retVal = temp->left->data;
			delNode = temp->left;
			if (delNode->left == nullptr && delNode->right == nullptr) { // Removing leaf
				delete delNode;
				temp->left = nullptr;
			}
			else if (delNode->left != nullptr && delNode->right != nullptr) { // Removing node with 2 children
				delNode = delNode->right;
				while (delNode->left != nullptr) {
					delNode = delNode->left;
				}
				delNode = new Node(Remove(delNode->data));
				nodeCount++;
				delNode->left = temp->left->left;
				delNode->right = temp->left->right;
				delete temp->left;
				temp->left = delNode;
				delNode->left->parent = delNode;
				delNode->right->parent = delNode;
				delNode->parent = temp;
			}
			else { // Removing node with 1 child
				if (delNode->left != nullptr) { // Child on left
					temp->left = delNode->left;
					temp->left->parent = temp;
				}
				else { // Child on right
					temp->left = delNode->right;
					temp->left->parent = temp;
				}
				delete delNode;
			}
		}
		else if (temp->right != nullptr && temp->right->data == key){ // If the key node is on the right of the parent
			retVal = temp->right->data;
			delNode = temp->right;
			if (delNode->left == nullptr && delNode->right == nullptr) { // Removing leaf
				delete delNode;
				temp->right = nullptr;
			}
			else if (delNode->left != nullptr && delNode->right != nullptr) { // Removing node with 2 children
				delNode = delNode->right;
				while (delNode->left != nullptr) {
					delNode = delNode->left;
				}
				delNode = new Node(Remove(delNode->data));
				nodeCount++;
				delNode->left = temp->right->left;
				delNode->right = temp->right->right;
				delete temp->right;
				temp->right = delNode;
				delNode->left->parent = delNode;
				delNode->right->parent = delNode;
				delNode->parent = temp;
			}
			else { // Removing node with 1 child
				if (delNode->left != nullptr) { // Child on left
					temp->right = delNode->left;
					temp->right->parent = temp;
				}
				else { // Child on right
					temp->right = delNode->right;
					temp->right->parent = temp;
				}
				delete delNode;
			}
		}
		nodeCount--;

		// Balancing section
		Node* tempLeft = temp;
		Node* tempRight = temp;
		while (tempLeft->left != nullptr) {
			tempLeft = tempLeft->left;
		}
		while (tempRight->right != nullptr) {
			tempRight = tempRight->right;
		}
		BalanceTree(tempLeft); // Checks to see if the left of temp needs to be balanced
		BalanceTree(tempRight); // Checks to see if the right of temp needs to be balanced

		return retVal;
	}

	// Prints contents of a subtree for testing purposes
	void PrintTree(Node* curr) {
		if (curr == nullptr) {
			return;
		}
		PrintTree(curr->left);
		// node (left, right), node (left, right), ...... with nodes in ascending order
		if (curr->left == nullptr && curr->right == nullptr) {
			cout << curr->data << " ( , ) | ";
		}
		else if (curr->left == nullptr) {
			cout << curr->data << " ( , " << curr->right->data << ") |  ";
		}
		else if (curr->right == nullptr) {
			cout << curr->data << " (" << curr->left->data << ", ) | ";
		}
		else {
			cout << curr->data << " (" << curr->left->data << ", " << curr->right->data << ") | "; 
		} 
		PrintTree(curr->right);		
	}

	// Prints the whole tree for testing purposes
	void Print() {
		if (root != nullptr) {
			PrintTree(root);
		}
	}

	// Rotates left around a pivot
	void RotateLeft(Node* grandparent, Node* parent) { 
		Node* pivot = parent->left;
		if (grandparent == nullptr) { // No grandparent
			root = pivot;
			parent->left = pivot->right;
			pivot->right = parent;
		}
		else if (grandparent->data > pivot->data) { // Grandparent on the right
			grandparent->left = pivot;
			parent->left = pivot->right;
			pivot->right = parent;
		}
		else if (grandparent->data < pivot->data) { // Grandparent on the left
			grandparent->right = pivot;
			parent->left = pivot->right;
			pivot->right = parent;
		}
	}

	// Rotates right around a pivot
	void RotateRight(Node* grandparent, Node* parent) {
		Node* pivot = parent->right;
		if (grandparent == nullptr) { // No grandparent
			root = pivot;
			parent->right = pivot->left;
			pivot->left = parent;
		}
		else if (grandparent->data > pivot->data) { // Grandparent on the right
			grandparent->left = pivot;
			parent->right = pivot->left;
			pivot->left = parent;
		}
		else if (grandparent->data < pivot->data) { // Grandparent on the left
			grandparent->right = pivot;
			parent->right = pivot->left;
			pivot->left = parent;
		}

	}

	// Returns the height of a node - from Balance Trees 6.mp4
	int GetHeight(Node* temp) {
		if (temp == nullptr) return 0;
		int rheight = GetHeight(temp->right);
		int lheight = GetHeight(temp->left);
		if (rheight > lheight) return 1 + rheight;
		return 1 + lheight;
	}

	// Returns the left height of a node
	int GetLeftHeight(Node* temp) {
		if (temp->left == nullptr) return 0;
		return GetHeight(temp->left);
	}

	// Returns the right height of a node
	int GetRightHeight(Node* temp) {
		if (temp->right == nullptr) return 0;
		return GetHeight(temp->right);
	}
};
