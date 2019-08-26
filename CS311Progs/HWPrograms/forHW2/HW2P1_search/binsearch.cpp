using namespace std;
#include <iostream>

//--------------------------------------------
// CS311 HW2P1 Binary Search
// Name: James Bertel
// Compiler: g++
// --------------------------------------------

// x is what we are looking for in L; first and last are slot numbers 
//Algorithm used: Binary Search of an Ordered List 
int binarySearch(int L[], int x, int first, int last) 
{

  int middle = int((first+last)/2); //find middle element
  
  cout << "comparing against an element in slot " << middle << endl;

  if(first > last) 
    return -1; //if first and last surpass each other, then element does not exist
  
  else if  (x == L[middle])
    return middle; //found X at middle, so return location

  else if(x < L[middle])
    last = middle - 1; //go to first half of array

  else if(x > L[middle])
    first = middle + 1; //go to second half of array

  return binarySearch(L, x, first, last); //recursive call

}


int main()
{ 
  int A[10];
  int e;  // to look for this

  // fixed elements for A
  A[0]= 1; A[1]= 3; A[2]= 5; A[3]= 7; A[4]= 9; 
  A[5]=11; A[6]=13; A[7]=15; A[8]=17; A[9]=19;

  cout << "What do you want to look for? ";
  cin >> e;

  // Call binarySearch here to look for e in A
  int respos = binarySearch(A, e, 0, 9);

  if (respos == -1) 
    cout << "Element not found" << endl; 
  else 
    cout << "Found it in position " << respos+1 << endl;
}
