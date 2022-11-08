#include <iostream>
#include "lqueue.h"
using namespace std;

//prototypes
void createReverseLL(LQueue& l, const string& s);
void addLLs(LQueue& l1, LQueue& l2, LQueue& t);

int main()
{
  //ask for user input
  string n1, n2;
  cout << "Enter integer 1: ";
  cin >> n1;
  cout << "Enter integer 2: ";
  cin >> n2;
  
  LQueue l1; //queue for number 1
  createReverseLL(l1, n1); //reverses it
  cout << "-- Displaying integer 1 in reverse order --" << endl;
  l1.displayAll();  //displays it
  cout << endl;

  LQueue l2; //queue for number 2
  createReverseLL(l2, n2); //reverses it
  cout << "-- Displaying integer 2 in reverse order --" << endl;
  l2.displayAll(); //displays it
  cout << endl;

  cout << "-- Total in reverse order --" << endl;
  l1.displayAll(); //displays l1 reverse
  cout << " + ";
  l2.displayAll(); //displays l2 reverse
  cout << " = ";
  LQueue total; //object for list that contains the total
  addLLs(l1, l2, total); //call the add function to add the numbers to get the total in reverse order

  total.displayAll(); //display the total number in reverse order
  cout << endl;
 
  cout << "-- Total in correct order --" << endl;
  cout << n1 << " + " << n2 << " = ";
  total.printAllReverse(); //call print reverse function to print in correct order
  cout << endl;

  return 0;
}

//this function converts the character string to an int. reverses the number.
//parameters: the queue object and string object
void createReverseLL(LQueue& l, const string& s)
{
  for(int i = s.length() - 1; i >= 0; i--) //goes through string backwards
    {
      int num = s[i] - '0'; //converts each char to num
      l.addRear(num); //add to linked queue
    }
}

//this function will add both queues together and add to the total queue
//parameters: both queue objects for both numbers. queue object for the total
void addLLs(LQueue& l1, LQueue& l2, LQueue& t) 
{
  int carryover = 0; //carryover variable
  int num1; //num1 for the first number queue
  int num2; //num2 for the second number queue
  int sum; //sum for the total number queue
  while(!l1.isEmpty() || !l2.isEmpty()) //while l1 or l2 queues are not empty
    {
      if(l1.isEmpty()) //if l1 is empty
	{
	  num1 = 0; //set num1 to 0 
	}
      else //if its not empty
	{
	  num1 = l1.deleteFront(); //delete the front number in the first number queue and set num1 equal to it  
	}
      if (l2.isEmpty()) //if l2 is empty
	{
	  num2 = 0; //set num2 to 0 
	}
      else //if its not empty
	{
	  num2 = l2.deleteFront(); //delete the front number in the second number queue and set num2 equal to it
	}
      sum = num1 + num2 + carryover; //add the front numbers with carryover (+0 if no carryover, +1 if carryover) and set sum equal to it
      if(sum >= 10) //if the total of the two numbers is greater than or equal to 10
	{
	  t.addRear(sum - 10); //puts the sum to the rear of the total queue but subtract 10
	  carryover = 1; //set carryover to 1 so that for the next loop it'll add +1 for the carryover
	}
      else //if the total of the two numbers is not greater than or equal to 10
	{
	  t.addRear(sum); //add sum to the rear of the total queue
	  carryover = 0;
	}
    } //end of while loop
   if(carryover == 1 && sum >= 10) //if the carryover is 1 at the very end and sum is greater than or equal to 10 at the end
    {
      t.addRear(1); //add 1 to the rear at the end so it does not leave out the last carryover
    }
}



