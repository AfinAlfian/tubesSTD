#include "relasi.h"

addressR alokasiRelasi(addressP parent, addressC child, int jumlahStok){
    addressR R = new elmRelasi;
    R->parent = parent;
    R->child = child;
    R->jumlahStok = jumlahStok;
    R->next = nullptr;
    return R;
}

bool isEmptyRelasi(ListRelasi LR) {
    return LR.first == nullptr;
}

void insertFirstRelasi(ListRelasi &LR, addressR R) {
    if (LR.first == nullptr) {
        LR.first = R;
    } else {
        R->next = LR.first;
        LR.first = R;
    }
}

void insertLastRelasi(ListRelasi &LR, addressR r){
    if (LR.first == nullptr){
        LR.first = r;
    } else {
        addressR p = LR.first;
        while (p->next != nullptr){
            p = p->next;
        }
        p->next = r;
    }
}

void inputRelasi(ListRelasi &LR, addressP p, addressC c){
    int n;
    cout << "Masukkan jumlah stok barang: ";
    cin >> n;
    addressR r = alokasiRelasi(p, c, n);   
    r->jumlahStok = n;
    insertLastRelasi(LR, r);
}

void deleteFirstRelasi(ListRelasi &LR, addressR &r){
    if (isEmptyRelasi(LR)){
        r = nullptr;
    }else if (LR.first->next == nullptr){
        r = LR.first;
        LR.first = nullptr;
    }else{
        r = LR.first;
        LR.first = LR.first->next;
        r->next = nullptr;
    }
}

void deleteAfterRelasi(ListRelasi &LR, addressR &r, addressR prec){
    if (isEmptyRelasi(LR)){
        r = nullptr;
    }else if (prec->next == nullptr){
        r = nullptr;
    }else{
        r = prec->next;
        prec->next = r->next;
        r->next = nullptr;
    }
}

void deleteLastRelasi(ListRelasi &LR, addressR &r){
    addressR prev= LR.first;
    if (isEmptyRelasi(LR)){
        r = nullptr;
    }else if (LR.first->next == nullptr){
        r = LR.first;
        LR.first = nullptr;
    }else{
        while (prev->next->next != nullptr){
            prev = prev->next;
        }
        r = prev->next;
        prev->next = nullptr;
    }
}

addressR searchRelasi(ListRelasi LR, string namaCabang, string namaBarang){
    addressR r = LR.first;
    addressR find = nullptr;
    while (r != nullptr){
        if (r->parent->info == namaCabang && r->child->info.namaBarang == namaBarang){
            find = r;           
        }
        r = r->next;
    }
    return find;
}
