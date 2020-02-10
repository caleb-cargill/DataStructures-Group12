#pragma once
#include "Show.h"
class TVShow : public Show
{
public:
	// Declaration of default constructor
	TVShow();

	// Declaration of inherited function Play
	void Play();

	// Declaration of inherited function Details
	void Details();
protected:	
	static const int seasons = 6; // constant number of seasons
	static const int episodes = 24; // constant number of episodes per season
	string seasonsEpisodes[seasons][episodes]; //placeholder values
};

