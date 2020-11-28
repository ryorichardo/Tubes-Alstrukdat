/* File: mesinkata.c */
/* Definisi Mesin Kata: Model Akuisisi Versi I */

#include <stdio.h>
#include <stdlib.h>
#include "mesinkata.h"

boolean EndKata;
Kata CKata;

//void IgnoreBlank()
/* Mengabaikan satu atau beberapa BLANK
   I.S. : CC sembarang
   F.S. : CC ≠ BLANK atau CC = MARK */
//{   /* Kamus Lokal */
/* Algoritma */
//   while ((CC == BLANK) && (CC != MARK)) {
//       ADV();
//   }
//}

void STARTKATA(FILE *input)
/* I.S. : CC sembarang
   F.S. : EndKata = true, dan CC = MARK;
          atau EndKata = false, CKata adalah kata yang sudah diakuisisi,
          CC karakter pertama sesudah karakter terakhir kata */
{ /* Kamus Lokal */
    /* Algoritma */
    START(input);
    //IgnoreBlank();
    if (CC == MARK)
    {
        EndKata = true;
    }
    else
    {
        EndKata = false;
        SalinKata();
    }
}

void ADVKATA()
/* I.S. : CC adalah karakter pertama kata yang akan diakuisisi
   F.S. : CKata adalah kata terakhir yang sudah diakuisisi,
          CC adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika CC = MARK, EndKata = true.
   Proses : Akuisisi kata menggunakan procedure SalinKata */
{ /* Kamus Lokal */
    /* Algoritma */
    //IgnoreBlank();
    if (CC == MARK)
    {
        EndKata = true;
    }
    else if (CC == ',')
    {
        SalinKata();
        IgnoreBlank();
    }
    else
    {
        SalinKata();
        IgnoreBlank();
    }
}

void SalinKata()
/* Mengakuisisi kata, menyimpan dalam CKata
   I.S. : CC adalah karakter pertama dari kata
   F.S. : CKata berisi kata yang sudah diakuisisi;
          CC = BLANK atau CC = MARK;
          CC adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */
{ /* Kamus Lokal */
    int i;
    /* Algoritma */
    i = 0;
    while ((CC != MARK))
    {
        if (i == NMax)
        {
            ADV();
        }
        else
        {
            CKata.TabKata[i] = CC;
            ADV();
            i++;
        }
    }
    CKata.Length = i;
}

boolean IsKataSama(Kata Kata1, Kata Kata2)
{
    if (Kata1.Length == Kata2.Length)
    {
        int i;
        for (i = 0; i < Kata1.Length; i++)
        {
            if (Kata1.TabKata[i] != Kata2.TabKata[i])
            {
                return false;
            }
        }
        return true;
    }
    return false;
}

void BacaFileWahana(char namafile[], Wahana TabWahana[10], Wahana TabUp[10])
{
    FILE *ptr;
    ptr = fopen(namafile, "r");
    if (ptr == NULL)
    {
        printf("Error! opening file\n");
        exit(1);
    }

    int i = 0;
    while (CC != ';')
    {
        if (i == 0)
        {
            STARTKATA(ptr);
        }
        else
        {
            SalinKata();
        }
        ADV();

        TabWahana[i].Nama = CopyKata(CKata);
        SalinToken();
        ADV();
        TabWahana[i].Harga = CToken;
        SalinToken();
        ADV();
        TabWahana[i].Kapasitas = CToken;
        SalinToken();
        ADV();
        TabWahana[i].Pemain = CToken;
        SalinToken();
        TabWahana[i].Durasi = CToken;
        SalinToken();
        ADV();
        TabWahana[i].HargaBuild = CToken;
        SalinToken();
        ADV();
        TabWahana[i].DurasiBuild = CToken;
        SalinToken();
        ADV();
        TabWahana[i].Mat[0] = CToken;
        SalinToken();
        ADV();
        TabWahana[i].Mat[1] = CToken;
        SalinToken();
        ADV();
        TabWahana[i].Mat[2] = CToken;
        SalinKata();
        ADV();
        TabWahana[i].Deskripsi = CopyKata(CKata);
        TabWahana[i].Rusak = false;
        i++;
    }
    i=0;
    ADV();
    while (CC != ',')
    {
        SalinKata();
        ADV();
        TabUp[i].Nama = CopyKata(CKata);
        SalinToken();
        ADV();
        TabUp[i].Harga = CToken;
        SalinToken();
        ADV();
        TabUp[i].Kapasitas = CToken;
        SalinToken();
        ADV();
        TabUp[i].HargaBuild = CToken;
        SalinToken();
        ADV();
        TabUp[i].Mat[0] = CToken;
        SalinToken();
        ADV();
        TabUp[i].Mat[1] = CToken;
        SalinToken();
        ADV();
        TabUp[i].Mat[2] = CToken;
        i++;
    }

}

void BacaFileMaterial(char namafile[], Material TabMat[3])
{
    FILE *ptr;
    ptr = fopen(namafile, "r");
    if (ptr == NULL)
    {
        printf("Error! opening file\n");
        exit(1);
    }
    int i = 0;
    while (CC != '.')
    {
        if (i == 0)
        {
            STARTKATA(ptr);
        }
        else
        {
            SalinKata();
        }
        TabMat[i].Nama = CopyKata(CKata);
        SalinToken();
        TabMat[i].Harga = CToken;
        i++;
    }
}

Kata CopyKata(Kata K)
{
    int i;
    Kata New;
    for (i = 0; i < K.Length; i++)
    {
        New.TabKata[i] = K.TabKata[i];
    }
    New.Length = K.Length;
    return New;
}

void PrintKata(Kata X)
{
    int i;
    for (i = 0; i < X.Length; i++)
    {
        printf("%c", X.TabKata[i]);
    }
}
