#include <iostream>
#include "array.h"
#include <fstream>
#include <string>
using namespace std;
#include "/cs/slott/cs211/checkInput.h"
//prototypes
int showMenu();
void getVisitorInfo(string arS[], int arI[], double arD[], int s, int& i);
bool checkPassword();
template <class O>
void showStatistic(O& out, string arS[], int arI[], double arD[], string uniqAr[], int i);

int main()
{
  const int size = 100; //size of all the arrays
  string arrS[size]; //country array
  int arrI[size]; //age array
  double arrD[size]; // hours array
  int visitors = 0; //visitors in museum
  char YN; //character choice to close museum
  string UniqS[size]; //unique array for country

do
{
  int choice = showMenu(); 
  if(choice == 1) //if the user picks 1 as visitor
   {
     getVisitorInfo(arrS, arrI, arrD, size, visitors); //call to get the info of each visitor and fill the arrays
   }
  else //if user picks 2 as staff
   {
bool password = checkPassword();
 if(password == true) //if password is correct
       {
	 if(visitors == 0) //if there are no visitors
	   {
	     cout << "The total number of visitors is 0" << endl; 
	   }
	 else //if there are visitors
	   {
	 showStatistic(cout, arrS, arrI, arrD, UniqS, visitors); //call showStats to display in the output
	   }
	 cout << " Do you want to close museum? Y or N: ";
	 YN = getYN("Invalid answer, answer Y or N: ");
	 if(YN == 'Y' || YN == 'y') //if user enters Y or y to close museum
	    {
	      ofstream fout;
	      string date;
	      string filename;
	      cout << "Enter today's date: "; //gets the date
	      cin >> date; 
	      filename = date + ".txt"; //makes filename be date.txt
	      fout.open(filename.c_str()); //open and create file with the filename
	      showStatistic(fout, arrS, arrI, arrD, UniqS, visitors); //call showStats again but for fout so the entire thing goes into file
	      fout.close(); //close file
	      return 0;
	    }
       }
 else //if password is wrong
       {
	 cout << "Password is wrong." << endl;
       }
   }
 }
 while(YN != 'Y' || YN != 'y' && visitors < size); //so it continues to show menu until you close museum
  return 0;
}


//this function will show the menu and asks if the user is a visitor or museum staff
int showMenu()
{
  cout << "=============================================" << endl << "1. Visitor" << endl << "2. Museum Staff" << endl << "Enter your choice: ";
  int userChoice = getData(1, 2, "Invalid choice. Enter 1 or 2: " );
  return userChoice; 
}


//this function will get the visitors info and fill it into the arrays.
//parameters: arS is for the country array. arI is for the age array. arD is for the hours array. s is the size. i is the number of visitors. 
void getVisitorInfo(string arS[], int arI[], double arD[], int s, int& i)
{
  if(i < s) //if there is still size for the arrays
    {
  string country;
  cout << "Enter your country: ";
  cin >> country;
  arS[i] = country; //fills country array

  cout << "Enter your age: ";
  int userAge = getData(0, 200, "The age has to be between 0 and 200. Enter again: ");
  arI[i] = userAge; //fills age array

  cout << "Enter hours you spent at museum: ";
  double userHours = getData(0.0, 10.0, "The hours has to be between 0 and 10.0. Enter again: ");
  arD[i] = userHours; //fills hours array

  i++; //increment it
    }
  else //if the size is full
    {
      cout << "Can't take anymore visitor info" << endl;
    }
}

//this function will check to see if the user entered the right password for the staff
bool checkPassword()
{
  int password = 5678; //the password
  int userinput; 
  cout << "Enter the password: " ;
  cin >> userinput;
  if(userinput == password) //if user input is the correct password
    {
      return true;
    }
  else //if user input is the wrong password
    {
      return false;
    }
}


//this function will show the statistics of all the visitors, show the countries in alphabetical order, print out the youngest, oldest and average age. and also the shortet, longest, and average hours.
template <class O>  //template function
void showStatistic(O& out, string arS[], int arI[], double arD[], string uniqAr[], int i)
{
  out << "The total number of visitors is " << i << endl; //use out so it can be in the file
  out << "----- The names of the countries of visitors -----" << endl;
  int counter = unique(arS, uniqAr, i);
  sort(uniqAr, counter);
  print(out, uniqAr, counter);
  cout << endl;
  int youngest = getLowest(arI, i);
  out << "The age of the youngest visitor is: " << arI[youngest] << endl;
  int oldest = getHighest(arI, i);
  out << "The age of the oldest visitor is: " << arI[oldest] << endl;
  double average = getAvg(arI, i);
  out << "The average age of the visitor is: " << average << endl;

  int shortest = getLowest(arD, i);
  out << "The shortest visit hours: " << arD[shortest] << endl;
  int longest = getHighest(arD, i);
  out << "The longest visit hours: " << arD[longest] << endl;
  double hourAverage = getAvg(arD, i);
  out << "The average visit hours: " << hourAverage << endl;

}


