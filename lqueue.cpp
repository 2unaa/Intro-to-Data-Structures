#include "lqueue.h"
#include <iostream>
#include <cstdlib>
using namespace std;

//this function will display an error message
void LQueue::queueError(string msg)
{
  cout << msg << endl;
  exit(1);
}

//constructor
LQueue::LQueue()
{
  front = NULL;
  rear = NULL;
  count = 0;
}

//this function will check to see if the queue is empty
bool LQueue::isEmpty() const
{
  return (front == NULL && rear == NULL && count == 0) ? true : false;
}

//destructor
LQueue::~LQueue()
{
  while(!isEmpty()) //while its not empty
    {
      deleteFront(); //call deleteFront until empty
    }
}

//this function will delete the front element and set the new front to the second
el_t LQueue::deleteFront()
{
  if(isEmpty()) //if its empty
    {
      queueError("Error: list is empty.");
    }
  if(count == 1) //if count is 1
    {
      el_t temp = front -> elem; //set temp to front element
      delete front; //delete front
      front = NULL; //set front and rear to null
      rear = NULL;
      count--; //decrement count
      return temp; //return value of front
    }
 else
   {
     el_t temp = front -> elem; //set temp to front element
     node* second = front -> next; //make a node second that is at the second spot
     delete front; //delete front
     front = second; //make second the new front
     count--; //decrement count
     return temp; //return value of front
   }
}

//this function will add an element to the rear
void LQueue::addRear(el_t el)
{
  if(isEmpty() == true) //if its empty
    {
      front = new node; //sets front to a new node
      front -> elem = el; //puts data in front node
      rear = front; //sets rear to front
    }
  else
    {
  rear -> next = new node; //make the node of the rear point to a new one
  rear = rear -> next; //rear points to the new node
  rear -> next = NULL; //new node points to NULL
  rear -> elem = el; //put data in rear node
    }
  count++; //increment count
}

//this function will display each element of the queue starting from front
void LQueue::displayAll()
{
  if(isEmpty()) //if its empty
    {
      cout << "[Empty]" << endl;
    }
  node* p = front; //set p to front
  while(p != NULL) //while p isnt null
    {
      cout << p -> elem; //print them out
      p = p -> next; 
    }
}

//this public function calls the other printAllReverse so we can use it in client. 
void LQueue::printAllReverse()
{
  printAllReverse(front);
}

//private function because u cant call with front from client.
void LQueue::printAllReverse(node* p)
{
  if(p == NULL) //base case
    return;
  else
    {
      printAllReverse (p -> next); //recursion
      cout << p -> elem; //prints out elements after popping them
    }
}
