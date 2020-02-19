#include "Player.h"

// Definition of default constructor for Player, setting balance to 1000
Player::Player() {
	balance = 1000;
}

// Definition of constructor accepting integer arguments for balance and wheel range
Player::Player(int initialBalance, int wheelRange) {
	balance = initialBalance;
	wheel.setRange(wheelRange);
}