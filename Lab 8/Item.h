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
	Item(int sku, string dscrp, double price, string uom, int quant = 0){
		SKU = sku;
		description = dscrp;
		Price = price;
		UOM = uom;
		QuantityOH = quant;
	}

	string GetPartInfo(){
		string retstr = to_string(SKU) + description;
		return retstr;
	}

	double GetPrice(){
		return Price;
	}

	bool Available(int day, int month, int year){
		if (QuantityOH > 0){
			return true;
		}
		else{
			//handle input
			if (year == currYear && month == currMonth){
				return day - currDay > LeadTime;
			}
			else if (year == currYear && month > currMonth){
				return true;
			}
			else if (year > currYear){
				return true;
			}
			else {
				return false;
			}
		}
	}

	bool InStock(){
		return QuantityOH > 0;
	}

	bool operator==(const Item& rhs){
		return this->SKU == rhs.SKU;
	}

	bool operator<(const Item& rhs){
		return this->SKU < rhs.SKU;
	}

	bool operator>(const Item& rhs){
		return this->SKU > rhs.SKU;
	}


};