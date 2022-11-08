#include <iostream>
#include "utility.h"
#include "LL_T.h"
#include <fstream>
using namespace std;

//prototypes
void buildLL(LL<string>& a);
string stripStr(const string& wd);
void removeBadWords(LL<string>& a);
void outputToFile(LL<string>& a);

int main()
{
  LL <string> s;
  buildLL(s);
  removeBadWords(s);
  outputToFile(s);

  return 0;
}

//this function will create a linked list from txt file in alphabetical order 
//this parameters: Linked list
void buildLL(LL<string>& a)
{
  ifstream fin;
  string s;
  fin.open("essay.txt");
  while(fin >> s) //while its open
    {
      s = stripStr(s);
      if(!a.search(s)) //if it isnt found
	{
	  a.addInOrderAscend(s); //makes it a unique array so if it is found it wont add to it
	}
    }
  fin.close();
}

//makes the string into lowercase letters 
//parameters: the word to make into lowercase
string stripStr(const string& wd)
{
  string w = "";
  for(int i = 0; i < wd.length(); i++) //for loop to go through the string
    {
      if(isLetter(wd[i])) //if it a letter
	{
	  w += myToLower(wd[i]); //make the first letter a lowercase
	}
    }
  return w;
}

//this function will remove all the bad words from the linked list.
//parameters: linked list
void removeBadWords(LL<string>& a)
{
  ifstream fin;
  string s;
  fin.open("bad.txt"); //open bad.txt
  while(getline(fin, s)) //reads bad.txt
    {
      a.deleteNodes(s); //deletes the bad words in it
    }
    fin.close();
}
//this function will output a .txt of each letter and put every word starting with that letter
//parameterse: linked list
void outputToFile(LL<string>& a)
{
  ofstream fout;
  string s;
  string fileName = "./dictionary/?.txt";
  if(!a.isEmpty()) //if its not empty 
    {
      s = a.deleteFront(); //delete the front
      fileName[13] = toMyUpper(s[0]); //get the text name
      fout.open(fileName.c_str()); //open the file
    }
  while(!a.isEmpty()) //while its not empty
    {
      if(fileName[13] == toMyUpper(s[0])) //if they are the same
	{
	  fout << s << endl; //file output
	}
      else //if its not the same
	  {
	    fout.close(); //close it
	    fileName[13] = toMyUpper(s[0]);
	    fout.open(fileName.c_str());
	    fout << s << endl;
	  } 
	s = a.deleteFront();
    } //puts it into b to the end
      fout.close();
}

