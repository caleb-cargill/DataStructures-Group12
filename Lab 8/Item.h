#pragma once

#include <string>
#include <iostream>

using namespace std;

class Item {
private:
	int SKU;
	string description;
	double Price;
	string UOM;
	int QuantityOH;
	int LeadTime;
	int currDay;
	int currMonth;
	int currYear;
	
public:
	bool operator==(const Item& rhs) {
		return this->SKU == rhs.SKU;
	}

	bool operator<(const Item& rhs) {
		return this->SKU < rhs.SKU;
	}

	bool operator>(const Item& rhs) {
		return this->SKU > rhs.SKU;
	}

	Item();

	Item(int sku, string dscrp, double price, string uom, int quant = 0);

	string GetPartInfo();

	double GetPrice();

	bool Available(int day, int month, int year);

	bool InStock();

};