#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;
//prototypes here, not needed.

void fillArray(int arr[], int s);
bool findkey(const int arr[], int s, int key);
double getAvg(const int arr[], int s);
int key;
int main()
{
srand(time(0));
const int  SIZE = 10;
int array[SIZE];
 int key;
fillArray(array, SIZE);
cout << "Enter number you are looking for: " << endl;
 cin >> key;
 if(findkey(array, SIZE, key))
   {
   cout << "Found" << endl;
   }
   else
   {
   cout << "Not found" << endl;
   }
 double average =  getAvg(array,SIZE);
 cout << "The average value of array: " << setprecision(2) << fixed << getAvg(array, SIZE) << endl;
return 0;
}


void fillArray(int arr[], int s)
{
  for(int i=0; i < s ; i++)
    {
      arr[i]=  rand() % 100 + 1;
    }
}

bool findkey(const int arr[], int s, int key)
{
  for(int i = 0; i < s ; i++)
{
  if(arr[i]== key)
{
  return true;
}
  else
{
  return false;
}
}
}

double getAvg(const int arr[], int s)
{
  int total = 0;
  for(int i = 0; i < s; i++)
    {
    total += arr[i];
    }
  return (double)total/s;
}
