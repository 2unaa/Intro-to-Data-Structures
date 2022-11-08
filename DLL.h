#ifndef DLL_H
#define DLL_H
#include <iostream>
using namespace std;

typedef int el_t;

struct node
{
  el_t elem;
  node* next;
  node* prev;
};

class DLL
{
 private: 
  int count;
  node* front;
  node* rear;
 public:
  void LLError(string msg);
  DLL();
  bool isEmpty() const;
  ~DLL();
  DLL(const DLL& l);
  el_t deleteFront();
  el_t deleteRear();
  void addRear(el_t el);
  void addFront(el_t el);
  void displayAll() const;
  void printAllReverseDLL();
  bool search(el_t e);
  void deleteNode(el_t e);
  void deleteNodes(el_t e);
  void addInOrderAscend(el_t e);
  void addInOrderDescend(el_t e);
};

#endif
