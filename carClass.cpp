#include <iostream>
using namespace std;

enum direct{NORTH, EAST, SOUTH, WEST}; //enum for direction

class Car //class for the car
{
private: //attributes of the car and direction its going
  string model;
  int year;
  int mileage;
  direct direction;
  int x;
  int y;
public: //functions
  Car(string md, int yr); //what we should know
  string getModel() const;
  int getYear() const;
  void goForward(int block);
  int getMileage() const;
  int getx() const;
  int gety() const;
  void turnRight();
  string getDirection() const;
  void turnLeft();
};

Car::Car(string md, int yr) //set up to print 
{
  model = md;
  year = yr;
  mileage = 0;
  direction = NORTH;
  x = 0;
  y = 0;
}


string Car::getModel() const //prints model of car
{
  return model;
}

int Car::getYear() const //function to print the year
{
  return year;
}

void Car::goForward(int block) //function to move the car in the block and get mileage
{
  if(direction == NORTH) //adds y heading north
    y += block;
  else if(direction == EAST) //adds x heading east
    x += block;
  else if(direction == SOUTH) //subtracts y heading south
    y -= block;
  else if(direction == WEST)  //subtracts x heading west
    x -= block; 
  mileage += block; //calculates mileage
}

int Car::getMileage() const //function to print the mileage
{
  return mileage;
}

int Car::getx() const//gets x value of where block is
{
  return x;
}

int Car::gety() const //gets y value of where car is
{
  return y;
}

void Car::turnRight() //to change the direction of the car
{
  if(direction == WEST) //if the direction is at west, the next right will be north (because 4 + 1 is not 0)
    direction = NORTH;
    else //NORTH, EAST, SOUTH
      direction = (direct)(direction + 1);  //for all the other ones, it'll be the whatever the next direction is
}

void Car::turnLeft() //to change the direction of the car
{
  if(direction == NORTH) //if the direction is at east, the next left will be north (because 0 - 1 is not 4
    direction = WEST;
  else //EAST, WEST, SOUTH
    direction = (direct)(direction - 1);  //for all the other ones, it'll be the whatever the next direction is
}


string Car::getDirection() const //to get the direction it is heading to
{
  switch(direction) //switch so that it prints out the string and not the int
    {
    case NORTH: return "North";
    case EAST: return "East";
    case SOUTH: return "South";
    case WEST: return "West";
    }
}


void showInfo(const Car c); //prototype for showInfo

int main()
{
  Car c1("Camry", 2019); //creats c1 car
  Car c2("Neon", 2020); //creats c2 car
  //outputs:
  cout << c1.getModel() << endl;
  cout << c1.getDirection() << endl;
  c1.goForward(3); 
  c1.turnRight();
  c1.goForward(5);
  c1.turnRight();
  c1.goForward(7);
  c1.turnRight();
  c1.goForward(6);
  c1.turnLeft();
  c1.goForward(1);
  cout << "Ends up at (" << c1.getx() << "," << c1.gety() << ")" << endl;
  cout << "Facing " <<  c1.getDirection() << endl;
  cout << c1.getMileage() << endl;
  showInfo(c1); //shows the entire info of c1

  c2.goForward(5);
  c2.turnLeft();
  c2.goForward(1);
  c2.turnLeft();
  c2.goForward(2);
  c2.turnLeft();
  c2.goForward(4);
  c2.turnLeft();
  c2.goForward(10);
  showInfo(c2); //shows entire info of c2

  return 0;
}

void showInfo(const Car c) //to show info of whatever car is created
{
  cout << c.getModel() << " (" <<  c.getYear() << ") is located at (" << c.getx() << "," << c.gety() << ") facing " << c.getDirection() << ". It has " << c.getMileage() << " miles on it. " << endl ;
}
