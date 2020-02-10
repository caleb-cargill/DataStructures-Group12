#include "Movie.h"
#include <iostream>

using namespace std;

// Definition for default constructor
Movie::Movie() : Show("Test Movie", "Test Movie Description", 123) {
	Genre = "Default Genre";
}

// Definition for constructor with parameter
Movie::Movie(string genre) : Show("Test Movie", "Test Movie Description", 123) {
	Genre = genre;
}

// Definition of getter for genre
string Movie::getGenre() {
	return Genre;
}

// Definition of setter for genre
void Movie::setGenre(string genre) {
	Genre = genre;
}

// Definition of inherited function Play : prints out genre of movie
void Movie::Play() {
	cout << "Movie Genre: " << Genre << endl;
}
