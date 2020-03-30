#include "Tree.h"

using namespace std;

int main() {

	// Testing Binary Tree

	Tree<int> tree;

	cout << "Insert 5" << endl;
	tree.Insert(5);
	cout << endl << endl;

	cout << "Insert 2" << endl;
	tree.Insert(2);
	cout << endl << endl;

	cout << "Insert 8" << endl;
	tree.Insert(8);
	cout << endl << endl;

	cout << "Insert 3" << endl;
	tree.Insert(3);
	cout << endl << endl;

	cout << "Insert 1" << endl;
	tree.Insert(1);
	cout << endl << endl;

	cout << "Insert 4" << endl;
	tree.Insert(4);
	cout << endl << endl;

	cout << "Remove 2" << endl;
	tree.Remove(2);
	cout << endl << endl;

	return 0;
}