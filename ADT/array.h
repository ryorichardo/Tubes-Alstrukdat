// ADT Array: untuk list wahana, list upgrade, list material

#ifndef ARRAYPOS_H
#define ARRAYPOS_H

#include "boolean.h"
#include "tipebentukan.h"
#include "mesinkata.h"
#include <stdio.h>

/*  Kamus Umum */
#define IdxMax 99
/* Indeks maksimum array */
#define IdxMin 0
/* Indeks minimum array */
#define IdxUndef -999 
/* Indeks tak terdefinisi*/
#define ValUndef NULL
/* Nilai elemen tak terdefinisi*/

/* Definisi elemen dan koleksi objek */
typedef int IdxType;  /* type indeks */

typedef struct { 
  Material Tab[IdxMax+1]; 
} TabMaterial;

/* Indeks yang digunakan [IdxMin..IdxMax] */
/* Indeks ke-0 tidak digunakan */
/* Jika T adalah TabInt, cara deklarasi dan akses: */
/* Deklarasi : T : TabInt */
/* Maka cara akses: 
   T[i] untuk mengakses elemen ke-i */
/* Definisi : 
   Tabel kosong: semua elemen bernilai ValUndef
   Definisi elemen pertama : T[i] dengan i=1 */
  
/* ********** SELEKTOR ********** */
#define Elmt(T,i) (T).Tab[(i)]

/* ********** KONSTRUKTOR ********** */ //keknya gabutuh make empty
/* Konstruktor : create tabel kosong  */
//void MakeEmptyW (TabWahana * T);
//void MakeEmptyU (TabUpgrade * T);
//void MakeEmptyM (TabMaterial * T);
/* I.S. T sembarang */
/* F.S. Terbentuk tabel T kosong dengan kapasitas IdxMax-IdxMin+1 */
/* Proses: Inisialisasi semua elemen tabel T dengan ValUndef */

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */

int NbElmt (TabMaterial T);
/* Mengirimkan banyaknya elemen efektif tabel */
/* Mengirimkan nol jika tabel kosong */
/* *** Daya tampung container *** */

IdxType GetLastIdx (TabMaterial T);
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen T terakhir */


/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* *** Mendefinisikan isi tabel dari pembacaan *** */

void TulisIsiTab (TabMaterial T);
/* Proses : Menuliskan isi tabel dengan traversal, tabel ditulis di antara kurung siku; 
   antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan karakter di depan,
   di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. T boleh kosong */
/* F.S. Jika T tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika tabel kosong : menulis [] */


/* ********** SEARCHING ********** */
/* ***  Perhatian : Tabel boleh kosong!! *** */
IdxType Search (TabMaterial T, Kata X);
/* Search apakah ada elemen tabel T yang bernilai X */
/* Jika ada, menghasilkan indeks i terkecil, dengan elemen ke-i = X */
/* Jika tidak ada, mengirimkan IdxUndef */
/* Menghasilkan indeks tak terdefinisi (IdxUndef) jika tabel T kosong */
/* Skema Searching yang digunakan bebas */

/* ********** MENAMBAH DAN MENGHAPUS ELEMEN DI AKHIR ********** */
/* *** Menambahkan elemen terakhir *** */
void AddAsLastEl (TabMaterial * T, Material X);
/* Proses: Menambahkan X sebagai elemen terakhir tabel */
/* I.S. Tabel T boleh kosong, tetapi tidak penuh */
/* F.S. X adalah elemen terakhir T yang baru */

#endif