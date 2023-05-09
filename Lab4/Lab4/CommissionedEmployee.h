#ifndef COMMISSIONEDEMPLOYEE
#define COMMISSIONEDEMPLOYEE
#include "Employee.h"

class CommissionedEmployee : public Employee
{
public:
	float sales;
	float rate;
	CommissionedEmployee(int empId, float sal, float sales, float rate);

	float calculateSalary();
};

#endif