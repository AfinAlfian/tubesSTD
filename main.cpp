#include "tubes.h"

int main() {
    
    ListParent LP; 
    ListChild LC; 
    ListRelasi LR;
    createList(LP, LC, LR);
    addressP p;
    addressC c;
    addressR r;
    
    int menu = -1;
    int sub = -1;

    while (menu != 0) {
        clearScreen();
        header();
        mainMenu();
        cin >> menu;

        if (menu == 1) {  // ===== MENU CABANG =====
            sub = -1;
            while (sub != 0) {
                clearScreen();
                header();
                menuCabang();
                cin >> sub;

                if (sub == 1) {
                    inputCabang(LP, p);
                }else if (sub == 2) {
                    hapusCabang(LP, LR);
                    enterToContinue();
                }else if (sub == 3) {
                    displayNamaCabang(LP);
                    enterToContinue();
                }
            }
        }

        else if (menu == 2) { // ===== MENU BARANG =====
            sub = -1;
            while (sub != 0) {
                clearScreen();
                header();
                menuBarang();
                cin >> sub;

                if (sub == 1) {
                    inputBarang(LC, c);
                    enterToContinue();
                }
                else if (sub == 2) {
                    hapusBarang(LC, LR);
                    enterToContinue();
                }
                else if (sub == 3) {
                    displayNamaBarang(LC);
                    enterToContinue();
                }
            }
        }

        else if (menu == 3) {
            sub = -1;
            while (sub != 0) {
                clearScreen();
                header();
                menuInventori();
                cin >> sub;

                if (sub == 1) {
                    tambahBarang(LP, LC, LR);
                    enterToContinue();
                }
                else if (sub == 2) {
                    hapusBarang(LC, LR);
                    enterToContinue();
                }
                else if (sub == 3) {
                    updateStokBarang(LR);
                    enterToContinue();
                }
            }
        }

        else if (menu == 4) { // ===== MENU LAPORAN =====
            sub = -1;
            while (sub != 0) {
                clearScreen();
                header();
                menuLaporan();
                cin >> sub;

                if (sub == 1) {
                    displayCabang(LP, LR);
                    enterToContinue();
                }
                else if (sub == 2) {
                    // hitungJumlah
                    enterToContinue();
                }
                else if (sub == 3) {
                    // statistik
                    enterToContinue();
                }
            }
        }
    }
}