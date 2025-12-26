#include "parent.h"

addressP alokasiParent(string info){
    //I.S. info terdefinisi
    //F.S. Menghasilkan sebuah addressP baru yang berisi info dan next bernilai nullptr
    addressP P = new elmParent;
    P->info = info;
    P->next = nullptr;
    return P;
}

bool isEmptyParent(ListParent LP) {
    //I.S. LP terdefinisi
    //F.S. Mengembalikan true jika LP kosong, false jika tidak
    return LP.first == nullptr;
}

void insertFirstParent(ListParent &LP, addressP p) {
    //I.S. LP terdefinisi, p terdefinisi
    //F.S. p menjadi elemen pertama pada LP
    if (LP.first == nullptr) {
        LP.first = p;
    } else {
        p->next = LP.first;
        LP.first = p;
    }
}

void inputCabang(ListParent &LP, addressP &p){
    //I.S. LP terdefinisi
    //F.S. Menambahkan cabang baru ke dalam LP dengan insertFirstParent
    string namaCabang;
    addressP find;
    cout << "Masukkan nama cabang: ('-' untuk berhenti) :";
    cin >> namaCabang;
    while (namaCabang != "-"){
        find = searchCabang(LP, namaCabang);
        if (find == nullptr){
            p = alokasiParent(namaCabang);
            insertFirstParent(LP, p);
            cout << "Cabang berhasil ditambahkan." << endl;
        }else{
            cout << "Cabang sudah ada." << endl;
        }
        cout << "Masukkan nama cabang: ('-' untuk berhenti) :";
        cin >> namaCabang;
    }
}

addressP searchCabang(ListParent LP, string x){
    //I.S. LP terdefinisi, x terdefinisi
    //F.S. Mengembalikan addressP dari cabang dengan nama x, atau nullptr jika tidak ditemukan
    addressP p, find;
    p = LP.first;
    find = nullptr;
    while (p != nullptr){
        if (p->info == x){
            find = p;           
        }
        p = p->next;
    }
    return find;
}

void deleteFirstParent(ListParent &LP, addressP &p){
    //I.S. LP terdefinisi
    //F.S. Menghapus elemen pertama dari LP dan mengembalikan addressP
    if (LP.first == nullptr){
        p = nullptr;
    }else if (LP.first->next == nullptr){
        p = LP.first;
        LP.first = nullptr;
    }else{
        p = LP.first;
        LP.first = LP.first->next;
        p->next = nullptr;
    }
}

void deleteAfterParent(ListParent &LP, addressP &p, addressP prec){
    //I.S. LP terdefinisi, prec terdefinisi
    //F.S. Menghapus elemen setelah prec dari LP dan mengembalikan address
    if (isEmptyParent(LP)){
        p = nullptr;
    }else if (prec->next == nullptr){
        p = nullptr;
    }else{
        p = prec->next;
        prec->next = p->next;
        p->next = nullptr;
    }
}

void deleteLastParent(ListParent &LP, addressP &p){
    //I.S. LP terdefinisi
    //F.S. Menghapus elemen terakhir dari LP dan mengembalikan addressP
    addressP prev = LP.first;
    if (LP.first == nullptr){
        p = nullptr;
    }else if (LP.first->next == nullptr){
        p = LP.first;
        LP.first = nullptr;
    }else{
        while (prev->next->next != nullptr){
            prev = prev->next;
        }
        p = prev->next;
        prev->next = nullptr;
    }
}

