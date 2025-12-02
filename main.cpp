#include "tubes.h"

int main() {
    
    ListParent parent; 
    ListChild child; 
    ListRelasi relasi;
    createList(parent, child, relasi);
    for (int i = 0; i < 5; i++) {
        tambahCabang(parent, child, relasi);
    }
    displayInfo(parent, child, relasi);

    return 0;
}