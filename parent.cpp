#include "parent.h"

addressP alokasiParent(string info){
    addressP P = new elmParent;
    P->info = info;
    P->next = nullptr;
    return P;
}

bool isEmptyParent(ListParent LP) {
    return LP.first == nullptr;
}

void insertFirstParent(ListParent &LP, addressP p) {
    if (LP.first == nullptr) {
        LP.first = p;
    } else {
        p->next = LP.first;
        LP.first = p;
    }
}

void inputCabang(ListParent &LP, addressP &p){
    string namaCabang;
    addressP find;
    cout << "Masukkan nama cabang: ";
    cin >> namaCabang;
    find = searchCabang(LP, namaCabang);
    if (find == nullptr){
        p = alokasiParent(namaCabang);
        insertFirstParent(LP, p);
        cout << "Cabang berhasil ditambahkan." << endl;
    }else{
        cout << "Cabang sudah ada." << endl;
    }
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

void deleteFirstParent(ListParent &LP, addressP &p){
    if (LP.first == nullptr){
        p = nullptr;
    }else if (LP.first->next == nullptr){
        p = LP.first;
        LP.first = nullptr;
    }else{
        p = LP.first;
        LP.first = LP.first->next;
        p->next = nullptr;
    }
}

void deleteAfterParent(ListParent &LP, addressP &p, addressP prec){
    if (isEmptyParent(LP)){
        p = nullptr;
    }else if (prec->next == nullptr){
        p = nullptr;
    }else{
        p = prec->next;
        prec->next = p->next;
        p->next = nullptr;
    }
}

void deleteLastParent(ListParent &LP, addressP &p){
    addressP prev = LP.first;
    if (LP.first == nullptr){
        p = nullptr;
    }else if (LP.first->next == nullptr){
        p = LP.first;
        LP.first = nullptr;
    }else{
        while (prev->next->next != nullptr){
            prev = prev->next;
        }
        p = prev->next;
        prev->next = nullptr;
    }
}
