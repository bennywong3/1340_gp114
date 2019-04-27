#include <iostream>
#include <time.h>
#include "time_list.h"

using namespace std;

// head_insert: to create a backward linked list when new group came in which stored their records including table position, number of costumers and entry time
//
// input: trecord * & head, int r, int c, int n, int inttime: location of head, row, column, number of customers and the time they enter
// output: a linked list which stored customers position and time is created
void head_insert(trecord * & head, int r, int c, int n, int inttime){
  trecord * p = new trecord;
  p->row = r;
  p->col = c;
  p->num = n;
  p->input_time = inttime;
  p->next = head;
  head = p;
}

// find_table: to find out whether customers have occupied a table for too long so that we can ask them to leave
//
// input: trecord *&head, bool &status: location of head and boolean status(initially as false)
// output: the number of customers and the position of the customers are print if they occupied the table for too long
//         otherwise, "There is no costumer occupied a table for too long." will be printed and return true status
int find_table(trecord *&head, bool &status){
  time_t start;
  start = time(NULL);
  int intstart;
  intstart=start;
  trecord *current = head;
  int counter=0;
  while (current != NULL) {
    if (start-current->input_time > 20) {
      cout<< current->num<<" customers occupied table "<<"R"<< current->row <<"C"<< current->col <<" for too long."<<endl;
      counter++;
    }
    current = current->next;
  }
  if (counter==0) {
    cout<<"There is no costumer occupied a table for too long."<<endl;
    status=true;
  }
  return intstart;
}

// delete_table: to change the input_time of the record of those occupied for too long in the linked list to invalid
//
// input: trecord *&head, int start_in_find, int avaseat[][5]: location of head, the start time get in find table function and integer array of available seats
// output: the input_time of the corresponding record will become invalid
void delete_table(trecord *&head, int start_in_find, int avaseat[][5]){
  trecord *current = head;
  while (current != NULL) {
    if (start_in_find-current->input_time > 20) {
      avaseat[current->row][current->col]+=(current->num);
      current->input_time=2147483647;
    }
    current = current->next;
  }
}
