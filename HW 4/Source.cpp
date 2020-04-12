#include<iostream>
#include "HashHead.h"

using namespace std;


int main(){

Table hashList;

int collide;

int userInput;

int Quit = 1;

while (Quit != 0) {
	cout << "Enter the number ";
	cin >> userInput;
	cout << endl;
	collide = hashList.insert(userInput);
	cout << "So far we have " << collide <<" collisions" << endl;
	cout << "Press 0 to quit or 1 to continue" << endl;
	cin >> Quit;

}
Quit = 1;
while (Quit != 0) {
	cout << "Which number would you like to find?" << endl;
	cin >> userInput;
	int x = hashList.find(userInput);
	if (x >= 500) {
		cout << "The number is not in the array try again." << endl;
	}
	else {
		cout << "It took this many spots to find the number: " << x << endl;
	}

	cout << "Would you like to find another number? Press 0 if you want to exit" << endl;
	cin >> Quit;
	cout << endl;
}
Quit = 1;
while (Quit != 0) {
	cout << "Which number would you like to delete?" << endl;
	cin >> userInput;
	int x = hashList.remove(userInput);
	if (x >= 500) {
		cout << "The number is not in the array try again." << endl;
	}
	else {
		cout << "It took this many collisions to find the number: " << x << endl;
	}

	cout << "Would you like to delete another number? Press 0 if you want to exit" << endl;
	cin >> Quit;
	cout << endl;
}
Quit = 1;
while (Quit != 0) {

	hashList.Print();
	cout << "Would you like to Quit? " << endl;
	cin >> Quit;
}
return 0;
}

