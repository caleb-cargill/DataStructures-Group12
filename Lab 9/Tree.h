#pragma once
#include <exception>
#include <iostream>

using namespace std;

template <class T>
class Tree {

private:
	struct Node {
		T data;
		Node* left;
		Node* right;

		Node(T val) {
			data = val;
			left = nullptr;
			right = nullptr;
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
		// Destructor - make sure there are no leaks
	}

	// Inserts a new node into the tree with the selected value
	// If the value is already in the tree, it throws an exception
	// Keeps the tree balanced when adding new nodes
	void Insert(T value) {
		Node* newNode = new Node(value);
		if (root == nullptr) {
			root = newNode;
			nodeCount++;
			PrintTree(root);
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
		}
		else {
			curr->right = newNode;
		}
		nodeCount++;
		PrintTree(root);
	}

	// Returns a pointer to the node with the desired value
	// Throws an exception if the value is not found in the tree
	T* Find(T key) {
		if (root->data == key) {
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
		throw ItemNotFound;
	}

	// Returns the number of nodes in the tree
	int Size() {
		return nodeCount;
	}

	// Returns a pointer to an array of the nodes in order from smallest to largest
	T* GetAllAscending() {
		
	}

	// Returns a pointer to an array of the nodes in order from largest to smallest
	T* GetAllDescending() {

	}

	// Removes all nodes from the tree
	void EmptyTree() {

	}

	// Returns the node from the tree with the selected value
	// If there is not a node with the selected value, it will throw an exception
	// Removes the node from the tree with the selected value
	// Keeps the tree balanced when removing nodes
	T Remove(T key) {
		Node* temp = root;
		// While temp is not the parent of the key node
		while ((temp->left != nullptr && key < temp->data) || (temp->right != nullptr & key > temp->data)) {
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
			}
			else { // Removing node with 1 child
				if (delNode->left != nullptr) { // Child on left
					temp->left = delNode->left;
				}
				else { // Child on right
					temp->left = delNode->right;
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
			}
			else { // Removing node with 1 child
				if (delNode->left != nullptr) { // Child on left
					temp->right = delNode->left;
				}
				else { // Child on right
					temp->right = delNode->right;
				}
				delete delNode;
			}
		}
		else {
			//throw ItemNotFound;
		}
		PrintTree(root);
		nodeCount--;
		return retVal;
	}

	// Prints contents of the tree for testing purposes
	void PrintTree(Node* curr) {
		if (curr == nullptr) {
			return;
		}
		PrintTree(curr->left);
		// node (left, right), node (left, right), ......
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
			cout << curr->data << " (" << curr->left->data << ", " << curr->right->data << ") | "; // node (left, right), node (left, right), ......
		} 
		PrintTree(curr->right);		
	}

	// Rotates right around a pivot
	void RotateRight(Node* grandparent, Node* parent) { 
		Node* pivot = parent->right;
		if (grandparent == nullptr) { // No grandparent
			root = pivot;
			parent->left = pivot->right;
			pivot->right = parent;
		}
		else if (grandparent->data > pivot->data) { // Grandparent on the right
			grandparent->right = pivot;
			parent->left = pivot->right;
			pivot->right = parent;
		}
		else if (grandparent->data < pivot->data) { // Grandparent on the left
			grandparent->left = pivot;
			parent->left = pivot->right;
			pivot->right = parent;
		}
	}

	// Rotates left around a pivot
	void RotateLeft(Node* grandparent, Node* parent) {
		Node* pivot = parent->left;
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

	class ItemInTree : public exception {
	public:
		string Message = "The item is already in the tree";
	};

	class ItemNotFound : public exception {
	public:
		string Message = "The item is not in the tree";
	};

};