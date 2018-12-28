//	Ceejay Guiking
//	Assignment 1
//	CS 302 - 1003

#include <iostream>
#include "complex.h"

	complex operator+(float num,const complex&right){
		complex temp;
		temp.rpart = right.rpart + num;
		temp.ipart = right.ipart;
		return temp;
	}	
	
	complex operator-(float num,const complex&right){
		complex temp;
		temp.rpart = right.rpart - num;
		temp.ipart = right.ipart;
		return temp;
	}
	
	complex operator*(float num,const complex&right){
		complex temp;
		temp.rpart = right.rpart * num;
		temp.ipart = right.ipart * num;
		return temp;
	}
	
	complex operator/(float num,const complex&right){
		complex temp;
		temp.rpart = right.rpart / num;
		temp.ipart = right.ipart / num;
		return temp;
	}
	
	ostream&operator<<(ostream&outfile,const complex&z){
		if (z.rpart == 0) outfile << z.ipart << "i";
			else outfile << z.rpart << "+" << z.ipart << "i";
			return outfile;
	}
	 
	complex::complex(){
		rpart = 0.0;
		ipart = 0.0;
	}	
	
	complex::complex(float r,float i){
		 rpart = r;
		 ipart = i;
	}
	 
	const complex& complex::operator=(const complex&right){
		rpart = right.rpart;
		ipart = right.ipart;
		return *this;
	}
	 
	const complex& complex::operator=(float num){
		rpart = num;
		ipart = ipart;
		return *this;
	}
	
	bool complex::operator==(const complex&right) const{
		if ((rpart==right.rpart) && (ipart==right.ipart))
			return true;
		else
			return false;
		 
	}
	 
	complex complex::operator+(const complex& addend) const {
		complex sum;
		sum.rpart = rpart+addend.rpart;
		sum.ipart = ipart+addend.ipart;
		return sum;
	}
	
	complex complex::operator+(float addend) const{
		complex sum;
		sum.rpart = rpart+addend;
		sum.ipart = ipart;
		return sum;
	}

	complex complex::operator-(const complex& subtrahend) const{
		complex difference;
		difference.rpart = rpart-subtrahend.rpart;
		difference.ipart = ipart-subtrahend.ipart;
		return difference;
	 }
	
	complex complex::operator-(float subtrahend) const{
		complex difference;
		difference.rpart = rpart-subtrahend;
		difference.ipart = ipart;
		return difference;
	}
	
	complex complex::operator-() const{
		complex temp;
		temp.rpart = -temp.rpart;
		temp.ipart = -temp.ipart;
		return temp;
	}	
	
	complex complex::operator*(const complex&temp) const{
		complex	product;
		product.rpart = (rpart*temp.rpart) - (ipart*temp.ipart);
		product.ipart = (rpart*temp.ipart) + (ipart*temp.rpart);
		return product;
	}
	
	complex complex::operator*(float num) const{
		complex product;
		product.rpart = rpart * num;
		product.ipart = ipart * num;
		return product;
	}
	
	complex complex::operator/(const complex&temp) const{
//	equation for this is (a + bi) / c + di =
//	(ac + bd) + i(bc - ad) / c^2 + d^2

		complex	quotient;
		quotient.rpart = (rpart*temp.rpart + ipart*temp.ipart) / (temp.rpart*temp.rpart + temp.ipart*temp.ipart);
		quotient.ipart = (ipart*temp.rpart - rpart*temp.ipart) / (temp.rpart*temp.rpart + temp.ipart*temp.ipart);
		return quotient;
	}
	
	complex complex::operator/(float num) const{
		complex quotient;
		quotient.rpart = rpart/num;
		quotient.ipart = ipart/num;
		return quotient;
	}
