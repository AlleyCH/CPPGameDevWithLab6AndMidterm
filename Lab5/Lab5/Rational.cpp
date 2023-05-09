#include "Rational.h"
#include <iostream>
#include<conio.h>

using namespace std;

Rational::Rational()
{
}

Rational::Rational(double num, double denom)
{
	numerator = num;
	denominator = denom;
}

double Rational::gcd(int a, int b)
{
	if (b == 0)
		return a;
	return gcd(b, a % b);
}

void Rational::Reduce()
{
	double g;
	g = gcd(numerator, denominator);
	numerator /= g;
	denominator /= g;
	cout << "\nNumerator = " << numerator << "\nDenominator = " << denominator;
}

Rational Rational::operator+(const Rational& other) const
{
	return Rational(numerator * other.denominator + other.numerator * denominator, denominator * other.denominator);
}

Rational Rational::operator-(const Rational& other) const {
	return Rational(numerator * other.denominator - other.numerator * denominator, denominator * other.denominator);
}

Rational Rational::operator*(const Rational& other) const {
	return Rational(numerator * other.numerator, denominator * other.denominator);
}

Rational Rational::operator/(const Rational& other) const {
	return Rational(numerator * other.denominator, denominator * other.numerator);
}

//<< operator overloading
 ostream& operator<<(ostream& output, const Rational& r)
{
	output << "Numerator = " << r.numerator << "\nDenominator = " << r.denominator;
	return output;
}

//>> operator overloading
 istream& operator>>(istream& input, Rational& r) {
	input >> r.numerator >> r.denominator;
	return input;
}


 bool Rational::operator<(const Rational& rhs) const {
	 return numerator * rhs.denominator < rhs.numerator* denominator;
 }

 // Overloading > operator
 bool Rational::operator>(const Rational& rhs) const {
	 return numerator * rhs.denominator > rhs.numerator * denominator;
 }

 // Overloading <= operator
 bool Rational::operator<=(const Rational& rhs) const {
	 return numerator * rhs.denominator <= rhs.numerator * denominator;
 }

 // Overloading >= operator
 bool Rational::operator>=(const Rational& rhs) const {
	 return numerator * rhs.denominator >= rhs.numerator * denominator;
 }

 // Overloading != operator
 bool Rational::operator!=(const Rational& rhs) const {
	 return numerator * rhs.denominator != rhs.numerator * denominator;
 }

 // Overloading == operator
 bool Rational::operator==(const Rational& rhs) const {
	 return numerator * rhs.denominator == rhs.numerator * denominator;
 }



//main() function to test rational class
void main()
{
	Rational r1(3, 9);
	r1.Reduce();
	
	_getch();
}