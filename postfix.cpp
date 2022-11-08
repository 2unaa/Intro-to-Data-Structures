#include "stack.h"
#include <iostream>
using namespace std;

//prototypes
bool isOperator(char ch);
bool isOperand(char ch);
int doMath(int opr1, char opt, int opr2);
int charToInt(char ch);

int main()
{
  Stack s; //stack
  string expr; //expression
  cin >> expr;
  char optr; //operator
  int oprL; //left operand
  int oprR; //right operand
  int result;
  bool error = false; //sets up so it'll stop if there is an error
  for(int i = 0; i < expr.length() && error == false; i++) //for loop to go through expr
    {
      if(isOperand(expr[i]) == true) //if operand is valid
	{
	  if(!s.isFull()) //if it is not full
	    {
	      s.push(charToInt(expr[i])); //pushes the operand
	    }
	  else //if it is full
	    {
	      cout << "Error: Expression is too long. " << endl;
	      error = true;
	    } 
	}
      else if(isOperator(expr[i]) == true) //if operator is valid
	{
	  optr = expr[i];
	  if(!s.isEmpty()) //check if its empty
	    {
	      oprR = s.pop(); //first pop
	      if(!s.isEmpty()) //if it is empty
		{
		  oprL = s.pop(); //second pop
		  result = doMath(oprL, optr, oprR); //calls doMath function
		  if(!s.isFull()) //if the stack isnt full
		    {
		      s.push(result); //push the answer
		    } 
		  else //if stack is full
		    { 
		      cout << "Error: Expression is too long" << endl;
		      error = true;
		    }
		} //closes second if isEmpty()
	      else //if stack is empty before the second pop
		{
		  cout << " Error: Not enough operands. " << endl;
		  error = true;
		}
	    } //closes first if isEmpty()
	      else//if stack is empty before the first pop
		{
		  cout << " Error: Not enough operands. " << endl;
		  error = true;
		}
	} //closes else if operator true
      else //if operator is invalid
	{
	  cout << "Error: Invalid expression found (" << expr[i] << ")" << endl;
	  error = true;
	}
    } //closes for loop

  if(!s.isEmpty() && error == false) //if it is not empty and theres no error
    {
      int total = s.pop(); //pop the top, should be the total. 
      if(!s.isEmpty())  //if it is still not empty
	{
	  cout << "Error: Too many operands." << endl;
	}
      else //if it is empty, completed.
	{
	  cout << "= " << total << endl;
	}
	}
  return 0;
}


/*************************************************************************************************
This function checks to see if the passed character is an operator: +, -, * or /. It returns true if it is one
of the operators, otherwise returns false.
ch is a character
*************************************************************************************************/
bool isOperator(char ch)
{
  return(ch == '+' || ch =='-' || ch == '*' || ch == '/')? true : false;

}
/*************************************************************************************************
This function checks to see if the passed character is a valid operand within 0 to 0. It returns true if it is one
of the operators, otherwise returns false.
ch is a character
*************************************************************************************************/
bool isOperand(char ch)
{
  return (ch >= '0' && ch <= '9')? true : false;
}
/*************************************************************************************************
This function will convert a character to an integer
ch is the character
*************************************************************************************************/
int charToInt(char ch) //converts a character to integer (if an token is a digit)
{
ch = ch - '0';
return ch;
}

/*************************************************************************************************
This function will do the math of the 2 operands that are popped and the operator it is using
opr1 is the first operand on the left, opt is the operator. opr2 is the operand on the right.
*************************************************************************************************/
int doMath(int opr1, char opt, int opr2)
{
  switch(opt)
    {
    case '+':
      return opr1 + opr2;
      break;
    case '-':
      return opr1 - opr2;
      break;
    case '*':
      return opr1 * opr2;
      break;
    case '/':
      return opr1 / opr2;
      break;
    }
}

