#include <iostream>
#include "LL.h"
using namespace std;

int main()
{
  //testing adding and removing
  LL p;
  p.addFront(1);
  p.addFront(2);
  p.addFront(3);
  p.addRear(4);
  p.addRear(5);
  p.displayAll(); //displays 3 2 1 4 5
  cout << endl;
 
  cout << p.deleteFront() << " has been removed." << endl;
  cout << p.deleteRear() << " has been removed." << endl;
  p.displayAll(); //displays 2 1 4
  cout << endl;

  cout <<  p.deleteFront() << " has been removed." << endl;
  cout <<  p.deleteRear() << " has been removed." << endl;
  p.displayAll(); //displays 1
  cout << endl;

  cout << p.deleteFront() << " has been removed." << endl;
  p.displayAll(); //[Empty]

  p.addRear(10);
  p.addFront(11);
  p.displayAll(); //display 11 10
  cout << endl;

  cout <<  p.deleteRear() << " has been removed." << endl;
  cout <<  p.deleteRear() << " has been removed." << endl;
  p.displayAll(); //[Empty]
  cout << endl;

  //testing copy constructor
  LL a;
  a.addRear(1);
  a.addRear(2);
  LL b(a);
  cout << "Linked list for B: ";
  b.displayAll();
  cout << endl;
  cout << a.deleteFront() << " has been removed from list A" << endl;
  cout << "Linked list for A: ";
  a.displayAll();
  cout << endl;
  cout << "Linked list for B: ";
  b.displayAll();
  cout << endl;

  return 0;
}
