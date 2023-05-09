#pragma once
class Towers
{
public :
	int numberOfDisks;
	int source;
	int intermediate;
	int des;

	Towers(int n, int intialPeg, int movedTo, int tempPeg);

	

	int recursiveMethod(int n, int intialPeg, int movedTo, int tempPeg);


	int nonRecursiveMethod(int n, int intialPeg, int movedTo, int tempPeg);

	

};

