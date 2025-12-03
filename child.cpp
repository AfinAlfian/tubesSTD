#include "child.h"

addressC alokasiChild(inventori info){
    addressC c = new elmChild;
    c->info = info;
    c->next = nullptr;
    return c;
}

bool isEmptyChild(ListChild LC) {
    return LC.first == nullptr;
}

void insertFirstChild(ListChild &LC, addressC c) {
    if (isEmptyChild(LC)) {
        LC.first = c;
    } else {
        c->next = LC.first;
        LC.first = c;
    }
}

addressC searchBarang(ListChild LC, string x){
    addressC p, find;
    p = LC.first;
    find = nullptr;
    while (p != nullptr){
        if (p->info.namaBarang == x){
            find = p;           
        }
        p = p->next;
    }
    return find;
}

void inputBarang(ListChild &LC, addressC &c){
    infotype barang;
    addressC find;
    cout << "Masukkan nama barang: ";
    cin >> barang.namaBarang;
    find = searchBarang(LC, barang.namaBarang);
    if (find == nullptr){
        cout << "Masukkan kategori barang: ";
        cin >> barang.kategori;
        c = alokasiChild(barang);
        insertFirstChild(LC, c);       
    }else{
        cout << "Barang sudah ada dalam inventori." << endl;
    }   
}

void deleteFirstChild(ListChild &LC, addressC &c){
    if (isEmptyChild(LC)){
        c = nullptr;
    }else if (LC.first->next == nullptr){
        c = LC.first;
        LC.first = nullptr;
    }else{
        c = LC.first;
        LC.first = LC.first->next;
        c->next = nullptr;
    }
}

void deleteAfterChild(ListChild &LC, addressC &c, addressC prec){
    if (isEmptyChild(LC)){
        c = nullptr;
    }else if (prec->next == nullptr){
        c = nullptr;
    }else{
        c = prec->next;
        prec->next = c->next;
        c->next = nullptr;
    }
}

void deleteLastChild(ListChild &LC, addressC &c){
    addressC prev = LC.first;
    if (isEmptyChild(LC)){
        c = nullptr;
    }else if (LC.first->next == nullptr){
        c = LC.first;
        LC.first = nullptr;
    }else{
        while (prev->next->next != nullptr){
            prev = prev->next;
        }
        c = prev->next;
        prev->next = nullptr;
    }
}
