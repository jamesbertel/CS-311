// CS311 Yoshii - Recursive Function demonstration
// ------------------------------------------------------
#include<iostream>
using namespace std;

// this recursive function calls itself with end reduced by red each time
// Infinite Recursion
void divide(int L[], int count)
{ count++;
  cout << count << " Divide was called and its AR was pushed" << endl;
  divide(L, count);  // recursive call reducing end by red
}

int main()
{
  int MyArray[10];
  int red;

  cout << "I will need 3 integers from you." << endl;
  for (int i = 0; i< 3; i++)
    {
    cout << "Enter::";
    cin >> MyArray[i];
    }
  divide(MyArray, 0);
}
