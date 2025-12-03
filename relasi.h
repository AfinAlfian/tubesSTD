#ifndef RELASI_H_included
#define RELASI_H_included

#include <iostream>
using namespace std;
#include "parent.h"
#include "child.h"

struct elmRelasi;
typedef struct elmRelasi *addressR;

struct elmRelasi {
    int jumlahStok;
    addressP parent;
    addressC child;
    addressR next;
};

struct ListRelasi { 
    addressR first; 
};

addressR alokasiRelasi(addressP parent, addressC child, int jumlahStok);
bool isEmptyRelasi(ListRelasi LR);
void insertFirstRelasi(ListRelasi &LR, addressR r);
void inputRelasi(ListRelasi &LR, addressP parent, addressC child);
void deleteFirstRelasi(ListRelasi &LR, addressR &r);
void deleteAfterRelasi(ListRelasi &LR, addressR &r, addressR prec);
void deleteLastRelasi(ListRelasi &LR, addressR &r);
addressR searchRelasi(ListRelasi LR, string namaCabang, string namaBarang);

#endif






















