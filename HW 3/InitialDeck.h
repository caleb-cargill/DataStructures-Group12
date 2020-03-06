#pragma once
#include "Card.h"

// Credit: http://www.cplusplus.com/forum/general/163824/ for inspiration on InitialDeck() and ShuffleDeck()

class InitialDeck {
private:
	const static int SIZE = 52; // Change deck size for testing to speed up the game
	string names[13] = { "A","2","3","4","5","6","7","8","9","10","J","Q","K"};
	Card deck[SIZE];

public:
	// Creates the deck in order
	InitialDeck() {
		for (int i = 0; i < SIZE; i++) {
			deck[i] = Card(names[i % 13]);
		}
	}

	// Shuffles the deck randomly
	void ShuffleDeck() {
		for (int i = 0; i < SIZE; i++) {
			int randI = rand() % SIZE;
			Card tempCard = deck[i];
			deck[i] = deck[randI];
			deck[randI] = tempCard;
		}
	}

	int getSize() {
		return SIZE;
	}

	Card getCard(int i) {
		return deck[i];
	}
};