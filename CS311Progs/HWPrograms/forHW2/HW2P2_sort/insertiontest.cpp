#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
  int size;

  vector <int> a;

  cout << "insert size: ";
  cin >> size;

  cout << "Insert one element per line: " << endl;
  
  for (int i = 0; i < size; i++)
    { int elem;
      cin >> elem;
      a.insert(a.begin() + i, elem);
    }

  cout << "\nWAIT!\n";

  int Xindex = 1;

  int X = a[Xindex]; 

  while(Xindex < a.size())
    {
      for(int i = 1; i <= Xindex; i++)
	{

	  if((Xindex - i) == 0)
	    a[0] = X;

	  else if(X < a[Xindex - i])
	     a[Xindex] = a[Xindex - i];//shift a[Xindex - i] to the right into the hole
	  
	  else if(X > a[Xindex - i])
	    a[Xindex - i] = X;//STOP SHIFTING IMMEDIATELY, put x into the current hole
	  
	  //else if((Xindex - i) == 0)
	  //a[0] = X;//deposit X in a[1]*/)
	  
	}
      Xindex++;
      X = a[Xindex];

    }
	     
  for(int k = 0; k < a.size(); k++)
    cout << a[k] << " ";

  cout << endl;

  return 0;
}
