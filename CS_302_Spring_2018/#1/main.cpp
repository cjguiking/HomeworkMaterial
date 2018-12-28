//	Ceejay Guiking
//	Assignment 1
//	CS 302 - 1003

#include <iostream>
#include "complex.h"

using namespace std;

int	main(){
	cout << "For x= -(1+2i)/2 , (4x^2 - 2x - 1)/(i+1) = ";

//	represents -(1+2i)/2	
	complex x(-1,-2);	
	x = x/2;
	
//	used in the function for (i+1)	
	complex temp(1,1);

	complex answer;
	answer = (4*x*x - 2*x - 1) / temp;
	
	cout << answer << endl;
	
	return	0;
   }