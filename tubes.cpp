#include "tubes.h"

void header(){
    //I.S. -
    //F.S. Menampilkan header program
    cout << "+============================================+" << endl;
    cout << "|        SISTEM INVENTORI CABANG TOKO        |" << endl;
    cout << "|     Multi Linked List (Parent - Child)     |" << endl;
    cout << "|                                            |" << endl;
    cout << "|  Afin    - 103012400220                    |" << endl;
    cout << "|  Sandres - 103012400100                    |" << endl;
    cout << "+============================================+" << endl << endl;
}

void mainMenu(){
    //I.S. -
    //F.S. Menampilkan menu utama
    cout << "+============================================+" << endl;
    cout << "|                  MENU UTAMA                |" << endl;
    cout << "+============================================+" << endl;
    cout << "| 1. Kelola Cabang                           |" << endl;
    cout << "| 2. Kelola Barang                           |" << endl;
    cout << "| 3. Kelola Inventori Cabang                 |" << endl;
    cout << "| 4. Laporan Inventori                       |" << endl;
    cout << "| 5. Tampilkan semua data yang ada           |" << endl;
    cout << "| 0. Keluar                                  |" << endl;
    cout << "+============================================+" << endl;
    cout << "Pilih menu: ";
}

void menuCabang(){
    //I.S. -
    //F.S. Menampilkan menu cabang
    cout << "+================================================+" << endl;
    cout << "|                MENU CABANG                     |" << endl;
    cout << "+================================================+" << endl;
    cout << "| 1. Tambah Cabang                               |" << endl;
    cout << "| 2. Hapus Cabang                                |" << endl;
    cout << "| 3. Tampilkan Semua Cabang                      |" << endl;
    cout << "| 0. Kembali                                     |" << endl;
    cout << "+================================================+" << endl;
    cout << "Pilih menu: ";
}

void menuBarang(){
    //I.S. -
    //F.S. Menampilkan menu barang
    cout << "+================================================+" << endl;
    cout << "|                MENU BARANG                     |" << endl;
    cout << "+================================================+" << endl;
    cout << "| 1. Tambah Barang                               |" << endl;
    cout << "| 2. Hapus Barang                                |" << endl;
    cout << "| 3. Tampilkan Semua Barang                      |" << endl;
    cout << "| 0. Kembali                                     |" << endl;
    cout << "+================================================+" << endl;
    cout << "Pilih menu: ";
}

void menuInventori(){
    //I.S. -
    //F.S. Menampilkan menu inventori cabang
    cout << "+================================================+" << endl;
    cout << "|           MENU INVENTORI CABANG                |" << endl;
    cout << "+================================================+" << endl;
    cout << "| 1. Tambah Barang ke Cabang                     |" << endl;
    cout << "| 2. Hapus Barang dari Cabang                    |" << endl;
    cout << "| 3. Update Stok Barang                          |" << endl;
    cout << "| 0. Kembali                                     |" << endl;
    cout << "+================================================+" << endl;
    cout << "Pilih menu: ";
}

void menuLaporan(){
    //I.S. -
    //F.S. Menampilkan menu laporan inventori
    cout << "+================================================+" << endl;
    cout << "|               MENU LAPORAN                     |" << endl;
    cout << "+================================================+" << endl;
    cout << "| 1. Tampilkan Info Inventori                    |" << endl;
    cout << "| 2. Tampilkan Barang di Cabang Tertentu         |" << endl;
    cout << "| 3. Hitung Jumlah Barang (Per Item)             |" << endl;
    cout << "| 4. Statistik Barang                            |" << endl;
    cout << "| 0. Kembali                                     |" << endl;
    cout << "+================================================+" << endl;
    cout << "Pilih menu: ";
}

void createList(ListParent &LP, ListChild &LC, ListRelasi &LR){
    //I.S. -
    //F.S. Membuat list parent, child, dan relasi menjadi kosong
    LP.first = nullptr;
    LC.first = nullptr;
    LR.first = nullptr;
}

void tambahBarang(ListParent &LP, ListChild &LC, ListRelasi &LR){
    //I.S. LP, LC, LR terdefinisi
    //F.S. Menambahkan barang ke cabang tertentu dan memperbarui status ketersediaan barang
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
    updateStatusBarang(c, LR);
    cout << "Barang berhasil ditambahkan ke cabang." << endl;
}

void clearScreen() {
    //I.S. -
    //F.S. Membersihkan layar
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void enterToContinue() {
    //I.S. -
    //F.S. Menunggu user menekan Enter untuk melanjutkan
    cout << "Press Enter to continue...";
    cin.ignore();
    cin.get();
}

void displayCabang(ListParent LP, ListRelasi LR) {
    //I.S. LP, LR terdefinisi
    //F.S. Menampilkan daftar cabang beserta jumlah barang dan total stoknya
    addressP p;
    addressR r;
    int no = 1;

    printf("\n==================== DAFTAR CABANG ====================\n");
    printf("%-5s %-25s %-20s %-20s\n", "No", "Nama Cabang", "Jumlah Barang", "Total Stok");
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

        printf("%-5d %-25s %-20d %-20d\n", no,p->info.c_str(), jumlahBarang, totalStok);
        no++;
        p = p->next;
    }

    printf("=======================================================================\n");
}

void displayNamaCabang(ListParent LP) {
    //I.S. LP terdefinisi
    //F.S. Menampilkan daftar nama cabang
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
    //I.S. LC terdefinisi
    //F.S. Menampilkan daftar nama barang
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
    //I.S. LP, LR terdefinisi
    //F.S. Menghapus cabang beserta semua relasi yang terkait dengannya
    displayNamaCabang(LP);
    string namaCabang;
    cout << "Masukkan nama cabang yang akan dihapus: ";
    cin >> namaCabang;
    addressP p = LP.first;
    addressP prec = nullptr;
    addressR r, prevR;

    while (p != nullptr && p->info != namaCabang) {
        prec = p;
        p = p->next;
    }

    if (p == nullptr) {
        cout << "Cabang tidak ditemukan." << endl;
    } else {
        r = LR.first;
        prevR = nullptr;

        while (r != nullptr) {
            if (r->parent == p) {
                if (prevR == nullptr) {
                deleteFirstRelasi(LR, r);
                r = LR.first;
            } else if (r->next == nullptr) {
                deleteLastRelasi(LR, r);
                r = nullptr;
            } else {
                deleteAfterRelasi(LR, r, prevR);
                r = prevR->next;
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

void updateStokBarang(ListRelasi &LR, ListParent LP, ListChild LC) {
    //I.S. LR, LP, LC terdefinisi
    //F.S. Memperbarui stok barang di cabang tertentu
    string namaCabang, namaBarang;
    int stokBaru;
    addressR r;
    displayNamaCabang(LP);
    cout << "Masukkan nama cabang: ";
    cin >> namaCabang;
    tampilkanBarangDiCabang(LP, LR, namaCabang);
    cout << "Masukkan nama barang: ";
    cin >> namaBarang;

    r = searchRelasi(LR, namaCabang, namaBarang);
    if (r == nullptr) {
        cout << "Data barang atau cabang tidak ditemukan." << endl;
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
    //I.S. LC, LR terdefinisi
    //F.S. Menghapus barang dari inventori beserta semua relasi yang terkait 
    string namaBarang;
    addressC c = LC.first;
    addressC precC = nullptr;

    displayNamaBarang(LC);
    cout << "Masukkan nama barang yang akan dihapus: ";
    cin >> namaBarang;

    while (c != nullptr && c->info.namaBarang != namaBarang){
        precC = c;
        c = c->next;
    }

    if (c == nullptr){
        cout << "Barang tidak ditemukan." << endl;
    } else {
        addressR r = LR.first;
        addressR prevR = nullptr;

        while (r != nullptr){
            if (r->child == c){
                if (prevR == nullptr){
                    deleteFirstRelasi(LR, r);
                    r = LR.first;
                }else if (r->next == nullptr){
                    deleteLastRelasi(LR, r);
                    r = nullptr;
                }else{
                    deleteAfterRelasi(LR, r, prevR);
                    r = prevR->next;
                }
            }
            else{
                prevR = r;
                r = r->next;
            }
        }
        if (precC == nullptr){
            deleteFirstChild(LC, c);
        }else if (c->next == nullptr){
            deleteLastChild(LC, c);
        }else{
            deleteAfterChild(LC, c, precC);
        }
        cout << "Barang berhasil dihapus." << endl;
    }
}

void hapusBarangDariCabang(ListParent &LP, ListRelasi &LR) {
    //I.S. LP, LR terdefinisi
    //F.S. Menghapus barang dari cabang tertentu
    string namaCabang, namaBarang;
    addressP p;
    addressR r, prev;

    displayNamaCabang(LP);
    cout << "Masukkan nama cabang: ";
    cin >> namaCabang;

    p = searchCabang(LP, namaCabang);

    if (p == nullptr) {
        cout << "Cabang tidak ditemukan." << endl;
    } else {
        tampilkanBarangDiCabang(LP, LR, namaCabang);

        cout << "Masukkan nama barang yang akan dihapus: ";
        cin >> namaBarang;

        r = LR.first;
        prev = nullptr;

        while (r != nullptr &&
              !(r->parent == p &&
                r->child->info.namaBarang == namaBarang)) {
            prev = r;
            r = r->next;
        }

        if (r == nullptr) {
            cout << "Barang tidak ditemukan di cabang ini." << endl;
        } else {
            if (prev == nullptr) {
                deleteFirstRelasi(LR, r);
            } else if (r->next == nullptr) {
                deleteLastRelasi(LR, r);
            } else {
                deleteAfterRelasi(LR, r, prev);
            }

            cout << "Barang berhasil dihapus dari cabang." << endl;
        }
    }
}

void tampilkanBarangDiCabang(ListParent LP, ListRelasi LR, string namaCabang) {
    //I.S. LP, LR terdefinisi, namaCabang terdefinisi
    //F.S. Menampilkan daftar barang beserta stoknya di cabang tertentu
    addressP p = searchCabang(LP, namaCabang);

    if (p == nullptr) {
        printf("Cabang tidak ditemukan.\n");
        return;
    }

    printf("\nBarang di Cabang %s\n", namaCabang.c_str());
    printf("%-5s %-20s %-10s\n", "No", "Nama Barang", "Stok");
    printf("------------------------------------\n");

    addressR r = LR.first;
    int no = 1;
    bool ada = false;

    while (r != nullptr) {
        if (r->parent == p) {
            printf("%-5d %-20s %-10d\n", no++, r->child->info.namaBarang.c_str(), r->jumlahStok);
            ada = true;
        }
        r = r->next;
    }

    if (!ada) {
        printf("Belum ada barang di cabang ini.\n");
    }
}

void hitungJumlahBarangPerItem(ListChild LC, ListRelasi LR) {
    //I.S. LC, LR terdefinisi
    //F.S. Menampilkan jumlah total stok untuk setiap barang
    addressC c = LC.first;
    addressR r;

    cout << "\n===== JUMLAH BARANG TERSEDIA (PER ITEM) =====" << endl;
    printf("%-20s %-15s\n", "Nama Barang", "Total Stok");
    cout << "--------------------------------------------" << endl;

    if (c == nullptr) {
        cout << "Belum ada data barang." << endl;
        return;
    }

    while (c != nullptr) {
        int totalStok = 0;
        r = LR.first;

        while (r != nullptr) {
            if (r->child == c) {
                totalStok += r->jumlahStok;
            }
            r = r->next;
        }
        printf("%-20s %-15d\n",c->info.namaBarang.c_str(),totalStok);
        c = c->next;
    }

    cout << "--------------------------------------------" << endl;
}

void statistikBarang(ListChild LC, ListRelasi LR) {
    //I.S. LC, LR terdefinisi
    //F.S. Menampilkan barang dengan stok terbanyak dan tersedikit
    addressC c = LC.first;
    addressR r;

    if (c == nullptr) {
        cout << "Belum ada data barang." << endl;
        return;
    }

    addressC barangMax = nullptr;
    addressC barangMin = nullptr;
    int maxStok = -1;
    int minStok = -1;

    while (c != nullptr) {
        int totalStok = 0;
        r = LR.first;

        while (r != nullptr) {
            if (r->child == c) {
                totalStok += r->jumlahStok;
            }
            r = r->next;
        }

        if (barangMax == nullptr || totalStok > maxStok) {
            barangMax = c;
            maxStok = totalStok;
        }

        if (barangMin == nullptr || totalStok < minStok) {
            barangMin = c;
            minStok = totalStok;
        }

        c = c->next;
    }

    cout << "\n===== STATISTIK BARANG =====" << endl;

    cout << "Barang stok TERBANYAK :" << endl;
    cout << "Nama Barang : " << barangMax->info.namaBarang << endl;
    cout << "Total Stok  : " << maxStok << endl << endl;

    cout << "Barang stok TERSEDIKIT :" << endl;
    cout << "Nama Barang : " << barangMin->info.namaBarang << endl;
    cout << "Total Stok  : " << minStok << endl;

    cout << "===========================" << endl;
}

void updateStatusBarang(addressC c, ListRelasi LR) {
    //I.S. c, LR terdefinisi
    //F.S. Memperbarui status ketersediaan barang berdasarkan total stoknya
    addressR r = LR.first;
    int totalStok = 0;

    while (r != nullptr) {
        if (r->child == c) {
            totalStok += r->jumlahStok;
        }
        r = r->next;
    }

    if (totalStok > 0) {
        c->statusKetersediaan = true;
    } else {
        c->statusKetersediaan = false;
    }
}

void tampilkanSemua(ListParent LP, ListRelasi LR) {
    // I.S. LP dan LR terdefinisi
    // F.S. Menampilkan seluruh cabang beserta daftar barang dan stoknya

    if (LP.first == nullptr) {
        printf("Belum ada data cabang.\n");
    } else {
        addressP p = LP.first;

        while (p != nullptr) {
            tampilkanBarangDiCabang(LP, LR, p->info);
            printf("\n");
            p = p->next;
        }
    }
}