//CS311 Yoshii Linked List class
//INSTRUCTION:
//Must use the provided HW3P1_help.doc to create llist.cpp
//It helps to first create if-then-else structure to fill in later.
//- Make sure PURPOSE and PARAMETER comments are given in detail
//- Make sure all if-then-else are commented describing which case it is
//- Make sure all local variables are described fully with their purposes
//EMACS HINT:
//  You can copy from a Word document to emacs (contrl-right click)
//  control-K cuts and control-Y pastes
//  Esc x replace-str does string replacements
//  Esc > goes to the end of the file; Esc < to the beginning
//  Tab on each line will indent perfectly for C++

// ====================================================
//HW#: HW3P1 llist
//Your name: James Bertel
//Complier:  g++
//File type: llist.cpp implementation file
//=====================================================

using namespace std;
#include <iostream>
#include "llist.h" 

llist::llist()
{
  cout << "calling the llist constructor" << endl;
  Front = Rear = NULL;
  Count = 0;
}

llist::~llist() 
{ 
  cout << "calling the llist destructor" << endl;
  while(!isEmpty())
    deleteFront(Front->Elem/*?*/);
}

//PURPOSE: Checks to see if list is empty 
//PARAMETER: None
bool llist::isEmpty() 
{ 
  if(Front == NULL && Rear == NULL && Count == 0)
    return true;
  else 
    return false;
}

//PURPOSE: Displays all elements of all nodes in the list  
//PARAMETER: None
void llist::displayAll() 
{ 
  //special case: if list is empty, abort function
  if(isEmpty())
    return;

  //regular case: displays all characters using temporary Node pointer
  cout << "[ ";
  Node *p = new Node;

  while(p != NULL)
    {
      cout << p->Elem << " ";
      p = p->Next;
    }

  cout << "]" << endl;
}
  
//PURPOSE: Adds a node to the front of the list  
//PARAMETER: NewNum == Element being added
void llist::addFront(el_t NewNum) 
{ 
  //special case: the node added will be the first and rear node,
  // and NewNum is put in Elem field. Count is updated.
  if(isEmpty())
    {
      Node *P = new Node;
      P->Elem = NewNum;
      Front->Elem = Rear->Elem = NewNum;
      Count++;
    }
  //regular case: adds a a new node in the front,
  // and NewNum is put in Elem field. Count is updated.
  else
    {
      Node *Q = new Node;
      Q->Elem = NewNum;
      Front = Q;
    }      
}

//PURPOSE: Adds a node to the rear of the list  
//PARAMETER: NewNum == Element being added  
void llist::addRear(el_t NewNum) 
{ 
  //special case: the node added will be the first and rear node,
  // and NewNum is put in Elem field. Count is updated.
  if(isEmpty())
    {
      Node *P = new Node;

      //cout << "check\n";
      P->Elem = NewNum;
      cout << "done\n";

      Front->Elem = Rear->Elem = NewNum;
      Count++;
    }
  //regular case: adds a new node at the rear of the list
  // and puts NewNum in the Elem field. Count is updated.
  else
    {
      Node *Q = new Node;
      Rear->Next = Q;
      Rear = Rear->Next;
      Rear->Elem = NewNum;
      Rear->Next = NULL;
    }
}

//PURPOSE: Deletes a node in the front of the list 
//PARAMETER: OldNum == Element being deleted  
void llist::deleteFront(el_t& OldNum) 
{ 
  //error case: If list is empty, throws an exception
  if(isEmpty())
    throw "ERROR: Cannot delete node from empty list";
  //special case: if node being deleted is the only node in the list, give back
  // the front node element (pass by reference) before removing. Count is updated.
  else if(Count == 1)
    {
      OldNum = Front->Elem;
      delete Front;
      Count--;
    }
  //regular case: gives back front node (pass by reference) and removes
  // the front node. Count is updated.
  else //Count > 1
    {
      OldNum = Front->Elem;
      Node *Second = new Node;
      Second = Front->Next;
      delete Front;
      Front = Second;
      Count--;
    }
}

//PURPOSE: Deletes a node in the rear of the list  
//PARAMETER: OldNum == Element being deleted    
void llist::deleteRear(el_t& OldNum) 
{ 
  //error case: If list is empty, throws an exception
  if(isEmpty())
    throw "ERROR: Cannot delete node from empty list";
  //special case: if node being deleted is the only node in the list, give back
  // the rear node element (pass by reference) before removing. Count is updated.
  else if(Count == 1)
    {
      OldNum = Rear->Elem;
      delete Rear;
      Count--;
    }
  //regular case: gives back rear node (pass by reference) and removes
  // the front node. Count is updated.
  else //Count > 1
    {
      OldNum = Rear->Elem;

      Node *SecondToLast = new Node;
      SecondToLast = Front;
      while(SecondToLast->Next != Rear) 
	SecondToLast = SecondToLast->Next;
      
      delete Rear;
      Rear = SecondToLast;
      Count--;
    }
}

//PURPOSE: Deletes a certain node (the Ith node)  
//PARAMETERS: I == Node position being found; OldNum ==  element being deleted 
void llist::deleteIth(int I, el_t& OldNum) 
{ 
  //Error cases: If I is an illegal value, throws exception
  if(I > Count || I < 1)
    throw "ERROR: Illegal 'I' Value: Cannot delete Ith Node";
  //Special Cases: calls deleteFront if I == 1 ; calls deleteRear if I == Count
  else if(I == 1)
    deleteFront(OldNum);
  else if(I == Count)
    deleteRear(OldNum);
  //Regular case: Deletes Ith node (I starts at 1). Count is updated.
  else // 1 < I < Count
    {
      Node *J = New Node;
      Node *K = New Node;

      //place J before Ith Node
      for(int L = 1; L < I-1; L++)
	J = J->Next;

      K = J->Next; //places K at I 
      OldNum = K->Elem;
      J->Next = K->Next;
      delete K;
      Count--;
    }
}

//PURPOSE: Adds a node in the Ith position  
//PARAMETER: I == Node position being found; newNum == element being inserted
void llist::insertIth(int I, el_t newNum) 
{ 
  //Error cases: If I is an illegal value, throws exception
  if(I > Count+1 || I < 1)
    throw "ERROR: Illegal 'I' Value: Cannot delete Ith Node";
  //Special Cases: calls addFront if I == 1 ; calls addRear if I == Count
  else if(I == 1)
    addFront(newNum);
  else if(I == Count)
    addRear(newNum);
  //Regular case: Deletes Ith node (I starts at 1). Count is updated.
  else // 1 < I < Count+1
    {
      Node *J = new Node;
      //place J before Ith Node Spot
      for(int L = 1; L < I-1; L++)
	J = J->Next;

      //create new node K to place at I
      Node *K = new Node;
      K->Elem = newNum;
      J->Next = K; //places K at I 
      newNum = K->Elem;
      J->Next = K->Next;
      delete K;
      Count--;
    }
}

//PURPOSE: Copy constructor to allow pass by value and return by vallue
//PARAMETER: Original == Original linked list being copied
llist::llist(const llist& Original) 
{ 
  //  this->'s data members need to be initialized here first
  //Front = NULL; Rear - NULL; Count = 0;
       //Original Front = atop , this front = btop
  /*
  while(! this->isEmpty())
    this->deleteRear();

  this->Front = NULL;
  this->Rear = NULL;
  this->Count = 0;

  //  this-> object has to be built up by allocating new cells
  Node *P = Original.Front;
  this->Front = P;

  while(P != NULL)
    {
    
  //  and copying the values from Original into each cell as we did with 
  //  operator= above. 
  //      To do this, copy here the (**) lines in Operator Overloading of = ,
  //      but note that it is Original and not OtherOne.

    //  Nothing to return because this is a constructor.
    */
  this->Front = NULL;
  this->Rear = NULL;
  this->Count = 0;

      if (&Original != this)  // if not the same
	{
	  // this-> object has to be emptied first.
	  while (! this->isEmpty() )
	  {
	  el_t OldNum;
	  this->deleteRear(OldNum); 
	  }
	  // this-> object has to be built up by allocating new cells with OtherOne elements (**)
	  Node* P = new Node;  // local pointer for OtherOne
	  P = Original.Front;
	  while (P != NULL)  // a loop which repeats until you reach the end of OtherOne. 
	    {
	      el_t newNum = P->Elem;
	      this->addRear(P->Elem);    //P’s element is added to this->
	      P = P->Next;                         // Go to the next node in OtherOne   
	    } 
	}// end of if              
}

//???????????????????????????????????????????????
//PURPOSE: Overloading of =
//PARAMETER: Linked list being overloaded 
llist& llist::operator=(const llist& OtherOne) 
{ 
  // First make sure this-> and OtherOne are not the same object.
  // To do this, compare the pointers to the objects .
  if (&OtherOne != this)  // if not the same
    {
      // this-> object has to be emptied first.
      while (! this->isEmpty() )
	{
	  //el_t OldNum;
	  this->deleteRear(this->Rear->Elem);
	}
      // this-> object has to be built up by allocating new cells with OtherOne elements 
      //(**)
      Node* P = new Node;  // local pointer for OtherOne
      P = OtherOne.Front;

      while (P != NULL)  // a loop which repeats until you reach the end of OtherOne. 
        {
	  this->addRear(P->Elem);    //P’s element is added to this->
	  P = P->Next;                         // Go to the next node in OtherOne   
	} 
    }// end of if              
  return *this;    // return the result unconditionally.  Note that the result is returned by reference.

}

