#include <iostream>
using namespace std;

template <class T>
class myVector
{
private:
  T* ar; //pointer to array
  int num; //number of elements in array
public:
  myVector();
  ~myVector();
  void push_back(const T& e);
  int size() const;
  T operator[](int index) const;
  void erase(int index);
  void insert(int index, const T& e);
};

template <class T>
myVector<T>::myVector() //constructor
{
  ar = NULL;
  num = 0;
}

template <class T>
myVector<T>::~myVector()
{
  if(ar != NULL)
    {
    delete [] ar;
    }
}

template <class T>
void myVector<T>::push_back(const T& e)
{
  T* temp = new T[num + 1]; //new array
  for(int i = 0; i < num; i++)
    {
      *(temp + i) = *(ar + i); //copies the old array to the new array
    }
  *(temp+num) = e; //add element to the back. temp + num is the last slot of the new array
  num++; //increment num
  if(ar != NULL) //check if the pointer is NULL, if it isn't
    {
      delete [] ar; //delete array
    }
  ar = temp; //pointer to the new array
}

template <class T>
int myVector<T>::size() const
{
  return num;
}

template <class T>
T myVector<T>::operator[](int index) const
{
  return *(ar+index);

}

template <class T>
void myVector<T>::erase(int index)
{
  if(index >= num || index < 0)
    {
      cout <<  "Illegal index" << endl;
    }
  else
    {
  T* temp = new T[num - 1]; //new array
  for(int i = 0; i < index; i++) //first for loop goes from beginning to whenever it finds the index
    {
      *(temp + i) = *(ar + i); //copies the first part of the old array (anything before the index) to the new array
    }
  for(int i = index; i < num; i++) //second for loop goes from past the index to the end
    {
      *(temp + i) = *(ar + i + 1); //copies the second part of the old array (anything after the index) to the new array
    }
  num--; //decrement num
  if(ar != NULL) //check if the pointer is NULL, if it isn't
    {
      delete [] ar; //delete array
    }
  ar = temp; //pointer to the new array
    }
}
template <class T>
void myVector<T>::insert(int index, const T& e)
{
  if(index >= num + 1 || index < 0)
    {
      cout << "Illegal index" << endl;
    }
  else
    {
  T* temp = new T[num + 1]; //new array
  for(int i = 0; i < index; i++) //first for loop goes from beginning to whenever it finds the index
    {
      *(temp + i) = *(ar + i); //copies the first part of the old array (anything before the index) to the new array
    }
  *(temp+index) = e; // insert the new number into temp
  for(int i = index; i < num; i++) //second for loop goes from past the index to the end
    {
      *(temp + i + 1) = *(ar + i); //copies the second part of the old array (anything after the index) to the new array
    }
  num++;
  if(ar != NULL) //check if the pointer is NULL, if it isn't
    {
      delete [] ar; //delete array
    }
  ar = temp; //pointer to the new array
    }
}

void print(const myVector<int>& vector);

int main()
{
  myVector<int> v;
  v.push_back(1);
  v.push_back(2);
  v.push_back(3);
  print(v);
  cout << endl;
  v.insert(1, 5);
  v.insert(5, 6);
  print(v);
  cout << endl;
  v.erase(1);
  v.erase(3);
  
  print(v);
  cout << endl;
  return 0;
}

void print(const myVector<int>& vector)
{
  for(int i = 0; i < vector.size(); i++)
    {
      cout << vector[i];
    }
}
