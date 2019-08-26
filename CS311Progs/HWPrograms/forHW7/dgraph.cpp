//CS311 Yoshii dgraph.cpp 
// INSTRUCTION:
//  Complete all the functions you listed in dgraph.h
//  Comment the file completely using How to Comment file.
//  Use HW6-help.docx to finish the functions.
//-------------------------------------------------------

//======================================================
// HW#: HW6 dgraph
// Name: James Bertel
// File Type: .cpp
//========================================================

using namespace std;
#include <iostream>
#include "dgraph.h"
#include <fstream>

dgraph::dgraph() // initialize vertexName (blank) and visit numbers (0)b &countUsed to be 0
{
  for(int i = 0; i < SIZE; i++)
    {
      Gtable[i].vertexName = ' ';
      Gtable[i].visit = 0;
    }
  countUsed = 0;
}

dgraph::~dgraph()   // do we have to delete all nodes of slists in table??
// Question: If we do not do this, will the llist destructor be called automatically??? Try it.
{}

//read from input file table.txt and fill GTable
void dgraph::fillTable()  // be sure to read from a file
{
  ifstream fin;
  fin.open("table.txt");

  if(!fin) return; //if file cannot be opened, exit function

  char x;
  while(fin >> Gtable[countUsed].vertexName)
    {
      fin >> Gtable[countUsed].outDegree;

      //add rear for outDegree number times
      for(int i = 1; i <= Gtable[countUsed].outDegree; i++)
	{
	  fin >> x;
	  (Gtable[countUsed].adjacentOnes).addRear(x); //slist function
	}
      countUsed++;
    }
  fin.close();
}

// displays in nice format
void dgraph::displayGraph() // be sure to display
// in a really nice format -- all columns
{
  cout << "------------------------------" << endl;
  for(int i = 0; i < countUsed; i++)
    {
      cout << Gtable[i].vertexName << " ";
      cout << Gtable[i].outDegree << " ";
      cout << Gtable[i].visit << " ";
      (Gtable[i].adjacentOnes).displayAll();
    }
}

//returns the out degree of a given vertex - may throw badvertex
int dgraph::findOutDegree(char V)// throws exception
// does not use a loop
{
  int temp = int(V) - 65; //change V to integer
  if(temp >= 0 && temp < countUsed)
    return Gtable[temp].outDegree;
  else
    throw BadVertex();
  /*  
      (bad) alternative:
  for(int i=0;i<countUsed;i++)
    if(Gtable[i].vertexName==V) 
      return Gtable[i].outDegree;
  throw BadVertex();
  */
}
//returns adjacency list of a given vertez - may throw badvertex
slist dgraph::findAdjacency(char V)// throws exception
// does not use a loop
{
  int temp = int(V) - 65; //change V to integer 
  if(temp >= 0 && temp < countUsed)
    return Gtable[temp].adjacentOnes;
  else
    throw BadVertex();

  /*
    (bad) alternative:
  for(int i=0;i<countUsed;i++)
    if(Gtable[i].vertexName==V) 
      return Gtable[i].adjacentOnes;
  throw BadVertex();
*/
}

//enters the given visit number (num) for a given vertex (v)
//to indicate the order in which vertices were visited
void dgraph::visit(int num, char V)
{
  //note: do not use loop to look for vertex
  //convert A to slot 0, B to slot 1, etc

  int temp = int(V) - 65; //change V to integer where A == 0
  Gtable[temp].visit = num;
}


//returns true if a given vertex was already visited
bool dgraph::isMarked(char V)
{
  //note: do not use a loop to look for a vertex

  int temp = int(V) - 65;

  if(Gtable[temp].visit == 0) return false;
  else return true;
}
