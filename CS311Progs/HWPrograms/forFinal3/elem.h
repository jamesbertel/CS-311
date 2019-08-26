/****************
James Bertel
CS 311
Dr. Yoshii
May 2019

Element type of a list node is defined here
****************/
//-----------------------------------------------------
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
using namespace std;

//el_t hold information about all Orienttion Team Leaders (Oteamers)
class el_t
{
 private:
  string firstName;
  string lastName;
  string major;
  char position; //D = Co-Director , L = Leader, R = Returning Oteamer, O = First Fime Oteamer
  string email;
  long phoneNum;
  int rank; //each Oteamer is ranked by how great they have been doing at orientations

 public:

  el_t();  // to create a blank el_t object
  el_t(string, string, string, char, string, long, int);

  int getrank() {return rank;};
  
  bool operator==(el_t);  // overload == for search
  //bool operator!=(el_t);  // overload != for search

  // this overloads cout for the el_t object
  // This is a friend function since the receiver object is not el_t
  friend ostream& operator<<(ostream&, const el_t&);  
  
  friend class htable;  // client of this class is htable which needs access to the key part of el_t 

};
