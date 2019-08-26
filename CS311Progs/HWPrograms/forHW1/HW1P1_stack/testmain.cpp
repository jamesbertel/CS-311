//CS311 Yoshii
//INSTRUCTION:
//Look for ** to complete this program (Use control-S)
//The output should match my hw1stackDemo.out 

//=========================================================
//HW#: HW1P1 stack application (post-fix evaluation)
//Your name: James Bertel
//Complier:  g++
//File type: client program client1.cpp
//===========================================================

using namespace std;
#include <iostream>
#include <stdlib.h>
#include <string>
#include "stack.h"

//Purpose of the program: This program evaluates post-fix expressions.
//Algorithm: integer stack
int main()
{
  stack postfixstack;  // integer stack
  string expression;   // user entered expression
  
  cout << "type a postfix expression: " ;
  cin >> expression;
  
  int i = 0;  // character position within expression
  char item;  // one char out of the expression
  
  int box1;  // receive things from pop
  int box2;  // receive things from pop
  
  while (expression[i] != '\0')
    {
     try
       {
	 item = expression[i];  // current char
	 
	 // ** do all the steps in the algorithm given in Notes-1

	 if(isdigit(item))//** if item is an operand/number
	   postfixstack.push(item); //push item into the stack

	 else if(item == 0)//item is an operator/symbol*/)
	   {
	     //pop the two operands (might get underflow exception)
	     //apply the operator to the two operands
	     //push the result
	   }
	 else
	   ;//item invalid, throw exception
	 
       } // this closes try


      // Catch exceptions and report problems and quit the program now (exit(1)). 
      // Error messages describe what is wrong with the expression.

      catch (stack::Overflow) 
	{ cerr << "Error: The expression was too long"; exit(1);}
      catch (stack::Underflow)
	{ cerr << "Error: Too few operands/numbers"; exit(1);}
      catch (char const* errormsg ) // for invalid item case
	{/**/ }

     i++; // go back to the loop after incrementing i
      
    }// end of while
  
 // After the loop successfully completes: 
 // Pop the result and show it.
   
  //********** cout << topElem



 // If anything is left on the stack, an incomplete expression 
 // was found so inform the user.

  //if (!isEmpty()) cout << "Incomplete expresion found.\n";   

}// end of the program
