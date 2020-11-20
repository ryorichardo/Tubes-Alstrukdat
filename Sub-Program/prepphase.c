#include "prepphase.h"


void Build (Stack Perintah, Wahana ArrayWahana[100], POINT Posisi_Player, int Duit);
// Program 

void Upgrade (Stack Perintah, Wahana ArrayWahana[100], POINT Posisi_Player, int Duit);

void Buy (Stack Perintah, Material ArrayMat[3], int Duit){
    printf("Ingin membeli apa?\n");
    printf("List:\n");
    int i;
    for (i = 0; i < 3; i++){
        printf("  -  ");
        PrintKata(Nama(ArrayMat[i]));
        printf("\n");
    }
    int found, jumlah = 0;
    while (jumlah == 0){
        SalinKata();
        for (i = 0; i < 3; i++){
            if (IsKataSama(CKata, Nama(ArrayMat[i]))){
                found = i;
                printf("Masukkan jumlahnya:\n");
                scanf("%d", &jumlah);
            }
        }
        if (jumlah == 0){
            printf("Barang yang dimasukkan tidak sesuai!\n");
        }
    }

    if (Duit > jumlah*Harga(ArrayMat[found])){
        Duit -= jumlah*Harga(ArrayMat[found]);
        Push(&S, )
    }

}