#include <iostream>
#include <cstdlib> //for atoi() <-- you might not use this
using namespace std;
#include "/cs/slott/cs211/checkInput.h"
#include "student.h"
#include "array.h"
#include "price.h"
const int SIZE = 100; //size of the array
const int START = 100000;//student id starts at 100000
const int PASSWORD = 123; //password for admission's office 
const int PRIME1 = 31; //used to calculate a student's password
const int PRIME2 = 5;

//prototypes
int showMenu();
int showAdmMenu();
int showStuMenu();
void addStu(Student ar[], int& n, int& i);
void showStuInfo(const Student& s);
void allStuInfo(const Student s[], int n);
bool operator==(const Student& s, int id);
void removeStu(Student ar[], int& i);
void addStuFromFile(Student ar[], int& i, int& n);
void addCourse(Student& s, int crn);
void dropCourse(Student& s, int crn);
void makePayment(Student& s);
bool checkPassword(int password);
int findStu(Student ar[], int s);


int main()
{
  int count = 0; //the number of students in the array
  int curID = START; //curID is the student id used for the next student you are creating
  Student StuAr[SIZE]; //student array
  int choice;
  int AdmChoice;
  int StuChoice;
  int crn;
  do //for the entire menu
  {
    choice = showMenu();
    switch(choice) //switch cases for the main menu
      {
      case 1: //case for admissions office
	{
	int AdmPW = checkPassword(PASSWORD);
	if(AdmPW == true) //if user entered the right password
	  {
	    do //for the admissions menu to print
	      {
		AdmChoice = showAdmMenu();
		if(AdmChoice == 1) //1: Add a new student
		  {
		    addStu(StuAr, count, curID);
		  }
		else if(AdmChoice == 2) //2: Add new students from a file
		  {
		    addStuFromFile(StuAr, count, curID);
		  }
		else if(AdmChoice == 3) //3: drop a student
		  {
		    removeStu(StuAr, count); 
		  }
		else if(AdmChoice == 4) //4: View one student info
		  {
		    int i = findStu(StuAr, SIZE);
		    if(i == -1) //if student ID isnt found
		     {
		       cout << " The student ID doesn't exist. " << endl;
		     }
		   else
		     {
		       showStuInfo(StuAr[i]); //show the info of the student
		     }
		  }
		else if(AdmChoice == 5) //5: View all students' info
		  {
		    allStuInfo(StuAr, count);
		  }
	      } 
	    while(AdmChoice != 6); //6: Quit
	  }
	break;
	}
      case 2: //case for student
	int StuI = findStu(StuAr, SIZE); //getting the student index
	if(StuI == -1) //if student ID isnt found
	  {
	    cout << " The student ID doesn't exist. " << endl;
	  }
	else //if student is found
	  {
	    int StuPW = checkPassword(StuAr[StuI].getStuID() % (PRIME1 * PRIME2)); //check password for student
	    if(StuPW == true)
	      {
		cout << "Welcome " << (StuAr[StuI].getFirstName());
		do //for the students menu to print
		  {
		    StuChoice = showStuMenu();
		    if(StuChoice == 1) //1: Add a course
		      {
			cout << "Enter a crn: ";
			cin >> crn;
			addCourse(StuAr[StuI], crn);
		      }
		    else if(StuChoice == 2) //2: Drop a Course
		      {
			cout << "Enter a crn: ";
                        cin >> crn;
                        dropCourse(StuAr[StuI], crn);
		      }
		    else if(StuChoice == 3) //3: Make a payment
		      {
			makePayment(StuAr[StuI]);
		      }
		    else if(StuChoice == 4) //4: View my information
		      {
			showStuInfo(StuAr[StuI]); //show the info of the student
		      }
		  }
		while(StuChoice != 5);  //5: Quit
	      }
	  }
	break;	    
      
      }
  }
  while(choice != 3); //3: End the program
  
  
  return 0;
}




// ************************  PHASE 1  ****************************

/********************************************
//this function will add a student to the student array.
//parameters: n is the id. i is the count. Student s[] is the student array
*********************************************/
void addStu(Student ar[], int& i, int& n)
{
  //case 1 of admission
  string fn;
  string ln;
  char gen;
  cout << "Enter the first name: ";
  cin >> fn;
  cout << "Enter the last name: ";
  cin >> ln;
  cout << "Enter the gender: " ;
  cin >> gen;
  cout << endl;
  if(i < SIZE) //if there is still size in the array
    {  
  //create a student object. The first student created is given a stu id, 100000 (coming from const START).
  //The second student gets 100001, the third student gets 100002, etc (notice curID in main).
  Student s(fn, ln, gen, n);
  ar[i++] = s; //copy info into array
  n++; //increment id
    }
  else //its full
    {
      cout << "College is full" << endl;
    }
}
/********************************************
//this function will show the student info of 1 student
//parameter: student object                  
*********************************************/                                                                       
void showStuInfo(const Student& s)                                             
{                                                                                                                                             
//*********************************************************************
//DO NOT send the entire array to this function. BIG deduction if you do.
//SEND only ONE student object as a parameter. If you don't know how, check
//lab1-struct.cpp.
//********************************************************************** 


  cout << "--------------------" << endl;                                                         
  //calling all the member functions for the student info                                                                                                   
  cout << "first name: " << s.getFirstName()  << endl;                                                                                                 
 
  cout << "last name: " << s.getLastName()  << endl;                                                                                                  
 
  cout << "gender: " << s.getGender() << endl;                                                                                                      
 
  cout << "stu id: " << s.getStuID() << endl;                                                                                                      
 
  cout << "num classes: " << s.getNumClasses()  << endl;                                                                                                  
 
                                                                                                                                            
  cout << "Courses: ";                                                                                                                        
 
  for(int i = 0; i < s.getNumClasses(); i++)  //goes through the classes student is taking
    {
      if(i == 0) //if its the first one
	{
	  cout << s.getClassOf(i);                    
	}
      else //if its not the first one have a comma in it
	{
	  cout << ", " << s.getClassOf(i);
	}
    }
                                                                                                                                              
  cout << "\nAmount owed $" << s.getBalance() << endl;  //You have an operator overloading function to show a price object at once                   
 
  cout << endl;                                                                                                                       
 
  }
/********************************************
//this function will show the all of the students with their info.
//parameters: student array and n is the count of students.
*********************************************/ 
void allStuInfo(const Student ar[], int n)
{
//Case 5 of Admission and case 4 of student
//Call showStuInfo()
//******************************************
//YOU MUST call showStuInfo() to show each student.
//*******************************************
  for(int i = 0; i < n; i++) //goes through the student array
    {
      showStuInfo(ar[i]); //prints out all the students and their info
    }
}
/********************************************
This passes the student object and the id of the student.
Returns true if student has id, false otherwise.
parameters: student object and id
*********************************************/
bool operator==(const Student& s, int id) 
{
  return(s.getStuID() == id) ? true : false;
}

/********************************************
//this function will remove a student to the student array.
//parameters: i is the count. Student s[] is the student array
*********************************************/
void removeStu(Student ar[], int& i)
{
//Case 3 of Admission

//2 different messages
  int id; 
  cout << "Enter the student id: ";
  cin >> id; //gets the users id they want to remove
  int found = find(ar, i, id); //call find to look through and find a student with that id
  if(found != -1) //if id is found is true
    {
      string fn = ar[found].getFirstName(); //gets the student first name that we want to remove
      string ln = ar[found].getLastName(); //gets the last name ^
      cout << fn << " " << ln << " has been removed." << endl; //print that it is removed
      remove(ar, i, id); //removes the student
      i--; //decrement the count
    }
  else //if id isn't found
    {
      cout << "student with id " << id << " doesn't exist" << endl; //print that it isnt removed
    }
}

/********************************************
//this function will add a student to the student array from a file. 
//parameters: n is the id. i is the count. Student s[] is the student array
*********************************************/

void addStuFromFile(Student ar[], int& i, int& n)
{
//Case 2 of admission
  ifstream fin; 
  string filename;
  string fn;
  string ln;
  char gen;
  cout << "Enter a file name: ";
  cin >> filename;
  fin.open(filename.c_str()); //open file
  if(!fin) //if file doesn't exists
    {
      cout << "File doesn't exist." << endl;
    }
  else //if file does exist
    {
      fin >> fn;
      fin >> ln;
      fin >> gen; //input first name last name and gender from file into the array
      while(fin && i < SIZE) //while there is still students left in the file
	{
	  Student s(fn, ln, gen, n); //create student object to put into array
	  ar[i++] = s; //copy info into array slot
	  fin >> fn; 
	  fin >> ln;
	  fin >> gen;  //input first last name and gender into array
	  n++; //increment id
	}
    }
  fin.close(); //close file
}




//*******************  PHASE 2 ****************************

/********************************************
//this function will add a course to a student with a message depending on it is successful or not. Will add a fee if it is added
//parameters: student object and class number
*********************************************/
void addCourse(Student& s, int crn)
{
  int c = s.addCourse(crn);
  if(c == 1) //if addcourse is 1
    {
      cout << crn << " has been added successfully." << endl;
      s.addFee(50,14);
    }
  else if(c == 0) //if addcourse is 0
    {
      cout << crn << " has not been added because you have " << crn << " already. " <<  endl;
    }
  else //if addcourse is -1)
    {
      cout << crn << " was not added because your schedule is full." << endl;
    }
}

/********************************************
//this function will drop the course that you wish to drop and will print a message on if you can drop it or not. Will also reduce your fee if you drop it
//parameters: student object and class number you want to drop
*********************************************/
void dropCourse(Student& s, int crn)
{
  if(s.dropCourse(crn) == true) //if you can drop it
    {
      cout << crn << " has been dropped successfully." << endl;
      s.reduceFee(50, 14);
    }
  else //if it returned false
    {
      cout << crn << " wasn't dropped from " << s.getFirstName() << " because " << crn << " doesn't exist" << endl;
    }
}
/********************************************
//this function will make a payment for you to pay your fee. 
//parameters: student object
*********************************************/
void makePayment(Student& s)
{
 string pay;
  cout << "You owe $" << s.getBalance() << endl;
  cout << "Enter the amount you want to pay: $";
  cin >> pay;
  string dollar;
  string cent;  
  int d;
  int c;
  bool error = false;
  if(pay.find(".") == -1) //if payment has no decimals like 50
    {
      d = atoi(pay.c_str());  // convert the string to an int
      c = 0; //cent to 0
    }
  else //if payment has a decimal
    {	
      cent = pay.substr(pay.find(".") + 1, pay.length() - pay.find(".") + 1); //starts at the . and gets to the end of cents
      c = atoi(cent.c_str()); //change string cent to int
      if(cent.length() != 2)
	{
	  cout << "Wrong format. " << endl;
	  error = true;
	}
      else
	{
	  if(pay.find(".") != 0) //if payment has a dollar and a cent 
	    {
	      dollar = pay.substr(0, pay.find(".")); //gets the dollars and stops when it finds the .
	      d = atoi(dollar.c_str()); //change to an int
	    }
	  else //if payment has no dollar but a cent
	    {
	      d = 0; //set dollar to 0
	    }
	  
	}
    }
  if(error == false) 
    {
      Price p(d, c);
      if(p > s.getBalance()) //if the payment amount is greater than the balance owed
	{
	  cout << "Payment is too much. " << endl;
	}
      else // if the payment is valid
	{
	  s.reduceFee(d, c); //reduce it
	}
    } 
}



//******************** PHASE 3 ****************************

//I am using this function to check a password for both the admission's office and student
//FYI, I am passing the correct password as a parameter and returning true/false.
//The correct password for a student is  student_id % (PRIME1 * PRIME2)
/********************************************
//this function will check to see if the password is correct on the admissions office or the students account
//parameters: the correct password
*********************************************/
bool checkPassword(int password)
{
  int userPW;
  cout << "Enter the password: ";
  cin >> userPW;
  if(userPW != password) //if what the user put is not the password to the admission's office
    {
      cout << "Password is wrong. " << endl;
      return false; 
    }
  else
    {
      return true;
    }
}
//Small function. You may choose not to use this function. That is OK.

//Ask for the student id
//call find() to find the student id
//return what find() returned which is index where it was found or -1
/********************************************
//this function will search through the student array and find the student id that the user inputs. if it is found, it will return the index of where the student is found. if not found, return -1
//parameters: student array, size
*********************************************/

int findStu(Student ar[], int s)
{
  int id;
  cout << "Enter the student id: ";
  cin >> id;
  int finder = find(ar, s, id);
  if(finder != -1) //if it is found
    {
      for(int i = finder; i < s-1; i++)
	{
	  return i; //return the index
	}
    }
  else //if it isnt found
    {
      return -1;
    }
}


//Case 4 of admission
//Ask for the student id
//If the student doesn't exist, show an error message.
//If it exists, call showStuInfo to show the student
/********************************************
//this function will 
//parameters:
*********************************************/
/*void  viewStuInfo()
{
  int id;
  cout << "Enter student id: ";
  cin >> id;
  if(
  }*/

//You may decide not to use this function. If so, that is OK.

//When the user is a student, select 2 in the top menu. He/she enters hi/her student id.
//Make sure the stuent id exists in the array. If not, I am showing an error message.
//FYI, I am returning the index where the student was found or -1 if not found.
/********************************************
//this function will
//parameters:
*********************************************/

/* verifyStu()
{

}

*/

int showMenu()
{
  int choice;
  cout << "========================================================" << endl;
  cout << "1: Admission's Office" << endl;
  cout << "2: Student" << endl;
  cout << "3: End program" << endl;
  cout << "========================================================" << endl;
  cout << "Enter your choice: ";
  choice = getData(1, 3, "\tInvalid choice. Enter only 1, 2 or 3: ");

  return choice;
}


int showStuMenu()
{
  int choice;

  cout << endl;
  cout << "***************************" << endl;
  cout << "1: Add a course" << endl;
  cout << "2: drop a course" << endl;
  cout << "3: Make a payment" << endl;
  cout << "4: View my information" << endl;
  cout << "5: Quit" << endl;
  cout << "***************************" << endl;
  cout << "Enter your choice: ";
  choice = getData(1, 5, "\tInvalid choice. Enter only 1 through 5: ");

  return choice;
}

int showAdmMenu()
{
  int choice;

  cout << endl;
  cout << "***************************" << endl;
  cout << "1: Add a new student" << endl;
  cout << "2: Add new students from a file" << endl;
  cout << "3: drop a student" << endl;
  cout << "4: View one student info" << endl;
  cout << "5: View all students' info" << endl;
  cout << "6: Quit" << endl;
  cout << "***************************" << endl;
  cout << "Enter your choice: ";
  choice = getData(1, 6, "\tInvalid choice. Enter only 1 through 6: ");

  return choice;
}



