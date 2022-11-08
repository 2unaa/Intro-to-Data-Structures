/****************************************************
Template written by Kazumi Slott
CS211
selection sort lab

This program has 4 different selection sort functions.
*****************************************************/
#include <iostream>
#include "array.h" //include your array.h
#include <cstdlib>
using namespace std;

void selectionSort1(int array[], int N);
void selectionSort2(int array[], int N);
void selectionSort3(int array[], int N);
void selectionSort4(int array[], int N);
void test(int code);

int main()
{
  cout << "------ testing selectionSort1: Ascending moving largest to end  ------" << endl;
  test(1);
  cout << "\n------ testing selectionSort2: Descending moving smallest to end  ------" << endl;
  //??????
  test(2);
  cout << "\n------ testing selectionSort3: Ascending moving smallest to beginning  ------" << endl;
  //??????
  test(3);
  cout << "\n------ testing selectionSort4: Descending moving largest to beginning  ------" << endl;
  //??????
  test(4);
  cout << endl;
  return 0;
}

//This function fills the array with random numbers between 1 and 100
void fill(int arr[], int s)
{
  srand(time(0));
  for(int i=0; i < s ; i++)
    {
      arr[i]=  rand() % 100 + 1;
    }
}


//code = 1 for selectionSort1
//       2 for selectionSort2
//       3 for selectionSort3
//       4 for selectionSort4

void test(int code)
{
 const int SIZE = 10;  //make a constant SIZE set to 10
 
 int array[SIZE]; //declare an integer array using SIZE  

 fill(array, SIZE); //fill the array by calling fill()

 print(array, SIZE);  //print the array by calling print() in array.h

 switch(code)
   {
   case 1:
     selectionSort1(array, SIZE);
     cout << endl;
     break;
   case 2:
  selectionSort2(array, SIZE);
  cout << endl;
     break;
   case 3:
  selectionSort3(array, SIZE);
  cout << endl;
     break;
   case 4:
  selectionSort4(array, SIZE);
  cout << endl;
     break;
   } //create a switch statement here to call a different sort function depending on the code.
  //?????

 print(array, SIZE);  //print the array - hopefully the numbers are sorted correctly

}


//this function sorts the numbers in ascending order by moving the largest to the end: smallest to largest
void selectionSort1(int array[], int N) 
{
  int lrgIndx; //the index of the largest value
  int temp; //temporary variable that holds the largest value

  //last is the last index in unsorted part
  for(int last = N-1; last >= 1; last--) 
    {
      lrgIndx = 0; //assume the first item is the largest
      //find the largest in unsorted part ([0..last])
      for(int i = 1; i <= last; i++) 
	{
	  if(array[i] > array[lrgIndx]) //The current item is larger 
	    lrgIndx = i;
	}

      //swap the largest with the last item in the unsorted part
      temp = array[lrgIndx]; 
      array[lrgIndx] = array[last]; 
      array[last] = temp;
    } 
}



//Change this function so it sorts the numbers in descending order by moving the smallest to the end: largest to smallest                                                                    
//You can change the variable names to suit their purposes. 
//The structure of this code shouldn't change.
void selectionSort2(int array[], int N)
{
  int smallIndx; //index that holds the smallest                                                                                                                                               
  int temp; // temp to hold the smallest
                                                                                                                                        
  for(int last = N-1; last >= 1; last--) //last = last index of array
    {
      smallIndx = 0; // assumes first index is smallest
                                                                                                                                      
      // find the smallest in unsorted part                                                                                                                 
      for(int i = 1; i <= last; i++)
        {
          if(array[i] < array[smallIndx]) //the current slot is smaller                                                                                                                           
            smallIndx = i;
        }

      //swap the smallest with last item in unsorted part               
      temp = array[smallIndx];
      array[smallIndx] = array[last];
      array[last] = temp;
    }
}




//Change this function so it sorts the numbers in ascending order by moving the smallest to the beginning: smallest to largest                                                                
//You can change the variable names to suit their purposes.                                                                                                                                   
//The structure of this code shouldn't change.
void selectionSort3(int array[], int N)
{
  int smallIndx; //index that holds smallest                                                                                                                                                            
  int temp; //temp to hold smallest                                                                                                                                                                                                                                                                                                                                       
  for(int first = 0; first < N-1; first++) //makes first equal to 0 and goes through the array, stops at the last one
    {
      smallIndx = first; //moves up slot everytime                                                                                                                                                                                                                                                         
      for(int i = first + 1; i < N; i++) //finds smallest after first
        {
          if(array[i] < array[smallIndx]) //if less then                                                                                                   
            smallIndx = i;
        }

      //swap the smallest with the first item in the unsorted part                                                                                         
      temp = array[smallIndx];
      array[smallIndx] = array[first];
      array[first] = temp;
    }
}



//Change this function so it sorts the numbers in descending order by moving the largest to the beginning: largest to smallest                                                                
//You can change the variable names to suit their purposes.                                                                                                                                   
//The structure of this code shouldn't change.
void selectionSort4(int array[], int N)
{
  int lrgIndx; //index that holds largest index                                                                                                                                                                       
  int temp; //temp to hold largest                                                                                                                        
  for(int first = 0; first < N-1; first++) ////makes first equal to 0 and goes through the array, stops at the last one
    {
      lrgIndx = first; //moves up slot everytime                                                                                                           

      for(int i = first + 1 ; i < N; i++)  //finds largest after first
        {
          if(array[i] > array[lrgIndx]) //if greater than                                                                                                
            lrgIndx = i;
        }
      //swap largest with the first item in the unsorted part                                                                                            
      temp = array[lrgIndx];
      array[lrgIndx] = array[first];
      array[first] = temp;
    }
}











