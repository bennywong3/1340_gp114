#include <iostream>
#include <time.h>
#include <string>
#include <fstream>
#include "time_list.h"
#include "layout.h"
#include "print_layout.h"
#include "occupy.h"
#include "release.h"
#include "file_in_out.h"

using namespace std;

int main (){
  int total=0;
  int set[3][5] = {8,8,8,8,8,4,4,4,4,4,2,2,2,2,2};
  int avaseat[3][5];
  trecord * head = NULL;
  layout(set,avaseat);
  print_layout(set,avaseat);
  int choice;
  while (choice != 5) {
    cout<<"Input the corresponding number"<<endl;
    cout<<"---------------------------------------"<<endl;
    cout<<"1: Occupy a table"<<endl;
    cout<<"2: Release a table"<<endl;
    cout<<"3. Check tables occupied for too long"<<endl;
    cout<<"4. Show current availability of seats"<<endl;
    cout<<"5. End program"<<endl;
    cout<<"---------------------------------------"<<endl;
    cout<<"Your input: ";
    cin>> choice;
    switch (choice) {
      case 1:
        new_customer(set,avaseat,head,total);
        print_layout(set,avaseat);
        break;
      case 2:
        print_layout(set,avaseat);
        release(set,avaseat,head);
        print_layout(set,avaseat);
        break;
      case 3:
        int start_in_find;
        char yorn;
        bool no_occ;
        no_occ = false;
        start_in_find = find_table(head,no_occ);
        if (no_occ==false) {
          cout<<"Would you like those customers to leave?"<<endl;
          cout<<"Your choice(Y/N): ";
          cin >> yorn;
          if (yorn=='Y' || yorn=='y') {
            delete_table(head,start_in_find, avaseat);
          }
        }
        print_layout(set,avaseat);
        break;
      case 4:
        print_layout(set,avaseat);
        break;
      case 5:
        cout<<"Today a total of "<<total<<" customers visited our deli."<<endl;
        cout<<"See output.txt for more details."<<endl;
        cout<<"End of program."<<endl;
        break;
    }
  }
  file_in_out(total,head);
  return 0;
}
