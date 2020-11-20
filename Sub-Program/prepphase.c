#include "prepphase.h"


void Build (Stack Perintah, Wahana ArrayWahana[100], POINT Posisi_Player, int Duit);
// Program 

void Upgrade (Stack Perintah, Wahana ArrayWahana[100], POINT Posisi_Player, int Duit){

}

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
        Element X;
        X.perintah = "Y";
        X.Point = MakePOINT(0, 0);
        X.Target = CKata;
        X.Biaya = jumlah*Harga(ArrayMat[found]);
        if (found == 0){
            X.Wood = jumlah;
        }
        else if (found == 1){
            X.Fire = jumlah;
        }
        else if (found == 3){
            X.Primogem = jumlah;
        }
        Push(&Perintah, X);
    }
    else{
        printf("Uang kamu ga cukup.");
    }
}

void Undo (Stack Perintah, int Duit){
    Element X;
    Pop(&Perintah, &X);
    Duit += X.Biaya;
}

void Execute (Stack Perintah, Wahana Wahanaskrg[100], int Wood, int Fire, int Primogem){
    Element X;
    while (!IsEmpty(Perintah)){
        Pop(&Perintah, &X);
        if (X.perintah == 'B'){

        }
        else if (X.perintah == 'U'){

        }
        else if (X.perintah == 'Y'){
            Wood += X.Wood;
            Fire += X.Fire;
            Primogem += X.Primogem;
        }
    }
}