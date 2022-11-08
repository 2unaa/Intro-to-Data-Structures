#include <iostream>

using namespace std;

int isPrime();

int main()
{
  int counter;
  counter = isPrime();
  cout << endl << "There are " << counter << " numbers between 2 and 1000" << endl;

  return 0; 

}
int isPrime()
  {
    bool prime = true;
    int  counter = 0;
    for(int i = 2; i  <= 1000; i++)
      {
	for(int n = 2; n<= i/2; n++)
	  {
	    if(i % n == 0)
	      {
		prime = false;
	      }
	  }
	if(prime == true)
	  {
	    cout  << i << " " ;
	    counter++;
	    if(counter % 10 == 0)
	      {
		cout << endl;
	      }
	  }
	prime = true;
      }
    return counter;
  }


