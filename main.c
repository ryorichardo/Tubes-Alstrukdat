#include "ADT/tipebentukan.h"
#include "ADT/mesinkata.h"
#include "ADT/mesintoken.h"
#include "Sub-Program/mainphase.h"
#include "Sub-Program/prepphase.h"
#include "Sub-Program/PetaWahana.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ADT/boolean.h"

void printLegend(MATRIKS CurrentMap, int day, Kata Player, JAM CurrentTime, int Money)
{
    printf("%d\n", day);

    TulisMATRIKS(CurrentMap);
    printf("Legend:\n");
    printf("A = Antrian\n");
    printf("P = Player\n");
    printf("W = Wahana\n");
    printf("O = Office\n");
    printf("<, ^, >, v = Gerbang\n");
    printf("\nName: ");
    PrintKata(Player);
    printf("\nMoney: %d", Money);
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
    TabLaporan TL;
    POINT Posisi = MakePOINT(2, 2);
    JAM CurrentTime = MakeJAM(21, 0);
    JAM Open = MakeJAM(9, 0);
    JAM Close = MakeJAM(21, 0);
    MATRIKS CurrentMap;
    MATRIKS ListMap[4];
    Graph RelationMap[4];
    Stack Perintah;
    PrioQueueChar Customer;
    extern Antrian CustomerA, CustomerB, CustomerC, CustomerD, CustomerE;
    extern Kata Wahana1, Wahana2, Wahana3;
    int Banyak;

    //baca file wahana, material, map
    MakeMap(RelationMap, ListMap);
    CurrentMap = ListMap[0];
    MakeTabWahanaEmpty(ListOwnedWahana, 100);
    MakeTabWahanaEmpty(ListWahana, 10);
    MakeTabWahanaEmpty(ListUpgrade, 10);
    MakeTabMaterialEmpty(ListMat);
    MakeTabLaporanEmpty(&TL);
    char filename5[] = "File-Eksternal/Wahana.txt";
    BacaFileWahana(filename5, ListWahana, ListUpgrade);
    char filename6[] = "File-Eksternal/Material.txt";
    BacaFileMaterial(filename6, ListMat);

    int day = 1;
    int Wood = 1000, Fire = 10000, Primogem = 1000, Money = 1000000, idxmap = 0;
    //bikin array action
    Kata ListAksi[18];
    InitTabAction(ListAksi);

    //print halaman utama
    Kata Player, Game;
    printf("Welcome to Willy Wangky's PLayground\n");
    printf("Type 'new' to start a new game\n");
    STARTKATA(stdin);
    Game = CopyKata(CKata);
    boolean gameOn;
    // Exit = ListAksi[11];
    int j;

    if (!IsKataSama(Game, ListAksi[16]))
    {
        printf("\n#############################################\n");
        printf("tidak ada pilihan tersebut buangg");
        printf("\n#############################################\n\n");

        // Next Perintah
        printf("Type 'new' to start a new game\n");
        STARTKATA(stdin);
        Game = CopyKata(CKata);
    }

    if (!IsKataSama(Game, ListAksi[11]))
    {
        printf("Masukkan nama: ");
        STARTKATA(stdin);
        Player = CopyKata(CKata);

        // for (j = 0; j < Player.Length - 1; j++)
        // {
        //     Player.TabKata[j] = Player.TabKata[j + 1];
        // }
        // Player.Length -= 1;
        gameOn = true;
    }

    boolean isMain = false;
    while (!IsKataSama(Game, ListAksi[11]) && gameOn)
    {

        if (isMain == true)
        {
            // Assign(&Wahana1, &Wahana2, &Wahana3);
            // CustomA(&CustomerA, Wahana1, Wahana2, Wahana3);
            // CustomB(&CustomerB, Wahana1, Wahana2, Wahana3);
            // CustomC(&CustomerC, Wahana1, Wahana2, Wahana3);
            // CustomD(&CustomerD, Wahana1, Wahana2, Wahana3);
            // CustomE(&CustomerE, Wahana1, Wahana2, Wahana3);
            printf("Main phase day ");

            // print Map dan Perintah
            printLegend(CurrentMap, day, Player, CurrentTime, Money);

            // close
            printf("Closing time: ");
            TulisJAM(Close);
            printf("\nTime remaining: ");
            TulisJAM(MenitToJAM(SelisihJam(CurrentTime, Close)));
            printf("\n");
            // RefreshLaporan(&TL);
            // PrintAntrian(Banyak, Customer);

            // Next Perintah
            printf("\nMasukkan Perintah\n");
            STARTKATA(stdin);
            Game = CopyKata(CKata);

            // Game.Length -= 1;
            // PrintKata(Game);
            // PrintKata(ListAksi[11]);

            // for (j = 0; j < Player.Length - 1; j++)
            // {
            //     Player.TabKata[j] = Player.TabKata[j + 1];
            // }
            // Player.Length -= 1;

            if (IsKataSama(Game, ListAksi[11]))
            {
                gameOn = false;
            }

            //serve
            if (IsKataSama(Game, ListAksi[6]))
            {
                Serve(ListOwnedWahana, SearchWahanaFromPoint(ListOwnedWahana, Posisi).Nama, &Money, &Customer, &CurrentTime, Banyak, &TL);
            }
            //repair
            else if (IsKataSama(Game, ListAksi[7]))
            {
                Repair(ListOwnedWahana, SearchWahanaFromPoint(ListOwnedWahana, Posisi).Nama, &CurrentTime);
            }
            //detail
            else if (IsKataSama(Game, ListAksi[8]))
            {
                Detail(ListOwnedWahana, SearchWahanaFromPoint(ListOwnedWahana, Posisi).Nama);
            }
            //office
            else if (IsKataSama(Game, ListAksi[9]))
            {
                // printf("masuk di office.\n");
                if (Absis(Posisi) == 9 && Ordinat(Posisi) == 9 && idxmap == 0)
                {
                    // PrintKata(ListOwnedWahana->Nama);
                    Office(ListOwnedWahana, TL);
                }
                else
                {
                    printf("\n#############################################\n");
                    printf("Kamu sedang tidak berada di office.");
                    printf("\n#############################################\n\n");
                }
            }
            //prepare
            else if (IsKataSama(Game, ListAksi[10]))
            {
                printf("1\n");
                Prepare(&isMain, &Customer, Banyak);
                day++;
                printf("1\n");
            }

            //buat gerak
            else if (IsKataSama(Game, ListAksi[12]))
            {
                W(RelationMap, &Posisi, &CurrentMap, ListMap, &idxmap);
                CurrentTime = NextNMenit(CurrentTime, 1);
            }
            else if (IsKataSama(Game, ListAksi[13]))
            {
                A(RelationMap, &Posisi, &CurrentMap, ListMap, &idxmap);
                CurrentTime = NextNMenit(CurrentTime, 1);
            }
            else if (IsKataSama(Game, ListAksi[14]))
            {
                S(RelationMap, &Posisi, &CurrentMap, ListMap, &idxmap);
                CurrentTime = NextNMenit(CurrentTime, 1);
            }
            else if (IsKataSama(Game, ListAksi[15]))
            {
                D(RelationMap, &Posisi, &CurrentMap, ListMap, &idxmap);
                CurrentTime = NextNMenit(CurrentTime, 1);
            }
        }
        else
        {
            printf("Preparation phase day ");

            // print Map dan Perintah
            printLegend(CurrentMap, day, Player, CurrentTime, Money);

            // open
            printf("Opening time: ");
            TulisJAM(Open);
            printf("\nTime remaining: ");
            TulisJAM(MenitToJAM(SelisihJam(CurrentTime, Open)));
            printf("\nList Material yang dimiliki:\n");
            printf("-Wood: %d\n", Wood);
            printf("-Fire: %d\n", Fire);
            printf("-Primogem: %d", Primogem);
            printf("\nTotal aksi yang akan dilakukan: %ld", countaksi);
            printf("\nTotal waktu yang dibutuhkan: ");
            TulisJAM(MenitToJAM(durasi));
            printf("\nTotal uang yang dibutuhkan: %ld\n", totalbiaya);

            // Next Perintah
            printf("Masukkan Perintah\n");
            STARTKATA(stdin);
            // printf("sini\n");
            // PrintKata(CKata);
            // printf("sana\n");
            //build

            // CKata.Length -= 1;
            // printf("%c", CKata.TabKata[0]);
            // printf("%c", CKata.TabKata[1]);

            Game = CopyKata(CKata);
            // for (j = 0; j < Game.Length - 1; j++)
            // {
            //     Game.TabKata[j] = Game.TabKata[j + 1];
            // }
            // Game.Length -= 1;
            // PrintKata(Game);
            // PrintKata(ListAksi[11]);
            if (IsKataSama(Game, ListAksi[11]))
            {
                gameOn = false;
            }

            if (IsKataSama(Game, ListAksi[0]))
            {
                Build(&Perintah, ListWahana, Posisi, idxmap, &Money, &Wood, &Fire, &Primogem);
            }
            //upgrade
            else if (IsKataSama(Game, ListAksi[1]))
            {
                Upgrade(&Perintah, ListOwnedWahana, ListUpgrade, Posisi, &Money, &Wood, &Fire, &Primogem);
            }
            //buy
            else if (IsKataSama(Game, ListAksi[2]))
            {
                Buy(&Perintah, ListMat, &Money);
            }
            //undo
            else if (IsKataSama(Game, ListAksi[3]))
            {
                Undo(&Perintah, &Money, &Wood, &Fire, &Primogem);
            }
            //execute
            else if (IsKataSama(Game, ListAksi[4]))
            {
                Execute(&Perintah, ListOwnedWahana, &TL, ListWahana, ListUpgrade, &Wood, &Fire, &Primogem, &isMain, &CurrentMap, &Posisi);
                CurrentTime = MakeJAM(9, 0);
                // PrintKata(ListOwnedWahana->Nama);
            }
            //main
            else if (IsKataSama(Game, ListAksi[5]))
            {
                Mainphase(&Perintah, &isMain, ListWahana, &Money);
                CurrentTime = MakeJAM(9, 0);
            }

            //buat gerak
            else if (IsKataSama(Game, ListAksi[12]))
            {
                W(RelationMap, &Posisi, &CurrentMap, ListMap, &idxmap);
            }
            else if (IsKataSama(Game, ListAksi[13]))
            {
                A(RelationMap, &Posisi, &CurrentMap, ListMap, &idxmap);
            }
            else if (IsKataSama(Game, ListAksi[14]))
            {
                S(RelationMap, &Posisi, &CurrentMap, ListMap, &idxmap);
            }
            else if (IsKataSama(Game, ListAksi[15]))
            {
                D(RelationMap, &Posisi, &CurrentMap, ListMap, &idxmap);
            }
            //RandomAntrian(Banyak, &Customer, CustomerA, CustomerB, CustomerC, CustomerD, CustomerE);
        }
    }

    // ketika telah menginput
    printf("Thanks For Playing\n");
    return 0;
}
