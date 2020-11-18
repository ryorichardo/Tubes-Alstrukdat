/* File: mesinkata.c */
/* Definisi Mesin Kata: Model Akuisisi Versi I */

/*
NIM         : 13519217
Nama        : Hughie Alghaiyyu Emiliano
Tanggal     : 30 September 2020
Topik       : Pra-Praktikum 6
Deskripsi   : Body mesinkata.h
*/

#include "boolean.h"
#include "mesinkar.h"
#include "mesinkata.h"
#include <stdio.h>

boolean EndKata;
Kata CKata;

void IgnoreBlank()
/* Mengabaikan satu atau beberapa BLANK
   I.S. : CC sembarang 
   F.S. : CC ≠ BLANK atau CC = MARK */
{   /* Kamus Lokal */
    /* Algoritma */
    while ((CC == BLANK) && (CC != MARK)) {
        ADV();
    }
}

void STARTKATA()
/* I.S. : CC sembarang 
   F.S. : EndKata = true, dan CC = MARK; 
          atau EndKata = false, CKata adalah kata yang sudah diakuisisi,
          CC karakter pertama sesudah karakter terakhir kata */
{   /* Kamus Lokal */
    /* Algoritma */
    START();
    IgnoreBlank();
    if (CC == MARK){
        EndKata = true;
    }
    else {
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
{   /* Kamus Lokal */
    /* Algoritma */
    IgnoreBlank();
    if (CC == MARK){
        EndKata = true;
    }
    else {
        SalinKata();
    }
}

void SalinKata()
/* Mengakuisisi kata, menyimpan dalam CKata
   I.S. : CC adalah karakter pertama dari kata
   F.S. : CKata berisi kata yang sudah diakuisisi; 
          CC = BLANK atau CC = MARK; 
          CC adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */
{   /* Kamus Lokal */
    int i;
    /* Algoritma */
    i = 0;
    while ((CC != MARK) && (CC != BLANK)){
        if (i == NMax){
            ADV();
        }
        else {
            CKata.TabKata[i] = CC;
            ADV();
            i++;
        }
    }
    CKata.Length = i;
}
