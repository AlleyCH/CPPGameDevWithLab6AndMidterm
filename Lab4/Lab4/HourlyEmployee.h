#pragma once
#ifndef HOURLYEMPLOYEE
#define HOURLYEMPLOYEE
#include "Employee.h"

class HourlyEmployee : public Employee
{
public:
	int exHours;
	float pay;
	HourlyEmployee(int empId, float sal, int exHours, float pay);

	float calculateSalary();

};

#endif // !HOURLYEMPLOYEE