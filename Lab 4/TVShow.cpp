#include "TVShow.h"
#include <iostream>

using namespace std;

// Definition of default constructor
TVShow::TVShow() : Show("Test TV Show", "Test TV Show Description", 25) {
	for (int i = 0; i < seasons; i++)
	{
		for (int j = 0; j < episodes; j++)
		{
			seasonsEpisodes[i][j] = "Season " + to_string(i + 1) + ", Episode " + to_string(j + 1);
		}
	}
}

// Definition of play function to print episode content to user
void TVShow::Play() {
	int se, ep;
	cout << "Which season would you like to view?" << endl;
	cin >> se;
	cout << "Which episode would you like to view? " << endl;
	cin >> ep;
	cout << endl;
	cout << "Episode Content: " << seasonsEpisodes[se-1][ep-1] << endl;
}

// Definition of overloaded details function to print out attributes of TVShow
void TVShow::Details() {
	cout << "Title: " << Title << endl;
	cout << "Description: " << Description << endl;
	cout << "Duration: " << Duration << endl;
	cout << "Number of Seasons: " << seasons << endl;
}