#include "tubes.h"

int main() {
    
    ListParent parent; 
    ListChild child; 
    ListRelasi relasi;
    createList(parent, child, relasi);
    for (int i = 0; i < 3; i++) {
        inputData(parent, child, relasi);
    }
    displayInfo(parent, child, relasi);

    return 0;
}
// touched to update timestamp