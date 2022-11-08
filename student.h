#ifndef STUDENT_H
#define STUDENT_H
#include <string>
using namespace std;
#include "price.h"

const int MAX = 6;

class Student
{
private:
  string fn;
  string ln;
  char gen;
  int numclass;
  int array[MAX];
  int stuID;
  Price balance;
public:
  Student(string first, string last, char gend, int id);
  Student();
  string getFirstName() const;
  string getLastName() const;
  char getGender() const;
  int getNumClasses() const;
  int getStuID() const;
  int getClassOf(int i) const;
  Price getBalance() const;
  void addFee(int d, int c);
  void reduceFee(int d, int c);
  int addCourse(int crn);
  void viewAllCourses() const;
  bool dropCourse(int crn);
};

#endif
