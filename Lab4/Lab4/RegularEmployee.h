#ifndef REGUALREMPLOYEE_HEADER
#define REGUALREMPLOYEE_HEADER
#include "Employee.h"
class RegularEmployee : public Employee
{
public:
	float bonus;
	RegularEmployee(int empId, float sal, float bonus);

	float calculateSalary();
};

#endif