//CS311 Yoshii
//INSTRUCTION:
//Look for ** to complete this program 
//The string output should match my hw1queueDemo.out 

//=========================================================
//HW#: HW1P2 queue application (generate all strings)
//Your name: James Bertel
//Complier:  g++ compiler
//File type: client program client2.cpp
//===========================================================

using namespace std;
#include <iostream>
#include <stdlib.h>
#include <string>
#include "queue.h"

//Purpose of the program: Generates all strings using A, B, and C as the letters
//Algorithm: Uses a queue, as well as string functions
int main()
{ 
  queue stringqueue;
  string first; //front of the first temporary queue
  string insert; //what the user wants to add to the queue
  string temp; //amendment to "insert"

  // ** "A", "B", "C" in the queue
  stringqueue.add("A");
  stringqueue.add("B");
  stringqueue.add("C");

  /********
  //!!!!!!!!!!1**** Check and see if extra queuesredundant?
  //                   --> likely due to usage of space
  *********/

  //copy of stringqueue, but removes el[front] after usage
  queue tempqueue = stringqueue; 
  
  //queue only containing [ A B C ]
  queue constqueue = stringqueue;

  // ** while loop -- indefinitely
  while(stringqueue.getSize() < MAX_SIZE)
    {
      try
	{ 
	  //get first item from temporary queue
	  tempqueue.frontElem(first);
	  
	  for(int j = 0; j < constqueue.getSize(); j++)
	    {
	      //replace insert with first
	      insert = first;  

	      //ammend insert with variable [j] from constant queue
	      constqueue.frontElem(temp);
	      insert += temp;
	      
	      //add new insert to queues
	      stringqueue.add(insert);
	      tempqueue.add(insert);

	      //moves variable to back of queue
	      constqueue.goToBack();
	    }
	  //remove front of tempqueue since it will not be used again
	  tempqueue.remove(first);
	}

      //catches      
      catch (queue::Overflow)
	{ stringqueue.displayAll();
	  cerr << "Overflow. Too many strings.\n"; exit(1);}
      catch (queue::Underflow)
	{ cerr << "Underflow. Too few strings.\n"; exit(1);}

    }// end of while loop
}
