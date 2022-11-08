#include "rationalNumber.h"
#include <iostream>
using namespace std;

//default constructor: set top to 0 and bottom to 1
rNum::rNum()
{
  top = 0;
  bottom = 1;
}


//non-default constructor: we won't be using it in the client, but we might as well make it.
rNum::rNum(int t, int b)
{
  top = t;
  bottom = b;
}


//Create all operator overloaded functions here. You need to figure out what you need by reading the client. 

//+ operator
rNum rNum::operator+(const rNum& rhs)
{
  int Ttop = this-> top * rhs.bottom + rhs.top * this->bottom;
  int Tbottom = this-> bottom * rhs.bottom;
  rNum r(Ttop, Tbottom);
  return r;
}

//<< operator for the cout
ostream& operator<<(ostream& o, const rNum& n)
{
  o << n.top << "/" << n.bottom;
  return o;
}
//>> operator for the cin
istream& operator>>(istream& i, rNum& n)
{
  cout << "\tEnter the top number: ";
  i >> n.top;
  cout << "\tEnter the bottom number: ";
  i >> n.bottom;
  return i;
}

//> operators for the sort function
bool rNum::operator>(const rNum& rhs)
{
  return (this-> top * rhs.bottom > rhs.top * bottom) ? true : false; //compares the left rational number and the right rational number and returns true if left is greater than right. sets all of them to have a common denominator
}

//== operator for the find function
bool rNum::operator==(const rNum& rhs)
{
  return (this-> top * rhs.bottom == rhs.top * bottom) ? true : false; //compares the top numerators. Sets all of them to have a common denominator
}

//+= operator
rNum operator+=(rNum& lhs, const rNum& rhs) //makes lhs = to lhs + rhs
{
  lhs = lhs + rhs; //makes lhs equal to lhs and rhs
  return lhs; 
}

//This is not an operator overloaded function.. This function will simplify a rational number to the simplest form.
void rNum::simplify()
{
  int gcd = 1; //greatest commmon denominator
  for(int i = 1 ; i <= top && i <= bottom; i++) //increases i each time and if it hits the top and bottom number, there is no simplifying
    {
      if(top %i== 0 && bottom%i == 0) //finds greatest common denominator. top %i == 0 means if top divided by i has no remainder
	{
	  gcd = i; // greatest common denominator is i.
	}
    }
  top = top/gcd; //new top equals the top/gcd
  bottom = bottom/gcd; //new bottom equals bottom/gcd
}
