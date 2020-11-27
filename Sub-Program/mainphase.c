#include "stdio.h"
#include "mainphase.h"
#include "../ADT/listlinier.h"
#include "../ADT/tipebentukan.h"

void Serve(Wahana ArrayWahana[100], Kata NamaWahana, int Uang, Antrian *Customer)
{
    int i;

    /* Search Wahana */
    while (i < 100)
    {
        if (Nama(ArrayWahana[i]) == String(NamaWahana))
        {
            break;
        }
        i++;
    }

    /* Kasus Wahana Rusak */
    if (Rusak(ArrayWahana[i]))
    {
        printf("Maaf, wahana sedang maintenance, wahana tidak bisa digunakan.\n");
        /* Hapus antrian wahana dari customer */
        /* Kasus ga ada antrian wahana dari customer */

        /* Customer dihapus dari antrian (keluar dari antrian) */
    }
    /* Wahana aman */
    else if (Pemain(ArrayWahana[i]) == Kapasitas(ArrayWahana[i]))
    {
        printf("Maaf, wahana sudah penuh.\n");
        /* Hapus antrian wahana dari customer */

        /* Kasus antrian wahana dari customer sudah habis */

        /* Customer dihapus dari antrian (keluar dari antrian) */
    }
    else
    {
        Uang += Harga(ArrayWahana[i]);
        /* Hapus antrian wahana dari customer */

        /* Kasus antrian wahana dari customer sudah habis */

        /* Customer dihapus dari antrian (keluar dari antrian) */
    }
}

void Repair(Wahana ArrayWahana[100], Kata NamaWahana)
{
    int i;

    /* Search Wahana */
    while (i < 100)
    {
        if (Nama(ArrayWahana[i]) == String(NamaWahana))
        {
            /* Repair wahana */
            Rusak(ArrayWahana[i]) = false;
            break;
        }
        i++;
    }
}

void Office(Wahana ArrayWahana[100])
{
    int i;
    Kata NamaWahana;
    char pilihan[10];
    i = 0;

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

void Prepare(boolean isMain)
{
    isMain = false;
}