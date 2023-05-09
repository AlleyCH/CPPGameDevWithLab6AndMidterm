#include "Employee.h"
#include "HourlyEmployee.h"

HourlyEmployee::HourlyEmployee(int empId, float sal, int exHours, float pay)
	: Employee(empId, sal) {

	this->pay = pay;
	this->exHours = exHours;
}

float HourlyEmployee::calculateSalary()
{
	return sal+(pay*exHours);
}
