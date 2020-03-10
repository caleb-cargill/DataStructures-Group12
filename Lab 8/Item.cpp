#include "Item.h"

Item::Item(int sku, string dscrp, double price, string uom, int quant) {
	SKU = sku;
	description = dscrp;
	Price = price;
	UOM = uom;
	QuantityOH = quant;
}

string Item::GetPartInfo() {
	string retstr = to_string(SKU) + description;
	return retstr;
}

double Item::GetPrice() {
	return Price;
}

bool Item::InStock() {
	return QuantityOH > 0;
}

bool Item::Available(int day, int month, int year) {
	if (InStock()) {
		return true;
	}
	else {
		//handle input
		if (year > currYear) {
			return true;
		}
		else if (year == currYear && month > currMonth) {
			return true;
		}
		else if (year == currYear && month == currMonth) {
			return day - currDay > LeadTime;
		}
		else {
			return false;
		}
	}
}
