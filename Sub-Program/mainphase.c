#include "stdio.h"
#include "mainphase.h"
#include "../ADT/prioqueuechar.h"
#include "../ADT/listlinier.h"
#include "../ADT/tipebentukan.h"
#include "../ADT/array.h"

void Serve(Wahana ArrayWahana[100], Kata NamaWahana, int *Uang, PrioQueueChar *Customer)
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
        Pemain(W) += 1;
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
        else
        {
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

void Prepare(boolean *isMain)
{
    *isMain = false;
}
