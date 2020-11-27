#include "ADT/tipebentukan.h"
#include "ADT/mesinkata.c"
#include "ADT/mesintoken.c"
#include "ADT/mesinkar.c"
#include "Sub-Program/mainphase.c"
#include "Sub-Program/prepphase.c"
#include "Sub-Program/PetaWahana.c"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printLegend(MATRIKS CurrentMap, int day, Kata Player, JAM CurrentTime)
{
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
}

int main()
{
    //deklarasi variabel global
    Wahana ListWahana[10];
    Wahana ListUpgrade[10];
    Wahana ListOwnedWahana[100];
    Material ListMat[3];
    int Wood = 0, Fire = 0, Primogem = 0, Money = 1000, idxmap = 0, day = 1;
    POINT Posisi = MakePOINT(1, 1);
    JAM CurrentTime = MakeJAM(21, 0);
    JAM Open = MakeJAM(9, 0);
    JAM Close = MakeJAM(21, 0);
    MATRIKS CurrentMap;
    MATRIKS ListMap[4];
    Graph RelationMap[4];
    boolean isMain = false;
    Stack Perintah;

    //baca file wahana, material, map
    MakeMap(RelationMap, ListMap);
    CurrentMap = ListMap[0];
    char filename5[] = "File-Eksternal/Wahana.txt";
    BacaFileWahana(filename5, &ListWahana[10], &ListUpgrade[10]);
    char filename6[] = "File-Eksternal/Material.txt";
    BacaFileMaterial(filename6, &ListMat[3]);

    //bikin array action
    Kata ListAksi[16];
    InitTabAction(ListAksi);

    //print halaman utama
    Kata Player;
    printf("Welcome to Willy Wangky's PLayground\n");
    printf("Type 'new' to start a new game");
    STARTKATA(stdin);
    if (!IsKataSama(CKata, ListAksi[11]))
    {
        printf("Masukkan nama: ");
        STARTKATA(stdin);
        Player = CopyKata(CKata);
    }
    while (!IsKataSama(CKata, ListAksi[11]))
    {
        if (isMain)
        {
            printf("Main phase day ");

            // print Map dan Perintah
            printLegend(CurrentMap, day, Player, CurrentTime);

            // close
            printf("Closing time: ");
            TulisJAM(Close);
            printf("\nTime remaining: ");
            TulisJAM(MenitToJAM(SelisihJam(CurrentTime, Close)));
            printf("Antrian: ");

            // Next Perintah
            printf("Masukkan Perintah\n");
            STARTKATA(stdin);

            //serve
            if (IsKataSama(CKata, ListAksi[6]))
            {
            }
            //repair
            else if (IsKataSama(CKata, ListAksi[7]))
            {
                Repair(ListOwnedWahana, SearchWahanaFromPoint(ListOwnedWahana, Posisi).Nama);
            }
            //detail
            else if (IsKataSama(CKata, ListAksi[8]))
            {
                Detail(ListOwnedWahana, SearchWahanaFromPoint(ListOwnedWahana, Posisi).Nama);
            }
            //office
            else if (IsKataSama(CKata, ListAksi[9]))
            {
                if (Elmt(CurrentMap, Absis(Posisi), Ordinat(Posisi)) == 'O'){
                    Office(ListOwnedWahana);
                }
                else{
                    printf("Kamu sedang tidak berada di office.\n");
                }
            }
            //prepare
            else if (IsKataSama(CKata, ListAksi[10]))
            {
               Prepare(isMain);
            }
        }
        else
        {
            printf("Preparation phase day ");

            // print Map dan Perintah
            printLegend(CurrentMap, day, Player, CurrentTime);

            // open
            printf("Opening time: ");
            TulisJAM(Open);
            printf("\nTime remaining: ");
            TulisJAM(MenitToJAM(SelisihJam(CurrentTime, Open)));
            printf("\nTotal aksi yang akan dilakukan: %ld", countaksi);
            printf("\nTotal waktu yang dibutuhkan: ");
            TulisJAM(MenitToJAM(durasi));
            printf("\nTotal uang yang dibutuhkan: %ld\n", totalbiaya);

            // Next Perintah
            printf("Masukkan Perintah\n");
            STARTKATA(stdin);

            //build
            if (IsKataSama(CKata, ListAksi[0]))
            {
                Build(Perintah, ListWahana, Posisi, Money);
            }
            //upgrade
            else if (IsKataSama(CKata, ListAksi[1]))
            {
                Upgrade(Perintah, ListOwnedWahana, ListUpgrade, Posisi, Money);
            }
            //buy
            else if (IsKataSama(CKata, ListAksi[2]))
            {
                Buy(Perintah, ListMat, Money);
            }
            //undo
            else if (IsKataSama(CKata, ListAksi[3]))
            {
                Undo(Perintah, Money);
            }
            //execute
            else if (IsKataSama(CKata, ListAksi[4]))
            {
                Execute(Perintah, ListOwnedWahana, ListWahana, ListUpgrade, Wood, Fire, Primogem, isMain, &CurrentMap);
            }
            //main
            else if (IsKataSama(CKata, ListAksi[5]))
            {
                Main(Perintah, isMain);
            }
        }

        //buat gerak
        if (IsKataSama(CKata, ListAksi[12])){
            W(RelationMap, &Posisi, CurrentMap, ListMap, idxmap);
        }
        else if (IsKataSama(CKata, ListAksi[13])){
            A(RelationMap, &Posisi, CurrentMap, ListMap, idxmap);
        }
        else if (IsKataSama(CKata, ListAksi[14])){
            S(RelationMap, &Posisi, CurrentMap, ListMap, idxmap);
        }
        else if (IsKataSama(CKata, ListAksi[15])){
            D(RelationMap, &Posisi, CurrentMap, ListMap, idxmap);
        }
    }

    // ketika telah menginput
    printf("Thanks For Playing\n");
    return 0;
}
