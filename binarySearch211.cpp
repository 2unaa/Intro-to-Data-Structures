/***************************************************************************
CS211
Template created by Kazumi Slott
Implement binary search that works on an ascending and descending ordered list.
Your program will abort if the function doesn't return the correct value. 

Your name: Tuan Tran
*****************************************************************************/
#include <iostream>
#include <assert.h>
using namespace std;

void reverseArray(int a[], int s);
int binarySearchAscend(const int a[], int s, int key);
int binarySearchDescend(const int a[], int s, int key);

int main()
{
  const int SIZE = 10;
  int ar[SIZE] = {1, 10, 20, 30, 40, 50, 60, 70, 80, 90};

  //test binarySearchAscend()
  for(int i = 0; i < SIZE; i++)
    assert(binarySearchAscend(ar, SIZE, ar[i]) == i);  //assert() terminates the program if the condition is false.

  assert(binarySearchAscend(ar, SIZE, 100) == -1); 


  //call reverseArray() to reverse the elements in ar 
  reverseArray(ar, SIZE);
  /* for(int i = 0; i < SIZE; i++)
    {
      cout << ar[i] << " ";
      }*/
  //test binarySearchDescend() - mimic how you tested binarySearchAscend()
  for(int i = 0; i < SIZE; i++)
    assert(binarySearchDescend(ar, SIZE, ar[i]) == i);  //assert() terminates the program if the condition is false.

  assert(binarySearchDescend(ar, SIZE, 100) == -1);
 
  return 0;
}



/****************************************************************************
This functioon reverse the contents of the array. Don't make a second array.
e.g. If ar is [5, 1, 3, 8, 2], this function changes the array to [2, 8, 3, 1, 5]
a is an integer array of any size.
s is the size of the array.
****************************************************************************/
void reverseArray(int a[], int s)
{
  for(int i = 0, j = s-1; i < s/2; i++, j--) //go through both sides of the middle of the array
    {
      int temp = a[i]; //set temp to the value of i
      a[i] = a[j]; //swap the two places
      a[j] = temp; //put temp in where j is
    } 
}


/****************************************************************************
This function returns the index where key is found or -1 if key is not found.
a is an integer array of any size sorted in ascending order.
s is the size of the array.
key is the number being searched for.
****************************************************************************/
int binarySearchAscend(const int a[], int s, int key)
{
  int l = 0; //left boudary starts at first index
  int r = s-1; //right boundary starts at last index
  int m; //middle point between left and right.

  //When l and r cross over, search ends. --> key was not found. 
  while(r >= l)
    {
      //calculate the middle point between l and r
      m = (r+l) / 2; //right plus left divided by 2

      if(key == a[m]) //key was found
	return m; //return index of where key was found
      else if(key < a[m]) //if the key is less than the middle
	r = m - 1; //move right to the left of middle
      else if(key > a[m]) //if key is greater than middle
	l = m + 1; //move left to the right of middle
    }
  
  return -1; //key wasn't found
}

/****************************************************************************                                                             
This function returns the index where key is found or -1 if key is not found.                                                             
a is an integer array of any size sorted in descending order.                                                                                                     
s is the size of the array.                                                                                                               
key is the number being searched for.                                                                                                     
****************************************************************************/
int binarySearchDescend(const int a[], int s, int key)
{
  int l = 0; //left boudary starts at first index                                                                                      
  int r = s-1; //right boundary starts at last index                                                                                     
  int m; //middle point between left and right.                                                                                           

  //When l and r cross over, search ends. --> key was not found.                                                                          
  while(l <= r)
    {
      //calculate the middle point between l and r                                                                                        
      m = (l+r) / 2;

      if(key == a[m]) //key was found                                                                                                       
        return m;
      else if(key < a[m]) //if key is less than the middle
	l = m + 1; //move left to the right of middle 
      else if(key > a[m]) //if key is greater than middle
        r = m - 1; //move right to the left of middle
    }

  return -1; //key wasn't found                                                                                                      
}
