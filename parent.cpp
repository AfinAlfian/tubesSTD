#include "parent.h"

addressP alokasiParent(string info){
    addressP P = new elmParent;
    P->info = info;
    P->next = nullptr;
    return P;
}

void insertFirstParent(ListParent &LP, addressP P) {
    if (LP.first == nullptr) {
        LP.first = P;
    } else {
        P->next = LP.first;
        LP.first = P;
    }
}

void inputCabang(ListParent &LP, addressP &P){
    string namaCabang;
    cout << "Masukkan nama cabang: ";
    cin >> namaCabang;
    P = alokasiParent(namaCabang);
    insertFirstParent(LP, P);
}

addressP searchCabang(ListParent LP, string x){
    addressP p, find;
    p = LP.first;
    find = nullptr;
    while (p != nullptr){
        if (p->info == x){
            find = p;           
        }
        p = p->next;
    }
    return find;
}

void deleteFirstParent(ListParent &LP, addressP &P){
    if (LP.first == nullptr){
        P = nullptr;
    }else if (LP.first->next == nullptr){
        P = LP.first;
        LP.first = nullptr;
    }else{
        P = LP.first;
        LP.first = LP.first->next;
        P->next = nullptr;
    }
}

void deleteAfterParent(ListParent &LP, addressP &P, addressP prec){
    if (prec != nullptr){
        P = prec->next;
        prec->next = P->next;
        P->next = nullptr;
    }
}

void deleteLastParent(ListParent &LP, addressP &P){
    addressP prev = LP.first;
    if (LP.first == nullptr){
        P = nullptr;
    }else if (LP.first->next == nullptr){
        P = LP.first;
        LP.first = nullptr;
    }else{
        while (prev->next->next != nullptr){
            prev = prev->next;
        }
        P = prev->next;
        prev->next = nullptr;
    }
}
