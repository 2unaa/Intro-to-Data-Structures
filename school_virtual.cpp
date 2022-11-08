#include <iostream>
using namespace std;
#include "LL_T.h"
#include <fstream>

//***********Person Class**********
class Person
{
protected:
  static int num; // total number of people created
  static int current_id;
  const int id;
  string firstname;
  string lastname;
  string SSN;
  string email;
public:
  Person(string f = "unknown", string l = "unknown", string s = "000-00-0000", string e = "unknown");
  virtual void printInfo();
  static int getNum(); 
  static int getCurrentID(); 
  string getSSN(); 

};

int Person::num = 0;
int Person::current_id = 1000;

Person::Person(string f, string l, string s, string e): id(current_id) 
{
  num++;
  current_id++;
  firstname = f;
  lastname = l;
  SSN = s;
  email = e;
}

void Person::printInfo()
{
  cout << "Person::printInfo()" << endl;
  cout << id << " (ID) "<< firstname << " (fn) " << lastname << " (ln) " << SSN << " (SSN) " << email << " (email) " << endl;
}


int Person::getNum()
{
  return num;
}

int Person::getCurrentID()
{
  return current_id;
}

string Person::getSSN()
{
  return SSN;
}


//**********Faculty class**********
class Faculty : public Person
{
private: 
  int D_id;
  int ys;
public:
  Faculty(string f = "unknown", string l = "unknown", string s = "000-00-0000", string e = "unknown", int d = -1, int y = -1) : Person(f, l, s, e)//constructor
  {
    D_id = d;
    ys = y;
  }
  void printInfo()
  {
    cout << "Faculty::printInfo()" << endl;
    Person::printInfo();
    cout << D_id << " (department id) " << ys << " (years at school) " << endl;
  }
};
//**********Student**********
class Student : public Person
{
private:
  string major;
  double gpa;
  char grade;
public:
  Student(string f = "unknown", string l = "unknown", string s = "000-00-0000", string e = "unknown", string m = "unknown", double g = -1.00, char gr = '?' ) : Person(f, l, s, e)
  {
    major = m;
    gpa = g;
    grade = gr;
  }
  void printInfo()
  {
    cout << "Student::printInfo()" << endl;
    Person::printInfo();
    cout << major << " (major) " << gpa << " (gpa) " << grade << " (grade) " << endl;
  }
};

//**************Client File*************
void readData(LL <Person*>& p)
{
  ifstream fin;
  int num, dep_id, yrs;
  string fn, ln, ssn, email, major;
  double gpa;
  char grade;
  fin.open("campus.dat");
  if(!fin)
    {
      cout << "invalid file" << endl;
    }
  else
    {
      fin >> num;
      while(fin)
	{
	  fin >> fn >> ln >> ssn >> email;
	  if(num == 1) //if its a person
	    {
	      Person* pr = new Person(fn, ln, ssn, email); //make pointer and node for person
		p.addRear(pr); //add rear to the linked list
	    }
	  else if(num == 2) //if its a faculty
	    {
	      fin >> dep_id >> yrs;
	      Faculty* fc = new Faculty(fn, ln, ssn, email, dep_id, yrs);
	      p.addRear(fc);
	    }
	  else if(num == 3)
	    {
	      fin >> major >> gpa >> grade;
	      Student* st = new Student(fn, ln, ssn, email, major, gpa, grade);
	      p.addRear(st);
	    }
	  fin >> num;
	}
      fin.close();
    }
}

void display(LL<Person*>& l)
{
try
  {
 for(node <Person*>* pr = l.getFront(); pr != NULL; pr = l.getNext(pr))
    {
      pr -> elem -> printInfo();
    }
  }
 catch(LL <Person*> :: OutOfBoundary)
   {
     cout << "Out of boundary." << endl;
   }
}

void sort(LL<Person*>& l)
{
  node <Person*>* smallIndx; //node that holds smallest                                                                                                              
  Person* temp; //temp to hold smallest                                                                                                  

  for(node <Person*>* first = l.getFront(); first != l.getRear(); first = l.getNext(first)) //makes first equal to front and goes through the linked list, stops at the last one
    {
      smallIndx = first; //saves it to first

      for(node<Person*>* i = l.getNext(first); i != NULL; i = l.getNext(i)) //finds smallest after first
        {
          if(i -> elem -> getSSN() < smallIndx -> elem -> getSSN()) //if less then
            smallIndx = i;
        }
      //swap the smallest with the first item in the unsorted part
      temp = smallIndx -> elem;
      smallIndx -> elem = first -> elem;
      first -> elem = temp;
    }
}





int main()
{
  LL <Person*> p;
  cout << "Printing everyone in the list ---------" << endl;
  readData(p);
  display(p);
  cout << "--------------------------------------" << endl << endl; 
  cout << "Printing everyone in the list after sort ---------" << endl;
  sort(p);
  display(p);


  return 0;
}
