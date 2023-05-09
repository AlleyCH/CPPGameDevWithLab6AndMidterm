#include "Towers.h"
#include <stdio.h>

Towers::Towers(int n, int intialPeg, int movedTo, int tempPeg) {
	numberOfDisks = n;
	source = intialPeg;
	intermediate = tempPeg;
	des = movedTo;
};

int recursiveMethod(int n, int intialPeg, int movedTo, int tempPeg)
{
	if (n == 1) // base case
	{
		printf("%d-->%d\n", intialPeg, tempPeg); // 1-3 last/first disk on 1st peg goes straight to 3rd peg
	}
	else {
		recursiveMethod(n - 1, intialPeg, tempPeg, movedTo); // Calls itself 
		printf("%d-->%d\n", intialPeg, tempPeg);// 3-1 = 2nd disk, 2nd disk goes to peg 2 
		recursiveMethod(n - 1, movedTo, intialPeg, tempPeg); // calls itself again
	}
	return n; 
}

void nonRecursiveMethod(int n, int intialPeg, int movedTo, int tempPeg)
{
	/*number of pegs = 3
		intial = 1st
		middle = 2nd
		end = 3rd

		number of disks = 3
		small = 1
		medium = 2
		large = 3
		if number of disks == to the number of disks on peg 3 == win game*/

	printf("Non recursive \n");

	
	for (; n==0; n-1) {
		if (n % 2 == 0) { 
			(n - 1, intialPeg, tempPeg, movedTo); 
			printf("%d-->%d\n", intialPeg, tempPeg);
		}
	}	
}

int main(void) {

	recursiveMethod(3, 1, 2, 3); // determine how many pegs and disks there are
	
	nonRecursiveMethod(3, 1, 2, 3);
	
}