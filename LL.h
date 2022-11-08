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

class LL
{
 private: 
  int count;
  node* front;
  node* rear;
  void printAllReverse(node* p);
 public:
  void LLError(string msg);
  LL();
  bool isEmpty() const;
  ~LL();
  LL(const LL& l);
  el_t deleteFront();
  el_t deleteRear();
  void addRear(el_t el);
  void addFront(el_t el);
  void displayAll() const;
  void printAllReverse();
  bool search(el_t e);
  void deleteNode(el_t e);
  void deleteNodes(el_t e);
  void addInOrderAscend(el_t e);
  void addInOrderDescend(el_t e);
};

#endif
