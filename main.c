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

void printLegend(MATRIKS CurrentMap, int day, Kata Player, JAM CurrentTime)
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
    int Wood = 0, Fire = 0, Primogem = 0, Money = 1000, idxmap = 0;
    POINT Posisi = MakePOINT(1, 1);
    JAM CurrentTime = MakeJAM(21, 0);
    JAM Open = MakeJAM(9, 0);
    JAM Close = MakeJAM(21, 0);
    MATRIKS CurrentMap;
    MATRIKS ListMap[4];
    Graph RelationMap[4];
    Stack Perintah;
    //baca file wahana, material, map
    MakeMap(RelationMap, ListMap);
    CurrentMap = ListMap[0];
    MakeTabWahanaEmpty(ListOwnedWahana);
    char filename5[] = "File-Eksternal/Wahana.txt";
    BacaFileWahana(filename5, &ListWahana[10], &ListUpgrade[10]);
    char filename6[] = "File-Eksternal/Material.txt";
    BacaFileMaterial(filename6, &ListMat[3]);

    int day = 1;

    //bikin array action
    Kata ListAksi[16];
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
            printf("Main phase day ");

            // print Map dan Perintah
            printLegend(CurrentMap, day, Player, CurrentTime);

            // close
            printf("Closing time: ");
            TulisJAM(Close);
            printf("\nTime remaining: ");
            TulisJAM(MenitToJAM(SelisihJam(CurrentTime, Close)));
            printf("\n");
            printf("Antrian: ");

            // Next Perintah
            printf("\nMasukkan Perintah\n");
            STARTKATA(stdin);

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
            }
            //repair
            else if (IsKataSama(Game, ListAksi[7]))
            {
                Repair(ListOwnedWahana, SearchWahanaFromPoint(ListOwnedWahana, Posisi).Nama);
            }
            //detail
            else if (IsKataSama(Game, ListAksi[8]))
            {
                Detail(ListOwnedWahana, SearchWahanaFromPoint(ListOwnedWahana, Posisi).Nama);
            }
            //office
            else if (IsKataSama(Game, ListAksi[9]))
            {
                if (Elmt(CurrentMap, Absis(Posisi), Ordinat(Posisi)) == 'O')
                {
                    Office(ListOwnedWahana);
                }
                else
                {
                    printf("Kamu sedang tidak berada di office.\n");
                }
            }
            //prepare
            else if (IsKataSama(Game, ListAksi[10]))
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
            printf("\n");
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
                Build(Perintah, ListWahana, Posisi, Money);
            }
            //upgrade
            else if (IsKataSama(Game, ListAksi[1]))
            {
                Upgrade(Perintah, ListOwnedWahana, ListUpgrade, Posisi, Money);
            }
            //buy
            else if (IsKataSama(Game, ListAksi[2]))
            {
                Buy(Perintah, ListMat, Money);
            }
            //undo
            else if (IsKataSama(Game, ListAksi[3]))
            {
                Undo(Perintah, Money);
            }
            //execute
            else if (IsKataSama(Game, ListAksi[4]))
            {
                Execute(Perintah, ListOwnedWahana, ListWahana, ListUpgrade, Wood, Fire, Primogem, isMain, &CurrentMap);
            }
            //main
            else if (IsKataSama(Game, ListAksi[5]))
            {
                Main(Perintah, isMain, ListWahana);
            }
        }

        //buat gerak
        if (IsKataSama(Game, ListAksi[12]))
        {
            W(RelationMap, &Posisi, CurrentMap, ListMap, idxmap);
        }
        else if (IsKataSama(Game, ListAksi[13]))
        {
            A(RelationMap, &Posisi, CurrentMap, ListMap, idxmap);
        }
        else if (IsKataSama(Game, ListAksi[14]))
        {
            S(RelationMap, &Posisi, CurrentMap, ListMap, idxmap);
        }
        else if (IsKataSama(Game, ListAksi[15]))
        {
            D(RelationMap, &Posisi, CurrentMap, ListMap, idxmap);
        }
    }

    // ketika telah menginput
    printf("Thanks For Playing\n");
    return 0;
}
