/* File: mesinkata.c */
/* Definisi Mesin Kata: Model Akuisisi Versi I */

#include "boolean.h"
#include "mesinkar.h"
#include "mesinkata.h"
#include <stdio.h>

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

void STARTKATA(FILE * input)
/* I.S. : CC sembarang 
   F.S. : EndKata = true, dan CC = MARK; 
          atau EndKata = false, CKata adalah kata yang sudah diakuisisi,
          CC karakter pertama sesudah karakter terakhir kata */
{   /* Kamus Lokal */
    /* Algoritma */
    START(input);
    //IgnoreBlank();
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
    //IgnoreBlank();
    if (CC == MARK){
        EndKata = true;
    }
    else if (CC == ','){
        SalinKata();
    }
    else {
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
{   /* Kamus Lokal */
    int i;
    /* Algoritma */
    i = 0;
    while ((CC != MARK)){
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

boolean IsKataSama(Kata Kata1, Kata Kata2){
    if (Kata1.Length == Kata2.Length){
        int i;
        for (i = 0; i < Kata1.Length; i++){
            if (Kata1.TabKata[i] != Kata2.TabKata[i]){
                return false;
            }
        }
        return true;
    }
    return false;
}
