#include "Player.h"

Player::Player() {
	balance = 1000;
}

Player::Player(int initialBalance, int wheelRange) {
	balance = initialBalance;
	wheel.setRange(wheelRange);
}