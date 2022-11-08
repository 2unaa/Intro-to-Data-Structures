#include "LL_T.h"
#include <iostream>
#include <fstream>
using namespace std;

//prototypes: 
void createLL(const string s, LL<char>& a);
bool isLetter(char c);
char myToLower(char c);
bool palindrome(LL<char>& a);

int main()
{
  string s; //string
  ifstream fin; //open file
  fin.open("/cs/slott/cs211/palindrome.dat"); //open the file
  while(getline(fin, s)) //while there is stuff to cin
    {
      LL <char> b; //linked list
      createLL(s, b); //convert string into the linked list
      if(palindrome(b) == true) //if it is palindrome
	{
	  cout << s << " is a palindrome." << endl;
	}
      else //if not palindrome
	{
	  cout << s << " is not a palindrome." << endl;
	}
    }
  fin.close(); //close file

  return 0;
}

//this function will create a linked list with the string that the user enters
//parameters: string and linked list
void createLL(const string s, LL<char>& a)
{
  for(int i = 0; i < s.length(); i++) //goes through entire string array
    {
      if(!isLetter(s[i])) //if its not a character
	{
	  continue; //continue skips everything and moves to the next character
	}
      else //if it is a character
	{
	  a.addFront(myToLower(s[i]));
	}
    }
}

//this function will return true if it is a letter and return false otherwise
//parameters: character to be checked
bool isLetter(char c)
{
  return (c >= 'A' && c <= 'Z' || c >= 'a' && c <= 'z') ? true : false;
}

//this function will make every uppercase letter a lowercase letter
//parameters: character to convert
char myToLower(char c)
{
  if(c >= 'A' && c <= 'Z') //if its a uppercase
    {
      c = c + 32; //make it a lowercase
    }
  return c;
}

//this function will return true if the list is a palindrome, false otherwise
//parameters: linked list
bool palindrome(LL<char>& a)
{
  while(!a.isEmpty()) //while the list is not empty
    {
      char f = a.deleteFront(); //delete the front and set it to f(front)
      char r = f; //set r(rear) equal to the front that was deleted
      if(!a.isEmpty()) //if the list is still not empty
	{
	  r = a.deleteRear(); //delete the rear  and set it to r
	}
      if(f != r) //if front and rear are not the same
	{
	  return false; //return false because they are not the same
	}
    }
  return true; //return true if all the characters are the same throughout the entire list.
}

