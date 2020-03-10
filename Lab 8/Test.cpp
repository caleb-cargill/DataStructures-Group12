#include "LinkedList.h"
#include <iostream>

using namespace std;

int main() {
	Placeholder<int> list;

	cout << "Add 5" << endl;
	list.AddItem(new int(5));
	list.PrintList();
	cout << "Add 6" << endl;
	list.AddItem(new int(6));
	list.PrintList();
	cout << "Add 2" << endl;
	list.AddItem(new int(2));
	list.PrintList();
	
	cout << "Remove 5" << endl;
	int x = list.GetItem(new int (5));
	list.PrintList();

	int size = list.Size();

	cout << "Get Next: " << list.SeeNext() << endl;

	cout << "Get Prev: " << list.SeePrev() << endl;

	return 0;
}
