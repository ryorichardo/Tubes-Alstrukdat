#include <stdio.h>
#include <stdlib.h>
#include "mesinkata.h"
#include "../tipebentukan.h"

Kata CKata;
FILE *input;
Wahana ListWahana[10];
Wahana ListUpgrade[10];
Material ListMat[3];

int main(){
    printf("Ketik kalimat : \n");
    STARTKATA(stdin);
    PrintKata(CKata);
    ADV();
    while (CC != ','){
        SalinKata();
        printf(", ");PrintKata(CKata);
        ADV();
    }
    printf("\n");
    printf("Hasil copy kata terakhir : ");
    PrintKata(CopyKata(CKata)); printf("\n");

    printf("Apakah hasil copy kata terakhir sama dengan kata terakhir? \n");
    if (IsKataSama(CKata, CopyKata(CKata))){
        printf("Ya, sama\n");
    }
    else {
        printf("Beda");
    }
}