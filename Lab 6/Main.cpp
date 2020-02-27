#include "TowerStack.h"
#include "TowerQueue.h"

#include <fstream>
#include <iostream>

using namespace std;

void reverseString();

int main() {
	//// Testing stack

	//int x1 = 1;
	//int x2 = 2;
	//int x3 = 3;
	//int* x1ptr = &x1;
	//int* x2ptr = &x2;
	//int* x3ptr = &x3;
	//TowerStack<int>* stack = new TowerStack<int>(10);
	//TowerQueue<int>* queue = new TowerQueue<int>(10);

	//stack->Push(x1ptr);
	//stack->Push(x2ptr);
	//stack->Push(x3ptr);
	//int itrlen = stack->Length();
	//for (int i = 0; i < itrlen; i++) {
	//	int* x = stack->Pop();
	//	cout << *x << endl;
	//	queue->Enqueue(x);
	//  delete x;
	//}

	//cout << endl;

	//for (int i = 0; i < itrlen; ++i) {
	//	int* x = queue->Dequeue();

	//	cout << *x << endl;
	
	//  delete x;

	//}

	//cout << endl;

	reverseString();

	//delete stack;
	//delete queue;
}



// Read text from a file, reverse the order and display to the user
void reverseString() {
	fstream text;
	text.open("NewFile.txt", ios::in);
	string lines;

	while (!text.eof())
	{
		string temp;
		getline(text, temp);
		lines = lines + temp;
		lines += '\n';
	}

	string reverseLines;
	int len = lines.size();
	TowerStack<char>* stackF = new TowerStack<char>(len);
	TowerQueue<char>* queueF = new TowerQueue<char>(len);

	for (int i = 0; i < len; ++i) {
		char c = lines.at(i);
		char* cptr = &c;
		stackF->Push(cptr);
	}

	for (int i = 0; i < len; ++i) {
		char* c = stackF->Pop();
		queueF->Enqueue(c);
	}

	for (int i = 0; i < len; ++i) {
		char* c = queueF->Dequeue();
		cout << *c;
	}
	//fo

	cout << endl;

	delete stackF;
	delete queueF;
}