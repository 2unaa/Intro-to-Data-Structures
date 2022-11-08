#ifndef RATIONALNUMBER_H
#define RATIONALNUMBER_H
#include <string>
using namespace std;

//define the rNum class here. The data members are top and bottom.
class rNum
{
  friend ostream& operator<<(ostream& o, const rNum& n);
  friend istream& operator>>(istream& i, rNum& n);
    private:
  int top;
  int bottom;
 public:
  rNum();
  rNum(int t, int b);
  rNum operator+(const rNum& rhs);
  bool operator>(const rNum& rhs);
  bool operator==(const rNum& rhs);
  void simplify();
};

rNum operator+=(rNum& lhs, const rNum& rhs);

#endif
