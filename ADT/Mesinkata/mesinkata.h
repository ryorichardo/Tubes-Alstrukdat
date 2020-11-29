#ifndef __MESINKATA_H__
#define __MESINKATA_H__

#include <stdio.h>
#include <stdlib.h>
#include "../boolean.h"
#include "../Mesinkar/mesinkar.h"
#include "../Mesintoken/mesintoken.h"
#include "../tipebentukan.h"

/* State Mesin Kata */
extern boolean EndKata;
extern Kata CKata;

void IgnoreBlank();
/* Mengabaikan satu atau beberapa BLANK
   I.S. : CC sembarang 
   F.S. : CC ≠ BLANK atau CC = MARK */

void STARTKATA(FILE *input);
/* I.S. : CC sembarang 
   F.S. : EndKata = true, dan CC = MARK; 
          atau EndKata = false, CKata adalah kata yang sudah diakuisisi,
          CC karakter pertama sesudah karakter terakhir kata */

void ADVKATA();
/* I.S. : CC adalah karakter pertama kata yang akan diakuisisi 
   F.S. : CKata adalah kata terakhir yang sudah diakuisisi, 
          CC adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika CC = MARK, EndKata = true.		  
   Proses : Akuisisi kata menggunakan procedure SalinKata */

void SalinKata();
/* Mengakuisisi kata, menyimpan dalam CKata
   I.S. : CC adalah karakter pertama dari kata
   F.S. : CKata berisi kata yang sudah diakuisisi; 
          CC = BLANK atau CC = MARK; 
          CC adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */

boolean IsKataSama(Kata Kata1, Kata Kata2);
// True jika kata1 = kata2

void BacaFileWahana(char namafile[], Wahana TabWahana[10], Wahana TabUp[10]);

void BacaFileMaterial(char namafile[], Material TabMat[3]);

void BacaLoadSave(char namafile[], Save TabSave[3]);

Kata CopyKata(Kata K);

void PrintKata(Kata X);

#endif
