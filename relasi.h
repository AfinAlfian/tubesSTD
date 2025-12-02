#ifndef RELASI_H_included
#define RELASI_H_included

#include <iostream>
using namespace std;
#include "parent.h"
#include "child.h"

struct elmRelasi; // forward declaration
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
void insertFirstRelasi(ListRelasi &LR, addressR R);
void inputRelasi(ListRelasi &LR, addressP parent, addressC child);

#endif






















