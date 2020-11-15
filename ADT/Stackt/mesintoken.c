/* File: mesintoken.h */
/* Definisi Mesin Token: Model Akuisisi Versi I */
/*
   Nama  = Kadek Dwi Bagus Ananta Udayana 
   NIM   = 13519057
   Kelas = K1
   Tanggal = 1 Oktober 2020
   Topik = Mesin token
   Deskripsi = body mesin token

*/

#include "boolean.h"
#include "mesintoken.h"

/* State Mesin Kata */
boolean EndToken;
Token CToken;

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
void STARTTOKEN()
/* I.S. : CC sembarang 
   F.S. : EndToken = true, dan CC = MARK; 
          atau EndToken = false, CToken adalah Token yang sudah diakuisisi,
          CC karakter pertama sesudah karakter terakhir Token */
{
    START();
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
    int i, bil; /* definisi */
    /* Algoritma*/
    i = 0;
    bil = 0; /* inisialisasi */
    while ((CC != MARK) && (CC != BLANK) && (i < NMax))
    {
        if ((CC == '+') || (CC == '-') || (CC == '*') || (CC == '/') || (CC == '^'))
        {
            CToken.tkn = CC;
            CToken.val = -1;
        }
        else
        {
            CToken.val = (bil * 10) + (CC - '0');
            CToken.tkn = 'b';
            bil = CToken.val;
        }
        ADV();
        i++;
    } /* CC = MARK or CC = BLANK */
}