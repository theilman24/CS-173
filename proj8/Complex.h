/*==============================================================================
Haley Nugent
March 6, 2015
Complex.h

This is the Complex class definition
A complex number is represented by a+bi, 
where a is the real part and b is the imaginary part.

We can operate on our complex number with the following operations:

default constructor: 	initializes a and b to 0 (0+0i).
copy constructor: 	creates a copy of the existing object
constuctor with a/b: 	specifies a new Complex type by giving real and
			imaginary components
assignment operator:    allows assignment of values between complex numbers
destructor: 		deallocates memory for complex
ostream: 		allows printing of a complex number as a string "a+bi"
addidtion:
  complex + complex:    adds 2 complex numbers together
  complex + real:       adds a complex number and a real number together.	
  			the real number must be on the right of the complex.
subtraction:
  complex - complex:	subtracts one complex number from another
  complex - real: 	subtracts a real number from a complex number.
  			the real number must be on the right of the complex.
multiplication:
  complex * complex:    multiplies two complex numbers
  complex * real:	multiplies a complex number and a real number.
  			the real number must be on the right of the complex number.
division:
  complex / complex:    divides one complex number by another
  complex / real: 	divides a complex number by a real number
  			the real number must be on the right of the complex number.
conjugate:		returns the complex conjugate. a-bi
exponentiation:		the operator raises a complex number to an integer power





==============================================================================*/

#ifndef COMPLEX_H
#define COMPLEX_H

#include <iostream>
using namespace std;

class Complex {

	private:
		//float real;
		//float imaginary;
		
	public: 
	
		float real;
		float imaginary;
		
			 Complex     ( void );
			 Complex     ( const Complex &c );
			 Complex     ( float a, float b );
			 ~Complex    ( void );
		Complex  operator=   ( const Complex &c ); 
		
		Complex operator+ ( const Complex &c) const;
		
		Complex operator+ ( float num );
		
		Complex operator- ( const Complex &c) const;
		
		Complex operator- ( float num );
		
		Complex operator* ( const Complex &c) const;
		
		Complex operator* ( float num);
		
		Complex operator/ ( const Complex &c) const;
		
		Complex operator/ ( float num);
		
		Complex operator~ ( ) const;
		
		Complex operator^  ( int x );
		
		
		
		friend ostream & operator << (ostream&, const Complex & );
		
	
	
};



#endif

