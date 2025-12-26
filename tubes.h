#ifndef TUBES_H_included
#define TUBES_H_included

#include <iostream>
using namespace std;
#include "relasi.h"
#include "parent.h"
#include "child.h"

void header();
void footer();
void mainMenu();
void menuCabang();
void menuBarang();
void menuInventori();
void menuLaporan();
void menu(int &n);
void createList(ListParent &LP, ListChild &LC, ListRelasi &LR);
void tambahCabang(ListParent &LP, ListChild &LC, ListRelasi &LR);
void tambahBarang(ListParent &LP, ListChild &LC, ListRelasi &LR);
void clearScreen();
void enterToContinue();
void displayNamaCabang(ListParent LP);
void displayNamaBarang(ListChild LC);
void displayCabang(ListParent LP, ListRelasi LR);
void hapusCabang(ListParent &LP, ListRelasi &LR);
void hapusBarang(ListChild &LC, ListRelasi &LR);
void hapusBarangDariCabang(ListRelasi &LR);
void updateStokBarang(ListRelasi &LR, ListParent LP, ListChild LC);
void tampilkanBarangDiCabang(ListParent LP, ListRelasi LR, string namaCabang);
void hitungJumlahBarangPerItem(ListChild LC, ListRelasi LR);
void statistikBarang(ListChild LC, ListRelasi LR);
void updateStatusBarang(addressC c, ListRelasi LR);
void tampilkanSemua(ListParent LP, ListRelasi LR);

#endif // TUBES_H_included

