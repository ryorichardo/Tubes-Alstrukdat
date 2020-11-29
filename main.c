#include "ADT/tipebentukan.h"
#include "ADT/Mesinkata/mesinkata.h"
#include "ADT/Mesintoken/mesintoken.h"
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
    // Wahana ListSaveWahana[100];

    List ListUpgradeOwnedWahana[100];
    Material ListMat[3];
    TabLaporan TL;
    POINT Posisi = MakePOINT(2, 2);
    JAM CurrentTime = MakeJAM(21, 0);
    JAM Open = MakeJAM(9, 0);
    JAM Close = MakeJAM(21, 0);
    MATRIKS CurrentMap;
    MATRIKS ListMap[5];
    Graph RelationMap[5];
    Stack Perintah;
    PrioQueueChar Customer;
    int Banyak;
    Antrian Pelanggan[5];
    Save ListSave[3];

    //baca file wahana, material, map
    MakeMap(RelationMap, ListMap);
    CurrentMap = ListMap[0];
    MakeTabWahanaEmpty(ListOwnedWahana, 100);
    MakeTabWahanaEmpty(ListWahana, 10);
    MakeTabWahanaEmpty(ListUpgrade, 10);
    MakeTabMaterialEmpty(ListMat);

    // untuk save
    MakeTabSaveEmpty(ListSave);
    // MakeTabWahanaEmpty(ListSaveWahana, 100);
    //

    MakeTabLaporanEmpty(&TL);
    char filename5[] = "File-Eksternal/Wahana.txt";
    BacaFileWahana(filename5, ListWahana, ListUpgrade);
    char filename6[] = "File-Eksternal/Material.txt";
    BacaFileMaterial(filename6, ListMat);

    // untuk save
    char filename7[] = "File-Eksternal/save.txt";
    BacaLoadSave(filename7, ListSave);
    // char filename8[] = "File-Eksternal/saveWahana.txt";
    // BacaFileWahana(filename8, ListSaveWahana, ListUpgrade);
    //

    int day = 1;
    int Wood = 1000, Fire = 10000, Primogem = 1000, Money = 1000000, idxmap = 0;
    //bikin array action
    Kata ListAksi[19];

    InitTabAction(ListAksi);
    InitCustomer(Pelanggan);

    //print halaman utama
    Kata Player, Game;
    printf("Welcome to Willy Wangky's PLayground\n");
    printf("Type 'new' or 'load' to start a new game\n");
    STARTKATA(stdin);
    Game = CopyKata(CKata);
    boolean gameOn;
    // Exit = ListAksi[11];
    int j;

    // printf("%d", Absis(Posisi));
    // printf("%d", Ordinat(Posisi));

    // SALAH INPUTAN
    if (!IsKataSama(Game, ListAksi[16]) && !IsKataSama(Game, ListAksi[17]))
    {
        printf("\n#############################################\n");
        printf("tidak ada pilihan tersebut buangg");
        printf("\n#############################################\n\n");

        // Next Perintah
        printf("Type 'new' or 'load' to start a new game\n");
        STARTKATA(stdin);
        Game = CopyKata(CKata);
    }

    // LOAD GAME

    if (IsKataSama(Game, ListAksi[17]))
    {
        // POINT Posisi = MakePOINT(ListSave->Absis, ListSave->Ordinat);
        day = ListSave->Day;
        Player = ListSave->Player;
        Money = ListSave->Money;
        gameOn = true;
        Absis(Posisi) = ListSave->Absis;
        Ordinat(Posisi) = ListSave->Ordinat;
        // char filename8[] = "File-Eksternal/saveWahana.txt";
        // BacaFileWahana(filename8, ListOwnedWahana, ListUpgrade);
        // CurrentMap = ListMap[4];
        // printf("\n1\n");
        //
    }
    //

    // NEW GAME
    if (IsKataSama(Game, ListAksi[16]))
    {
        // POINT Posisi = MakePOINT(2, 2);
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
    while (!IsKataSama(Game, ListAksi[11]) && gameOn && !IsKataSama(Game, ListAksi[18]))
    {
        if (isMain == true)
        {
            if (JGT(CurrentTime, Close))
            {
                isMain == false;
                day++;
                CurrentTime = MakeJAM(21, 0);
            }

            printf("\nMain phase day ");

            // print Map dan Perintah
            printLegend(CurrentMap, day, Player, CurrentTime, Money);

            // close
            printf("Closing time: ");
            TulisJAM(Close);
            printf("\nTime remaining: ");
            TulisJAM(MenitToJAM(SelisihJam(CurrentTime, Close)));
            printf("\n");
            RefreshLaporan(&TL);
            PrintAntrian(Banyak, Customer);

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
                Wahana New = SearchWahanaFromPoint(ListOwnedWahana, Posisi, idxmap);
                Serve(ListOwnedWahana, Nama(New), &Money, &Customer, &CurrentTime, Banyak, &TL, &isMain);
            }
            //repair
            else if (IsKataSama(Game, ListAksi[7]))
            {
                Wahana New = SearchWahanaFromPoint(ListOwnedWahana, Posisi, idxmap);
                Repair(ListOwnedWahana, Nama(New), &CurrentTime);
            }
            //detail
            else if (IsKataSama(Game, ListAksi[8]))
            {
                Wahana New = SearchWahanaFromPoint(ListOwnedWahana, Posisi, idxmap);
                Detail(ListOwnedWahana, Nama(New), ListUpgradeOwnedWahana);
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
                Prepare(&isMain, &Customer);
                CurrentTime = MakeJAM(21, 0);
                day++;
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

            else if (IsKataSama(Game, ListAksi[18]))
            {
                // SimpanMATRIKS(CurrentMap, "save.txt");
                // PrintListWahana(ListOwnedWahana);

                save(Player, day, Money, Close, Banyak, Absis(Posisi), Ordinat(Posisi));
                saveWahana(ListOwnedWahana);
            }
        }
        else
        {

            printf("\nPreparation phase day ");

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
            printf("\nMasukkan Perintah\n");
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
                Build(&Perintah, ListWahana, ListOwnedWahana, &Posisi, &CurrentMap, idxmap, &Money, &Wood, &Fire, &Primogem);
            }
            //upgrade
            else if (IsKataSama(Game, ListAksi[1]))
            {
                Upgrade(&Perintah, ListOwnedWahana, ListUpgrade, Posisi, &Money, &Wood, &Fire, &Primogem, idxmap);
            }
            //buy
            else if (IsKataSama(Game, ListAksi[2]))
            {
                Buy(&Perintah, ListMat, &Money);
            }
            //undo
            else if (IsKataSama(Game, ListAksi[3]))
            {
                Undo(&Perintah, &CurrentMap, &Money, &Wood, &Fire, &Primogem, ListOwnedWahana);
            }
            //execute
            else if (IsKataSama(Game, ListAksi[4]))
            {
                Execute(&Perintah, ListOwnedWahana, &TL, ListWahana, ListUpgrade, &Wood, &Fire, &Primogem, &isMain, &CurrentMap, &Posisi, ListUpgradeOwnedWahana);
                CurrentTime = MakeJAM(9, 0);
                // PrintKata(ListOwnedWahana->Nama);
                RandomAntrian(&Customer, Pelanggan, ListOwnedWahana, &Banyak);
                // PrintListWahana(ListOwnedWahana);
            }
            //main
            else if (IsKataSama(Game, ListAksi[5]))
            {
                Mainphase(&Perintah, &isMain, ListWahana, &Money);
                CurrentTime = MakeJAM(9, 0);
                RandomAntrian(&Customer, Pelanggan, ListOwnedWahana, &Banyak);
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
        }
    }

    // ketika telah menginput
    printf("Thanks For Playing\n");
    return 0;
}
