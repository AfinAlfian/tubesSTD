#include "relasi.h"

addressR alokasiRelasi(addressP parent, addressC child, int jumlahStok){
    addressR R = new elmRelasi;
    R->parent = parent;
    R->child = child;
    R->jumlahStok = jumlahStok;
    R->next = nullptr;
    return R;
}

void insertFirstRelasi(ListRelasi &LR, addressR R) {
    if (LR.first == nullptr) {
        LR.first = R;
    } else {
        R->next = LR.first;
        LR.first = R;
    }
}

void inputRelasi(ListRelasi &LR, addressP p, addressC c){
    int n;
    cout << "Masukkan jumlah stok barang: ";
    cin >> n;
    addressR r = alokasiRelasi(p, c, n);   
    r->jumlahStok = n;
    insertFirstRelasi(LR, r);
}
