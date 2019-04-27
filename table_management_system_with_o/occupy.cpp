#include <iostream>
#include "time_list.h"
#include "occupy.h"

using namespace std;


// check_vacancy: to check how seats can be arranged to the customers if the seats with their most suitable number cannot be provided
//
// input: int n, int changed_set[][5], int de_set[][5], trecord *&head, int intentry: number of customers, one array with layout, one array with current available seats, the position of the head and the entry time
// output: the suitable table(s) for customers in RXCX.
void check_vacancy(int n, int changed_set[][5], int de_set[][5], trecord *&head, int intentry){
  int remain;                           //This two for-loops is used to check whether table with one class larger is available or not
  int x, y, min = n, temp;
  for (int i = 0; i < 3; i++){
    for (int j = 0; j < 5; j++){
      if (n <= 2 && n > 0){
        if (changed_set[i][j] == 4){
          changed_set[i][j] = 4-n;
          head_insert(head,i,j,n,intentry);
          cout << n << " customers are assigned to table "<< "R" << i << "C" << j << endl;
          n = 0;
        }
      }
      else if (n > 2){
        if (changed_set[i][j] == 8){
          changed_set[i][j] = 8-n;
          head_insert(head,i,j,n,intentry);
          cout << n << " customers are assigned to table "<< "R" << i << "C" << j << endl;
          n = 0;
        }
      }
    }
  }
  for (int i = 0; i < 3; i++){
    for (int j = 0; j < 5; j++){
      if (n <= 2 && n > 0){
        if (changed_set[i][j] == 8){
          changed_set[i][j] = 8-n;
          head_insert(head,i,j,n,intentry);
          cout << n << " customers are assigned to table "<< "R" << i << "C" << j << endl;
          n = 0;
        }
      }
    }
  }
  while (n != 0){
    for (int i = 0; i < 3; i++){
      for (int j = 0; j < 5; j++){
        temp = n - changed_set[i][j];
        if (temp < min){
          x = i;
          y = j;
          min = temp;
        }
      }
    }
    if (min == 0){
      changed_set[x][y] =  0;
      head_insert(head,x,y,n,intentry);
      cout << n << " customers are assigned to table "<< "R" << x << "C" << y << endl;
      n = 0;
    }
    else if (min > 0){
      head_insert(head,x,y,changed_set[x][y],intentry);
      cout << changed_set[x][y] << " customers are assigned to table "<< "R" << x << "C" << y << endl;
      changed_set[x][y] = 0;
      n=min;
    }
    else if (min < 0){
      changed_set[x][y] = -1*min;
      head_insert(head,x,y,n,intentry);
      cout << n << " customers are assigned to table "<< "R" << x << "C" << y << endl;
      n = 0;
    }
  }
}

// new customer: to give them the table with minimum numbers of seats that fullfill their need
//
// input: int de_set[][5], int changed_set[][5], trecord *&head, int &total_outside: one array with layout, one array with current available seats, the position of the head and the total number of customer entered.
// output: the suitable table(s) for customers in RXCX.
void new_customer(int de_set[][5], int changed_set[][5], trecord *&head, int &total_outside){
  int n, count = 0, total = 0;
  cout << "Number of customer (1-8): ";
  cin >> n;
  time_t entry;
  entry = time(NULL);
  int intentry;
  intentry=entry;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 5; j++){
      total += changed_set[i][j];
      }
    }
  if (n > total){
      cout << "Sorry, we don't have enough seat now, please wait for a while" << endl;
      return;
  }
  if (n > 8){
    cout << "Sorry, we can't provide seats with more than 8 people" << endl;
  }
  else{
      total_outside+=n;                                //This func1tion is used to check whether table with exactly minimum size can be provided
      for (int i = 0; i < 3; i++){          //If not it will enter another function check_vacancy
        for (int j = 0; j < 5; j++){
          if (n <= 2 && n > 0){
            if (changed_set[i][j] == 2 && de_set[i][j] == 2){
              changed_set[i][j] = 2-n;
              head_insert(head,i,j,n,intentry);
              cout << n << " customers are assigned to table "<< "R" << i << "C" << j << endl;
              n = 0;
            }
            else{
              count++;
            }
          }
          else if (n > 2 && n <= 4){
            if (changed_set[i][j] == 4 && de_set[i][j] == 4){
              changed_set[i][j] = 4-n;
              head_insert(head,i,j,n,intentry);
              cout << n << " customers are assigned to table "<< "R" << i << "C" << j << endl;
              n = 0;
            }
            else{
              count++;
            }
          }
          else if (n > 4){
            if (changed_set[i][j] == 8 && de_set[i][j] == 8){
              changed_set[i][j] = 8-n;
              head_insert(head,i,j,n,intentry);
              cout << n << " customers are assigned to table "<< "R" << i << "C" << j << endl;
              n = 0;
            }
            else{
              count++;
            }
          }
        }
      }
    if (count == 15){
      check_vacancy(n, changed_set, de_set, head, intentry);
    }
  }
}
