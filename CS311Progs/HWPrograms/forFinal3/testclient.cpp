#include "htable.h"

void showMenuALPHA(htable Oteam2019, string &skey, char &pos, long &num)
{
  char choice;

  while(choice != 'Z')
    {
      do{
	cout << "================ WELCOME ! ================" << endl;
	cout << "Choose how you would like to search for an Oteamer by:" << endl;
	cout << "\tA: First Name" << endl;
	cout << "\tB: Last Name" << endl;
	cout << "\tC: Major" << endl;
	cout << "\tD: Position" << endl;
	cout << "\tE: Email" << endl;
	cout << "\tF: Phone Number" << endl;
	cout << "\tZ: Exit Program" << endl;
	cin >> choice;
	toupper(choice);
	
      }while((choice >= 'A' && choice <= 'F') || choice == 'Z');
            
      if((choice == 'A' || choice =='B') || (choice == 'C' || choice == 'E'))
	{
	  cout << "Enter what you want to search for ";// << endl;
	  cin >> skey;
	  //el_t E = Oteam22019.findString(skey);
	}
      else if(choice == 'D')
	{
	  cout << "Enter position you want to search for: ";
	  cin >> pos;
	  //el_t E = Oteam2019.findPos(pos);
	}
      else if(choice == 'F')
	{
	  cout << "Enter phone number you want to search for: ";
	  cin >> num;
	  //el_t E = Oteam2019.findNum(num);
	}
      else //(choice == 'Z')
	return;
    }

    /*    
      if(choice == 'A')
	searchFirstN(skey);
      else if(choice == 'B')
	searchLastN(skey);
      else if(choice == 'C')
	searchMaj(skey);
      else if(choice == 'D')
	searchPos(pos);
      else if(choice == 'E')
	searchEmail(skey);
      else if(choice == 'F')
	searchNum(num);
      else return;
      */
}

void runProgram()
{
  htable Oteam2019;
  string skey; //in case key will be a name, major, or email
  char pos; //in case key will be the position
  long num; //in case key will be a phone number

  Oteam2019.loadTable();
  Oteam2019.displayTable();
  //showMenuALPHA(Oteam2019, skey, pos, num);
}

int main()
{
  runProgram();
  return 0;
}