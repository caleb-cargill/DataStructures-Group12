#include "ComplexCalc.h"
#include <iomanip>

using namespace std;

// definition for default constructor
ComplexCalc::ComplexCalc() {
	a = 0.0;
	bi = 0.0;
	radius = RadiusCalc();
	angle = PhiCalc();
}

// definition for overloaded cartesian constructor
ComplexCalc::ComplexCalc(double x, double y, int dummy = 0){
	a = x;
	bi = y;
	radius = RadiusCalc();
	angle = PhiCalc();
}

// definition for overloaded polar constructor
ComplexCalc::ComplexCalc(double r, double ang) {
	radius = r;
	angle = ang;
}

// defintion for addition overload operator
void ComplexCalc::operator+(const ComplexCalc& rhs){
	a += rhs.a;
	bi += rhs.bi;
	radius = RadiusCalc();
	angle = PhiCalc();
}

// defintion for subtraction overload operator
void ComplexCalc::operator-(const ComplexCalc& rhs){
	a -= rhs.a;
	bi -= rhs.bi;
	radius = RadiusCalc();
	angle = PhiCalc();
}

// defintion for multiplication overload operator
void ComplexCalc::operator*(double q){
	a = a * q;
	bi = bi * q;
	radius = RadiusCalc();
	angle = PhiCalc();
}

// defintion for division overload operator
void ComplexCalc::operator/(double q){
	a /= q;
	bi /= q;
	radius = RadiusCalc();
	angle = PhiCalc();
}

// defintion for equal comparision overload operator
bool ComplexCalc::operator==(ComplexCalc finalValue){	
	if (a == finalValue.a && bi == finalValue.bi)
	{
		return true;
	}
	else
	{
		return false;
	}
}

// defintion for print function
void ComplexCalc::Print() {
	string ANG = "undefined";

	cout << "Complex Coordinate: (" << setprecision(2) << a << ", " << setprecision(2) << bi << "i)" << endl;

	if (angle == -999999999999){
		cout << "Polar Coordinate: (" << setprecision(2) << radius << ", " << ANG  << ")" << endl << endl;
	}
	else{
		cout << "Polar Coordinate: (" << setprecision(2) << radius << ", " << setprecision(2) << angle << " rad)" << endl << endl;
	}
}
// definition of function to perform calculation of the radius
double ComplexCalc::RadiusCalc(){
	double r = a*a + bi*bi;
	radius = sqrt(r);
	return radius;
}

// definition of function to perform the calculation of the angle
double ComplexCalc::PhiCalc(){
	
	if (a > 0 && bi != 0){
		double r = bi / (sqrt(a * a + bi * bi) + a);
		angle = static_cast<double>(2) * atan(r);
	}
	else if(a < 0 && bi == 0){
		angle = pi;
	}
	else if(a == 0 && bi == 0){
		angle = -999999999999;  // angle is undefined, handled in print function
	}

	return angle;
}

