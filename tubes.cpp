#include "tubes.h"

void createList(ListParent &LP, ListChild &LC, ListRelasi &LR){
    LP.first = nullptr;
    LC.first = nullptr;
    LR.first = nullptr;
}

void tambahCabang(ListParent &LP, ListChild &LC, ListRelasi &LR){
    addressP p;
    addressC c;
    string x;
    inputCabang(LP, p);
    cout << "apakah anda ingin sekalian tambah barang? ";
    cin >> x;
    if (x == "Y" || x == "y"){
        inputBarang(LC, c);
        inputRelasi(LR, p, c);
    }
}

void tambahBarang(ListParent &LP, ListChild &LC, ListRelasi &LR){
    addressP p;
    addressC c;
    addressR r;
    inputBarang(LC, c);
    string namaCabang;
    cout << "Masukkan nama cabang untuk menambah barang: ";
    cin >> namaCabang;
    p = searchCabang(LP, namaCabang);
    if (p != nullptr){
        inputRelasi(LR, p, c);
    }else{
        cout << "Cabang tidak ditemukan." << endl;
        cout << "apakah anda ingin menambah cabang baru? (y/n): ";
        char choice;
        cin >> choice;
        if (choice == 'y' || choice == 'Y'){
            inputCabang(LP, p);
            inputRelasi(LR, p, c);
        }
    }

}



void displayInfo(ListParent LP, ListChild LC, ListRelasi LR) {
    addressR R = LR.first;
    printf("%-20s %-20s %-20s %-20s\n", "Cabang", "Barang", "Jumlah Stok", "kategori");
    while (R != nullptr) {
        printf("%-20s %-20s %-20d %-20s\n", R->parent->info.c_str(), R->child->info.namaBarang.c_str(), R->jumlahStok, R->child->info.kategori.c_str());
        R = R->next;
    }
}

