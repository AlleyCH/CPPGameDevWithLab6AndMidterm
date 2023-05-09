#pragma once

#include <iostream>
#include <string>

class HeartRates
{
public:
	std::string firstName;
	std::string lastName;
	int month;
	int day;
	int year;

	HeartRates(std::string fName, std::string lName, int m, int d, int y) {
		firstName = fName;
		lastName = lName;
		month = m;
		day = d;
		year = y;
	}

	std::string getFirstName() {
		return firstName;
	}

	void setFisrName(std::string fName) {
		firstName = fName;
	}

	std::string getLastName() {
		return lastName;
	}

	void setLastName(std::string lName) {
		lastName = lName;
	}

	int getBirthMonth() {
		return month;
	}
	void setBirthMonth(int m) {
		month = m;
	}

	int getBirthYear() {
		return year;
	}

	void setBirthYear(int y) {
		year = y;
	}
	int getBirthDay() {
		return day;
	}
	void setBirthDay(int d) {
		day = d;
	}

	int getAge() const{
		int pMonth, pDay, pYear;
		std::cout << "Please enter the current month, day, year: " ;
		std::cin >> pMonth >> pDay >> pYear;
		int age = pYear - year;
		if (pMonth < month || (pMonth == month && pDay < day)) {
			age--;
		}
		return age;
	}

	double getMaximumHeartRate() {
		double result = 220 - getAge();
		return result;
	}

	double getMinimumTargetHeartRate() {

		double max = 220 - getAge();
		double minTarget = max * 0.5;

		return minTarget;
	}

	double getMaximumTargetHeartRate() {
		double max = 220 - getAge();
		double maxTarget = max * 0.85;

		return maxTarget;
	}

};

