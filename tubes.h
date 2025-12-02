#ifndef TUBES_H_included
#define TUBES_H_included

#include <iostream>
using namespace std;
#include "relasi.h"

struct elmParent;
struct elmChild;
struct elmRelasi;

void createList(ListParent &LP, ListChild &LC, ListRelasi &LR);
void tambahCabang(ListParent &LP, ListChild &LC, ListRelasi &LR);
void tambahBarang(ListParent &LP, ListChild &LC, ListRelasi &LR);
void displayInfo(ListParent LP, ListChild LC, ListRelasi LR);





 
#endif // TUBES_H_included

