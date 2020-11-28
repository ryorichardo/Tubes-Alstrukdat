#include <stdio.h>
#include <stdlib.h>
#include "mainphase.h"

Antrian CustomerA, CustomerB, CustomerC, CustomerD, CustomerE;

Kata Wahana1, Wahana2, Wahana3;

void Assign(Kata * Wahana1, Kata * Wahana2, Kata * Wahana3){
    Wahana1->TabKata[0] = 'W';
    Wahana1->TabKata[1] = 'a';
    Wahana1->TabKata[2] = 'n';
    Wahana1->TabKata[3] = 'g';
    Wahana1->TabKata[4] = 'k';
    Wahana1->TabKata[5] = 'y';
    Wahana1->TabKata[6] = ' ';
    Wahana1->TabKata[7] = 'U';
    Wahana1->TabKata[8] = 'n';
    Wahana1->TabKata[9] = 'i';
    Wahana1->TabKata[10] = 'v';
    Wahana1->TabKata[11] = 'e';
    Wahana1->TabKata[12] = 'r';
    Wahana1->TabKata[13] = 's';
    Wahana1->TabKata[14] = 'e';

    Wahana2->TabKata[0] = 'u';
    Wahana2->TabKata[1] = 'W';
    Wahana2->TabKata[2] = 'u';
    Wahana2->TabKata[3] = 'c';
    Wahana2->TabKata[4] = 'o';
    Wahana2->TabKata[5] = 'a';
    Wahana2->TabKata[6] = 's';
    Wahana2->TabKata[7] = 't';
    Wahana2->TabKata[8] = 'e';
    Wahana2->TabKata[9] = 'r';

    Wahana3->TabKata[0] = 'H';
    Wahana3->TabKata[1] = 'A';
    Wahana3->TabKata[2] = 'L';
    Wahana3->TabKata[3] = 'O';
    Wahana3->TabKata[4] = 'l';
    Wahana3->TabKata[5] = 'i';
    Wahana3->TabKata[6] = 'n';
    Wahana3->TabKata[7] = 't';
    Wahana3->TabKata[8] = 'a';
    Wahana3->TabKata[9] = 'r';
}

void CustomA(Antrian CustomerA, Kata Wahana1, Kata Wahana2, Kata Wahana3){
    Assign(&Wahana1, &Wahana2, &Wahana3);
    (CustomerA.info).Main[0] = Wahana1;
    (CustomerA.info).Main[1] = Wahana2;
    (CustomerA.info).Main[2] = Wahana3;
    (CustomerA.info).Kesabaran = 5;
}

void CustomB(Antrian CustomerB, Kata Wahana1, Kata Wahana2, Kata Wahana3){
    Assign(&Wahana1, &Wahana2, &Wahana3);
    (CustomerB.info).Main[0] = Wahana1;
    (CustomerB.info).Main[1] = Wahana2;
    (CustomerB.info).Kesabaran = 5;
}

void CustomC(Antrian CustomerC, Kata Wahana1, Kata Wahana2, Kata Wahana3){
    Assign(&Wahana1, &Wahana2, &Wahana3);
    (CustomerC.info).Main[0] = Wahana2;
    (CustomerC.info).Main[1] = Wahana3;
    (CustomerC.info).Kesabaran = 5;
}

void CustomD(Antrian CustomerD, Kata Wahana1, Kata Wahana2, Kata Wahana3){
    Assign(&Wahana1, &Wahana2, &Wahana3);
    (CustomerD.info).Main[0] = Wahana2;
    (CustomerD.info).Kesabaran = 5;
}

void CustomE(Antrian CustomerE, Kata Wahana1, Kata Wahana2, Kata Wahana3){
    Assign(&Wahana1, &Wahana2, &Wahana3);
    (CustomerE.info).Main[0] = Wahana3;
    (CustomerE.info).Kesabaran = 5;
}

void Serve(Wahana ArrayWahana[100], Kata NamaWahana, int * Uang, PrioQueueChar *Customer, JAM * CurrentTime)
{
    Wahana W;
    int i, count, j;
    Antrian Buang;

    /* Search Wahana */
    W = SearchWahana(&ArrayWahana[100], NamaWahana);

    /* Kasus Wahana Rusak */
    if (Rusak(W))
    {
        printf("Maaf, wahana sedang maintenance, wahana tidak bisa digunakan.\n");
        /* Hapus antrian wahana dari customer */
        for (i = 0; i < 5; i++)
        {
            if (IsKataSama(W.Nama, Main(*Customer, i)))
            {
                Main(*Customer, i).TabKata[0] = '\0';
            }
        }
        /* Kasus ga ada antrian wahana dari customer */
        count = 0;
        for (j = 0; j < 5; j++)
        {
            if (Main(*Customer, j).TabKata[0] != '\0')
            {
                count += 1;
            }
        }
        /* Customer dihapus dari antrian (keluar dari antrian) */
        if (count == 0)
        {
            Dequeue(Customer, &Buang);
        }
    }
    /* Wahana aman */
    else if (Pemain(W) == Kapasitas(W))
    {
        printf("Maaf, wahana sudah penuh.\n");
         /* Hapus antrian wahana dari customer */
        for (i = 0; i < 5; i++)
        {
            if (IsKataSama(W.Nama, Main(*Customer, i)))
            {
                Main(*Customer, i).TabKata[0] = '\0';
            }
        }
        /* Kasus ga ada antrian wahana dari customer */
        count = 0;
        for (j = 0; j < 5; j++)
        {
            if (Main(*Customer, j).TabKata[0] != '\0')
            {
                count += 1;
            }
        }
        /* Customer dihapus dari antrian (keluar dari antrian) */
        if (count == 0)
        {
            Dequeue(Customer, &Buang);
        }
    }
    else
    {
        *Uang += Harga(W);
         /* Hapus antrian wahana dari customer */
        for (i = 0; i < 5; i++)
        {
            if (IsKataSama(W.Nama, Main(*Customer, i)))
            {
                Main(*Customer, i).TabKata[0] = '\0';
            }
        }
        /* Kasus ga ada antrian wahana dari customer */
        count = 0;
        for (j = 0; j < 5; j++)
        {
            if (Main(*Customer, j).TabKata[0] != '\0')
            {
                count += 1;
            }
        }
        /* Customer dihapus dari antrian (keluar dari antrian) */
        if (count == 0)
        {
            Dequeue(Customer, &Buang);
        }
        NextNMenit(*CurrentTime, Durasi(W));
    }
}

void Repair(Wahana ArrayWahana[100], Kata NamaWahana, JAM *CurrentTime)
{
    Wahana W;
    NextNMenit(*CurrentTime, 10);
    /* Search Wahana */
    W = SearchWahana(&ArrayWahana[100], NamaWahana);
    /* Repair wahana */
    Rusak(W) = false;
}

void Office(Wahana ArrayWahana[100])
{
    printf("Masukkan perintah (DETAILS / REPORT / EXIT)? \n ");
    int i;
    Kata NamaWahana, Pilihan, EXIT;
    Kata ListAksi[16];
    InitTabAction(ListAksi);
    // char pilihan[10];
    i = 0;
    TabLaporan TLap;

    // masukkan
    printf("Nama Wahana : \n");
    while (!isWahanaEmpty(ArrayWahana[i]))
    {
        printf("- ");
        // printf("%s\n ", Nama(ArrayWahana[i]));
        PrintKata(ArrayWahana[i].Nama);
        printf("\n");
        i++;
    }

    // Masukkan perintah (DETAILS / REPORT / EXIT)
    printf("Masukkan perintah (detail / report / exit)? \n");
    STARTKATA(stdin);
    Pilihan = CKata;
    // scanf("%s", pilihan);
    // while (pilihan != "EXIT")
    // MakeKataExit(&EXIT);
    // PrintKata(Pilihan);
    // PrintKata(ListAksi[11]);
    while (!IsKataSama(Pilihan, ListAksi[11]))
    {
        // printf("ANJAY ");
        // jika detail
        if (IsKataSama(Pilihan, ListAksi[8]))
        {
            printf("pingin melihat detail wahana dengan nama apa ? \n");
            STARTKATA(stdin);
            Detail(ArrayWahana, CKata);
            // printf("Ingin melihat detail wahana(y/n) ? \n ");
            // printf("y untuk yes dan n untuk no ? \n ");
        }

        // jika report
        else
        {
            // buat tab laporan
            TLap = MakeTabLaporan(ArrayWahana);

            // buat laporan yang ping dilihat
            printf("pingin melihat Laporan wahana dengan nama apa ? \n");
            STARTKATA(stdin);
            PrintLaporanWahana(TLap, CKata);
        }

        // Masukkan perintah (DETAILS / REPORT / EXIT)
        printf("Masukkan perintah (detail / report / exit)? \n");
        // STARTKATA(stdin);
        // Pilihan = CKata;
        STARTKATA(stdin);
        Pilihan = CKata;
    }
}

void Detail(Wahana ArrayWahana[100], Kata NamaWahana)
{
    int i = 0;
    while (!isWahanaEmpty(ArrayWahana[i]))
    {
        if (IsKataSama(NamaWahana, ArrayWahana[i].Nama))
        {
            printf("\n\n#############################################\n");
            printf("Nama Wahana : ");
            PrintKata(NamaWahana);
            printf("\n");
            printf("Harga Tiket : %d\n", Harga(ArrayWahana[i]));
            printf("Kapasitas Wahana : %d\n", Kapasitas(ArrayWahana[i]));
            printf("Durasi Wahana : %d\n", Durasi(ArrayWahana[i]));
            printf("Deskripsi Wahana : ");
            PrintKata(ArrayWahana[i].Deskripsi);
            printf("\n");
            printf("\n#############################################\n\n");
        }
        i++;
    }
}

void Prepare(boolean *isMain, PrioQueueChar * Customer)
{
    Antrian Buang;
    while(!IsEmpty(*Customer)){
        Dequeue(Customer, &Buang);
    }
    *isMain = false;
}

void RandomAntrian(int Banyak, PrioQueueChar * Customer, Antrian CustomerA, Antrian CustomerB, Antrian CustomerC, Antrian CustomerD, Antrian CustomerE){
    int i, j, Custom[5];

    Banyak = (rand() % 5) + 1;
    for (i = 0; i < Banyak; i++){
        j = (rand() % 5) + 1;
        while (Custom[j-1] == 1){
            j = (rand() % 5) + 1;
        }
        Custom[j-1] = 1;
        switch (j)
        {
        case 1:
            Enqueue(Customer, CustomerA);
            break;

        case 2:
            Enqueue(Customer, CustomerB);
            break;
        
        case 3:
            Enqueue(Customer, CustomerC);
            break;

        case 4:
            Enqueue(Customer, CustomerD);
            break;
        
        case 5:
            Enqueue(Customer, CustomerE);
            break;
        }
    }
}