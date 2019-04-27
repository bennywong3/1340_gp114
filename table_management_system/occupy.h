#ifndef _OCCUPY_
#define _OCCUPY_
#include "time_list.h"


void check_vacancy(int n, int changed_set[][5], int de_set[][5], trecord *&head, int intentry);
void new_customer(int de_set[][5], int changed_set[][5], trecord *&head, int &total_outside);

#endif // _OCCUPY_
