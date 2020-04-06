#pragma once
#include <string>

using namespace std;

class Word {
private:
	string word;
	int wordCount;

public:
	Word() {
		word = "";
		wordCount = 0;
	}

	Word(string key) {
		word = key;
		wordCount = 0;
	}

	bool operator==(const Word& rhs) {
		return this->word == rhs.word;
	}

	bool operator<(const Word& rhs) {
		return this->word < rhs.word;
	}

	bool operator>(const Word& rhs) {
		return this->word > rhs.word;
	}

	bool operator<=(const Word& rhs) {
		return this->word < rhs.word || this->word == rhs.word;
	}

	bool operator>=(const Word& rhs) {
		return this->word > rhs.word || this->word == rhs.word;
	}

	// https://www.learncpp.com/cpp-tutorial/93-overloading-the-io-operators/ on how to overload <<
	friend ostream& operator<<(ostream& os, const Word& rhs) 
	{
		os << rhs.word << ": " << rhs.wordCount;
		return os;
	}

	string getWord() {
		return word;
	}

	void setWord(string key) {
		word = key;
	}

	int getWordCount() {
		return wordCount;
	}

	void increaseWordCount() {
		wordCount++;
	}

};