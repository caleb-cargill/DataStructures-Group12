#pragma once
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

struct LETF {
public:

};

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

	int getLetFreq(fstream &out) {
		char let = 'a';
		for (int i = 0; i < letfreq.size(); ++i) {
			let = 'a' + i;
			cout << let << ": " << letfreq.at(i) << " times" << 
				" (" << (static_cast<float>(letfreq.at(i)) / totLet) * 100 << "%)" << endl;
			out << let << ": " << letfreq.at(i) << " times" << 
				" (" << (static_cast<float>(letfreq.at(i)) / totLet) * 100 << "%)" << "\n";
		}

		cout << "Total Letters: ";
		return totLet;
	}

	void LetCount(ifstream& inp) {
		int wc = 0;
		int lc = 0;
		int abc = 26;
		char ch;
		string word;
		vector<int> freq(26, 0);
		inp.clear();
		inp.seekg(0, ios::beg);
		getline(inp, word);
		getline(inp, word);
		getline(inp, word);
		while (!inp.eof()) {
			inp.get(ch);
			if (!(ispunct(ch) || isspace(ch))) {
				for (int i = 0; i <= 26; ++i) {
					if ('a' + i == ch) {
						freq.at(i)++;
						lc++;
					}
				}
			}
		}
		letfreq = freq;
		totLet = lc;
	}

	void CountWords(ifstream &inp) {
		string word;
		int count = 0;

		while (!inp.eof()) {
			inp >> word;
			count++;
		}
		wordCount = count - 1;
	}

	void LineCount(ifstream& inp) {
		string line;
		int count = 0;
		inp.clear();
		inp.seekg(0, ios::beg);
		getline(inp, line);
		getline(inp, line);
		getline(inp, line);
		while (!inp.eof()) {
			getline(inp, line);
			if (line != " ") {
				count++;
			}
		}

		lineCount = count - 1;
	}

	

	//~CardCatalog();

private:
	string title;
	string first;
	string last;
	string fullName;
	vector<int> letfreq;
	int wordCount;
	int totLet;
	int lineCount;
	int a, b, c, d, e, f, g, h, i, j, k, l, m,
		n, o, p, q, r, s, t, u, v, w, x, y, z;
};
