#include <iostream>
#include <string>
using namespace std;

bool theSize(string, string);

int main()
{
  string one, two;

  cout << "\nEnter first: ";
  cin >> one;
  cout << "\nEnter two: ";
  cin >> two;

  bool ans = theSize(one, two);

  cout << "One > Two ?: " << ans << endl;

  /*  string name1;
  string name2;
  int size;

  cout << "\nName 1: ";
  cin >> name1;
  cout << "\nName 2: ";
  cin >> name2;

  if(name1.size() > name2.size())
    size = name1.size();
  else
    size = name2.size();

  for(int i = 0; i < size; i++)
    {
      if(name1[i] != name2[i])
        {
	  cout << "\nNOT EQUAL!" << endl;
	  i = name1.size() + name2.size();
	}
    }      

  cout << "\nEQUAL" << endl;

  */
}

bool thesize(string a, string b)
{
  int s;

  if(a.size() < b.size())
    s = b.size();
  else
    s = a.size();

  for(int i = 0; i < s; i++)
    {
      if(a[i] == b[i]);
      else if(a[i] < b[i]) return true;
      else return false;
    }

  return true;
}