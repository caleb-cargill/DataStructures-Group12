// This program produces a sales report for DLC, Inc.
// This version of the program uses STL vectors instead of arrays.
#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

struct products
{
    int id;
    int units;
    double prices;
    double sales;
};

// Function prototypes
void initVectors(vector<products>& Products);
void calcSales(vector<products>& Products);
void showOrder(vector<products>& Products);
void dualSort(vector<products>& Products);
void showTotals(vector<products>& Products);

int main()
{
    vector<products> Products;

    // Must provide an initialization routine.
    initVectors(Products);

    // Calculate each product's sales.
    calcSales(Products);

    // Sort the sales elements in the Products array in descending
    // order and shuffle the ID numbers in the same array to
    // keep them in parallel.
    dualSort(Products);

    // Set the numeric output formatting.
    cout << fixed << showpoint << setprecision(2);

    // Display the products and sales amounts.
    showOrder(Products);

    // Display total units sold and total sales.
    showTotals(Products);
    return 0;
}

//******************************************************************
// Definition of initVectors. Accepts Products                     *
// vector as reference arguments. This function initializes the    *
// vector to a set of starting values.                             *
//******************************************************************

void initVectors(vector<products>& Products)
{
    // Initialize the vector with the ID numbers
    // 914 through 922.
    for (int value = 914; value <= 922; value++) {
        products tempProdObj;
        tempProdObj.id = value;
        Products.push_back(tempProdObj);
    }
        

    // Initialize the Products vector with units data.
    Products.at(0).units = 842;
    Products.at(1).units = 416;
    Products.at(2).units = 127;
    Products.at(3).units = 514;
    Products.at(4).units = 437;
    Products.at(5).units = 269;
    Products.at(6).units = 97;
    Products.at(7).units = 492;
    Products.at(8).units = 212;

    // Initialize the Products vector with prices data.
    Products.at(0).prices = 12.95;
    Products.at(1).prices = 14.95;
    Products.at(2).prices = 18.95;
    Products.at(3).prices = 16.95;
    Products.at(4).prices = 21.95;
    Products.at(5).prices = 31.95;
    Products.at(6).prices = 14.95;
    Products.at(7).prices = 14.95;
    Products.at(8).prices = 16.95;
}


//****************************************************************
// Definition of calcSales. Accepts Products                     *
// vector as argument (as reference).                            *
// This function calculates each product's                       *
// sales by multiplying its units sold by each unit's price. The *
// result is stored in the same vector.                          *
//****************************************************************

void calcSales(vector<products>& Products)
{
    for (int index = 0; index < Products.size(); index++) {
        Products.at(index).sales = Products.at(index).units * Products.at(index).prices;
    }
        
}

//****************************************************************
// Definition of function dualSort. Accepts Products vector      *
// as reference argument. This function performs a descending    *
// order selection sort on the sales. The id elements of the     *
// vector are exchanged identically as those of the sales        *
// elements.                                                     *
//****************************************************************

void dualSort(vector<products>& Products)
{
    int startScan, maxIndex, tempid, size;
    double maxValue;

    size = Products.size();
    for (startScan = 0; startScan < (size - 1); startScan++)
    {
        maxIndex = startScan;
        maxValue = Products.at(startScan).sales;
        tempid = Products.at(startScan).id;
        for (int index = startScan + 1; index < size; index++)
        {
            if (Products.at(index).sales > maxValue)
            {
                maxValue = Products.at(index).sales;
                tempid = Products.at(index).id;
                maxIndex = index;
            }
        }
        Products.at(maxIndex).sales = Products.at(startScan).sales;
        Products.at(maxIndex).id = Products.at(startScan).id;
        Products.at(startScan).sales = maxValue;
        Products.at(startScan).id = tempid;
    }
}

//*****************************************************************
// Definition of showOrder function. Accepts Products vector      *
// as argument (as reference). The function first displays a      *
// heading, then thesorted list of product numbers and sales.     *
//*****************************************************************

void showOrder(vector<products>& Products)
{
    cout << "Product Number\tSales\n";
    cout << "----------------------------------\n";
    for (int index = 0; index < Products.size(); index++)
    {
        cout << Products.at(index).id << "\t\t$";
        cout << setw(8) << Products.at(index).sales << endl;
    }
    cout << endl;
}

//*******************************************************************
// Definition of showTotals function. Accepts Product vector as     *
// argument (as reference). The function first calculates           *
// the total units (of all products) sold and the total sales.      *
// It then displays these amounts.                                  *
//*******************************************************************

void showTotals(vector<products>& Products)
{
    int totalUnits = 0;
    double totalSales = 0.0;

    for (int index = 0; index < Products.size(); index++)
    {
        totalUnits += Products.at(index).units;
        totalSales += Products.at(index).sales;
    }
    cout << "Total Units Sold:  " << totalUnits << endl;
    cout << "Total Sales:      $" << totalSales << endl;
}