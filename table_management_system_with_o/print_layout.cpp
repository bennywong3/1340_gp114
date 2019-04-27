#include <iostream>
#include "print_layout.h"
using namespace std;

// print_layout: to print out the current seats situation in grid form
//
//input: one array with layout, one array with current available seats
//output: print layouts(table size - curr. ava.seat) in grid form
void print_layout(int de_set[][5], int changed_set[][5]){
  cout <<"--------------------"<<endl;
  cout << "Current layout: " << endl;
  for (int i = 0; i < 3; i++){
    for (int j = 0; j < 5; j++){
      if (de_set[i][j]==0) {
        cout <<"X-X"<<" ";
      }
      else
        cout << de_set[i][j] << "-" << changed_set[i][j] <<" ";
    }
    cout << endl;
  }
  cout <<"--------------------"<<endl;
}
