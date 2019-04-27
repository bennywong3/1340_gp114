#include <iostream>
#include "layout.h"

using namespace std;

// layout: to select the suitable layout by using dynamic arrays to create the desired layout
//
// input: int set[][5], int avaseat[][5]: one array with layout and one array with current available seats
// output: the desired deli layout is created
void layout(int set[][5], int avaseat[][5]){
  int x, n;
  int * spring = new int[15]{8,8,8,8,8,0,0,0,0,0,4,4,4,4,4};
  int * summer = new int[15]{8,4,0,4,8,0,2,2,2,0,8,4,0,4,8};
  int * autumn = new int[15]{8,0,8,0,8,4,0,4,0,4,2,0,2,0,2};
  int * winter = new int[15]{0,0,0,0,0,4,8,8,8,4,0,0,0,0,0};
  cout << "Choose your layout:"<<endl;
  cout <<"-----------------------------------------------------"<<endl;
  cout << "1: Default setting (maximum number of tables)"<<endl;
  cout << "2: Spring setting  (deleted one row)"<<endl;
  cout << "3: Summer setting  (large tables are at the corner)"<<endl;
  cout << "4: Autumn setting  (deleted two columns for space)"<<endl;
  cout << "5: Winter setting  (fewer tables)"<<endl;
  cout << "6: Custom setting  (input your own layout)"<<endl;
  cout <<"-----------------------------------------------------"<<endl;
  cout << "Please select (1 to 6): ";
  cin >> x;
  int counter = 0;

  switch (x) {
    case 1:
      for ( int i = 0; i < 3 ;i++)
        for (int j = 0; j < 5; j++)
          avaseat[i][j]=set[i][j];
      break;
    case 2:
      for ( int i = 0; i < 3 ;i++){
        for (int j = 0; j < 5; j++){
          set[i][j]=spring[counter];
          avaseat[i][j]=set[i][j];
          counter++;
        }
      }
      break;
    case 3:
      for ( int i = 0; i < 3 ;i++){
        for (int j = 0; j < 5; j++){
          set[i][j]=summer[counter];
          avaseat[i][j]=set[i][j];
          counter++;
        }
      }
      break;
    case 4:
      for ( int i = 0; i < 3 ;i++){
        for (int j = 0; j < 5; j++){
          set[i][j]=autumn[counter];
          avaseat[i][j]=set[i][j];
          counter++;
        }
      }
      break;
    case 5:
      for ( int i = 0; i < 3 ;i++){
        for (int j = 0; j < 5; j++){
          set[i][j]=winter[counter];
          avaseat[i][j]=set[i][j];
          counter++;
        }
      }
      break;
    case 6:
      cout<< "Please input your layout (with 3 rows x 5 columns, input 0 if there is no table) "<<endl;
      for ( int i = 0; i < 3 ;i++){
        for (int j = 0; j < 5; j++){
          cin >> n;
          set[i][j] = n;
          avaseat[i][j]= n;
        }
      }
      break;
    default:
      for ( int i = 0; i < 3 ;i++)
        for (int j = 0; j < 5; j++)
          avaseat[i][j]=set[i][j];
  }
  delete [] spring;
  delete [] summer;
  delete [] autumn;
  delete [] winter;
}
