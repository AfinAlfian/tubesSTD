#ifndef CHILD_H_included
#define CHILD_H_included
#include <iostream>
#include <string>
using namespace std;

typedef struct elmChild *addressC;
typedef struct inventori infotype;

struct inventori{
    string namaBarang;
    string kategori;
};

struct elmChild {
    infotype info;
    addressC next;
    bool statusKetersediaan;
};

struct ListChild  { 
    addressC first; 
};

addressC alokasiChild(inventori info);
bool isEmptyChild(ListChild LC);
void insertFirstChild(ListChild &LC, addressC C);
void inputBarang(ListChild &LC, addressC &C);
void deleteFirstChild(ListChild &LC, addressC &C);
void deleteAfterChild(ListChild &LC, addressC &C, addressC prec);
void deleteLastChild(ListChild &LC, addressC &C);
addressC searchBarang(ListChild LC, string x);


#endif