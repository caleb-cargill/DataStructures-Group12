#include "Wheel.h"
#include <stdlib.h> // srand() and rand()
#include <time.h> // time()
using namespace std;

Wheel::Wheel() {
	range = 10;
}

Wheel::Wheel(int newRange) {
	range = newRange;
}


// Returns a random int between 1 and range
int Wheel::Spin() {
	srand(time(0));
	return rand() % range + 1;
}