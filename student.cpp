#include "student.h"
#include "array.h"
#include "price.h"
using namespace std;

Student::Student(string first, string last, char gend, int id) //constructor
{
  fn = first;
  ln = last;
  gen = gend;
  numclass = 0;
  stuID  = id; 
}

Student::Student() //default constructor
{
  fn = "unknown";
  ln = "unknown";
  gen = 'x';
  stuID = -1;
}

string Student:: getFirstName() const
{
  return fn;
}

string Student::getLastName() const
{
  return ln;
}

char Student::getGender() const
{
  return gen;
}

int Student::getNumClasses() const
{
  return numclass;
}

int Student::getStuID() const
{
  return stuID;
}
//get the crn at i from class array
int Student::getClassOf(int i) const
{
  if(i < numclass && i > -1) //if the numclass is in range
    {
  return array[i];
    }
  else
    cout << "Invalid student." << endl;
  return -1;
}

Price Student::getBalance() const
{
  return balance;
}

void Student::addFee(int d, int c)
{
  Price p(d, c); //make a new price from d and c
  balance = balance + p; //add to balance
}

void Student::reduceFee(int d, int c)
{
  Price p(d, c);
  balance = balance - p; //reduce to balance
}


int Student::addCourse(int crn) //function to add the course
{
int finder = find(array, numclass, crn); // call find function
 if(finder == -1 && numclass < MAX) //if there is space in the array and if the course isnt added already
   { 
    array[numclass++] = crn; //adds the class to the array
    return 1;
   }
 else if(numclass > MAX) //if there is no space in array
   {
    return -1;
   }
 else if(finder != -1) //if the course is already added
   {
     return 0;
   }
}

void Student::viewAllCourses() const //prints all courses added
{
  print(array, numclass); 
}

bool Student:: dropCourse(int crn) // removes a course
{
  bool remover = remove(array, numclass, crn); 
  if(remover == true) //if there is a course
    {
      numclass--; //decrements the number of classes so it removes it
      return true;
    }
  else //if there isn't a course
    { 
      return false;
    }
}

