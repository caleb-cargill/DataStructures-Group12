#include "ComplexCalc.h"
#include <stdlib.h>

double getXCoordinate();
double getYCoordinate();
double getScalar();
char getOperator();

// Testing class
int main()
{
	double x, y, scalar;
	double X, Y, SCALAR;
	char op;
	char OP;
	char cont = 'y';
	ComplexCalc firstComplexNum;
	ComplexCalc secondComplexNum;

	// get initial x and y coordinates from the user
	x = getXCoordinate();
	y = getYCoordinate();

	// set initial x and y coordinates
	firstComplexNum.set_cartesianA(x);
	firstComplexNum.set_cartesianBi(y);

	while (cont == 'y') // perform loop until the user says to stop
	{
		op = getOperator();

		switch (op) {
		case '+':
		{
			x = getXCoordinate();
			y = getYCoordinate();

			secondComplexNum.set_cartesianA(x);
			secondComplexNum.set_cartesianBi(y);

			firstComplexNum + secondComplexNum; // overloaded addition

			firstComplexNum.Print();
		}
		break;
		case '-':
		{
			x = getXCoordinate();
			y = getYCoordinate();

			secondComplexNum.set_cartesianA(x);
			secondComplexNum.set_cartesianBi(y);

			firstComplexNum - secondComplexNum; // overloaded subtraction

			firstComplexNum.Print();
		}
		break;
		case '*':
		{
			scalar = getScalar();
			cout << endl;

			firstComplexNum*scalar; // overloaded multiplication

			firstComplexNum.Print();
		}
		break;
		case '/':
		{
			scalar = getScalar();
			cout << endl;

			firstComplexNum / scalar; // overloaded division

			firstComplexNum.Print();
		}
		break;
		case '=':
		{
			x = getXCoordinate();
			y = getYCoordinate();

			secondComplexNum.set_cartesianA(x);
			secondComplexNum.set_cartesianBi(y);			

			if (firstComplexNum == secondComplexNum) // overloaded == 
			{
				cout << "The two complex numbers are equal" << endl << endl;
			}
			else
			{
				cout << "The two complex numbers are not equal" << endl << endl;
			}
		}
		break;
		default:
		{
			cout << "Not a valid input" << endl << endl;
		}
		break;
		}

		// ask the user if the would like to continue
		cout << "Continue? (y for yes, any other character for no): ";
		cin >> cont;

		// reset the console
		system("CLS");
	}
}

// function to prompt the user for an X Coordinate
double getXCoordinate() {
	double X;
	cout << "Enter an 'x' value for the complex number: ";
	cin >> X;
	while (!cin >>int(X)) { // continue to ask if they gave an invalid input
		cout << endl;
		cin.clear();
		cin.ignore(100000, '\n');

		cout << "Not a valid input. Try again." << endl;
		cout << "Enter an 'x' value for the complex number: ";
		cin >> X;
	}
	cout << endl;
	return X;
}

// function to prompt the user for an Y Coordinate
double getYCoordinate() {
	double Y;
	cout << "Enter an 'y' value for the complex number: ";
	cin >> Y;
	while (!cin >> int(Y)) { // continue to ask if they gave an invalid input
		cout << endl;
		cin.clear();
		cin.ignore(100000, '\n');

		cout << "Not a valid input. Try again." << endl;
		cout << "Enter an 'y' value for the complex number: ";
		cin >> Y;
	}
	cout << endl;
	return Y;
}

// function to prompt the user to select an operation to perform
char getOperator() {
	char OP;
	cout << "Which operation would you like to perform? " << endl;
	cout << "Enter '+' for addition" << endl;
	cout << "Enter '-' for subtraction" << endl;
	cout << "Enter '*' for multiplication" << endl;
	cout << "Enter '/' for division" << endl;
	cout << "Enter '=' to compare" << endl << endl;
	cout << "Operation: ";
	cin >> OP;
	cout << endl;

	while (!cin >> OP) { // continue to ask if they gave an invalid input
		cout << endl;
		cin.clear();
		cin.ignore(100000, '\n');

		cout << "Not a valid input. Try again." << endl;
		cout << "Enter an 'y' value for the complex number: ";	cout << "Which operation would you like to perform? " << endl;
		cout << "Enter '+' for addition" << endl;
		cout << "Enter '-' for subtraction" << endl;
		cout << "Enter '*' for multiplication" << endl;
		cout << "Enter '/' for division" << endl;
		cout << "Enter '=' to compare" << endl << endl;
		cout << "Operation: ";
		cin >> OP;
	}
	cout << endl;
	return OP;
}	

// function to prompt the user for a scalar to use to multiply / divide
double getScalar() {
	int SCALAR;
	cout << "Enter an scalar integer to divide by: ";
	cin >> SCALAR;
	
	while (!cin >> SCALAR) { // continue to ask if they gave an invalid input
		cout << endl;
		cin.clear();
		cin.ignore(100000, '\n');

		cout << "Not a valid input. Try again." << endl;
		cout << "Enter an scalar integer to divide by: ";
		cin >> SCALAR;
	}

	return SCALAR;
}