// CS311 Yoshii HW5 client to test the Pqueue
// Use as is!

#include "pqueue.h"

int main()
{
  pqueue Jobs;

  Jobs.insertjob(5);
  Jobs.insertjob(4);
  Jobs.insertjob(6);
  Jobs.insertjob(7);
  Jobs.insertjob(8);
  Jobs.insertjob(9);
  Jobs.insertjob(10);

  Jobs.displayAll();
}  
