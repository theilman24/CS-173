//==============================================================================
// Haley Nugent
// March 6, 2015
// Complex.cc
//
// This is the class methods file for the Complex class.
//==============================================================================

#include "Complex.h"
#include <iostream>

using namespace std;

//==============================================================================
// Default Constructor
// Sets default to 0 + 0i
//==============================================================================
Complex::Complex ( void )
{
	real = 0;
	imaginary = 0;
}

//==============================================================================
// Copy Constructor
//==============================================================================
Complex::Complex ( const Complex &c )
{
	real = c.real;
	imaginary = c.imaginary;
}

//==============================================================================
// Constructor with a/b
//==============================================================================
Complex::Complex ( float a, float b )
{
	real = a;
	imaginary = b;
}

//==============================================================================
// Assignment operator
//==============================================================================
Complex Complex::operator= ( const Complex &c )
{
	real = c.real;
	imaginary = c.imaginary;
	return *this;
}

//==============================================================================
// Destructor
//==============================================================================
Complex::~Complex ( void )
{
	// nothing to deallocate
}

//==============================================================================
// ostream <<
//==============================================================================
ostream & operator << (ostream& os, const Complex &c )
{
	if ( ( c.real == 0 ) && ( c.imaginary == 0 ) )
		os << c.real << "+" << c.imaginary << "i";	
	else if ( (c.real == 0) && (c.imaginary == -1))
		os << "-i";
	else if ( c.real == 0 )
		os << c.imaginary << "i";	
	else if ( c.imaginary == 0 )
		os << c.real;	
	else if ( c.imaginary < 0 )
		os << c.real << c.imaginary<< "i";	
	else if ( c.imaginary == 1 )
		os << c.real << "+" << "i";
	else
		os << c.real << "+" << c.imaginary << "i";
	return os;
}

//==============================================================================
// addition
// complex + complex
//==============================================================================
Complex Complex::operator+(const Complex &c2) const
{
	Complex c;	
	c.real = real + c2.real;	
	c.imaginary = imaginary + c2.imaginary;	
	return c;
	
}

//==============================================================================
// addition
// complex + real
//==============================================================================
Complex Complex::operator+(float num) 
{
	Complex c;
	c.real = real + num;
	c.imaginary = imaginary;
	return c;
}


//==============================================================================
// subtraction
// complex - complex
//==============================================================================
Complex Complex::operator-(const Complex &c2) const
{
	Complex c;
	c.real = real - c2.real;
	c.imaginary = imaginary - c2.imaginary;
	return c;
	
}

//==============================================================================
// subtraction
// complex - real
//==============================================================================
Complex Complex::operator-(float num) 
{
	Complex c;
	c.real = real - num;
	c.imaginary = imaginary;
	return c;
}


//==============================================================================
// multiplication
// complex * complex
//==============================================================================
Complex Complex::operator*(const Complex &c2) const
{
	Complex c;
	c.real = real * c2.real + (-1 * ( imaginary * c2.imaginary));
	c.imaginary = real * c2.imaginary + imaginary * c2.real;
	return c;
}

//==============================================================================
// multiplication
// complex * real
//==============================================================================
Complex Complex::operator*(float num) 
{
	Complex c;
	c.real = real * num;
	c.imaginary = imaginary * num;
	return c;
}


//==============================================================================
// division
// complex / complex
//==============================================================================
Complex Complex::operator/(const Complex&c2) const
{
	Complex c;
	//multiplies by the complex conjugate
	if ((c2.real==0) or (real==0) or (c2.imaginary==0) or (imaginary==0))
		cout<<"error! can't divide by zero"<<endl;
	c.real = (real * c2.real + -(imaginary * -c2.imaginary)) / (c2.real*c2.real+c2.imaginary*c2.imaginary);		
	c.imaginary = (real * -c2.imaginary + imaginary * c2.real) / (c2.real*c2.real+c2.imaginary*c2.imaginary);	
	return c;
}

//==============================================================================
// division
// complex / real
//==============================================================================
Complex Complex::operator/(float num) 
{
	Complex c;
	c.real = real / num;
	c.imaginary = imaginary / num;
	return c;
}


//==============================================================================
// conjugate
//==============================================================================
Complex Complex::operator~() const
{
	Complex c;
	if (real==0)
		c.real=0;
	if (imaginary==0)
		c.imaginary=0;
	else
	{
		c.real = real;
		c.imaginary = -imaginary;
	}
	return c;
}




//==============================================================================
// exponentiation
//==============================================================================
Complex Complex::operator^(int x)
{
	Complex c, d;
	
	// returns 1 if x=0
	if (x == 0)
	{
		c.real = 1;
		c.imaginary = 1;
		return c;
	}
	// returns inputted value if x=1
	else if (x == 1)
	{
		c.real = real;
		c.imaginary = imaginary;
		return c;
	}
	// normal multiplication if x=2
	else if (x==2)
	{
		c.real = (real*real)-(imaginary*imaginary);
		c.imaginary = 2*(real)*(imaginary);
		return c;
	}
	// uses temporary values when x>2 to store values that will
	// be multiplied during the next iteration.
	else 
	{
		
		c.real = (real*real)-(imaginary*imaginary);
		c.imaginary = 2*(real)*(imaginary);
		d.real = c.real;
		d.imaginary = c.imaginary;
		while ( x > 2)
		{
			c.real = (d.real * real) - (d.imaginary * imaginary);
			c.imaginary = (d.real * imaginary) + (real * d.imaginary);
			d.real = c.real;
			d.imaginary = c.imaginary;
			x--;
		}
		return c;
	}
}

