#include<iostream>
using namespace std;

// You may not change my code in any manner.  0 pts if you do.
// Simply add your code for **

//----------------------------------------
//CS311 HW2P2 Partition
//Name: James Bertel
//Compiler: g++
//-----------------------------------------

// partitions the array a into smaller than pivot and others.
// f is the beginning of the section to be partitioned
// r is the end of the section to be partitioned
// return the first slot of the Large section
int partition(int pivot, int a[], int f, int r)
{

  int left = f; // pointer from the left 
  int right = r; // pointer from the right 
  
  // loop for finding out of place pairs and swap them
  // loops until left and right cross
  while(left <= right) 
    {

      if(a[left] < pivot) //if left elemt OK, move left
	left++; 

      else if(a[right] >= pivot)  //if right element OK, move right
	right--; //move right

      else if (a[left] >= pivot && a[right] < pivot) //if both are bad, swap
	{
	  //use temporary variable to swap
	  int temp = a[left];
	  a[left] = a[right];
	  a[right] = temp;
	  
	  //move left and right closer to the center
	  left++;
	  right--;
	}
      
    }

  // return the partition point where
  // those smaller than pivot are before what is returned

  //special case
  if(left == 0) return --left;

  //regular case
  else return left;  

} //end of partition

int main()
{
  int x;  // number of elements
  int nums[10];
  cout << "How many elements? (must be less than 10) "; 
  cin >> x;
  cout << "Enter elements one per line.." << endl;
  for (int i = 0; i < x; i++)
    { cin >> nums[i]; }

  // the pivot is always the first element
  cout << "Ok the pivot is " << nums[0] << endl;

  //send first element (pivot), array, first element, and last element
  int part = partition(nums[0], nums, 0, x-1);

  cout << "Results..." << endl;
  // display up to the partition without endl
  for (int i = 0; i < part; i++)
    cout << nums[i];

  cout << "|";
  // display from the partition on.. without endl
  for (int i = part; i < x; i++)
    cout << nums[i];

  cout << endl;

} //end of main
