#include <iostream>
#include <string>
#include <fstream>
#include "time_list.h"
#include "file_in_out.h"

using namespace std;

// file_in_out: to add up the number of customers before and today and output to a file named output.txt
//
// input: int total: total numbers of customers of today
// output: the accumulated numbers of customers of the deli, total number of customers for today and
//         full record of today's customers in descending order
void file_in_out(int total, trecord *&head){
  int x;
  string line1;
  time_t seconds;
  seconds = time(NULL);
  char filename[100] = "input.txt";
  ifstream fin;
  fin.open(filename);
  ofstream fout;
  fout.open("output.txt");
  if ( fout.fail() ) {
      cout << "Failed to open " << filename << endl;
      exit(1);
   }
  if (fin.fail()) {
      cout << "Failed to open " << filename << endl;
      exit(1);
  }
  getline(fin, line1);
  fin >> x;
  x += total;
  fout << line1<< endl;
  fout << x << endl;
  fout <<"Total number of customers for today:"<<endl;
  fout <<total<<endl;
  fout << "Program ended at:" << endl;
  fout << asctime(localtime(&seconds)) << endl;
  fout << "Full record of today's customers (in descending order)"<<endl;
  trecord *current = head;
  while (current != NULL) {
    fout << current->num <<" customers came in and occupied table R" << current->row << "C" << current->col << endl;
    current = current->next;
  }
  fout<<endl;
  fin.close();
  fout.close();
  return;
}
