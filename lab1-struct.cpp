/*******************************************
Tuan Tran
CS211 Slott 
lab1
1-21-2020

This program will tell you what the oldest and youngest age from a group of students in another file.
*******************************************/
// header files
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

//struct for the student and the info
struct student
{
  int id; //student id
  string firstname; //student first name
  string lastname; //student last name
  int age; // student age
};
//prototypes:
void displayStu(const student& stu);
int getStuData(student stu[]);
int findID(student stu[], int size, int look);
void  displayAllStu(const student stu[], int size );
void  findYoungOld(const student stu[], int size, int& young, int& old );
//max const, maximum number of students the array can hold.
const int MAX = 20;

int main()
{
  student stu; // student called stu named lucy smith. id 1000. age 20.
  stu.id = 1000; //her id
  stu.firstname = "Lucy"; // her first name
  stu.lastname = "Smith"; //her last name
  stu.age = 20; //her age
 displayStu(stu);  // display stu. calls the function to display it.                                                                                                    
student arr[MAX]; // Creates an array of students using MAX

int num = getStuData(arr); // num holds the number of students in the array
 if(num == -1) //if file doesnt exist
    {  
      cout << "The file didn't exist." << endl;
    }
 else if(num  == 0) //if file exists but empty
    {
      cout << "There are no students in the input file." << endl;
    }
 else //The input file had at least one student 
    {
      displayAllStu(arr, num); //displays all students in a table
    
      int look; //The id the user is looking for
      cout << "\nEnter the id you are looking for: ";
      cin >> look;
      //Find a student with the id you are looking for and display the information about that student. If no student has the id, show an appropriate message.
      int finder = findID(arr, num, look); //finder equals the findID function so we can use if statements. 
      if(finder != -1) //if there is a match
    {
      displayStu(arr[finder]); //displays the student that the id matched
 }
  //display the info on the student with that id by calling displayStu
      else // if there isn't a match
    {
      cout << "No student with id " << look << " was found" << endl;
    }

  
  //find the youngest and oldest students by calling findYoungOld
  int yngInd; //index of the yougest student
  int oldInd; //index of the oldest student
  findYoungOld(arr, num, yngInd, oldInd );      //  call findYoundOld function
  
  cout<< "\nThe youngest Student -----" << endl;
  displayStu(arr[yngInd]);// call displayStu to show the youngest student's info
  
  cout<< "\nThe oldest Student -----" << endl;
  displayStu(arr[oldInd]); // call displayStu to show the oldest student's info
  
  cout << endl;
  
  return 0;
    }
}

//End of main.

/********************************************
Parameter: Student arr[] is the array.
Loads students' data into array and returns number of students.
*********************************************/
int getStuData(student arr[])
{
  int i = 0; //index of array
  string filename; //the name of the file you want
  cout << "Enter the input file name that has the students' info: ";
  cin >> filename;
  ifstream fin; //input file stream
  fin.open(filename.c_str()); //opens the file that user wants to open
  if(!fin) // if there is an invalid file that user wants
    {
      return -1;
    }
  student stu; // gets the info of the file
  fin >> stu.id; // id info
  fin >> stu.firstname; // first name info
  fin >> stu.lastname; //last name info
  fin >> stu.age; //age info 
  while(fin && i < MAX) // when file opens and it is less then the max
    {
      arr[i] = stu; // load the file info into an array
      fin >> stu.id;
      fin >> stu.firstname; 
      fin >> stu.lastname;
      fin >> stu.age;
      i++; //goes through the entire file and loads each student into an index of the array
    }
  fin.close(); // close file
  return i; // returns whatever the amount of students are in the array.
}
/********************************************
Parameters: stu is the array, size is the size of the current array, and look is the users id that they wanted to search through the array.
Searches through array to find the id of the student that user is looking for.
*********************************************/
int findID(student stu[], int size, int look)
{
  for(int i = 0; i < size; i++) //goes through each index of the array
    {
      if(stu[i].id == look) //if the id of the student is equal to user input
	{
	  return i; // returns the index of that student
	}
}
  return -1; //if there isnt a match. outside the if statement so it goes through the entire array
}
/********************************************
Parameters: stu is the array(const because we only want to display it, not change it), size is the size of current array.
It will pass through the array and display all the students in the array and a table of all their information.
*********************************************/
void displayAllStu(const student stu[], int size )
{
  cout << left << setw(13) << "ID" << setw(13) << "First name" << setw(13) << "Last name" << setw(13) << "Age" << setw(13) << endl << "------------------------------------------------" << endl; // formatting the table
  for(int i = 0; i < size; i++) //goes through each index of the array
    displayStu(stu[i]); //calls the display students function for each student in the array.
}

/********************************************
Parameters: student is the struct. const because we don't want to change anything and & to make it pass by reference.
This will display all the info about students.
*********************************************/
void displayStu(const student& stu)
{
  cout << left << setw(13) <<  stu.id << setw(13) << stu.firstname << setw(13) << stu.lastname << setw(13) << stu.age << setw(13) << endl; //the format for how each students info will be printed out
}

/********************************************
Parameters: student is the array. size is the size of the array. young is to determine which one is youngest. old is to determine which one is oldest.
It will give the youngest and oldest students.
*********************************************/
void findYoungOld(const student arr[], int size, int& young, int& old )
{
  young = 0; //set young to 0 so it can start at index 0
  old = 0; // set old to 0 so it can start at index 0
  for(int i=1; i < size; i++) //goes through each index of the array starting at index 1
    {
      if(arr[i].age < arr[young].age) //compares ages of each array index
      {
	young = i; // young becomes whatever the index of the youngest is
	  }
      if(arr[i].age > arr[old].age) //compares how old the age is of each array index
    {
      old = i; // old becomes whatever the index of oldest is
    }
    }
}
//end

