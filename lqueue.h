#ifndef LQUEUE_H
#define LQUEUE_H
#include <iostream>
using namespace std;

typedef int el_t;

struct node
{
  el_t elem;
  node* next;
};

class LQueue
{
 private: 
  int count;
  node* front;
  node* rear;
  void printAllReverse(node* p);
 public:
  void queueError(string msg);
  LQueue();
  bool isEmpty() const;
  ~LQueue();
  el_t deleteFront();
  void addRear(el_t el);
  void displayAll();
  void printAllReverse();
};

#endif
