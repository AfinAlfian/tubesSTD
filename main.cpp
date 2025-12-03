#include "tubes.h"

int main() {
    
    ListParent LP; 
    ListChild LC; 
    ListRelasi LR;
    createList(LP, LC, LR);
    addressP p;
    addressC c;
    addressR r;
    int n;

    while (true)
    {
        clearScreen();
        header();
        menu(n);
        switch (n)
        {
        case 1:
            clearScreen();
            header();
            inputCabang(LP, p);
            enterToContinue();
            footer();
            break;
        case 2:
            clearScreen();
            header();
            inputBarang(LC, c);
            enterToContinue();
            footer();
            break;
        case 3:
            clearScreen();
            header();
            tambahBarang(LP, LC, LR);
            enterToContinue();
            footer();
            break;
        case 4:
            clearScreen();
            header();
            //hapus cabang
            footer();
            break;
        case 5:
            clearScreen();
            header();
            //hapus barang
            footer();
            break;
        case 6:
            clearScreen();
            header();
            //cari cabang
            footer();
            break;
        case 7:           
            clearScreen();
            header();
            //cari barang
            footer();
            break;
        case 8:
            clearScreen();
            header();
            //tampilkan barang di cabang tertentu
            footer();
            break;
        case 9:
            clearScreen();
            header();
            displayInfo(LP, LC, LR);
            footer();
            break;
        case 10:
            clearScreen();
            header();
            //hitung jumlah barang tersedia
            footer();
            break;
        case 11:
            clearScreen();
            header();
            //statistik cabang
            footer();
            break;
        case 12:
            clearScreen();
            header();
            cout << "Keluar dari program." << endl;
            return 0;
        default:
            cout << "Pilihan tidak valid!" << endl;
            enterToContinue();
            break;
        }
        footer();
    }
    


    /*
    for (int i = 0; i < 3; i++) {
        tambahCabang(parent, child, relasi);
    }
    displayInfo(parent, child, relasi);
    */
    return 0;
}