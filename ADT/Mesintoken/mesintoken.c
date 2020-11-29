#include <stdio.h>
#include "../boolean.h"
#include "mesintoken.h"

/* State Mesin Kata */
boolean EndToken;
int CToken;

void IgnoreBlank()
/* Mengabaikan satu atau beberapa BLANK
   I.S. : CC sembarang 
   F.S. : CC ≠ BLANK atau CC = MARK */
{
    while (CC == BLANK)
    {
        ADV();
    }
}
void STARTTOKEN(FILE *input)
/* I.S. : CC sembarang 
   F.S. : EndToken = true, dan CC = MARK; 
          atau EndToken = false, CToken adalah Token yang sudah diakuisisi,
          CC karakter pertama sesudah karakter terakhir Token */
{
    START(input);
    IgnoreBlank();
    if (CC == MARK)
    {
        EndToken = true;
    }
    else /* CC != MARK */
    {
        EndToken = false;
        SalinToken();
    }
}
void ADVTOKEN()
/* I.S. : CC adalah karakter pertama kata yang akan diakuisisi 
   F.S. : CToken adalah Token terakhir yang sudah diakuisisi, 
          CC adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika CC = MARK, maka EndToken = true		  
   Proses : Akuisisi kata menggunakan procedure SalinKata */
{
    IgnoreBlank();
    if (CC == MARK)
    {
        EndToken = true;
    }
    else /* CC != MARK */
    {
        SalinToken();
        IgnoreBlank();
    }
}
void SalinToken()
/* Mengakuisisi Token dan menyimpan hasilnya dalam CToken
   I.S. : CC adalah karakter pertama dari Token
   F.S. : CToken berisi Token yang sudah diakuisisi; 
          CC = BLANK atau CC = MARK; 
          CC adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */
{
    int bil; /* definisi */
    /* Algoritma*/
    bil = 0; /* inisialisasi */
    while ((CC != MARK) && (CC != BLANK))
    {
        CToken = (bil * 10) + (CC - '0');
        bil = CToken;
        ADV();
    } /* CC = MARK or CC = BLANK */
}