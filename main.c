#include "ADT/tipebentukan.h"
#include "ADT/mesinkata.c"
#include "ADT/mesintoken.c"
#include "ADT/mesinkar.c"
#include <stdio.h>
#include <stdlib.h>

int main(){
    Wahana P;
    FILE *f;
    f = fopen("Wahana.txt", "w");
    while (!EndKata){
        ADVKATA();
        Nama(P) = CKata;
    }
    while (!EndToken){
        ADVTOKEN();
        Harga(P) = CToken;
    }
    while (!EndToken){
        ADVTOKEN();
        Kapasitas(P) = CToken;
    }
    while (!EndToken){
        ADVTOKEN();
        Durasi(P) = CToken;
    }

    while (!EndToken){
        ADVTOKEN();
        HargaBuild(P) = CToken;
    }
    while (!EndToken){
        ADVTOKEN();
        DurasiBuild(P) = CToken;
    }
    while (!EndToken){
        ADVTOKEN();
        Wood(P) = CToken;
    }
    while (!EndToken){
        ADVTOKEN();
        Fire(P) = CToken;
    }
    while (!EndToken){
        ADVTOKEN();
        Primogem(P) = CToken;
    }
    while (!EndKata){
        ADVKATA();
        Deskripsi(P) = CKata;
    }
    return 0;
}