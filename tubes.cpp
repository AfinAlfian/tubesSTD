#include "tubes.h"

void header(){
    cout << "==============================" << endl;
    cout << "    PROGRAM INVENTORI TOKO    " << endl;
    cout << "==============================" << endl;
}

void footer(){
    cout << "==============================" << endl;
    cout << "==============================" << endl;
}

void menu(int &n){
    cout << "Menu Program Inventori Toko" << endl;
    cout << "1. Tambah Cabang" << endl;
    cout << "2. Tambah Barang" << endl;
    cout << "3. Tambah data barang ke cabang" << endl;
    cout << "4. Hapus Cabang" << endl;
    cout << "5. Hapus Barang" << endl;
    cout << "6. Cari Cabang" << endl;
    cout << "7. Cari Barang" << endl;
    cout << "8. Tampilkan barang di cabang tertentu" << endl;
    cout << "9. Tampilkan Info Inventori" << endl;
    cout << "10. Hitung jumlah barang tersedia" << endl;
    cout << "11. Statistik Cabang (stok barang terbanyak dan sedikit)" << endl;
    cout << "12. Keluar" << endl;
    cout << "Pilih menu (1-12): ";
    cin >> n;
}

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
    cout << "apakah anda ingin sekalian tambah barang? (y/n): ";
    cin >> x;
    if (x == "Y" || x == "y" || x == "Ya" || x == "YA" || x == "ya"){
        inputBarang(LC, c);
        inputRelasi(LR, p, c);
    }
}

void tambahBarang(ListParent &LP, ListChild &LC, ListRelasi &LR){
    addressP p;
    addressC c;
    addressR r;
    string namaBarang, namaCabang;
    cout << "Masukkan nama barang yang ingin ditambahkan: ";
    cin >> namaBarang;
    c = searchBarang(LC, namaBarang);   
    
    if (c == nullptr){
        cout << "Barang tidak ditemukan. Silahkan tambahkan barang terlebih dahulu." << endl;
    }else{
        cout << "Masukkan nama cabang untuk menambahkan barang: ";
        cin >> namaCabang;
        p = searchCabang(LP, namaCabang);
        if (p != nullptr){
            inputRelasi(LR, p, c);
        }else{
            cout << "Cabang tidak ditemukan. Silahkan tambahkan cabang terlebih dahulu." << endl;
        }
    }
}

void displayInfo(ListParent LP, ListChild LC, ListRelasi LR) {
    addressP p;
    addressR r;
    string status;
    bool printed;

    printf("%-20s %-20s %-20s %-20s %-20s\n", "Cabang", "Barang", "Jumlah Stok", "kategori", "Status");
    cout << "----------------------------------------------------------------------------------------" << endl;
    p = LP.first;
    while (p != nullptr) {
        printed = false;
        r = LR.first;
        while (r != nullptr) {
            if (r->parent == p) {
                if (r->child->statusKetersediaan) {
                    status = "Tersedia";
                }else{
                    status = "Tidak tersedia";
                }

                if (!printed) {
                    printf("%-20s %-20s %-20d %-20s %-20s\n", p->info.c_str(), r->child->info.namaBarang.c_str(), r->jumlahStok, r->child->info.kategori.c_str(), status.c_str());
                    printed = true;
                } else {
                    printf("%-20s %-20s %-20d %-20s %-20s\n", " ", r->child->info.namaBarang.c_str(), r->jumlahStok, r->child->info.kategori.c_str(), status.c_str());
                }
            }else if (!printed && r->next == nullptr) {
                printf("%-20s %-20s %-20s %-20s %-20s\n", p->info.c_str(), "-", "-", "-", "-");
            }
            r = r->next;
        }
        p = p->next;
    }
    enterToContinue();
}

void clearScreen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void enterToContinue() {
    cout << "Press Enter to continue...";
    cin.ignore();
    cin.get();
}

