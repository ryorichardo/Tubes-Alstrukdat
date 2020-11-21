#include "prepphase.h"
#include <stdio.h>

long durasi = 0;
long Sisa = 720;

void Build (Stack Perintah, TabWahana ArrayWahana, POINT Posisi_Player, int Duit){
    printf("Mau bikin wahana apa?");
    PrintListWahana(ArrayWahana);
    STARTKATA(stdin);
    Wahana New = SearchWahana(ArrayWahana, CKata);
    if (Duit >= New.HargaBuild){
        Duit -= New.HargaBuild;
        Element X;
        X.perintah = 'B';
        X.Point = Posisi_Player;
        X.Target = CKata;
        X.Biaya = New.HargaBuild;
        X.Durasi = New.DurasiBuild;
        Push(&Perintah, X);
        durasi += New.DurasiBuild;
    }
    else{
        printf("uang kamu ga cukup.");
    }
}

void Upgrade (Stack Perintah, Wahana ArrayWahana[100], TabUpgrade DaftarUpgrade, POINT Player, int Duit){
    Wahana New = SearchPoint(ArrayWahana, Player);
    printf("Ingin upgrade apa?\n");
    printf("List:\n");
    PrintListWahana(DaftarUpgrade);
    STARTKATA(stdin);
    Wahana Up = SearchWahana(DaftarUpgrade, CKata);
    if (Duit >= Up.HargaBuild){
        Duit -= Up.HargaBuild;
        Element X;
        X.perintah = 'U';
        X.Point = Player;
        X.Target = CKata;
        X.Biaya = Up.HargaBuild;
        X.Durasi = Up.DurasiBuild;
        durasi += Up.DurasiBuild;
        Push(&Perintah, X);
    }
}

void Buy (Stack Perintah, Material ArrayMat[3], int Duit){
    printf("Ingin membeli apa?\n");
    printf("List:\n");
    int i;
    for (i = 0; i < 3; i++){
        printf("  -  ");
        PrintKata(ArrayMat[i].Nama);
        printf("\n");
    }
    int found, jumlah = 0;
    while (jumlah == 0){
        STARTKATA(stdin);
        for (i = 0; i < 3; i++){
            if (IsKataSama(CKata, ArrayMat[i].Nama)){
                found = i;
                printf("Masukkan jumlahnya:\n");
                scanf("%d", &jumlah);
            }
        }
        if (jumlah == 0){
            printf("Barang yang dimasukkan tidak sesuai!\n");
        }
    }

    if (Duit >= jumlah*Harga(ArrayMat[found])){
        Duit -= jumlah*Harga(ArrayMat[found]);
        Element X;
        X.perintah = 'Y';
        X.Point = MakePOINT(0, 0);
        X.Target = CKata;
        X.Biaya = jumlah*Harga(ArrayMat[found]);
        X.Durasi = 0;
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
    durasi += X.Durasi;
}

void Execute (Stack Perintah, Wahana Wahanaskrg[100], TabWahana DaftarWahana, TabUpgrade DaftarUpgrade, int Wood, int Fire, int Primogem, boolean isMain){
    Element X;
    Wahana New, Up;
    if (durasi <= Sisa){
        while (!IsEmpty(Perintah)){
            Pop(&Perintah, &X);
            if (X.perintah == 'B'){
                New = SearchWahana(DaftarWahana, X.Target);
                AddWahana(&Wahanaskrg, New);
            }
            else if (X.perintah == 'U'){
                New = SearchPoint(DaftarWahana, X.Point);
                Up = SearchWahana(DaftarUpgrade, X.Target);
                New.Harga += Up.Harga;
                New.Kapasitas += Up.Kapasitas;
            }
            else if (X.perintah == 'Y'){
                Wood += X.Wood;
                Fire += X.Fire;
                Primogem += X.Primogem;
            }
        }
        isMain = true;
    }
    else{
        printf("durasi ga cukup, silahkan undo beberapa aksi.");
    }
}

void Main(Stack Perintah, boolean isMain){
    Element X;
    while (!IsEmpty(Perintah)){
        Pop(&Perintah, &X);
    }
    isMain = true;
}