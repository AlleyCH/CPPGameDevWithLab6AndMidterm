#include "Employee.h"


Employee::Employee(int empId, float sal)
{
	this->empId = empId;
	this->sal = sal;
}

float Employee::calculateSalary()
{
	return sal;
}
