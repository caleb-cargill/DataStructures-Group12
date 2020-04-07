#include "Item.h"

Item::Item() {
	SKU = 0;
	description = "Default Description";
	Price = 0.0;
	UOM = "Default Unit of Measurement";
	QuantityOH = 0;
}

Item::Item(int sku, string dscrp, double price, string uom, int quant) {
	SKU = sku;
	description = dscrp;
	Price = price;
	UOM = uom;
	QuantityOH = quant;
}

string Item::GetPartInfo() {
	string retstr = "SKU: " + to_string(SKU) + ", Description: " + description;
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