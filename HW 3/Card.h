#pragma once

class Card {
private:
	int value = 0;
	string name = "";

public:
	Card() {
		value = 0;
		name = ' ';
	}

	Card(string inValue) {
		name = inValue;
		if (name == "A") value = 14;
		else if (inValue == "2") value = 2;
		else if (inValue == "3") value = 3;
		else if (inValue == "4") value = 4;
		else if (inValue == "5") value = 5;
		else if (inValue == "6") value = 6;
		else if (inValue == "7") value = 7;
		else if (inValue == "8") value = 8;
		else if (inValue == "9") value = 9;
		else if (inValue == "10") value = 10;
		else if (inValue == "J") value = 11;
		else if (inValue == "Q") value = 12;
		else if (inValue == "K") value = 13;
	}

	int getValue() {
		return value;
	}

	string getName() {
		return name;
	}

	void setValue(int newValue) {
		value = newValue;
	}

	void setName(string newName) {
		name = newName;
	}
};