#include "Wheel.h"
#include <stdlib.h> // srand() and rand()
#include <time.h> // time()
using namespace std;

// Definition of default constructor, sets range to 10
Wheel::Wheel() {
	range = 10;
}

// Definition of constructor accepting an argument to set the range
Wheel::Wheel(int newRange) {
	range = newRange;
}


// Returns a random int between 1 and range
int Wheel::Spin() {
	srand(time(0));
	return rand() % range + 1;
}