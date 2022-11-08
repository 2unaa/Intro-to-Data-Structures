#include "price.h"
#include <iostream>
using namespace std;


Price::Price() //default constructor
{
  dollar = 0;
  cent = 0;
}


Price::Price(int d, int c) //non-default constructor
{
  dollar = d;
  cent = c;
}

//this function is an overloading operator. + is overloaded. rhs would be the second values. 
Price Price::operator+(const Price& rhs)
{
  double Tdollar = this-> dollar + rhs.dollar;
  double Tcent = this-> cent + rhs.cent;
  if(Tcent >= 100) //if cent is greater than 100
    {
      Price p(Tdollar+1, Tcent-100);
      return p;
    }
  else //if cent is any number more than or equal to 0 and less than 100
    {
      Price p(Tdollar, Tcent);
      return p;
    }
}
//this function has - overloading. 
Price Price::operator-(const Price& rhs)
{
  double Tdollar = this-> dollar - rhs.dollar;
  double Tcent = this-> cent - rhs.cent;
  if(Tcent < 0) //if cent is less than 100
    {
      Price p(Tdollar - 1, Tcent + 100); //makes dollar subtract 1 and adds 100 so it is positive
      return p;
    }
  else
    {
      Price p(Tdollar, Tcent);
      return p;
    }
}

//cout operator
ostream& operator<<(ostream& o, const Price& p)
{
  if(p.cent < 10) //if cents are less than 0
    {
      o << p.dollar << ".0" << p.cent; //so it prints 5.05 instead of 5.5
    }
  else
    {
      o << p.dollar << "." << p.cent;
    }
  return o;
}
