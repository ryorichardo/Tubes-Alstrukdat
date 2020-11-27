#include "ADT/tipebentukan.h"
#include "ADT/mesinkata.c"
#include "ADT/mesintoken.c"
#include "ADT/mesinkar.c"
#include "Sub-Program/mainphase.h"
#include "Sub-Program/prepphase.h"
#include "Sub-Program/PetaWahana.c"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    //deklarasi variabel global
    Wahana ListWahana[10];
    Wahana ListUpgrade[10];
    Wahana ListOwnedWahana[100];
    Material ListMat[3];
    int Wood = 0, Fire = 0, Primogem = 0, Money = 0, idxmap = 0, day = 1;
    POINT Posisi = MakePOINT(1, 1);
    JAM CurrentTime = MakeJAM(21, 0);
    JAM Open = MakeJAM(9, 0);
    JAM Close = MakeJAM(21, 0);
    MATRIKS CurrentMap;
    MATRIKS ListMap[4];
    Graph RelationMap[4];
    boolean isMain = false;

    //baca file wahana, material, map
    MakeMap(RelationMap, ListMap);
    CurrentMap = ListMap[0];
    char filename5[] = "Wahana.txt";
    BacaFileWahana(filename5, &ListWahana[10], &ListUpgrade[10]);
    char filename6[] = "Material.txt";
    BacaFileMaterial(filename6, &ListMat[3]);

    //bikin konstan exit
    Kata Exit;
    Exit.TabKata[0] = 'e';
    Exit.TabKata[1] = 'x';
    Exit.TabKata[2] = 'i';
    Exit.TabKata[3] = 't';
    Exit.Length = 4;

    //print halaman utama
    Kata Player;
    printf("Welcome to Willy Wangky's PLayground\n");
    printf("Type 'new' to start a new game");
    STARTKATA(stdin);
    if (!IsKataSama(CKata, Exit))
    {
        printf("Masukkan nama: ");
        STARTKATA(stdin);
        Player = CopyKata(CKata);
    }
    while (!IsKataSama(CKata, Exit))
    {
        if (isMain)
        {
            printf("Main phase day ");
        }
        else
        {
            printf("Preparation phase day ");
        }
        printf("%d/n", day);

        TulisMATRIKS(CurrentMap);
        printf("Legend:\n");
        printf("A = Antrian\n");
        printf("P = Player\n");
        printf("W = Wahana\n");
        printf("O = Office\n");
        printf("<, ^, >, v = Gerbang\n");
        printf("\nName: ");
        PrintKata(Player);
        printf("\nCurrent time: ");
        TulisJAM(CurrentTime);
        printf("\n");
        if (isMain){
            printf("Closing time: ");
            TulisJAM(Close);
            printf("\nTime remaining: ");
            TulisJAM(MenitToJAM(SelisihJam(CurrentTime, Close)));
            printf("Antrian: ")
        }
        else{
            printf("Opening time: ");
            TulisJAM(Open);
            printf("\nTime remaining: ");
            TulisJAM(MenitToJAM(SelisihJam(CurrentTime, Open)));
            printf("\nTotal aksi yang akan dilakukan: %d", countaksi);
            printf("\nTotal waktu yang dibutuhkan: ");
            TulisJAM(MenitToJAM(durasi));
            printf("\nTotal uang yang dibutuhkan: %d\n", totalbiaya);
        }

        // Next Perintah
        printf("Masukkan Perintah\n");
        STARTKATA(stdin);

    }

    // ketika telah menginput
    printf("Thanks For Playing\n");
}