#ifndef STACK_H
#define STACK_H
#include <string>
using namespace std;

const int MAX = 30; //size

typedef char el_t;

class Stack
{
 private:
  el_t el[MAX];
  int top;
  void stackError(string msg);
 public:
  Stack();
  bool isEmpty() const;
  bool isFull() const;
  void displayAll() const;
  el_t topElem();
  void push(el_t e);
  el_t pop();
  void clearIt();
};

#endif
