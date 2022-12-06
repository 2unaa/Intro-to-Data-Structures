#ifndef MYCSTRING_H
#define MYCSTRING_H
#include <iostream>

using namespace std;

int myStrLen(const char* cstr)
{
  int i;
  for(i=0; cstr[i] != '\0'; i++) //for loop goes through the char array
    {
      ;
    }
  return i; //return the length
}


void myStrcpy(char* dest, const char* source)
{
  int i;
  for(i = 0; source[i] != '\0'; i++) //for loop goes through the source char array
    {
      dest[i] = source[i]; //copies it to dest array
    }
  dest[i] = '\0'; 
}

void myStrcat(char* dest, const char* source)
{
  int d = myStrLen(dest);
  int i;
  for(i = 0; source[i] != '\0'; i++) //for loop goes through the source char array
    {
  dest[d++] = source[i]; //copies it
    }
  dest[d] = '\0'; //places '\0' at the end
}

int myStrcmp(const char* cstr1, const char* cstr2)
{
  int i; //i is used after the for loop.
  for(i = 0; cstr1[i] != '\0' || cstr2[i] != '\0'; i++)
    {
      if(cstr1[i] != cstr2[i]) //if both cstrings are not the same
	{
	  return (cstr1[i] - cstr2[i]); //checks which is shorter and longer
	}
    }
  return 0; //return 0 if same
}



/****************************************************************************
This function returns the index where key is found or -1 if key is not found.
a is an integer array of any size sorted in ascending order.
s is the size of the array.
key is the number being searched for.
****************************************************************************/
int binarySearchAscend(const char** a, int s, char* key)
{
  int l = 0; //left boundary starts at first index
  int r = s-1; //right boundary starts at last index
  int m; //middle point between left and right.

  //When l and r cross over, search ends. --> key was not found.
  while(r >= l)
    {
      //calculate the middle point between l and r
      m = (r+l) / 2; //right plus left divided by 2
      int finder = myStrcmp(a[m], key); //call comp class to find the class
      if(finder == 0) //if it was found
        return m; //return index of where key was found
      else if(finder > 0) //if the key is less than the middle
        r = m - 1; //move right to the left of middle
      else if(finder < 0) //if key is greater than middle
        l = m + 1; //move left to the right of middle
    }

  return -1; //key wasn't found
}

#endif

