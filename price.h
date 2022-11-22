#ifndef PRICE_H
#define PRICE_H
#include <string>
using namespace std;

class Price
{
  friend ostream& operator<<(ostream& o, const Price& p); //use friend bc its outside the class.
 private: 
  int dollar;
  int cent;
 public:
  Price();
  Price(int d, int c);
  Price operator+(const Price& rhs);
  Price operator-(const Price& rhs);
  bool operator>(const Price& rhs);
};

#endif
