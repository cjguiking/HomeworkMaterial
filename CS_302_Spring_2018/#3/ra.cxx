#include<iostream>
#include<cstdlib>
#include <time.h>
using namespace std;

int 
myrand(int lower, int upper) 
{
return (lower + rand() % ( upper - lower +1 )  );
}

main()
{

int lower, upper;
srand(time(NULL));

// DIALOG WITH THE USER

cout << "LOWER PLEASE > ";
cin >> lower;
cout << "UPPER PLEASE > ";
cin >> upper;

// END OF  DIALOG WITH THE USER

//GENERATE 10 NUMBERS IN RANGE

for ( int i =1 ; i < 10 ; i++) cout << myrand(lower,upper) << endl;

}
