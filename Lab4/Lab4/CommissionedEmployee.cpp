#include "CommissionedEmployee.h"

CommissionedEmployee::CommissionedEmployee(int empId, float sal, float sales, float rate)
    :Employee(empId, sal)
{
    this->sales = sales;
    this->rate = rate;
}

float CommissionedEmployee::calculateSalary()
{
    return (sales *(rate/100)) + sal;
}
