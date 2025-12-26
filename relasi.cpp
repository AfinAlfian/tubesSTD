#include "relasi.h"

addressR alokasiRelasi(addressP parent, addressC child, int jumlahStok){
    //I.S. parent, child, jumlahStok terdefinisi
    //F.S. Menghasilkan sebuah addressR baru yang berisi parent, child, jumlahStok dan next bernilai nullptr
    addressR R = new elmRelasi;
    R->parent = parent;
    R->child = child;
    R->jumlahStok = jumlahStok;
    R->next = nullptr;
    return R;
}

bool isEmptyRelasi(ListRelasi LR) {
    //I.S. LR terdefinisi
    //F.S. Mengembalikan true jika LR kosong, false jika tidak
    return LR.first == nullptr;
}

void insertFirstRelasi(ListRelasi &LR, addressR R) {
    //I.S. LR terdefinisi, R terdefinisi
    //F.S. R menjadi elemen pertama pada LR
    if (LR.first == nullptr) {
        LR.first = R;
    } else {
        R->next = LR.first;
        LR.first = R;
    }
}

void insertLastRelasi(ListRelasi &LR, addressR r){
    //I.S. LR terdefinisi, r terdefinisi
    //F.S. r menjadi elemen terakhir pada LR
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
    //I.S. LR, p, c terdefinisi
    //F.S. Menambahkan relasi baru ke dalam LR dengan insertLastRelasi
    int n;
    cout << "Masukkan jumlah stok barang: ";
    cin >> n;
    addressR r = alokasiRelasi(p, c, n);   
    r->jumlahStok = n;
    insertLastRelasi(LR, r);
}

void deleteFirstRelasi(ListRelasi &LR, addressR &r){
    //I.S. LR terdefinisi
    //F.S. Menghapus elemen pertama dari LR dan mengembalikan addressR
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
    //I.S. LR terdefinisi, prec terdefinisi
    //F.S. Menghapus elemen setelah prec dari LR dan mengembalikan addressR
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
    //I.S. LR terdefinisi
    //F.S. Menghapus elemen terakhir dari LR dan mengembalikan addressR
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
    //I.S. LR terdefinisi, namaCabang, namaBarang terdefinisi
    //F.S. Mengembalikan addressR dari relasi dengan namaCabang dan namaBarang, atau nullptr jika tidak ditemukan
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
