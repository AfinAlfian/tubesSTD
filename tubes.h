#ifndef TUBES_H_included
#define TUBES_H_included

#include <iostream>
using namespace std;

struct elmParent;
struct elmChild;
struct elmRelasi;

typedef struct inventori infotype;

typedef elmParent* addressP;
typedef elmChild* addressC;
typedef elmRelasi* addressR;

struct inventori{
    string namaBarang;
    int jumlahStok;
    string kategori;
    bool statusTersedia;
};

struct elmParent {
    string info;
    addressP next;
};

struct elmChild {
    infotype info;
    addressC next;
};

struct elmRelasi {
    addressP parent;
    addressC child;
    addressR next;
};

struct ListParent { 
    addressP first;
};
struct ListChild  { 
    addressC first; 
};
struct ListRelasi { 
    addressR first; 
};

void createList(ListParent &LP, ListChild &LC, ListRelasi &LR);
addressP alokasiParent(string info);
addressC alokasiChild(inventori info);
addressR alokasiRelasi(addressP parent, addressC child);
void insertFirstParent(ListParent &LP, addressP P);
void insertFirstChild(ListChild &LC, addressC C);
void insertFirstRelasi(ListRelasi &LR, addressR R);
void inputCabang(ListParent &LP, addressP &P);
void inputBarang(ListChild &LC, addressC &C);
void inputRelasi(ListRelasi &LR, addressP parent, addressC child);
void displayInfo(ListParent LP, ListChild LC, ListRelasi LR);
void inputData(ListParent &LP, ListChild &LC, ListRelasi &LR);
 
#endif // TUBES_H_included

