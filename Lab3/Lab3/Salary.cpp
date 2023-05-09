/*This new function should modify the above function calcSalary as follows :
The new function should use a pointer to the array salary, and pointer
arithmetic to accessand assign values to the array in all the for loops(see slides on “Pointers and Arrays” for reference)*/

#include "Salary.h"
#include <iostream>
using namespace std;

void calcSalary() {
	int salary[3];
	for (int i = 0; i < 3; ++i) {
		cout << "Enter Salary: ";
		cin >> salary[i];
	}
	cout << endl;
	cout << "Entered salaries are: " << endl;
	for (int i = 0; i < 3; ++i) {
		cout << salary[i] << " ";
	}
	cout << endl;
	cout << "Updated salaries are: " << endl;
	for (int i = 0; i < 3; ++i) {
		salary[i] = salary[i] + salary[i] / (i + 1);
		cout << salary[i] << " ";
	}
}

	void calcSalaryArrayByPointerArithmetic() {
		int salary[3];		// makes 3 salary ints in an array
		int* pSalary = salary;		// makes pointer (Points to salary)  
		pSalary = salary;	//pointer assigns salary 

		for (int i = 0; i < 3; ++i) { // loops until it hits 3 
			cout << "Enter Salary: "; 
			cin >> *(pSalary +i); 
			
		}
		cout << endl;
		cout << "Entered salaries are: \n" << endl;
		for (int i = 0; i < 3; ++i) {
			cout << *pSalary << " ";
		}
		cout << endl;
		cout << "Updated salaries are: " << endl;
		for (int i = 0; i < 3; ++i) {
			*(pSalary + i) = *(pSalary + i) + *(pSalary + i) / (i + 1);
			cout << (pSalary + i) << " ";
		}

	}

	int main() {
		calcSalary();
		calcSalaryArrayByPointerArithmetic();
	}