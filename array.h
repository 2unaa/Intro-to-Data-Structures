/*****************************************************
Template prepared by Kazumi Slott
CS211
lab on template functions
This header file provides useful operations on an array
of any data type.

Your name: Tuan Tran
*****************************************************/
#ifndef ARRAY_H
#define ARRAY_H
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

/********************************************
This function fills the array with data entered from the keyboard.

ar is an array of any data type
n is the number of items entered into ar
********************************************/
template <class T>
void fill(T ar[], int n)
{
  for(int i = 0; i < n; i++) // looks through entire array
    {
      cout << "Enter an item: " << endl;  //asks for user input
      cin >> ar[i];  // fills the array
    }
}

/********************************************
This function prints the array.

ar is an array of any data type
n is the number of items in ar
********************************************/
template <class T>
void print(const T ar[], int n)
{
  for(int i = 0; i < n; i++) // looks through entire array
    {
     cout << ar[i] << " "; // prints array
    }
}

//this function prints out the array to a file
template <class T ,class O>
  void printf(O& out, const T ar[], int n)
{
  for(int i = 0; i < n; i++) // looks through entire array
    {
      out << ar[i] << " "; // prints array
    }
}


/*******************************************
This function returns the index of the highest value.

ar is an array of any data type.
n is the number of items in ar
*******************************************/
template <class T>
int getHighest(const T ar[], int n)
{
  int LgIndex = 0; //index of largest value
  for(int i = 1; i < n; i++) //looks through entire array
    {
      if(ar[i] > ar[LgIndex]) //if the array slot is larger than the other slot
	LgIndex = i; //is equal to the index of the largest value
    }
  return LgIndex; //returns the index of largest value
}

/*******************************************
This function returns the index of the lowest value.

ar is an array of any data type.
n is the number of items in array
*******************************************/
template <class T>
int getLowest(const T ar[], int n)
{
  int SmallIndex = 0; //index of smallest  value
  for(int i = 1; i < n; i++) //looks through entire array
  {
    if(ar[i] <  ar[SmallIndex]) // if the array slot is smaller than the other slot
      SmallIndex = i; //is equal to index of smallest value
  }
  return SmallIndex; // returns index of smallest value
}

/********************************************
This function returns the average.

ar is an array of any data type.
n is the number of items in ar
********************************************/
template <class T>
double getAvg(const T ar[], int n)
{
  double avg;
  for(int i = 0; i < n; i++) //goes through entire array
    {
      avg = avg + ar[i]; //adds every slot together
    }
  avg = avg / (double) n; //divide by size of array
  return avg; //returns average
}

/*******************************************
This function stores unique items into an array
and returns the number of the unique items.
  e.g.  If ar contains  9 3 5 3 9 1 9
        uniqAr gets 9 3 5 1
        The function returns 4  
       
ar is the original array of any data type
uniqAr is the array that will have only unique items
n is the number of items in ar and uniqAr
*******************************************/
template <class T>
int unique(const T ar[], T uniqAr[] , int n)
{
  int counter = 0; //set counter to 0 so it starts at the first index
  int i; //for original array
  int j; //for unique array
   for(i = 0; i < n; i++) //go through original array
     {
       for(j = 0; j < i; j++) //comparing both arrays
 	{
 	  if(ar[i] == uniqAr[j]) //if value is already in uniqAr
 	     {
 	       break; // stop comparing those values so they dont copy into uniqAr
 	     }
 	}
      if(i == j) //if they're the same index
	{
	  uniqAr[counter] = ar[i]; //puts value in uniqAr
	  counter++; //moves index each time it happens
	}
    }
  return counter; //retuns amount of unique numbers
}

/***********************************************
This function sorts the items in ascending order: smallest to largest

array is an array of any data type
N is the number of items in the array
**********************************************/                                                

//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//The following function sorts an integer array in ascending order 
//using the selection sort algorithm.
//You need to change this code so it works with an array of any data type.
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
template <class T>
void sort(T array[], int N)
{
  int lrgIndx; //the index of the largest value                                                                                         
  T temp; //temporary variable that holds the largest value                                                                                  

  //last is the last index in unsorted portion                                                                                             
  for(int last = N-1; last >= 1; last--)
    {
      lrgIndx = 0; //assume the first item is the largest                                                                                      
      //find the largest in unsorted portion ([0..last])                                                                                       
      for(int i = 1; i <= last; i++)
        {
          if(array[i] > array[lrgIndx]) //The current item is larger                                                                           
            lrgIndx = i;
        }
      //swap the largest with the last item in the unsorted portion           
      temp = array[lrgIndx];
      array[lrgIndx] = array[last];
      array[last] = temp;
    }
}

//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//The following function sorts an integer array in descending order
//using the bubble  sort algorithm.
//You need to change this code so it works with an array of any data type.
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
template <class T>
void bubbleSort(T array[], int size)
{
  bool done = false;
  T temp;
 
  while (!done) // array is not fully sorted
    {
      done = true; //which parts are sorted correctly
      for(int i = 0; i < size-1; i++) // each adjacent pair of items in the unsorted part
	{
	  if(array[i] <  array[i+1]) // the pair of items are out of order
	    {
	      temp = array[i];
	      array[i] = array[i+1]; // swap the pair of items
	      array[i+1] = temp;
	      done = false; //array is not fully sorted
	    }
	}
      size--; //shorten number of pairs that need to be checked
    }
}
//This function will create a find key that will search through the array for a specific key
template <class T1, class T2>
int find(const T1 array[], int size, const T2& key)
{
  for(int i = 0; i < size ; i++)
    {
      if(array[i]== key)
	{
	  return i;
	}
    }
	  return -1;
}

template <class T1, class T2>
bool remove(T1 array[], int size, T2 key)
{
int finder = find(array, size, key);
 if(finder != -1)
   {
     for(int i = finder; i < size-1; i++)
       {
	 array[i] = array[i+1]; //copies every value to the right
       }
     return true; //outside so it checks every single input
   }
 else
   {
     return false;
   }
}

#endif
