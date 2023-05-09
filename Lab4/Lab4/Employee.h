#ifndef EMPLOYEE
#define EMPLOYEE

class Employee
{
public:
	int empId;
	float sal;
	Employee(int empId, float sal);

	float calculateSalary();
};
	
#endif
