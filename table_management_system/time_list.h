#ifndef _TIME_LIST_
#define _TIME_LIST_

struct trecord{
  int row;
  int col;
  int num;
  int input_time;
  trecord * next;
};
void head_insert(trecord * & head, int r, int c, int n, int inttime);
int find_table(trecord *&head, bool &status);
void delete_table(trecord *&head, int start_in_find, int avaseat[][5]);

#endif //_TIME_LIST_
