#ifndef PARENT_H_included
#define PARENT_H_included
#include <iostream>
#include <string>
using namespace std;

struct elmParent;

typedef struct elmParent *addressP;

struct elmParent {
    string info;
    addressP next;
};

struct ListParent { 
    addressP first;
};

addressP alokasiParent(string info);
void insertFirstParent(ListParent &LP, addressP P);
void inputCabang(ListParent &LP, addressP &P);
void deleteFirstParent(ListParent &LP, addressP &P);
void deletelastParent(ListParent &LP, addressP &P);
void deleteAfterParent(ListParent &LP, addressP &P, addressP prec);
addressP searchCabang(ListParent LP, string x);

#endif