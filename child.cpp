#include "child.h"

addressC alokasiChild(inventori info){
    //I.S. info terdefinisi
    //F.S. Menghasilkan sebuah addressC baru yang berisi info dan next bernilai nullptr
    addressC c = new elmChild;
    c->info = info;
    c->next = nullptr;
    c->statusKetersediaan = false;
    return c;
}

bool isEmptyChild(ListChild LC) {
    //I.S. LC terdefinisi
    //F.S. Mengembalikan true jika LC kosong, false jika tidak
    return LC.first == nullptr;
}

void insertFirstChild(ListChild &LC, addressC c) {
    //I.S. LC terdefinisi, c terdefinisi
    //F.S. c menjadi elemen pertama pada LC
    if (isEmptyChild(LC)) {
        LC.first = c;
    } else {
        c->next = LC.first;
        LC.first = c;
    }
}

addressC searchBarang(ListChild LC, string x){
    //I.S. LC terdefinisi, x terdefinisi
    //F.S. Mengembalikan addressC dari barang dengan nama x, atau nullptr jika tidak ditemukan
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
    //I.S. LC terdefinisi
    //F.S. Menambahkan barang baru ke dalam LC
    infotype barang;
    addressC find;
    cout << "Masukkan nama barang: ('-' untuk berhenti) :";
    cin >> barang.namaBarang;
    while (barang.namaBarang != "-"){
        find = searchBarang(LC, barang.namaBarang);
        if (find == nullptr){
            cout << "Masukkan kategori barang: ";
            cin >> barang.kategori;
            c = alokasiChild(barang);
            insertFirstChild(LC, c);       
        }else{
            cout << "Barang sudah ada dalam inventori." << endl;
        }  
        cout << "Masukkan nama barang: ('-' untuk berhenti) :";
        cin >> barang.namaBarang;
    }
}

void deleteFirstChild(ListChild &LC, addressC &c){
    //I.S. LC terdefinisi
    //F.S. Menghapus elemen pertama dari LC dan mengembalikan addressC
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
    //I.S. LC terdefinisi, prec terdefinisi
    //F.S. Menghapus elemen setelah prec dari LC dan mengembalikan address
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
    //I.S. LC terdefinisi
    //F.S. Menghapus elemen terakhir dari LC dan mengembalikan addressC
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
