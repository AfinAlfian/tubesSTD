#include "tubes.h"

int main() {
    
    ListParent LP; 
    ListChild LC; 
    ListRelasi LR;
    createList(LP, LC, LR);
    addressP p;
    addressC c;
    addressR r;
    string namaCabang;
    int menu = -1;
    int sub = -1;

    while (menu != 0) {
        clearScreen();
        header();
        mainMenu();
        cin >> menu;

        if (menu == 1) {
            sub = -1;
            while (sub != 0) {
                clearScreen();
                header();
                menuCabang();
                cin >> sub;

                if (sub == 1) {
                    inputCabang(LP, p);
                    enterToContinue();
                }else if (sub == 2) {
                    hapusCabang(LP, LR);
                    enterToContinue();
                }else if (sub == 3) {
                    displayNamaCabang(LP);
                    enterToContinue();
                }
            }
        }

        else if (menu == 2) {
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
                    updateStokBarang(LR, LP, LC);
                    enterToContinue();
                }
            }
        }

        else if (menu == 4) {
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
                    displayNamaCabang(LP);
                    cout << "Masukkan nama cabang: ";
                    cin >> namaCabang;

                    tampilkanBarangDiCabang(LP, LR, namaCabang);
                    enterToContinue();
                }
                else if (sub == 3) {
                    hitungJumlahBarangPerItem(LC, LR);
                    enterToContinue();
                }
                else if (sub == 4) {
                    statistikBarang(LC, LR);
                    enterToContinue();
                }
            }
        }
        else if (menu == 5) {
            clearScreen();
            header();
            tampilkanSemua(LP, LR);
            enterToContinue();
        }
    }
}