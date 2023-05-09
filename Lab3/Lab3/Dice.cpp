#include "Dice.h"
#include <cstdlib>
#include <iomanip>
#include <iostream>

using namespace std;

int main() {
	const int arraysize = 13;

    int counter[13], sum=0;
    // init counter
    for(int i=0; i<13; i++)
        counter[i] = 0;

    int die1; 
    int die2;

    for ( int roll1 = 0; roll1 <=36000; roll1++ ) {
        die1 =  1 + rand() % 6;
        die2 =  1 + rand() % 6;
        counter[die1+die2]++;
    }

    cout<<"sum of Faces"<<setw(13)<<"Frequency"<<endl;

    for(int face=2; face<arraysize;face++)
    {
        cout<<setw(7)<<face<<setw(13)<<counter[face]<<endl;
        sum += counter[face];
    }

    cout << "sum: " << sum;


    return 0;
}
