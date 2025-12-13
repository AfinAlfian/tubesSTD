#include "tubes.h"

void header(){
    cout << "╔══════════════════════════════════════╗" << endl;
    cout << "    PROGRAM INVENTORI TOKO    " << endl;
    cout << "╠══════════════════════════════════════╣" << endl;
}

void footer(){
    cout << "==============================" << endl;
    cout << "==============================" << endl;
}
void mainMenu(){
    clearScreen();
    int opsi;
    cout << "1. Kelola Cabang" << endl;
    cout << "2. Kelola Barang" << endl;
    cout << "3. Kelola Inventori Cabang" << endl;
    cout << "4. Laporan Inventori" << endl;
    cout << "0. Keluar" << endl;
    cout << "Pilih menu: ";

};

void menuCabang(){
    clearScreen();
    int opsi;
    cout << "1. Tambah Cabang" << endl;
    cout << "2. Hapus Cabang" << endl;
    cout << "3. Tampilkan Semua Cabang" << endl;
    cout << "0. Kembali ke Menu Utama" << endl;
    cout << "Pilih menu: ";
};

void menuBarang(){
    clearScreen();
    cout << "1. Tambah Barang" << endl;
    cout << "2. Hapus Barang" << endl;
    cout << "3. Tampilkan Semua Barang" << endl;
    cout << "0. Kembali ke Menu Utama" << endl;
    cout << "Pilih menu: ";
};

void menuInventori(){
        clearScreen();
        cout << "1. Tambah data barang ke cabang" << endl;
        cout << "2. Hapus data barang dari cabang" << endl;
        cout << "3. Update stok barang di cabang" << endl;
        cout << "0. Kembali ke Menu Utama" << endl;
        cout << "Pilih menu: ";
};

void menuLaporan(){
    clearScreen();
    cout << "1. Tampilkan Info Inventori" << endl;
    cout << "2. Hitung jumlah barang tersedia" << endl;
    cout << "3. Statistik Cabang (stok barang terbanyak dan sedikit)" << endl;
    cout << "0. Kembali ke Menu Utama" << endl;
    cout << "Pilih menu: ";
};

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

void tambahBarang(ListParent &LP, ListChild &LC, ListRelasi &LR){
    string namaCabang, namaBarang;
    addressP p;
    addressC c;

    displayNamaCabang(LP);
    cout << "Masukkan nama cabang: ";
    cin >> namaCabang;

    p = searchCabang(LP, namaCabang);
    if (p == nullptr) {
        cout << "Cabang tidak ditemukan." << endl;
        return;
    }

    displayNamaBarang(LC);
    cout << "Masukkan nama barang: ";
    cin >> namaBarang;

    c = searchBarang(LC, namaBarang);
    if (c == nullptr) {
        cout << "Barang tidak ditemukan." << endl;
        return;
    }

    inputRelasi(LR, p, c);

    cout << "Barang berhasil ditambahkan ke cabang." << endl;
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

void displayCabang(ListParent LP, ListRelasi LR) {
    addressP p;
    addressR r;
    int no = 1;

    printf("\n==================== DAFTAR CABANG ====================\n");
    printf("%-5s %-25s %-20s %-20s\n",
           "No", "Nama Cabang", "Jumlah Barang", "Total Stok");
    printf("-----------------------------------------------------------------------\n");

    p = LP.first;
    while (p != nullptr) {
        int jumlahBarang = 0;
        int totalStok = 0;

        r = LR.first;
        while (r != nullptr) {
            if (r->parent == p) {
                jumlahBarang++;
                totalStok += r->jumlahStok;
            }
            r = r->next;
        }

        printf("%-5d %-25s %-20d %-20d\n",
               no,
               p->info.c_str(),
               jumlahBarang,
               totalStok);

        no++;
        p = p->next;
    }

    printf("=======================================================================\n");
    enterToContinue();
}

void displayNamaCabang(ListParent LP) {
    addressP p = LP.first;
    int no = 1;

    printf("\n=========== DAFTAR CABANG ===========\n");
    printf("%-5s %-30s\n", "No", "Nama Cabang");
    printf("------------------------------------\n");

    if (p == nullptr) {
        printf("Belum ada cabang terdaftar.\n");
    }

    while (p != nullptr) {
        printf("%-5d %-30s\n", no++, p->info.c_str());
        p = p->next;
    }

    printf("====================================\n");
}

void displayNamaBarang(ListChild LC) {
    addressC c = LC.first;

    if (c == nullptr) {
        printf("Belum ada barang.\n");
        return;
    }

    printf("================================\n");
    printf("      DAFTAR NAMA BARANG\n");
    printf("================================\n");

    int no = 1;
    while (c != nullptr) {
        printf("%d. %s\n", no, c->info.namaBarang.c_str());
        c = c->next;
        no++;
    }

    printf("================================\n");
}

void hapusCabang(ListParent &LP, ListRelasi &LR) {
    displayNamaCabang(LP);
    string namaCabang;
    cout << "Masukkan nama cabang yang akan dihapus: ";
    cin >> namaCabang;
    addressP p = LP.first;
    addressP prec = nullptr;
    addressR r, prevR;

    // cari cabang
    while (p != nullptr && p->info != namaCabang) {
        prec = p;
        p = p->next;
    }

    if (p == nullptr) {
        cout << "Cabang tidak ditemukan." << endl;
    } else {

        // ===== hapus semua relasi milik cabang =====
        r = LR.first;
        prevR = nullptr;

        while (r != nullptr) {
            if (r->parent == p) {

                if (prevR == nullptr) {
                    LR.first = r->next;
                    r = LR.first;
                } else {
                    prevR->next = r->next;
                }
            } else {
                prevR = r;
                r = r->next;
            }
        }

        if (prec == nullptr) {
            LP.first = p->next;
        } else {
            prec->next = p->next;
        }

        cout << "Cabang berhasil dihapus." << endl;
    }
}

void updateStokBarang(ListRelasi &LR){
    string namaCabang, namaBarang;
    int stokBaru;
    addressR r;

    cout << "Masukkan nama cabang: ";
    cin >> namaCabang;

    cout << "Masukkan nama barang: ";
    cin >> namaBarang;

    r = searchRelasi(LR, namaCabang, namaBarang);
    if (r == nullptr) {
        cout << "Data barang di cabang tidak ditemukan." << endl;
        return;
    }

    cout << "Stok lama: " << r->jumlahStok << endl;
    cout << "Masukkan stok baru: ";
    cin >> stokBaru;

    r->jumlahStok = stokBaru;

    if (stokBaru > 0) {
        r->child->statusKetersediaan = true;
    } else {
        r->child->statusKetersediaan = false;
    }

    cout << "Stok berhasil diperbarui." << endl;
}

void hapusBarang(ListChild &LC, ListRelasi &LR){
    string namaBarang;
    addressC c = LC.first;
    addressC precC = nullptr;

    displayNamaBarang(LC);
    cout << "Masukkan nama barang yang akan dihapus: ";
    cin >> namaBarang;

    while (c != nullptr && c->info.namaBarang != namaBarang) {
        precC = c;
        c = c->next;
    }

    if (c == nullptr) {
        cout << "Barang tidak ditemukan." << endl;
        enterToContinue();
        return;
    }

    addressR r = LR.first;
    addressR prevR = nullptr;

    while (r != nullptr) {
        if (r->child == c) {

            if (prevR == nullptr) {
                deleteFirstRelasi(LR, r);
                r = LR.first;
            }
            else if (r->next == nullptr) {
                deleteLastRelasi(LR, r);
                r = nullptr;
            }
            else {
                prevR->next = r->next;
            }

        } else {
            prevR = r;
            r = r->next;
        }
    }

    if (precC == nullptr) {
        deleteFirstChild(LC, c);
    } else if (c->next == nullptr) {
        deleteLastChild(LC, c);
    } else {
        deleteAfterChild(LC, c, precC);
    }

    cout << "Barang  berhasil dihapus." << endl;
}