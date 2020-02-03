#pragma once
#include <iomanip>
#include <iostream>
#include <cstdlib>
#include <math.h>
#include <string>

using namespace std;

class ComplexCalc
{
public:
	ComplexCalc(); // default constructor
	ComplexCalc(double x, double y, int dummy); // cartesian form constructor (used int dummy to differentiate the cartesian and polar constructors since they both take two doubles as parameters)
	ComplexCalc(double r, double ang); // polar form constructor
	double RadiusCalc(); // Calculates radius from x and y coordinate
	double PhiCalc(); // Calculates phi from x and y coordinate
	void operator+(const ComplexCalc& rhs); // Overloaded addition operator
	void operator-(const ComplexCalc& rhs); // overloaded subtraction operator
	void operator*(double q); // overloaded multiplication operator
	void operator/(double q); // overloaded division operator
	bool operator==(ComplexCalc finalValue); // overloaded equal comparison operator
	void Print(); // Prints cartesian and polar coordinates

	// getter for radius
	double get_Radius()
	{
		return radius;
	}

	// getter for angle
	double get_Theta()
	{
		return angle;
	}

	// getter for first cartesian coordinate
	double get_cartesianA()
	{
		return a;
	}

	// getter for second cartesian coordinate
	double get_cartesianBi()
	{
		return bi;
	}

	// setter for radius
	void set_Radius(double r)
	{
		radius = r;
	}

	// setter for angle
	void set_Angle(double a)
	{
		angle = a;
	}

	// setter for first cartesian coordinate
	void set_cartesianA(double x)
	{
		a = x;
	}

	// setter for first cartesian coordinate
	void set_cartesianBi(double y)
	{
		bi = y;
	}

private:
	double radius, angle;
	double a, bi;
	double pi = 3.1415926535897;

};




