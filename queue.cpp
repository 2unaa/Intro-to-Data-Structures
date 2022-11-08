#include "queue.h"
#include <iostream>
#include <cstdlib>
using namespace std;

//default constructor
queue::queue()
{
  count = 0;
  front = 0;
  rear = -1;
}
//checks if its empty
bool queue::isEmpty() const
{
  return (count == 0) ? true : false;
}

bool queue::isFull() const
{
  return (count == MAX) ? true : false;
}

void queue:: queueError(string msg)
{
  cout << msg << endl;
  exit(1);
}

void queue:: add(el_t e)
{
  if(isFull())
    {
      queueError("queue overflow");
    }
  rear = (rear + 1) % MAX;
  el[rear] = e;
  count++;
}

el_t queue:: remove()
{
  if(isEmpty())
    {
      queueError("queue underflow");
    }
  else
    {
      el_t frnt = el[front];
      front = (front+ 1) % MAX;
      count--;
      return frnt;
    }
}

el_t queue:: getFront()
{
if(isEmpty())
  {
    queueError("empty queue");
  }
 else
   {
     return el[front];
   }
}

void queue:: goToBack()
{
  if(isEmpty())
    {
      queueError("empty queue");
    }
  else if(count > 1)
    {
      el_t temp = remove();
      add(temp);
    }
}

int queue::getSize()
{
  return count;
}

ostream& operator<<(ostream& o, const expr& p)
{
  o << p.oprd1 << p.oprt << p.oprd2;
  return o;
}


void queue::displayAll() const
{
  if(count == 0)
    {
      cout << "[empty]" << endl;
    }
  else
    {
      for(int i = front; i != rear; i = (i+1) % MAX)
        {
          cout << "[" << el[i] << "]";
        }
      cout << "[" << el[rear] << "]" << endl;
    }
}
