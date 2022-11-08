#include <iostream>
#include "/cs/slott/cs211/checkInput.h"
#include "stack.h"

//prototypes
int getBase();
char convertToChar(int n);
void convertStack(int n, int b);
void convertRec(int n, int b);

int main()
{
  int dec;
  int base;
  cout << "Enter a number in base 10: ";
  dec = getData(1, 999999, "Number out of range"); //use getData to get the decimal
  base = getBase(); //use getBase to get the base
  cout << "----------- Using recursion ---------------" << endl;
  convertRec(dec, base); //call recursion
  cout << endl;
  cout << "----------- Using a stack ---------------" << endl;
  convertStack(dec, base); //call stack
  cout << endl;

  return 0;
}

/****************************************************************************
This function asks for a number system to which a decimal number is converted,
either 2, 8 or 16.
It rejects bad inputs other than 2, 8 or 16.
It returns either 2, 8 or 16
****************************************************************************/
int getBase()
{
  int base;
  cout << "Enter a base to convert to: ";
  cin >> base;
  if(base == 2 || base == 8 || base == 16) //if the base is 2, 8 or 16
    {
      return base;
    }
  else
    {
      cout << "Invalid base." << endl;
      return getBase(); //recursion to go back
    }
}

/****************************************************************************
This function receives an integer between 0 and 15 and returns the character.
If n = 0 .. 9, it returns '0' .. '9'
If n = 10 .. 15, returns 'A' .. 'F'
n is an integer between 0 and 15
****************************************************************************/
char convertToChar(int n)
{
  if(n >= 0 && n <= 9) //if the number is between 0-9
    {
      return (char) n + '0'; //convert to char
    }
  else if(n >= 10 && n <= 15) //if the number is between 10-15
    {
      char ch;
      ch = n-10 + 'A'; //convert to char
      return ch;
    }
  else
    {
      cout << "invalid number to convert to character. " << endl;
    }
}

/***************************************************************************
This is a recursive function to convert a decimal number to a different number
system and print it.
n is a decimal number
b is a number system to which n is converted, either 2, 8 or 16
***************************************************************************/
void convertRec(int n, int b)
{
  if(n == 0) //base case: when decimal gets to 0
    return;
  else //when its anything else
    {
      convertRec(n/b, b); //divide
      cout << convertToChar(n % b); //get the remainder
    }
}

/**************************************************************************
This function uses a stack to convert a decimal number to a different number
system and prints it.
This is not a recursive function.
n is a decimal number
b is a number system to which n is converted, either 2, 8 or 16
**************************************************************************/
void convertStack(int n, int b)
{
  Stack s; //create stack
  while(n != 0) //while the decimal isnt 0
    {
      s.push(convertToChar(n % b)); //push the remainder to the stack and convert to char so it'll work for 16.
      n = n / b; //divide it
    }
  while(!s.isEmpty()) //while the stack isnt empty
    {
      cout << s.pop(); //pop the remainders
    }
}
