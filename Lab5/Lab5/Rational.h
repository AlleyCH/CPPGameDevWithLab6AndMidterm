#pragma once
class Rational
{
public:
	double numerator;
	double denominator;

	Rational();

	Rational(double num, double den);


	double gcd(int a, int b);
	void Reduce();

	Rational operator+(const Rational& other) const;

	Rational operator-(const Rational& other) const;

	Rational operator*(const Rational& other) const;

	Rational operator/(const Rational& other) const;


	bool operator<(const Rational& rhs) const;

	bool operator>(const Rational& rhs) const;

	bool operator<=(const Rational& rhs) const;

	bool operator>=(const Rational& rhs) const;

	bool operator!=(const Rational& rhs) const;

	bool operator==(const Rational& rhs) const;

	//ostream & operator<<(ostream& output, const Rational& r);

	//friend istream& operator>>(istream& input, Rational& r);

};

