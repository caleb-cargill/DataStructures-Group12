#pragma once
#include "Show.h"
class Movie : public Show
{
public:
	// Declaration of default constructor
	Movie();

	// Declaration of constructor with parameters
	Movie(string genre);

	// Declaration of function to show movie attribute
	void Play();

	// Declaration of getter for genre
	string getGenre();

	// Declaration of setter for genre
	void setGenre(string genre);

protected:
	string Genre; 	// genre attribute of movie
};

