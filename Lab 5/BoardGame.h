#include <string>
using namespace std;

#pragma once
class BoardGame
{
public:
	// Declaration of default constructor
	BoardGame() {
		Title = "Default Title";
		Description = "Default Description";
	}

	// Definition of getter for title
	string getTitle() {
		return Title;
	}

	// Definition of getter for description
	string getDescription() {
		return Description;
	}

	// Definition of setter for Title
	void setTitle(string title) {
		Title = title;
	}

	// Definition of setter for description
	void setDescription(string description) {
		Description = description;
	}

protected:
	string Title, Description; // title and description attribtues
};



