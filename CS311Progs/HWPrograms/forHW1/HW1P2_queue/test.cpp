#include <iostream>
#include <string>
#include "queue.h"
using namespace std;

int main()
{
  queue test;

  test.add("A");
  test.add("B");
  test.add("C");

  //for(int i = 1; i < 3; i++)
  //cout << test[i] << endl;

  string one = "hot";
  string two = "dog";
  
  cout << one+two << endl;

  one += two;

  cout << one << endl;

  return 0;
}
