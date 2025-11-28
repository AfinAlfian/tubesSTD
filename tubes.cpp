#include "tubes.h"

void createList(ListParent &LP, ListChild &LC, ListRelasi &LR){
    LP.first = nullptr;
    LC.first = nullptr;
    LR.first = nullptr;
}

addressP alokasiParent(string info){
    addressP P = new elmParent;
    P->info = info;
    P->next = nullptr;
    return P;
}

addressC alokasiChild(inventori info){
    addressC C = new elmChild;
    C->info = info;
    C->next = nullptr;
    return C;
}

addressR alokasiRelasi(addressP parent, addressC child){
    addressR R = new elmRelasi;
    R->parent = parent;
    R->child = child;
    R->next = nullptr;
    return R;
}

void insertFirstParent(ListParent &LP, addressP P) {
    if (LP.first == nullptr) {
        LP.first = P;
    } else {
        P->next = LP.first;
        LP.first = P;
    }
}

void insertFirstChild(ListChild &LC, addressC C) {
    if (LC.first == nullptr) {
        LC.first = C;
    } else {
        C->next = LC.first;
        LC.first = C;
    }
}

void insertFirstRelasi(ListRelasi &LR, addressR R) {
    if (LR.first == nullptr) {
        LR.first = R;
    } else {
        R->next = LR.first;
        LR.first = R;
    }
}

void inputCabang(ListParent &LP, addressP &P){
    string namaCabang;
    cout << "Masukkan nama cabang: ";
    cin >> namaCabang;
    P = alokasiParent(namaCabang);
    insertFirstParent(LP, P);
}

void inputBarang(ListChild &LC, addressC &C){
    infotype barang;
    cout << "Masukkan nama barang: ";
    cin >> barang.namaBarang;
    cout << "Masukkan jumlah stok: ";
    cin >> barang.jumlahStok;
    cout << "Masukkan kategori barang: ";
    cin >> barang.kategori;
    barang.statusTersedia = (barang.jumlahStok > 0);
    C = alokasiChild(barang);
    insertFirstChild(LC, C);
}

void inputRelasi(ListRelasi &LR, addressP parent, addressC child){
    addressR R = alokasiRelasi(parent, child);
    insertFirstRelasi(LR, R);
}

void displayInfo(ListParent LP, ListChild LC, ListRelasi LR) {
    addressR R = LR.first;
    while (R != nullptr) {
        cout << "Cabang: " << R->parent->info << " - Barang: " << R->child->info.namaBarang << endl;
        R = R->next;
    }
}

void inputData(ListParent &LP, ListChild &LC, ListRelasi &LR) {
    addressP P;
    addressC C;
    inputCabang(LP, P);
    inputBarang(LC, C);
    inputRelasi(LR, P, C);
}