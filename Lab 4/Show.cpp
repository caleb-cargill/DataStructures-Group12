#include "Show.h"
#include "TVShow.h"
#include <iomanip>
#include <iostream>
using namespace std;

// Definition for default constructor
Show::Show() {
	Title = "Default Title";
	Description = "Default Description";
	Duration = 0;
}

// Definition for constructor including parameters
Show::Show(string title, string description, int duration) {
	Title = title;
	Description = description;
	Duration = duration;
}

// Definition of virtual play function
void Show::Play(){

}

// Definition for Details function : prints out Show attributes
void Show::Details() {
	cout << "Title: " << Title << endl;
	cout << "Description: " << Description << endl;
	cout << "Duration: " << Duration << endl;  
}
