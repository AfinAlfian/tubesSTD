#ifndef TUBES_H_included
#define TUBES_H_included

#include <iostream>
using namespace std;
#include "relasi.h"
#include "parent.h"
#include "child.h"

//struct elmParent;
//struct elmChild;
//struct elmRelasi;
//tes
void header();
void footer();
void menu(int &n);
void createList(ListParent &LP, ListChild &LC, ListRelasi &LR);
void tambahCabang(ListParent &LP, ListChild &LC, ListRelasi &LR);
void tambahBarang(ListParent &LP, ListChild &LC, ListRelasi &LR);
void displayInfo(ListParent LP, ListChild LC, ListRelasi LR);
void clearScreen();
void enterToContinue();

#endif // TUBES_H_included

