#include "RegularEmployee.h"
#include "Employee.h"

RegularEmployee::RegularEmployee(int empId, float sal, float bonus)
	: Employee (empId, sal)
{
	this->bonus = bonus;
}

float RegularEmployee::calculateSalary()
{
	return sal + bonus;
}
