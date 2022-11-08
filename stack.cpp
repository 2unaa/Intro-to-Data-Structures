#include "stack.h"
#include <iostream>
#include <cstdlib>
using namespace std;
//default constructor
Stack::Stack()
{
  top = -1;
}
//checks if stack is empty
bool Stack::isEmpty() const
{
  return (top == -1) ? true : false;
}
//checks if stack is full
bool Stack::isFull() const
{
  return (top == MAX-1) ? true : false;
}

//displays stacks
void Stack::displayAll() const
{
  if(isEmpty() == true) //if stack is empty
    {
      cout << "Stack is empty. " << endl;
    }
  else //if stack isnt empty, display all
    {
    for(int i = top; i >= 0; i--)
      {
	cout << el[i] << endl;
      }
    }
}
//error message for stacks
void Stack:: stackError(string msg)
{
  cout << msg << endl;
  exit(1);
}

//shows top element
el_t Stack::topElem()
{
  if(isEmpty() == true) //if it the empty
    {
      stackError("stack is empty") ;
    }
  else //f it isnt empty
    {
      return el[top]; 
    }
}
//push function
void Stack::push(el_t e)
{
  if(isFull() == true) //if it is full
    {
      stackError("stack overflow"); //print out the error message
    }
  else //if its not full
    {
      el[++top] = e; //add to the stack
    }
}
//pop function
el_t Stack::pop()
{
  if(isEmpty() == true) //if it is empty
    stackError("stack underflow");
  else //if its not empty
    {
      return el[top--]; //decrement the top
    }
}
//function to clear the entire stack
void Stack::clearIt()
{
  while(!isEmpty()) //while its not empty
    {
      pop();
      //pop    }
    }
}
