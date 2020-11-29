#include "prepphase.h"
#include "../ADT/tipebentukan.h"
#include <stdio.h>

long durasi = 0;
long countaksi = 0;
long totalbiaya = 0;
long Sisa = 720;

void Build(Stack *Perintah, Wahana ArrayWahana[10], POINT Posisi_Player, int idxpeta, int *Duit, int *Wood, int *Fire, int *Primogem)
{
    Kata empty;
    boolean nimpa;
    int RectAR,RectAL,RectAT,RectAB,RectBR,RectBL,RectBT,RectBB;
    MakeKataEmpty(&empty);
    printf("Mau bikin wahana apa?\n");
    PrintListWahana(ArrayWahana);
    STARTKATA(stdin);
    Wahana New = SearchWahana(ArrayWahana, CKata);
    nimpa=false;
    // batas kanan atas dan kiri bawah
    RectAR=Ordinat(Posisi_Player)+PanjangWahana(New)-1;
    RectAL=Ordinat(Posisi_Player);
    RectAT=Absis(Posisi_Player);
    RectAB=Absis(Posisi_Player)+LebarWahana(New)-1;
    if (!IsKataSama(New.Nama, empty))
    {
        int i = 0;
        Wahana Curr;
        while (!isWahanaEmpty(ArrayWahana[i]))
        {
           Curr = ArrayWahana[i];
           if (IsKataSama(Nama(Curr), Nama(New)) && (IndexPeta(Curr))==idxpeta)
           {
              RectBR=Ordinat(Point(Curr))+PanjangWahana(Curr)-1;
              RectBL=Ordinat(Point(Curr));
              RectBT=Absis(Point(Curr));
              RectBB=Absis(Point(Curr))+LebarWahana(Curr)-1;
              if (Intersection(RectAL, RectAR, RectAT, RectAB, RectBL, RectBR, RectBT, RectBB)) {
                nimpa=true;
                break;
              }
           }
           i++;
        }

        if (nimpa||RectAL<1 || RectAT<1 || RectAR>10|| RectAB>10) {
          printf("Bangunan yang akan buat menimpa salah satu objek.\n");
        }
        else if (*Duit >= New.HargaBuild && *Wood >= New.Mat[0] && *Fire >= New.Mat[1] && *Primogem >= New.Mat[2])
        {
            *Duit -= New.HargaBuild;
            *Wood -= New.Mat[0];
            *Fire -= New.Mat[1];
            *Primogem -= New.Mat[2];
            Element X;
            X.perintah = 'B';
            X.Point = Posisi_Player;
            X.Target = CKata;
            X.Biaya = New.HargaBuild;
            X.Durasi = New.DurasiBuild;
            X.Wood = New.Mat[0];
            X.Fire = New.Mat[1];
            X.Primogem = New.Mat[2];
            durasi += New.DurasiBuild;
            countaksi++;
            totalbiaya += X.Biaya;
            Push(Perintah, X);
        }
        else
        {
            printf("Uang atau material kamu ga cukup.\n");
        }
    }
    else
    {
        printf("Wahana tidak ditemukan\n");
    }
}

void Upgrade(Stack *Perintah, Wahana ArrayWahana[100], Wahana DaftarUpgrade[10], POINT Player, int *Duit, int *Wood, int *Fire, int *Primogem)
{
    Wahana New = SearchWahanaFromPoint(ArrayWahana, Player);
    Kata empty;
    MakeKataEmpty(&empty);
    if (!IsKataSama(New.Nama, empty))
    {
        printf("Ingin upgrade apa?\n");
        printf("List:\n");
        PrintListWahana(DaftarUpgrade);
        STARTKATA(stdin);
        Wahana Up = SearchWahana(DaftarUpgrade, CKata);
        if (*Duit >= Up.HargaBuild && *Wood >= New.Mat[0] && *Fire >= New.Mat[1] && *Primogem >= New.Mat[2])
        {
            *Duit -= Up.HargaBuild;
            *Wood -= New.Mat[0];
            *Fire -= New.Mat[1];
            *Primogem -= New.Mat[2];
            Element X;
            X.perintah = 'U';
            X.Point = Player;
            X.Target = CKata;
            X.Biaya = Up.HargaBuild;
            X.Durasi = Up.DurasiBuild;
            X.Wood = New.Mat[0];
            X.Fire = New.Mat[1];
            X.Primogem = New.Mat[2];
            durasi += Up.DurasiBuild;
            countaksi++;
            totalbiaya += X.Biaya;
            Push(Perintah, X);
        }
        else
        {
            printf("Uang kamu ga cukup.\n");
        }
    }
    else
    {
        printf("tidak ada wahana di sektiar kamu\n");
    }
}

void Buy(Stack *Perintah, Material ArrayMat[3], int *Duit)
{
    printf("Ingin membeli apa?\n");
    printf("List:\n");
    int i;
    for (i = 0; i < 3; i++)
    {
        printf("  -  ");
        PrintKata(ArrayMat[i].Nama);
        printf("\n");
    }
    int found, jumlah = 0;
    while (jumlah == 0)
    {
        STARTKATA(stdin);
        for (i = 0; i < 3; i++)
        {
            if (IsKataSama(CKata, ArrayMat[i].Nama))
            {
                found = i;
                printf("Masukkan jumlahnya:\n");
                STARTTOKEN(stdin);
                jumlah = CToken;
            }
        }
        if (jumlah == 0)
        {
            printf("Barang yang dimasukkan tidak sesuai!\n");
        }
    }

    if (*Duit >= jumlah * Harga(ArrayMat[found]))
    {
        *Duit -= jumlah * Harga(ArrayMat[found]);
        Element X;
        X.perintah = 'Y';
        X.Point = MakePOINT(0, 0);
        X.Target = CopyKata(CKata);
        X.Biaya = jumlah * Harga(ArrayMat[found]);
        X.Durasi = 0;
        if (found == 0)
        {
            X.Wood = jumlah;
            X.Fire = 0;
            X.Primogem = 0;
        }
        else if (found == 1)
        {
            X.Wood = 0;
            X.Fire = jumlah;
            X.Primogem = 0;
        }
        else if (found == 2)
        {
            X.Wood = 0;
            X.Fire = 0;
            X.Primogem = jumlah;
        }
        countaksi++;
        totalbiaya += X.Biaya;
        Push(Perintah, X);
    }
    else
    {
        printf("Uang kamu ga cukup.\n");
    }
}

void Undo(Stack *Perintah, int *Duit, int *Wood, int *Fire, int *Primogem)
{
    Element X;
    Pop(Perintah, &X);
    *Duit += X.Biaya;
    durasi += X.Durasi;
    countaksi--;
    totalbiaya -= X.Biaya;
    if (X.perintah == 'B' || X.perintah == 'U')
    {
        *Wood += X.Wood;
        *Fire += X.Fire;
        *Primogem += X.Primogem;
    }
}

void Execute(Stack *Perintah, Wahana Wahanaskrg[100], TabLaporan *TL, Wahana DaftarWahana[10], Wahana DaftarUpgrade[10], int *Wood, int *Fire, int *Primogem, boolean *isMain, MATRIKS *Peta, POINT *Posisi)
{
    Element X;
    int i,j;
    Wahana New, Up;
    if (durasi <= Sisa)
    {
        while (!IsEmptyStack(*Perintah))
        {
            Pop(Perintah, &X);
            // build
            if (X.perintah == 'B')
            {
                New = SearchWahana(DaftarWahana, X.Target);
                AddWahana(Wahanaskrg, New);
                // AddLaporan(TL, New);
                // PrintKata(Wahanaskrg->Nama);
                for (i=Absis(X.Point);i<=Absis(X.Point)+LebarWahana(New)-1;i++) {
                  for(j=Ordinat(X.Point);j<=Ordinat(X.Point)+PanjangWahana(New)-1;j++) {
                    Elmt(*Peta, i, j) = 'W';
                  }
                }
                Absis(*Posisi)=i;
                Ordinat(*Posisi)=j;


            }
            // update
            else if (X.perintah == 'U')
            {
                New = SearchWahanaFromPoint(Wahanaskrg, X.Point);
                Up = SearchWahana(DaftarUpgrade, X.Target);
                New.Harga += Up.Harga;
                New.Kapasitas += Up.Kapasitas;
            }
            // buy
            else if (X.perintah == 'Y')
            {
                *Wood += X.Wood;
                *Fire += X.Fire;
                *Primogem += X.Primogem;
            }
        }
        Elmt(*Peta, Absis(*Posisi), Ordinat(*Posisi)) = 'P';
        int i = 0;
        while (!isWahanaEmpty(Wahanaskrg[i]))
        {
            int r = rand() % 5;
            if (r == 0)
            {
                Wahanaskrg[i].Rusak = true;
            }
            i++;
        }
        countaksi = 0;
        totalbiaya = 0;
        durasi = 0;
        *isMain = true;
    }
    else
    {
        printf("durasi ga cukup, silahkan undo beberapa aksi.");
    }
}

void Mainphase(Stack *Perintah, boolean *isMain, Wahana ArrayWahana[10], int *Duit)
{
    Element X;
    while (!IsEmptyStack(*Perintah))
    {
        Pop(Perintah, &X);
        *Duit += X.Biaya;
    }
    countaksi = 0;
    totalbiaya = 0;
    durasi = 0;
    *isMain = true;
}
