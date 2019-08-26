// CS311 Yoshii
// This program generates sentences randomly.
// Try improving it to generate more sentences.

#include<iostream>
#include<string>
#include<stdlib.h>
#include<time.h>
using namespace std;

string actor[10] = {"A dog", "My teacher", "A cow", "The President", 
		    "A monster", "A robot", "Justin Beaver", "U2",
                    "My friend", "A zombie"};

string action[10] = {"ate", "kicked", "hit", "destroyed", "chopped", 
                     "chased", "created", "cooked", "threw", "stroked"};

string object[10] = {"a ball", "a computer", "a car", "an apple", "a cat",
		     "a desk", "a zombie", "a guitar", "a dancer", "a lion"};

string where[10] = {"on stage", "in a truck", "on a plane", "in a classroom", 
	     "in an alley", "in a hotel room", "at a conference",
             "in the lab", 
             "in the restroom", "at a bank"};


int main()   
{
  string ans;
  cout << "Continue? Enter Q to quit."; cin >> ans;
  while (ans != "Q")
    {
      srand(time(NULL));
      
      int slot = rand()%10;   
      string a = actor[slot];
      slot = rand()%10;   
      string b = action[slot];
      slot = rand()%10;   
      string c = object[slot];
      slot = rand()%10;   
      string d = where[slot];
   
      cout << a << " " << b << " " << c << " " <<  d << "." << endl;

      cout << "Continue? Enter Q to quit."; cin >> ans;
    }
  
}
