#include "child.h"

addressC alokasiChild(inventori info){
    addressC C = new elmChild;
    C->info = info;
    C->next = nullptr;
    return C;
}

void insertFirstChild(ListChild &LC, addressC C) {
    if (LC.first == nullptr) {
        LC.first = C;
    } else {
        C->next = LC.first;
        LC.first = C;
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

void inputBarang(ListChild &LC, addressC &C){
    infotype barang;
    addressC find;
    cout << "Masukkan nama barang: ";
    cin >> barang.namaBarang;
    find = searchBarang(LC, barang.namaBarang);
    if (find == nullptr){
        cout << "Masukkan kategori barang: ";
        cin >> barang.kategori;
        C = alokasiChild(barang);
        insertFirstChild(LC, C);       
    }else{
        insertFirstChild(LC, find);
    }   
}

void deleteFirstChild(ListChild &LC, addressC &C){
    if (LC.first == nullptr){
        C = nullptr;
    }else if (LC.first->next == nullptr){
        C = LC.first;
        LC.first = nullptr;
    }else{
        C = LC.first;
        LC.first = LC.first->next;
        C->next = nullptr;
    }
}

void deleteAfterChild(ListChild &LC, addressC &C, addressC prec){
    if (prec != nullptr){
        C = prec->next;
        prec->next = C->next;
        C->next = nullptr;
    }
}

void deleteLastChild(ListChild &LC, addressC &C){
    addressC prev = LC.first;
    if (LC.first == nullptr){
        C = nullptr;
    }else if (LC.first->next == nullptr){
        C = LC.first;
        LC.first = nullptr;
    }else{
        while (prev->next->next != nullptr){
            prev = prev->next;
        }
        C = prev->next;
        prev->next = nullptr;
    }
}
