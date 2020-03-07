#include "Deck.h"
#include "Side.h"
#include "Card.h"
#include "InitialDeck.h"
#include <iostream>
#include <time.h>

using namespace std;

// Helper function declarations
void addToDecksStart(InitialDeck deck, Deck<Card> &player, Deck<Card> &computer);
bool getPeek();
char getSideDecision(Side<Card> playerSide, Deck<Card> playerDeck);
char getGameMode();
void displayNewStatus(Side<Card> playerSide, Deck<Card> playerDeck, Deck<Card> cpudeck);
int getNumRounds();

int main() {
	srand(time(0)); // Randomly seeds rand() based on current time
	
	// Game control variables
	bool gameover = false;
	bool peek = false;
	char sideDecision = ' ';
	char gamemode = ' ';
	int numRounds = 0;
	int round = 0;
	int playerWins = 0;
	int cpuWins = 0;

	// Card variables used for drawing from deck/side pile
	Card playerCard;
	Card playerSideCard;
	Card cpuCard;
	Card cpuSideCard;

	// Creates a deck which is an array of 52 card objects arranged like a typical deck
	// Shuffles the deck based on a random seed
	InitialDeck fullDeck;
	fullDeck.ShuffleDeck();

	// Deck and side pile variables
	Deck<Card> playerDeck;
	Deck<Card> cpuDeck;
	Side<Card> playerSide;
	Side<Card> cpuSide;
	Deck<Card> tiePile; // Used to queue cards if there is a tie

	// Initializes the player and cpu decks to a 26 random cards from the shuffled 52 card deck
	addToDecksStart(fullDeck, playerDeck, cpuDeck);

	// Gets game mode at start of game
	gamemode = getGameMode();
	system("CLS");

	// Game mode = Out Of Cards
	if (gamemode == '1') {
		cout << "You have chosen Out Of Cards mode" << endl << endl;
		while (!gameover) {
			if (playerDeck.Length() > 0) {
				peek = getPeek();
				system("CLS");
				// If the player wants to peek, it will take the top card off the deck and display its information
				if (peek) {
					playerCard = playerDeck.Dequeue();
					cout << "Your top card is a " << playerCard.getName() << endl << endl;
					sideDecision = getSideDecision(playerSide, playerDeck);
					system("CLS");
					// Put card on side pile
					// Play next card from deck
					if (sideDecision == '1') {
						playerSide.Push(playerCard);
						cout << "You put your " << playerCard.getName() << " in your side pile" << endl << endl;
						playerCard = playerDeck.Dequeue();
						cout << "You pulled a " << playerCard.getName() << " from your deck" << endl << endl;
						cpuCard = cpuDeck.Dequeue();
						cout << "Player put down a " << playerCard.getName() << " from their deck" << endl;
						cout << "CPU put down a " << cpuCard.getName() << endl << endl;
						// If there's a tie, it will keep playing cards until there's a winner
						while (playerCard.getValue() == cpuCard.getValue()) {
							tiePile.Enqueue(playerCard);
							tiePile.Enqueue(cpuCard);
							cout << "Tie." << endl << endl;
							if (playerDeck.Length() > 0 && cpuDeck.Length() > 0) {
								playerCard = playerDeck.Dequeue();
								cpuCard = cpuDeck.Dequeue();
								cout << "Player put down a " << playerCard.getName() << " from their deck" << endl;
								cout << "CPU put down a " << cpuCard.getName() << endl << endl;
							}
							else if (playerDeck.Length() == 0 && playerSide.Length() > 0 && cpuDeck.Length() > 0) {
								playerCard = playerSide.Pop();
								cpuCard = cpuDeck.Dequeue();
								cout << "Player put down a " << playerCard.getName() << " from their side pile" << endl;
								cout << "CPU put down a " << cpuCard.getName() << endl << endl;
							}
							else {
								cout << "Game over" << endl << endl;
								gameover = true;
								break;
							}
						}
						if (playerCard.getValue() > cpuCard.getValue()) {
							playerDeck.Enqueue(playerCard);
							playerDeck.Enqueue(cpuCard);
							for (int i = 0; i < tiePile.Length(); i++) {
								playerDeck.Enqueue(tiePile.Dequeue());
							}
							cout << "Player wins this round" << endl << endl;
						}
						else if (playerCard.getValue() < cpuCard.getValue()) {
							cpuDeck.Enqueue(playerCard);
							cpuDeck.Enqueue(cpuCard);
							for (int i = 0; i < tiePile.Length(); i++) {
								cpuDeck.Enqueue(tiePile.Dequeue());
							}
							cout << "Computer wins this round" << endl << endl; 
						}
						displayNewStatus(playerSide, playerDeck, cpuDeck);
					}
					// Pull card from side pile
					// Play with current card from deck
					else if (sideDecision == '2') {
						playerSideCard = playerSide.Pop();
						cout << "You pulled a " << playerSideCard.getName() << " from your side deck" << endl << endl;
						cpuCard = cpuDeck.Dequeue();
						cout << "Player put down a " << playerCard.getName() << " and a " << playerSideCard.getName() << endl;
						cout << "CPU put down a " << cpuCard.getName() << endl << endl;
						if (playerCard.getValue() + playerSideCard.getValue() > cpuCard.getValue()) {
							playerDeck.Enqueue(playerCard);
							playerDeck.Enqueue(playerSideCard);
							playerDeck.Enqueue(cpuCard);
							cout << "Player wins this round" << endl << endl;
						}
						else if (playerCard.getValue() + playerSideCard.getValue() <= cpuCard.getValue()) {
							cpuDeck.Enqueue(playerCard);
							cpuDeck.Enqueue(playerSideCard);
							cpuDeck.Enqueue(cpuCard);
							cout << "Computer wins this round" << endl << endl;
						}
						displayNewStatus(playerSide, playerDeck, cpuDeck);
					}
					// Play current card
					else if (sideDecision == '3') {
						cpuCard = cpuDeck.Dequeue();
						cout << "Player put down a " << playerCard.getName() << endl;
						cout << "CPU put down a " << cpuCard.getName() << endl << endl;
						// If there's a tie, it will keep playing cards until there's a winner
						while (playerCard.getValue() == cpuCard.getValue()) {
							tiePile.Enqueue(playerCard);
							tiePile.Enqueue(cpuCard);
							cout << "Tie." << endl << endl;
							if (playerDeck.Length() > 0 && cpuDeck.Length() > 0) {
								playerCard = playerDeck.Dequeue();
								cpuCard = cpuDeck.Dequeue();
								cout << "Player put down a " << playerCard.getName() << " from their deck" << endl;
								cout << "CPU put down a " << cpuCard.getName() << endl << endl;
							}
							else if (playerDeck.Length() == 0 && playerSide.Length() > 0 && cpuDeck.Length() > 0) {
								playerCard = playerSide.Pop();
								cpuCard = cpuDeck.Dequeue();
								cout << "Player put down a " << playerCard.getName() << " from their side pile" << endl;
								cout << "CPU put down a " << cpuCard.getName() << endl << endl;
							}
							else {
								cout << "Game over" << endl << endl;
								gameover = true;
								break;
							}
						}
						if (playerCard.getValue() > cpuCard.getValue()) {
							playerDeck.Enqueue(playerCard);
							playerDeck.Enqueue(cpuCard);
							for (int i = 0; i < tiePile.Length(); i++) {
								playerDeck.Enqueue(tiePile.Dequeue());
							}
							cout << "Player wins this round" << endl << endl;
						}
						else if (playerCard.getValue() < cpuCard.getValue()) {
							cpuDeck.Enqueue(playerCard);
							cpuDeck.Enqueue(cpuCard);
							for (int i = 0; i < tiePile.Length(); i++) {
								cpuDeck.Enqueue(tiePile.Dequeue());
							}
							cout << "Computer wins this round" << endl << endl;
						}
						displayNewStatus(playerSide, playerDeck, cpuDeck);
					}
				}
				// Plays top card from deck without peeking
				else {
					playerCard = playerDeck.Dequeue();
					cpuCard = cpuDeck.Dequeue();
					cout << "Player put down a " << playerCard.getName() << endl;
					cout << "CPU put down a " << cpuCard.getName() << endl << endl;
					// If there's a tie, it will keep playing cards until there's a winner
					while (playerCard.getValue() == cpuCard.getValue()) {
						tiePile.Enqueue(playerCard);
						tiePile.Enqueue(cpuCard);
						cout << "Tie." << endl << endl;
						if (playerDeck.Length() > 0 && cpuDeck.Length() > 0) {
							playerCard = playerDeck.Dequeue();
							cpuCard = cpuDeck.Dequeue();
							cout << "Player put down a " << playerCard.getName() << " from their deck" << endl;
							cout << "CPU put down a " << cpuCard.getName() << endl << endl;
						}
						else if (playerDeck.Length() == 0 && playerSide.Length() > 0 && cpuDeck.Length() > 0) {
							playerCard = playerSide.Pop();
							cpuCard = cpuDeck.Dequeue();
							cout << "Player put down a " << playerCard.getName() << " from their side pile" << endl;
							cout << "CPU put down a " << cpuCard.getName() << endl << endl;
						}
						else {
							cout << "Game over" << endl << endl;
							gameover = true;
							break;
						}
					}
					if (playerCard.getValue() > cpuCard.getValue()) {
						playerDeck.Enqueue(playerCard);
						playerDeck.Enqueue(cpuCard);
						for (int i = 0; i < tiePile.Length(); i++) {
							playerDeck.Enqueue(tiePile.Dequeue());
						}
						cout << "Player wins this round" << endl << endl;
					}
					else if (playerCard.getValue() < cpuCard.getValue()) {
						cpuDeck.Enqueue(playerCard);
						cpuDeck.Enqueue(cpuCard);
						for (int i = 0; i < tiePile.Length(); i++) {
							cpuDeck.Enqueue(tiePile.Dequeue());
						}
						cout << "Computer wins this round" << endl << endl;
					}
					displayNewStatus(playerSide, playerDeck, cpuDeck);
				}
			}
			// Player has to play from side pile because deck is empty
			else if (playerSide.Length() > 0) {
				playerCard = playerSide.Pop();
				cpuCard = cpuDeck.Dequeue();
				cout << "Player put down a " << playerCard.getName() << " from their side pile" << endl;
				cout << "CPU put down a " << cpuCard.getName() << endl << endl;
				// If there's a tie, it will keep playing cards until there's a winner
				while (playerCard.getValue() == cpuCard.getValue()) {
					tiePile.Enqueue(playerCard);
					tiePile.Enqueue(cpuCard);
					cout << "Tie." << endl << endl;
					playerCard = playerDeck.Dequeue();
					cpuCard = cpuDeck.Dequeue();
					if (playerDeck.Length() == 0 && playerSide.Length() > 0 && cpuDeck.Length() > 0) {
						playerCard = playerSide.Pop();
						cpuCard = cpuDeck.Dequeue();
						cout << "Player put down a " << playerCard.getName() << " from their side pile" << endl;
						cout << "CPU put down a " << cpuCard.getName() << endl << endl;
					}
					else {
						cout << "Game over" << endl << endl;
						gameover = true;
						break;
					}
				}
				if (playerCard.getValue() > cpuCard.getValue()) {
					playerDeck.Enqueue(playerCard);
					playerDeck.Enqueue(cpuCard);
					for (int i = 0; i < tiePile.Length(); i++) {
						playerDeck.Enqueue(tiePile.Dequeue());
					}
					cout << "Player wins this round" << endl << endl;
				}
				else if (playerCard.getValue() < cpuCard.getValue()) {
					cpuDeck.Enqueue(playerCard);
					cpuDeck.Enqueue(cpuCard);
					for (int i = 0; i < tiePile.Length(); i++) {
						cpuDeck.Enqueue(tiePile.Dequeue());
					}
					cout << "Computer wins this round" << endl << endl;
				}
				displayNewStatus(playerSide, playerDeck, cpuDeck);
			}

			// Checks if game is over at the end of each round
			if ((playerDeck.Length() == 0 && playerSide.Length() == 0) || (cpuDeck.Length() == 0 && cpuSide.Length() == 0)) {
				gameover = true;
			}
		}
		// Outputs appropriate end game comment based on the results
		if ((playerDeck.Length() == 0 && playerSide.Length() == 0)) {
			cout << "Sorry, the computer won this game. Better luck next time" << endl;
		}
		else {
			cout << "Congratulations! You beat the computer" << endl;
		}
	}
	// Game mode = Rounds
	else {
		cout << "You have chosen Rounds mode" << endl << endl;
		numRounds = getNumRounds();
		while (!gameover && round < numRounds) {
			cout << "Round " << round + 1 << " of " << numRounds << endl << endl;
			if (playerDeck.Length() > 0) {
				peek = getPeek();
				system("CLS");
				if (peek) {
					playerCard = playerDeck.Dequeue();
					cout << "Your top card is a " << playerCard.getName() << endl << endl;
					sideDecision = getSideDecision(playerSide, playerDeck);
					system("CLS");
					// Put card on side pile
					// Play next card from deck
					if (sideDecision == '1') {
						playerSide.Push(playerCard);
						cout << "You put your " << playerCard.getName() << " in your side pile" << endl << endl;
						playerCard = playerDeck.Dequeue();
						cout << "You pulled a " << playerCard.getName() << " from your deck" << endl << endl;
						cpuCard = cpuDeck.Dequeue();
						cout << "Player put down a " << playerCard.getName() << " from their deck" << endl;
						cout << "CPU put down a " << cpuCard.getName() << endl << endl;
						// If there's a tie, it will keep playing cards until there's a winner
						while (playerCard.getValue() == cpuCard.getValue()) {
							tiePile.Enqueue(playerCard);
							tiePile.Enqueue(cpuCard);
							cout << "Tie." << endl << endl;
							if (playerDeck.Length() > 0 && cpuDeck.Length() > 0) {
								playerCard = playerDeck.Dequeue();
								cpuCard = cpuDeck.Dequeue();
								cout << "Player put down a " << playerCard.getName() << " from their deck" << endl;
								cout << "CPU put down a " << cpuCard.getName() << endl << endl;
							}
							else if (playerDeck.Length() == 0 && playerSide.Length() > 0 && cpuDeck.Length() > 0) {
								playerCard = playerSide.Pop();
								cpuCard = cpuDeck.Dequeue();
								cout << "Player put down a " << playerCard.getName() << " from their side pile" << endl;
								cout << "CPU put down a " << cpuCard.getName() << endl << endl;
							}
							else {
								cout << "Game over" << endl << endl;
								gameover = true;
								break;
							}
						}
						if (playerCard.getValue() > cpuCard.getValue()) {
							playerDeck.Enqueue(playerCard);
							playerDeck.Enqueue(cpuCard);
							for (int i = 0; i < tiePile.Length(); i++) {
								playerDeck.Enqueue(tiePile.Dequeue());
							}
							cout << "Player wins this round" << endl << endl;
							playerWins++;
						}
						else if (playerCard.getValue() < cpuCard.getValue()) {
							cpuDeck.Enqueue(playerCard);
							cpuDeck.Enqueue(cpuCard);
							for (int i = 0; i < tiePile.Length(); i++) {
								cpuDeck.Enqueue(tiePile.Dequeue());
							}
							cout << "Computer wins this round" << endl << endl;
							cpuWins++;
						}
						displayNewStatus(playerSide, playerDeck, cpuDeck);
					}
					// Pull card from side pile
					// Play with current card from deck
					else if (sideDecision == '2') {
						playerSideCard = playerSide.Pop();
						cout << "You pulled a " << playerSideCard.getName() << " from your side deck" << endl << endl;
						cpuCard = cpuDeck.Dequeue();
						cout << "Player put down a " << playerCard.getName() << " and a " << playerSideCard.getName() << endl;
						cout << "CPU put down a " << cpuCard.getName() << endl << endl;
						if (playerCard.getValue() + playerSideCard.getValue() > cpuCard.getValue()) {
							playerDeck.Enqueue(playerCard);
							playerDeck.Enqueue(playerSideCard);
							playerDeck.Enqueue(cpuCard);
							cout << "Player wins this round" << endl << endl;
							playerWins++;
						}
						else if (playerCard.getValue() + playerSideCard.getValue() <= cpuCard.getValue()) {
							cpuDeck.Enqueue(playerCard);
							cpuDeck.Enqueue(playerSideCard);
							cpuDeck.Enqueue(cpuCard);
							cout << "Computer wins this round" << endl << endl;
							cpuWins++;
						}
						displayNewStatus(playerSide, playerDeck, cpuDeck);
					}
					// Play current card
					else if (sideDecision == '3') {
						cpuCard = cpuDeck.Dequeue();
						cout << "Player put down a " << playerCard.getName() << endl;
						cout << "CPU put down a " << cpuCard.getName() << endl << endl;
						// If there's a tie, it will keep playing cards until there's a winner
						while (playerCard.getValue() == cpuCard.getValue()) {
							tiePile.Enqueue(playerCard);
							tiePile.Enqueue(cpuCard);
							cout << "Tie." << endl << endl;
							if (playerDeck.Length() > 0 && cpuDeck.Length() > 0) {
								playerCard = playerDeck.Dequeue();
								cpuCard = cpuDeck.Dequeue();
								cout << "Player put down a " << playerCard.getName() << " from their deck" << endl;
								cout << "CPU put down a " << cpuCard.getName() << endl << endl;
							}
							else if (playerDeck.Length() == 0 && playerSide.Length() > 0 && cpuDeck.Length() > 0) {
								playerCard = playerSide.Pop();
								cpuCard = cpuDeck.Dequeue();
								cout << "Player put down a " << playerCard.getName() << " from their side pile" << endl;
								cout << "CPU put down a " << cpuCard.getName() << endl << endl;
							}
							else {
								cout << "Game over" << endl << endl;
								gameover = true;
								break;
							}
						}
						if (playerCard.getValue() > cpuCard.getValue()) {
							playerDeck.Enqueue(playerCard);
							playerDeck.Enqueue(cpuCard);
							for (int i = 0; i < tiePile.Length(); i++) {
								playerDeck.Enqueue(tiePile.Dequeue());
							}
							cout << "Player wins this round" << endl << endl;
							playerWins++;
						}
						else if (playerCard.getValue() < cpuCard.getValue()) {
							cpuDeck.Enqueue(playerCard);
							cpuDeck.Enqueue(cpuCard);
							for (int i = 0; i < tiePile.Length(); i++) {
								cpuDeck.Enqueue(tiePile.Dequeue());
							}
							cout << "Computer wins this round" << endl << endl;
							cpuWins++;
						}
						displayNewStatus(playerSide, playerDeck, cpuDeck);
					}
				}
				// Plays top card from deck without peeking
				else {
					playerCard = playerDeck.Dequeue();
					cpuCard = cpuDeck.Dequeue();
					cout << "Player put down a " << playerCard.getName() << endl;
					cout << "CPU put down a " << cpuCard.getName() << endl << endl;
					// If there's a tie, it will keep playing cards until there's a winner
					while (playerCard.getValue() == cpuCard.getValue()) {
						tiePile.Enqueue(playerCard);
						tiePile.Enqueue(cpuCard);
						cout << "Tie." << endl << endl;
						if (playerDeck.Length() > 0 && cpuDeck.Length() > 0) {
							playerCard = playerDeck.Dequeue();
							cpuCard = cpuDeck.Dequeue();
							cout << "Player put down a " << playerCard.getName() << " from their deck" << endl;
							cout << "CPU put down a " << cpuCard.getName() << endl << endl;
						}
						else if (playerDeck.Length() == 0 && playerSide.Length() > 0 && cpuDeck.Length() > 0) {
							playerCard = playerSide.Pop();
							cpuCard = cpuDeck.Dequeue();
							cout << "Player put down a " << playerCard.getName() << " from their side pile" << endl;
							cout << "CPU put down a " << cpuCard.getName() << endl << endl;
						}
						else {
							cout << "Game over" << endl << endl;
							gameover = true;
							break;
						}
					}
					if (playerCard.getValue() > cpuCard.getValue()) {
						playerDeck.Enqueue(playerCard);
						playerDeck.Enqueue(cpuCard);
						for (int i = 0; i < tiePile.Length(); i++) {
							playerDeck.Enqueue(tiePile.Dequeue());
						}
						cout << "Player wins this round" << endl << endl;
						playerWins++;
					}
					else if (playerCard.getValue() < cpuCard.getValue()) {
						cpuDeck.Enqueue(playerCard);
						cpuDeck.Enqueue(cpuCard);
						for (int i = 0; i < tiePile.Length(); i++) {
							cpuDeck.Enqueue(tiePile.Dequeue());
						}
						cout << "Computer wins this round" << endl << endl;
						cpuWins++;
					}
					displayNewStatus(playerSide, playerDeck, cpuDeck);
				}
			}
			// Player has to play from side pile because deck is empty
			else if (playerSide.Length() > 0) {
				playerCard = playerSide.Pop();
				cpuCard = cpuDeck.Dequeue();
				cout << "Player put down a " << playerCard.getName() << " from their side pile" << endl;
				cout << "CPU put down a " << cpuCard.getName() << endl << endl;
				// If there's a tie, it will keep playing cards until there's a winner
				while (playerCard.getValue() == cpuCard.getValue()) {
					tiePile.Enqueue(playerCard);
					tiePile.Enqueue(cpuCard);
					cout << "Tie." << endl << endl;
					playerCard = playerDeck.Dequeue();
					cpuCard = cpuDeck.Dequeue();
					if (playerDeck.Length() == 0 && playerSide.Length() > 0 && cpuDeck.Length() > 0) {
						playerCard = playerSide.Pop();
						cpuCard = cpuDeck.Dequeue();
						cout << "Player put down a " << playerCard.getName() << " from their side pile" << endl;
						cout << "CPU put down a " << cpuCard.getName() << endl << endl;
					}
					else {
						cout << "Game over" << endl << endl;
						gameover = true;
						break;
					}
				}
				if (playerCard.getValue() > cpuCard.getValue()) {
					playerDeck.Enqueue(playerCard);
					playerDeck.Enqueue(cpuCard);
					for (int i = 0; i < tiePile.Length(); i++) {
						playerDeck.Enqueue(tiePile.Dequeue());
					}
					cout << "Player wins this round" << endl << endl;
					playerWins++;
				}
				else if (playerCard.getValue() < cpuCard.getValue()) {
					cpuDeck.Enqueue(playerCard);
					cpuDeck.Enqueue(cpuCard);
					for (int i = 0; i < tiePile.Length(); i++) {
						cpuDeck.Enqueue(tiePile.Dequeue());
					}
					cout << "Computer wins this round" << endl << endl;
					cpuWins++;
				}
				displayNewStatus(playerSide, playerDeck, cpuDeck);
			}

			// Checks if game is over at the end of each round
			if ((playerDeck.Length() == 0 && playerSide.Length() == 0) || (cpuDeck.Length() == 0 && cpuSide.Length() == 0)) {
				gameover = true;
			}
			round++;
		}
		// Outputs appropriate end game comment based on the results
		if ((playerDeck.Length() == 0 && playerSide.Length() == 0)) {
			cout << "Sorry, the computer won this game. You ran out of cards. Better luck next time" << endl;
		}
		else if ((cpuDeck.Length() == 0 && cpuSide.Length() == 0)) {
			cout << "Congratulations! You beat the computer. They ran out of cards" << endl;
		}
		else if (playerWins > cpuWins) {
			cout << "Congratulations! You beat the computer with " << playerWins << " wins" << endl;
		}
		else if (playerWins < cpuWins) {
			cout << "Sorry, the computer won this game with " << cpuWins << " wins. Better luck next time" << endl;
		}
		else {
			cout << "Both players tied with " << playerWins << " wins" << endl;
		}
	}
	return 0;
}

// Takes in a shuffled full deck and adds the first 26 cards to the player deck and the second 26 cards to the cpu deck
void addToDecksStart(InitialDeck deck, Deck<Card>& player, Deck<Card>& computer) {
	for (int i = 0; i < deck.getSize() / 2; i++) {
		player.Enqueue(deck.getCard(i));
	}
	for (int i = deck.getSize() / 2; i < deck.getSize(); i++) {
		computer.Enqueue(deck.getCard(i));
	}
}

// Ask the player if they would like to peek at the top card in their deck
// Returns an associated bool
bool getPeek() {
	char input;
	cout << "Would you like to peek at the top card in your deck?" << endl;
	cout << "If you peak, you will have the option to push to or pull from the side pile" << endl << endl;
	cout << "Enter 'y' for yes, anything else for no" << endl << endl;
	cout << "Input: ";
	cin >> input;
	cout << endl;
	if (input == 'y') return true;
	else return false;
}

// Asks the player what they would like to do with the top card in their deck
// Returns the valid inputed character based on their decision
// Restricts options based on deck and side pile length
char getSideDecision(Side<Card> playerSide, Deck<Card> playerDeck) {
	char input;
	if (playerSide.isEmpty() && playerDeck.Length() > 0) {
		cout << "Your side pile is empty. Would you like to place this card on the side pile or play the current card?" << endl << endl;
		cout << "Enter a 1 to place the card onto the side pile" << endl;
		cout << "Enter a 3 to play the current card" << endl << endl;
		cout << "Input: ";
		cin >> input;
		cout << endl;
		while (input != '1' && input != '3') {
			cout << "Sorry that was not a valid option. Try again" << endl << endl;
			cout << "Enter a 1 to place the card onto the side pile" << endl;
			cout << "Enter a 3 to play the current card" << endl << endl;
			cout << "Input: ";
			cin >> input;
			cout << endl;
		}
	}
	else if (playerSide.isEmpty() && playerDeck.Length() == 0) {
		cout << "You must play the current card since it is your last card" << endl << endl;
		input = '3';
	}
	else if (playerSide.isFull()) {
		cout << "Your side pile is full. Would you like to pull a card from the side pile or play the current card?" << endl << endl;
		cout << "Enter a 2 to pull a card from the side pile to play with the current card" << endl;
		cout << "Enter a 3 to play the current card" << endl << endl;
		cout << "Input: ";
		cin >> input;
		cout << endl;
		while (input != '2' && input != '3') {
			cout << "Sorry that was not a valid option. Try again" << endl << endl;
			cout << "Enter a 2 to pull a card from the side pile to play with the current card" << endl;
			cout << "Enter a 3 to play the current card" << endl << endl;
			cout << "Input: ";
			cin >> input;
			cout << endl;
		}
	}
	else {
		cout << "Would you like to place this card on the side pile, pull a card from the side pile, or play the current card?" << endl << endl;
		cout << "Enter a 1 to place the card onto the side pile" << endl;
		cout << "Enter a 2 to pull a card from the side pile to play with the current card" << endl;
		cout << "Enter a 3 to play the current card" << endl << endl;
		cout << "Input: ";
		cin >> input;
		cout << endl;
		while (input != '1' && input != '2' && input != '3') {
			cout << "Sorry that was not a valid option. Try again" << endl << endl;
			cout << "Enter a 1 to place the card onto the side pile" << endl;
			cout << "Enter a 2 to pull a card from the side pile to play with the current card" << endl;
			cout << "Enter a 3 to play the current card" << endl << endl;
			cout << "Input: ";
			cin >> input;
			cout << endl;
		}
	}
	return input;
}

// Asks the user which game mode the would like to play in
// Returns the valid inputed character based on their decision
char getGameMode() {
	char input;
	cout << "Welcome to the game of War" << endl << endl;
	cout << "What game mode would you like to play in" << endl << endl;
	cout << "Enter a 1 to play in Out Of Cards mode (play until one of the players is out of cards, the player with no cards loses)" << endl;
	cout << "Enter a 2 to play in Rounds mode (play a predetermined amount of rounds, the player that wins the most rounds wins)" << endl << endl;
	cout << "Input: ";
	cin >> input;
	cout << endl;
	while (input != '1' && input != '2') {
		cout << "Sorry that was not a valid option. Try again" << endl << endl;
		cout << "Enter a 1 to play in Out Of Cards mode (play until one of the players is out of cards, the player with no cards loses)" << endl;
		cout << "Enter a 2 to play in Rounds mode (play a predetermined amount of rounds, the player that wins the most rounds wins)" << endl << endl;
		cout << "Input: ";
		cin >> input;
		cout << endl;
	}
	return input;
}

// Displays an update count on decks and player side pile
void displayNewStatus(Side<Card> playerSide, Deck<Card> playerDeck, Deck<Card> cpuDeck) {
	cout << "You have " << playerDeck.Length() << " cards remaining in your deck" << endl;
	cout << "You have " << playerSide.Length() << " cards in your side pile" << endl << endl;
	cout << "The CPU has " << cpuDeck.Length() << " cards remaining in their deck" << endl << endl;
}

// Gets the number of rounds the user wants to play for
// Returns the valid input
int getNumRounds() {
	int input = 0;
	cout << "How many rounds would you like to play?" << endl << endl;
	cout << "Enter a number between 1 and 50" << endl << endl;
	cout << "Input: ";
	cin >> input;
	cout << endl;
	while (input < 1 || input > 50) {
		if (!cin >> input) { // Will execute if input is not an integer
			cin.clear(); // Clears cin stream
			cin.ignore(10000, '\n'); // Ignores 10,000 characters until enter is hit
		}
		cout << "Sorry that was not a valid option. Try again" << endl << endl;
		cout << "Enter a number between 1 and 50" << endl << endl;
		cout << "Input: ";
		cin >> input;
		cout << endl;
	}
	return input;
}
