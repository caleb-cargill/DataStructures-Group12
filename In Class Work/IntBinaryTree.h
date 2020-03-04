#pragma once


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
};