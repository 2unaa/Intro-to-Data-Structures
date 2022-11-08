#include "DLL.h"
#include <iostream>
#include <cstdlib>
using namespace std;

//this function will display an error message
void DLL::LLError(string msg)
{
  cout << msg << endl;
  exit(1);
}

//constructor
DLL::DLL()
{
  front = NULL;
  rear = NULL;
  count = 0;
}

//this function will check to see if the queue is empty
bool DLL::isEmpty() const
{
  return (front == NULL && rear == NULL && count == 0) ? true : false;
}

//destructor
DLL::~DLL()
{
  while(!isEmpty()) //while its not empty
    {
      deleteFront(); //call deleteFront until empty
    }
}

//copy constructor
DLL::DLL(const DLL& l)
{
  this->front = this->rear = NULL;
  this->count = 0;
  node* p = l.front;
  while(p != NULL) //go through entire array
    {
      addRear(p->elem);
      p = p-> next;
    }
}

//this function will delete the front element and set the new front to the second
el_t DLL::deleteFront()
{
  if(isEmpty()) //if its empty
    {
      LLError("Error: list is empty.");
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
     front->prev = NULL; //set front prev to null
     count--; //decrement count
     return temp; //return value of front
   }
}
//this function will delete the rear of the linked list
el_t DLL::deleteRear()
{
  if(isEmpty())
    {
      LLError("Error: List is empty.");
    }
  el_t temp = rear -> elem; //temp equals to rear elem
  if(count == 1)
    {
      delete rear;
      front = NULL; //set front and rear to null
      rear = NULL;
    }
  else
    {
      node* p = rear-> prev; //get the node p to equal the one before rear 
      delete rear; //delete rear
      rear = p;  //set rear equal to the node before rear
      rear->next = NULL; //rear next to null
    }
  count--; //decrement count
  return temp;
}



//this function will add an element to the rear
void DLL::addRear(el_t el)
{
  if(isEmpty() == true) //if its empty
    {
      front = new node; //sets front to a new node
      front -> elem = el; //puts data in front node
      rear = front; //sets rear to front
      rear->next = rear->prev = NULL;
    }
  else
    {
  rear -> next = new node; //make the node of the rear point to a new one
  node* p = rear; //set p to the old rear
  rear = rear -> next; //rear points to the new node
  rear -> prev = p; //set rear prev to the old rear
  rear -> next = NULL; //new node points to NULL
  rear -> elem = el; //put data in rear node
    }
  count++; //increment count
}

//this function will add to the front of the linked list
void DLL::addFront(el_t el)
{
  if(isEmpty())
    {
      front = new node; //set front and rear to a new node
      front->elem = el; //put data into front
      rear = front; //front and rear are the same
      front->next = NULL; //set front next and prev to null
      front->prev = NULL; 
    }
  else
    {
      node* p = new node; //create new node
      p->next = front; // p next points to front which is now second
      front->prev = p; //set front prev to p
      p->elem = el; //put element in p elem
      front = p; //put p as the new front
      front->prev = NULL; //new front previous is null
    }
  count++; //increment count
}

//this function will display each element of the queue starting from front
void DLL::displayAll() const
{
  if(isEmpty()) //if its empty
    {
      cout << "[Empty]" << endl;
    }
  else
    {
      node* p = front; //set p to front
      while(p != NULL) //while p isnt null
	{
	  cout << "[" << p -> elem << "] "; //print them out
	  p = p -> next; 
	}
    }
}

//This function will print the Linked list in reverse
void DLL::printAllReverseDLL()
{
  for(node* p = rear; p != NULL; p = p->prev)
    {
      cout << p->elem << " ";
    }
}

//This function will return true if e is found in the linked list. Otherwise return false
bool DLL::search(el_t e)
{
  for(node* p = front; p != NULL; p = p->next) //for loop that goes through entire list
    {
      if(p-> elem == e) //if e is found 
	{
	  return true; //returns true
	}
    }
  return false; //returns false if not found
}

//this function will delete the node that holds element e. only the first one will be deleted
void DLL::deleteNode(el_t e)
{
  node* pre;
  node* del;
  if(isEmpty()) //if empty
    {
      return; //do nothing
    }
  if(e == front-> elem) //if e is the front element
    {
      deleteFront(); //call delete front
    }
  else //if e is not the front
    {
      for(del = front->next; del != NULL && del-> elem != e;  del = del->next)  //makes del the element wanted to be deleted. makes pre to be the node before del
	{
	  ;
	}
      if(del != NULL) //if del is not null, e is found
	{
   	  if(del == rear) //if del equals rear 
            {
	      deleteRear(); //call delete rear
            }
	  else
	    {
	  del->prev->next = del->next;
          del->next->prev = del->prev;
	  delete del; 
	  count--;
	    }
    	}
    }
}

void DLL::deleteNodes(el_t e)
{
  node* del;
  if(isEmpty()) //if empty
    {
      return; //do nothing
    }
  if(e == front-> elem) //if e is the front element
    {
      deleteFront(); //call delete front
    }
   if(!isEmpty()) //if e is not the front or empty
    {
      for(del = front->next; del != NULL && del-> elem != e; del = del->next)  //makes del the element wanted to be deleted. makes pre to be the node before del
        {
          ;
        }
      while(del != NULL) //if del is not null
        {
	  if(del->elem == e) //if the element u want to delete is found
	    {
	      if(del != rear)
		{
		  del -> next -> prev = del -> prev; //the node after del points back to the node before del
		}
	      else //if del is rear
		{
		  rear = del-> prev; //rear to del prev
		}
	      del -> prev -> next = del->next; // the node before del points to the node after del
      	      delete del; //delete del
     	      count--; //decrement count
	    }      
	  else //if its not found
	    {
	      del = del->next;
	    }
	}
    }
}

//add a new node in ascending order
void DLL::addInOrderAscend(el_t e)
{
  if(isEmpty()) //if its empty
    {
      addFront(e);
    }
  else if(e < front->elem) //if you want to insert the element to the very front
    {
      addFront(e);
    }
  else //if its somewhere else, in middle or end
    {
      node* p; //create node p
      p = front; //p starts at front
      while(p->next != NULL && p->next->elem < e) //p points to node before insertion
	{
	  p = p-> next; //increment p
	}
	 node* n = new node; //create a new node
	  n -> elem = e; //put e in the element of x node
	  if(e > rear-> elem) //if e is the at the rear
	    {
	      addRear(e); //call addRear
	    }
	  else //if its not at the rear
	    {
	  n -> next = p-> next; //n next points to what p next was pointing to
	  n -> prev = p; //n previous points to p
	  p->next = n; //p next now points to x node
	  n->next->prev = n; //the node next to n points back to n
	  count++; //increment count
	    }
    }
}
//this function will add a new node in order descending
void DLL::addInOrderDescend(el_t e)
{
  if(isEmpty()) //if its empty
    {
      addFront(e);
    }
  else if(e > front->elem) //if you want to insert the element to the very front
    {
      addFront(e);
    }
  else //if its somewhere else, in middle or end
    {
      node* p;
      p = front;
      while(p->next != NULL && p->next->elem > e) //p pointst to node before insertion
        {
          p = p-> next; //increment p
        }
      if(e < rear-> elem) //if e is the at the rear
	{
	  addRear(e); //call addRear
	}
      else
	{
      node* x = new node; //create a new node
      x -> elem = e; //put e in the element of x node
      x -> next = p-> next; //n next points to what p next was pointing to
      x -> prev = p; //n previous points to p
      p->next = x; //p next now points to x node
      x->next->prev = x; //the node next to n points back to n
      count++;
	}
    }
}

