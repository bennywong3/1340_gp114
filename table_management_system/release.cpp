#include <iostream>
#include "time_list.h"
#include "release.h"

using namespace std;

// release: to release a table if customers have finished their meal or they have occupied the seats for too long
//
// input: int set[][5], int avaseat[][5], trecord *&head: one array with layout, one array with current available seats and location of head
// output: the table is released and the seat available restored
void release(int set[][5], int avaseat[][5], trecord *&head){
  int r,c,num;
  cout<<"Please input the row and column of the table and the number of customers left"<<endl;
  cout<<"Row number: ";
  cin>>r;
  cout<<"Column number: ";
  cin>>c;
  cout<<"Number of customers left: ";
  cin>>num;
  while ((num-set[r][c])>0 || avaseat[r][c]+num > set[r][c]) {
    cout<<"Wrong input! Please input again."<<endl;
    cout<<"Number of customers left: ";
    cin>>num;
  }

  //assuming that the leaving customers belong to the same group
  //i.e. they enter and leave at the same time
  trecord *current = head;
  while (current != NULL) {
    if (current->row == r && current->col ==c && current->num == num) {
      current->input_time=2147483647;
      break;
    }
    current = current->next;
  }
  avaseat[r][c]+=num;
}
