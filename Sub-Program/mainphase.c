#include "stdio.h"
#include "mainphase.h"
#include "prioqueuechar.h"
#include "../ADT/listlinier.h"
#include "../ADT/tipebentukan.h"
#include "../ADT/array.h"

void Serve(Wahana ArrayWahana[100], Kata NamaWahana, int * Uang, PrioQueueChar *Customer)
{
    Wahana W;
    int i, count, j;
    Antrian Buang, Sementara;

    /* Search Wahana */
    W = SearchWahana(&ArrayWahana[100], NamaWahana);

    /* Kasus Wahana Rusak */
    if (Rusak(W))
    {
        printf("Maaf, wahana sedang maintenance, wahana tidak bisa digunakan.\n");
        /* Hapus antrian wahana dari customer */
        for (i = 0; i < 5; i++)
        {
            if (IsKataSama(W.Nama, Main(*Customer, i))){
                Main(*Customer, i) = '\0';
            }
        }
        /* Kasus ga ada antrian wahana dari customer */
        count = 0;
        for (j = 0; j < 5; j++)
        {
            if (Main(*Customer, j) != '\0'){
                count += 1;
            }
        }
        /* Customer dihapus dari antrian (keluar dari antrian) */
        if (count == 0){
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
            if (IsKataSama(W.Nama, Main(*Customer, i))){
                Main(*Customer, i) = '\0';
            }
        }
        /* Kasus ga ada antrian wahana dari customer */
        count = 0;
        for (j = 0; j < 5; j++)
        {
            if (Main(*Customer, j) != '\0'){
                count += 1;
            }
        }
        /* Customer dihapus dari antrian (keluar dari antrian) */
        if (count == 0){
            Dequeue(Customer, &Buang);
        }
    }
    else
    {
        *Uang += Harga(W);
        Pemain(W) += 1;
         /* Hapus antrian wahana dari customer */
        for (i = 0; i < 5; i++)
        {
            if (IsKataSama(W.Nama, Main(*Customer, i))){
                Main(*Customer, i) = '\0';
            }
        }
        /* Kasus ga ada antrian wahana dari customer */
        count = 0;
        for (j = 0; j < 5; j++)
        {
            if (Main(*Customer, j) != '\0'){
                count += 1;
            }
        }
        /* Customer dihapus dari antrian (keluar dari antrian) */
        if (count == 0){
            Dequeue(Customer, &Buang);
        }
        else {
            Dequeue(Customer, &Sementara);
        }
    }
}

void Repair(Wahana ArrayWahana[100], Kata NamaWahana)
{
    Wahana W;

    /* Search Wahana */
    W = SearchWahana(&ArrayWahana[100], NamaWahana);
    /* Repair wahana */
    Rusak(W) = false;
}

void Office(Wahana ArrayWahana[100])
{
    printf("Masukkan perintah (DETAILS / REPORT / EXIT)? \n ");
    int i;
    Kata NamaWahana;
    char pilihan[10];
    i = 0;
    TabLaporan TLap;

    // masukkan
    while (!isWahanaEmpty(ArrayWahana[i]))
    {
        printf("Nama Nama Wahana : \n ");
        printf("%s\n ", Nama(ArrayWahana[i]));
    }

    // Masukkan perintah (DETAILS / REPORT / EXIT)
    printf("Masukkan perintah (DETAILS / REPORT / EXIT)? \n ");
    // STARTKATA(stdin);
    // Pilihan = CKata;
    scanf("%s", pilihan);

    while (pilihan != "EXIT")
    {
        // jika detail
        if (pilihan == "DETAIL")
        {
            printf("pingin melihat detail wahana dengan nama apa ? \n ");
            STARTKATA(stdin);
            Detail(&ArrayWahana[100], CKata);
            printf("Ingin melihat detail wahana(y/n) ? \n ");
            printf(" `y` untuk yes dan `n` untuk no ? \n ");
        }

        else
        {
            // buat tab laporan
            TLap = MakeTabLaporan(&ArrayWahana[100]);

            // buat laporan yang ping dilihat
            printf("pingin melihat Laporan wahana dengan nama apa ? \n ");
            STARTKATA(stdin);
            PrintLaporanWahana(TLap, CKata);
        }

        // Masukkan perintah (DETAILS / REPORT / EXIT)
        printf("Masukkan perintah (DETAILS / REPORT / EXIT)? \n ");
        // STARTKATA(stdin);
        // Pilihan = CKata;
        scanf("%s", pilihan);
    }
}

void Detail(Wahana ArrayWahana[100], Kata NamaWahana)
{
    int i = 0;
    while (!isWahanaEmpty(ArrayWahana[i]))
    {
        if (Nama(ArrayWahana[i]) == String(NamaWahana))
        {
            printf("Nama Wahana : ");
            PrintKata(NamaWahana);
            printf("\n");
            printf("Harga Tiket : %d\n", Harga(ArrayWahana[i]));
            printf("Kapasitas Wahana : %d\n", Kapasitas(ArrayWahana[i]));
            printf("Durasi Wahana : %d\n", Durasi(ArrayWahana[i]));
            printf("Deskripsi Wahana : %s\n ", String(Deskripsi(ArrayWahana[i])));
        }
        i++;
    }
}

void Prepare(boolean * isMain)
{
    *isMain = false;
}
