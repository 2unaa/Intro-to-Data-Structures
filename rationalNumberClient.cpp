/********************************************
Template created by Kazumi Slott
CS211
Date: 2/18/2022
Your name: Tuan Tran
Description of your program: This program will add, sort and simplify rational numbers
********************************************/
#include <iostream>
using namespace std;
#include "array.h"  //This is your array.h
#include "rationalNumber.h"//?????????

int main()
{
  rNum n1;
  rNum n2;
  rNum n3;
  rNum ans;

  cout << "\n-------------- 1 -----------------" << endl;
  cout << "Rational Number 1:" << endl;
  cin >> n1;
    
  cout << "n1 is " << n1 << endl;
 
  cout << "\n-------------- 2 -----------------" << endl;
  cout << "\nRational Number 2" << endl;
  cin >> n2;
  
  cout << "n2 is " << n2 << endl; 
 
  cout << "\n-------------- 3 -----------------" << endl;
  ans = n1 + n2;
  ans.simplify();  //simplifies the answer
cout << n1 << " + " << n2 << " = " << ans << endl;
  cout << "\n-------------- 4 -----------------" << endl;
  const int SIZE = 3;
  //Declare an array of rNums that has SIZE slots
  rNum array[SIZE];
    //fill the array by calling fill() in your array.h
  fill(array, SIZE); 

   cout << "Checking to see if the array is filled" << endl;
  //print the array by calling print() in your array.h
  print(array, SIZE);

  cout << "\n-------------- 5 -----------------" << endl;
  //sort the array in ascending order by calling sort() in your array.h
  sort(array, SIZE);

  cout << "Checking to see if the array is sorted in ascending order" << endl;
  //print the array by calling print() in your array.h
  print(array, SIZE);

  cout << "\n-------------- 6 -----------------" << endl;
  cout << "Checking to see if " << n1 << " is in the array " << endl;
  //Call find() in your array.h to see if n1 exists in the array. Say found or not found. See #6 in the test runs in the hw document.   
int finder = find(array, SIZE, n1);
 if(finder == true) //if it is found
   {
     cout << n1 << " is found";
   }
 else //if not found
   {
     cout << n1 << " is not found";
   }
 
  cout << "\n-------------- 7 -----------------" << endl;
  cout << "n1 is " << n1 << " n2 is " << n2 << " before n1 += n2" << endl;
  n1 += n2; 
  n1.simplify(); //simplifies n1
 
  cout << "After n1 += n2, n1 is " << n1 << endl << endl;
  return 0;
  }

