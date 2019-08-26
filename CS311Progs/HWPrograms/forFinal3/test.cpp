#include "htable.h"

void showSearchMenu(htable Oteam2019)
{
  int key; //key == rank being searched

  cout << "Enter the ranking you want to search: ";
  cin >> key;
  el_t E = Oteam2019.find(key); //finds element with associated rank
  el_t blank; //purposely blank element
  
  if(E == blank)
    cout << key << " not found." << endl;
  else //if rank found, show Oteamer
    cout << "Found " << key << ":\n\t" << E << endl;  
}

void showMenu(htable Oteam2019)
{
  bool end = false; //variable to end program
  int choice; //menu choice

  while(end == false)
    {
      do{
	cout << endl;
	cout << "What would you like to do?" << endl;
	cout << "\t1. Search for an Oteamer" << endl;
	cout << "\t2. Show all Oteamers" << endl;
	cout << "\t3. End Program" << endl;
	cout << "\nEnter choice: ";
	cin >> choice;
      }while(choice < 1 || choice > 3);

      if(choice == 1)
	showSearchMenu(Oteam2019);
      else if(choice == 2)
	Oteam2019.displayTable();
      else //choice == 3
	end = true;
    }
}

void runProgram()
{
  htable Oteam2019;
  
  Oteam2019.loadTable();
  showMenu(Oteam2019);
}

int main()
{
  runProgram();
  return 0;
}
