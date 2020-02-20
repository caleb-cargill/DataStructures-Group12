#include "HardWheel.h"
#include <stdlib.h> // srand() and rand()
#include <time.h> // time()

// Default constructor, initializes range to 10
HardWheel::HardWheel() {
	range = 10;
	winstreak = 0;
}

// Takes the playerScore and then gets a random int between 1 and range
// If the house loses, the range increases one and the winstreak is reset to 0
// If the house wins, it will increase the winstreak by one
// If winstreak gets to two and the range isn't already equal to the player's wheel range then it will decrease the range by one and reset the winstreak to 0
// Return the house score
int HardWheel::Spin(int playerScore) {
	srand(time(0));
	int retScore = rand() % range + 1;
	if (playerScore > retScore) {
		setRange(range + 1);
		winstreak = 0;
	}
	else {
		winstreak += 1;
	}

	if (winstreak >= 2 && range > minRange) {
		setRange(range - 1);
		winstreak = 0;
	}
	return retScore;
}