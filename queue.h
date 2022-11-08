#ifndef QUEUE_H
#define QUEUE_H
#include <string>
using namespace std;


//create an enumuration type
enum op {ADD, SUB, MULT, DIVI};

//create a struct that will have an operand, a operator, another operand
struct expr
{
  int oprd1;
  op oprt;
  int oprd2;
};

const int MAX = 10; //size

typedef expr el_t;

class queue
{
 private:
  el_t el[MAX];
  int count;
  int front;
  int rear;
  void queueError(string msg);
 public:
  queue();
  bool isEmpty() const;
  bool isFull() const;
  void add(el_t e);
  el_t remove();
  el_t getFront();
  void goToBack();
  int getSize();
  void displayAll() const;
};

#endif
