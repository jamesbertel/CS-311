/****
/ Sat Jan 19, 2018
/ 
/ This program prints the maximum number of factors (excluding 1)
/ that can be multiplied together to produce n!
/
/***/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

vector<int> getNumbers()
{
  vector<int> nums;

  ifstream fin;
  fin.open("prob1.txt");
  int data;

  while(fin >> data)
    nums.push_back(data);

  return nums;
}

int findMaxNum(int num)
{
  int total = 0;

  for(int i = num; i >= 1; i++)
    {
      //???????????????
    }

  return total;
}


void runProgram()
{
  vector<int> numbers = getNumbers();
  
  for(int i = 0; i < numbers.size(); i++)
    {
      int num = numbers[i];
      
      int max = findMaxNum(num);
      
      cout << max << endl;
    }
}

int main()
{
  runProgram();
  return 0;
}
