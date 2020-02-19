#include "Show.h"
#include "Movie.h"
#include "TVShow.h"
#include <iostream>
//C:\Users\kspri\AppData\Local\Temp\7418602F308F527AC30BD7E590EE17CE6ED6\3\DataStructures-Group12\Lab 5B\Main.cpp
using namespace std;

int getValidInput();
void showDetails(Show *show);

int main() {
	int input = 0;
	char cont = 'y';

	while (cont == 'y') {
		input = getValidInput();
		switch (input) {
		case 1: { // user chose an instance of a show
			//Show userShow;
			Show *userShow = new Show();
			userShow->Details();
			userShow->Play();
			cout << endl;
			showDetails(userShow);
		}
			break;
		case 2: { // user chose an instance of a movie
			//Movie userMovie;
			Movie *userMovie = new Movie();
			userMovie->Details();
			userMovie->Play();
			cout << endl;
			showDetails(userMovie);
		}
			break;
		case 3: { // user chose an instance of a TvShow
			//TVShow userTVShow;
			TVShow *userTVShow = new TVShow();
			userTVShow->Details();
			userTVShow->Play();
			cout << endl;			
			showDetails(userTVShow);
		}
			break;
		case 4: { // user chose a Movie declared as a show
			//Show userMovie = Movie();
			Show *userMovie = new Movie();
			userMovie->Details();
			userMovie->Play();
			cout << endl;
			showDetails(userMovie);
		}
			break;
		case 5: { // user chose a TVShow declared as a show
			//Show userShow = TVShow();
			Show *userShow = new TVShow();
			userShow->Details();
			userShow->Play();
			cout << endl;
			showDetails(userShow);
		}
			break;
		}

		cout << endl;
		cout << "Would you like to continue?" << endl;
		cout << "Enter 'y' for yes and any other character for no" << endl << endl;
		cout << "Continue? ";
		cin >> cont;
	}
}

int getValidInput() {
	int inp = 0;
	cout << "Press 1 for an instance of a Show" << endl;
	cout << "Press 2 for an instance of a Movie" << endl;
	cout << "Press 3 for an instance of a TV Show" << endl;
	cout << "Press 4 for an instance of a Movie declared as a Show" << endl;
	cout << "Press 5 for an instance of a TV Show declared as a Show" << endl << endl;
	cout << "Input: ";
	cin >> inp;
	while (inp != 1 && inp != 2 && inp != 3 && inp != 4 and inp != 5) {
		system("CLS");
		if (!cin >> inp) {
			cin.clear();
				cin.ignore(100000, '/n');
		}
		cout << "Sorry, that was not a valid input. Try again" << endl << endl;
		cout << "Press 1 for an instance of a Show" << endl;
		cout << "Press 2 for an instance of a Movie" << endl;
		cout << "Press 3 for an instance of a TV Show" << endl;
		cout << "Press 4 for an instance of a Movie declared as a Show" << endl;
		cout << "Press 5 for an instance of a TV Show declared as a Show" << endl << endl;
		cout << "Input: ";
		cin >> inp;
	}
	return inp;
}

void showDetails(Show *show) {
	show->Play();
	show->Details();
	delete show;
}

