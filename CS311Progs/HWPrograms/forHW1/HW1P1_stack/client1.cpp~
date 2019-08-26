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

//Prototype(s)
bool isOperator(char);
int useOperator(int, int, char);

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
      try //steps for algorithm in Notes-2A
       {
	 item = expression[i];  // current char

	 if(isdigit(item)) //if item is an operand/number
	     postfixstack.push( (int)item - 48 ); //push item into the stack

	 else if(isOperator(item))//if item is an operator/symbol
	   {
	     //pop the two operands (might get underflow exception)
	     postfixstack.pop(box1);
	     postfixstack.pop(box2);
	     
	     //apply the operator to the two operands
	     //push the result
	     postfixstack.push(useOperator(box1, box2, item));
	   }
	 else
	   throw "Invalid items detected.\n"; //item invalid, throw exception
	 
       } // this closes try


      // Catch exceptions and report problems and quit the program now (exit(1)). 
      // Error messages describe what is wrong with the expression.

      catch (stack::Overflow) 
	{ cerr << "Overflow. Too many operands.\n"; exit(1);}
      catch (stack::Underflow)
	{ cerr << "Underflow. Too few operands.\n"; exit(1);}
      catch (char const* errormsg ) // for invalid item case
	{ cerr << errormsg; exit(1);}

      postfixstack.displayAll();
      
      i++; // go back to the loop after incrementing i
      
    }// end of while
  
 // After the loop successfully completes: 
 // Pop the result and show it.

  el_t result;
  postfixstack.pop(result);
  cout << "The result is:\n" << result << endl;

 // If anything is left on the stack, an incomplete expression 
 // was found so inform the user.

  if(!postfixstack.isEmpty())
    cout << "Incomplete expression found.\n";


}// end of the program


//Purpose: identifies which operator an item is
//Parameter: item is the unknown operator
bool isOperator(char item)
{
  switch(item)
    {
    case '+': 
    case '-': 
    case '*': return true; 
      break;
    default: return false;
    }
  return false;
}
      
//Purpose: applys an operator to the two operands
//Parameters: item is the operator while box1 and box2 are operands
int useOperator(int box1, int box2, char item)
{
  switch(item)
    {
    case '+': return(box2 + box1);
      break;
    case '-': return(box2 - box1);
      break;
    case '*': return(box2 * box1);
      break;
    }
}
