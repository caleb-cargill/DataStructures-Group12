#pragma once
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

struct CardCatalog {
public:
	CardCatalog() {
		title = "None";
		fullName = "None";
	}

	CardCatalog(string Title, string firstName, string lastName) {
		title = Title;
		first = firstName;
		last = lastName;
	}

	void setTitle(string Title) {
		title = Title;
	}

	void setFirstName(string firstName) {
		first = firstName;
	}

	void setLastName(string lastName) {
		last = lastName;
	}

	string getTitle() {
		return title;
	}

	string getFirstName() {
		return first;
	}

	string getLastName() {
		return last;
	}

	string getFullName() {
		fullName = first + " " + last;
		return fullName;
	}

	int getWordCount() {
		return wordCount;
	}

	int getLineCount() {
		return lineCount;
	}

	int getLetFreq(fstream& out);

	void LetCount(ifstream& inp);

	void CountWords(ifstream& inp); 

	void LineCount(ifstream& inp);

private:
	string title;
	string first;
	string last;
	string fullName;
	int letfreq[26] = {0};
	int wordCount;
	int totLet;
	int lineCount;
	int a, b, c, d, e, f, g, h, i, j, k, l, m,
		n, o, p, q, r, s, t, u, v, w, x, y, z;
};