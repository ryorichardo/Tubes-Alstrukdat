#include <stdio.h>
#include <stdlib.h>
#include "mainphase.h"

// Antrian Pelanggan[5];

void InitCustomer(Antrian Pelanggan[25])
{
    int j;
    int a = 65;
    char c;

    for (j = 0; j < 25; j++)
    {
        c = a;
        ((Pelanggan[j].info).Nama).TabKata[0] = 'C';
        ((Pelanggan[j].info).Nama).TabKata[1] = 'u';
        ((Pelanggan[j].info).Nama).TabKata[2] = 's';
        ((Pelanggan[j].info).Nama).TabKata[3] = 't';
        ((Pelanggan[j].info).Nama).TabKata[4] = 'o';
        ((Pelanggan[j].info).Nama).TabKata[5] = 'm';
        ((Pelanggan[j].info).Nama).TabKata[6] = 'e';
        ((Pelanggan[j].info).Nama).TabKata[7] = 'r';
        ((Pelanggan[j].info).Nama).TabKata[8] = ' ';
        ((Pelanggan[j].info).Nama).TabKata[9] = c;
        a++;
        (Pelanggan[j].info).Kesabaran = 5;
    }
}

void RandomAntrian(PrioQueueChar *Customer, Antrian Pelanggan[25], Wahana ArrayWahana[100], int Banyak)
{
    int i, j, Custom[25], count, k, Naik, Tempat[25], BanyakWahana, l;

    /* Reset Array Customer */
    for (i = 0; i < 25; i++)
    {
        Custom[i] = 0;
    }

    BanyakWahana = NbElmtTabWahana(ArrayWahana);
    MakeEmpty(Customer, 5);
    Banyak = (rand() % 5);

    count = 1;
    for (i = 0; i < Banyak; i++)
    {
        /* Reset Array Tempat[25] (Wahana) */
        for (k = 0; k < 25; k++)
        {
            Tempat[k] = 0;
        }

        j = rand() % 25;
        while (Custom[j] == 1)
        {
            j = (rand() % 25);
        }
        Custom[j] = 1;

        Pelanggan[j].prio = count;

        Naik = (rand() % 10) + 1;
        for (k = 0; k < Naik; k++)
        {
            l = rand() % 25;
            while (Tempat[l] == 1)
            {
                l = (rand() % 25);
            }
            Tempat[l] = 1;
            (Pelanggan[j].info).Main[k] = Nama(ArrayWahana[l]);
        }

        Enqueue(Customer, Pelanggan[j]);

        count++;
    }
}

void Serve(Wahana ArrayWahana[100], Kata NamaWahana, int *Uang, PrioQueueChar *Customer, JAM *CurrentTime, int Banyak, TabLaporan *TL)
{
    Wahana W;
    int i, count, j, k, r;
    Antrian Buang;

    /* Search Wahana */
    W = SearchWahana(ArrayWahana, NamaWahana);

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
            Banyak -= 1;
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
            Banyak -= 1;
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
            Banyak -= 1;
        }

        /* Menambah keterangan di Laporan */
        for (k = 0; k < NbElmtTabLaporan(*TL); k++)
        {
            if (IsKataSama(TL->TL[k].Nama, W.Nama))
            {
                TL->TL[k].Penggunaan += 1;
                TL->TL[k].PenghasilanTotal += W.Harga;
                TL->TL[k].PenggunaanHari += 1;
                TL->TL[k].PenghasilanHari += W.Harga;
            }
        }

        /* Algoritma random kemungkinan rusak */
        r = rand() % 5;
        if (r == 0)
        {
            Rusak(W) = true;
        }

        /* Menambah 10 menit setelah selesai serve */
        NextNMenit(*CurrentTime, Durasi(W));
    }
}

void Repair(Wahana ArrayWahana[100], Kata NamaWahana, JAM *CurrentTime)
{
    Wahana W;
    NextNMenit(*CurrentTime, 10);
    /* Search Wahana */
    W = SearchWahana(ArrayWahana, NamaWahana);
    /* Repair wahana */
    Rusak(W) = false;
}

void Office(Wahana ArrayWahana[100], TabLaporan TL)
{
    printf("Masukkan perintah (detail / report / exit)? \n");
    int i;
    Kata NamaWahana, Pilihan, EXIT;
    Kata ListAksi[18];
    InitTabAction(ListAksi);
    // char pilihan[10];
    i = 0;

    // masukkan
    if (isWahanaEmpty(ArrayWahana[i]))
    {
        printf("Tidak ada Nama Wahana : \n");
    }
    else
    {
        printf("Nama Wahana : \n");
    }
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
            PrintDetailWahana(ArrayWahana, CKata);
            // printf("Ingin melihat detail wahana(y/n) ? \n ");
            // printf("y untuk yes dan n untuk no ? \n ");
        }

        // jika report
        else
        {
            // buat laporan yang ping dilihat
            printf("pingin melihat Laporan wahana dengan nama apa ? \n");
            STARTKATA(stdin);
            PrintLaporanWahana(TL, CKata);
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
            printf("Kapasitas Wahana : %d\n", Kapasitas(ArrayWahana[i]));
            // PrintInfo();
            printf("Durasi Wahana : %d\n", Durasi(ArrayWahana[i]));
            printf("Ukuran Wahana : %d x %d\n", PanjangWahana(ArrayWahana[i]), LebarWahana(ArrayWahana[i]));
            printf("\n#############################################\n\n");
        }
        i++;
    }
    if (isWahanaEmpty(ArrayWahana[i]))
    {
        printf("Wahana belum dibangun");
    }
}

void Prepare(boolean *isMain, PrioQueueChar *Customer, int Banyak)
{
    Antrian Buang;
    printf("12\n");
    // while (!IsEmpty(*Customer))
    // {
    //     printf("13\n");
    //     Dequeue(Customer, &Buang);
    //     Banyak -= 1;
    // }
    printf("11\n");
    *isMain = false;
}

void PrintAntrian(int Banyak, PrioQueueChar Customer)
{
    printf("Antrian [%d/5]:\n", Banyak);
    PrintQueue(Customer);
}

void save(Kata Player, int day, int Money, JAM Close, int Banyak)
{
    /* I.S. M terdefinisi */
    /* F.S. Nilai M(i,j) ditulis ke file per baris per kolom*/
    /* Proses: Menulis nilai setiap elemen M ke file dengan traversal per baris dan per kolom */
    /* KAMUS LOKAL */
    indeks i;
    FILE *ptr;
    /* ALGORITMA */
    // ptr = fopen(namafile, "r");
    char namafile[] = "File-Eksternal/save.txt";
    if ((ptr = fopen(namafile, "w")) == NULL)
    {
        printf("Error! opening file\n");
        exit(1);
    }
    for (i = 0; i < Player.Length; i++)
    {
        fprintf(ptr, "%c", Player.TabKata[i]);
    }
    fprintf(ptr, ".");
    fprintf(ptr, "%d", day);
    fprintf(ptr, ".");
    fprintf(ptr, "%d", Money);
    fprintf(ptr, ".");
    fprintf(ptr, "%d", Close);
    fprintf(ptr, ".");
    fprintf(ptr, "%d", Banyak);
    fprintf(ptr, ".");
    fprintf(ptr, ",");

    printf("%d", day);
    printf("%d", Money);
    printf("%d", Close);
    printf("%d", Banyak);

    // for (i = 0; i < NBrsEff(M); i++)
    // {
    //     for (j = 0; j < NKolEff(M); j++)
    //     {
    //         fprintf(ptr, "%c", Elmt(M, i, j));
    //     }
    //     fprintf(ptr, "\n");
    // }
    fclose(ptr);
}
