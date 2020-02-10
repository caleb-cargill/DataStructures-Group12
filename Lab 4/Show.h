#include <string>
using namespace std;

#pragma once
class Show 
{
public:
	// Declaration of default constructor
	Show();

	// Declaration of overload constructor with parameters
	Show(string title, string description, int duration);

	// Declaration of virtual function Play
	virtual void Play();

	// Declaration of function details
	void Details();

	// Definition of getter for title
	string getTitle() {
		return Title;
	}
	
	// Definition of getter for description
	string getDescription() {
		return Description;
	}

	// Definition of getter for Duration
	int getDuration() {
		return Duration;
	}

	// Definition of setter for Title
	void setTitle(string title) {
		Title = title;
	}

	// Definition of setter for description
	void setDescription(string description) {
		Description = description;
	}

	// Definition of setter for duration
	void setDuration(int duration) {
		Duration = duration;
	}

protected:
	string Title, Description; // title and description attribtues
	int Duration; // duration (minutes) attribute
};



