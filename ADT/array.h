/* MODUL TABEL INTEGER DENGAN ELEMEN POSITIF */
/* Berisi definisi dan semua primitif pemrosesan tabel integer dengan elemen positif */
/* Penempatan elemen selalu rapat kiri */
/* Banyaknya elemen didefinisikan secara implisit, memori tabel statik */

#ifndef ARRAY_H
#define ARRAY_H

#include "boolean.h"
#include "jam.h"
#include "tipebentukan.h"

/*  Kamus Umum */
#define IdxMax 99
/* Indeks maksimum array */
#define IdxMin 0
/* Indeks minimum array */
#define IdxUndef -999 
/* Indeks tak terdefinisi*/
#define ValUndef -1
/* Nilai elemen tak terdefinisi*/

typedef struct {
    char NamaAction[50];
    JAM Durasi;
} Action;

typedef struct{
   Wahana TW[IdxMax+1];
} TabWahana;

typedef struct{
   Material TM[IdxMax+1];
} TabMaterial;

typedef struct{
   Action TA[IdxMax+1];
} TabAction;

typedef struct{
   char NamaUpgrade[50];
   int Harga;
   int JmlBahan;
} Upgrade;
  
typedef struct{
   Upgrade TU[IdxMax+1];
} TabUpgrade;

typedef struct{
   char Nama[50];
   int Penggunaan;
   int PenghasilanTotal;
   int PenggunaanHari;
   int PenghasilanHari;
} Laporan;
  
typedef struct{
   Laporan TL[IdxMax+1];
} TabLaporan;

/**** KONSTRUKTOR ****/

TabAction GetAction (char namafile[]);
/* Prosedur menginisialasi suatu array berisi daftar aksi dan durasi yang dibutuhkan dari file eksternal */


TabWahana GetTabWahana (char namafile[]);
/* Fungsi menginisialasi suatu array berisi daftar wahana dan spesifikasinya dari file eksternal */


TabMaterial GetTabMaterial(char namafile[]);
/* Fungsi menginisialasi suatu array berisi daftar material beserta harganya dari file eksternal */

TabLaporan MakeTabLaporan(TabWahana TW);
/* Fungsi untuk inisialisasi array laporan wahana */

Wahana MakeWahana (char Nama[50], int Harga, int Kapasitas, JAM Durasi, char Deskripsi[100] );
/* Fungsi untuk membuat tipe bentukan Wahana */

/**** EOP ****/
boolean isWahanaEmpty(Wahana W);
/* EOP Tab Wahana */

boolean isLaporanEmpty(Laporan L);
/* EOP Tab Laporan */

boolean isMaterialEmpty(Material M);
/* EOP Tab Material */

/**** OPERASI ****/
int NbElmtTabWahana(TabWahana TW);
/* Mengirimkan banyaknya elemen efektif TabWahana */

int NbElmtTabLaporan(TabLaporan TL);
/* Mengirimkan banyaknya elemen efektif TabLaporan */

int NbElmtTabMaterial (TabMaterial TM);
/* Mengirimkan banyaknya elemen efektif tabel */
/* Mengirimkan nol jika tabel kosong */
/* *** Daya tampung container *** */

void AddWahana(TabWahana *TW, Wahana);
/* Prosedur menambahkan suatu wahana beserta spesifikasinya ke daftar wahana */

void RefreshLaporan (TabLaporan *TL);
/* I.S. TL tidak kosong */
/* Prosedur untuk "refresh" laporan ketika memulai hari baru */

void AddLaporan(TabLaporan *TL, Wahana W);
/* Prosedur menambahkan laporan ke array laporan ketika wahana baru dibangun */

boolean SearchWahana(TabWahana TW, char Nama[50]);
/* Fungsi untuk mencari apakah suatu wahana ada di daftar wahana */

int SearchMaterial (TabMaterial T, Kata X);
/* Search apakah ada elemen tabel T yang bernilai X */
/* Jika ada, menghasilkan indeks i terkecil, dengan elemen ke-i = X */
/* Jika tidak ada, mengirimkan IdxUndef */
/* Menghasilkan indeks tak terdefinisi (IdxUndef) jika tabel T kosong */
/* Skema Searching yang digunakan bebas */


void PrintListWahana(TabWahana TW);
/* Prosedur untuk menampilkan daftar wahana yang tersedia */

void PrintDetailWahana(TabWahana TW, char Nama[50]);
/* Prosedur untuk menampilkan detail dari suatu wahana */


void PrintLaporanWahana(TabLaporan TL, char Nama[50]);
/* Prosedur untuk menampilkan laporan wahana */

#endif