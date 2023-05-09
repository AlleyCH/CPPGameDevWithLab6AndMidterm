#include "Array.h"
#include <iostream>
#include <cctype>
using namespace std;

void process(char x[], const int size){};

int main() {
	char x[3];
	cout << "Please enter 10 characters (only numbers allowed): " << endl;
	cin >> x;

	for (int i = 0; i < 3; i++) {
		
		if (!isdigit(x[i])) {
			cout << "Character '" << x[i] << "' at index " << i << " is not a digit." << std::endl;
			cout << "Array cannot be processed further." << endl;
			return 0;	
		}
	}

	process(x, 3);
	cout << "process..." << endl;
	return 0;
}


