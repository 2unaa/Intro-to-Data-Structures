#include "myCstring.h"
#include <iostream>

using namespace std;

//prototypes
void showResult();

int main()
{
  showResult(); 

  return 0;
}

void showResult()
{
  const char* badAr[4] = {"funky", "idiot", "stinky", "stupid"}; //bad words array 
  char wd[10]; //words array
  char all[111] = ""; //good words array
  char longestWd[10] = ""; //for the longest word
  char shortestWd[10] = "xxxxxxxxx"; //for the shortest word
  
  for(int i = 0; i < 10; i++) //to loop through entire array
    {
      cout << "Enter a word: ";
      cin >> wd;
      
      int found = binarySearchAscend(badAr, 4, wd); //search through the array to find the bad words and put it into the bad words array
      if(found == -1) //if bad words werent found
	{
	  myStrcat(all, wd); //put the words into the good words array
	  myStrcat(all, ",");
	  
	  if(myStrLen(longestWd) <= myStrLen(wd)) //to find the longest word 
	    {
   	      myStrcpy(longestWd, wd); //copy the word
	    }
	  if(myStrLen(shortestWd) >= myStrLen(wd)) //to find the shortest word
	    {
	      myStrcpy(shortestWd, wd); //copy the word 
	    }
	}
    }
  cout << "Longest word: " << longestWd << endl; //print the long word
  cout << "Shortest word: " << shortestWd << endl; //print the short word
  cout << "All words minus bad words: " << all << endl; //print the good words
  
}

