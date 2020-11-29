/* MODUL TABEL INTEGER DENGAN ELEMEN POSITIF */
/* Berisi definisi dan semua primitif pemrosesan tabel integer dengan elemen positif */
/* Penempatan elemen selalu rapat kiri */
/* Banyaknya elemen didefinisikan secara implisit, memori tabel statik */

#ifndef ARRAY_H
#define ARRAY_H

#include "boolean.h"
#include "jam.h"
#include "tipebentukan.h"
#include "point.h"
#include "mesinkata.h"

/*  Kamus Umum */
#define IdxMax 99
/* Indeks maksimum array */
#define IdxMin 0
/* Indeks minimum array */
#define IdxUndef -999
/* Indeks tak terdefinisi*/
#define ValUndef -1
/* Nilai elemen tak terdefinisi*/

extern Kata Empty;

typedef struct
{
   Kata NamaAction;
   JAM Durasi;
} Action;

typedef struct
{
   Action TA[IdxMax + 1];
} TabAction;

typedef struct
{
   Kata Nama;
   int Penggunaan;
   int PenghasilanTotal;
   int PenggunaanHari;
   int PenghasilanHari;
} Laporan;

typedef struct
{
   Laporan TL[IdxMax + 1];
} TabLaporan;

/**** KONSTRUKTOR ****/
void MakeKataEmpty(Kata *Kata);

void MakeKataBuild(Kata *Kata);

void MakeKataUpgrade(Kata *Kata);

void MakeKataBuy(Kata *Kata);

void MakeKataUndo(Kata *Kata);

void MakeKataExecute(Kata *Kata);

void MakeKataMain(Kata *Kata);

void MakeKataServe(Kata *Kata);

void MakeKataRepair(Kata *Kata);

void MakeKataDetail(Kata *Kata);

void MakeKataOffice(Kata *Kata);

void MakeKataPrepare(Kata *Kata);

void MakeKataExit(Kata *Kata);

void MakeTabWahanaEmpty (Wahana ListWahana[], int max);

void MakeTabMaterialEmpty(Material ListMaterial[3]);

void InitTabAction(Kata ListAksi[16]);
/* Prosedur menginisialasi suatu array berisi daftar aksi dan durasi yang dibutuhkan dari file eksternal */


Wahana GetTabWahana (char namafile[]);
/* Fungsi menginisialasi suatu array berisi daftar wahana dan spesifikasinya dari file eksternal */


Material GetTabMaterial(char namafile[]);
/* Fungsi menginisialasi suatu array berisi daftar material beserta harganya dari file eksternal */

void MakeTabLaporanEmpty(TabLaporan *TL);
/* Fungsi untuk inisialisasi array laporan wahana */

Wahana MakeWahana(Kata Nama, int Harga, int Kapasitas, int Durasi, int HargaBuild, int DurasiBuild, int Mat[3], Kata Deskripsi, POINT Point, boolean Rusak);
/* Fungsi untuk membuat tipe bentukan Wahana */

/**** EOP ****/
boolean isWahanaEmpty(Wahana W);
/* EOP Tab Wahana */

boolean isLaporanEmpty(Laporan L);
/* EOP Tab Laporan */

boolean isMaterialEmpty(Material M);
/* EOP Tab Material */

/**** OPERASI ****/
int NbElmtTabWahana(Wahana ListWahana[10]);
/* Mengirimkan banyaknya elemen efektif TabWahana */

int NbElmtTabLaporan(TabLaporan TL);
/* Mengirimkan banyaknya elemen efektif TabLaporan */

int NbElmtTabMaterial (Material ListMaterial[3]);
/* Mengirimkan banyaknya elemen efektif tabel */
/* Mengirimkan nol jika tabel kosong */
/* *** Daya tampung container *** */

void AddWahana(Wahana ListWahana[10], Wahana W);
/* Prosedur menambahkan suatu wahana beserta spesifikasinya ke daftar wahana */

void RefreshLaporan(TabLaporan *TL);
/* I.S. TL tidak kosong */
/* Prosedur untuk "refresh" laporan ketika memulai hari baru */

void AddLaporan(TabLaporan *TL, Wahana W);
/* Prosedur menambahkan laporan ke array laporan ketika wahana baru dibangun */

Wahana SearchWahana(Wahana ListWahana[10], Kata Nama);
/* Fungsi untuk mencari apakah suatu wahana ada di daftar wahana */

Wahana SearchWahanaFromPoint(Wahana ListWahana[10], POINT posisi);

int SearchMaterial (Material ListMaterial[3], Kata X);
/* Search apakah ada elemen tabel T yang bernilai X */
/* Jika ada, menghasilkan indeks i terkecil, dengan elemen ke-i = X */
/* Jika tidak ada, mengirimkan IdxUndef */
/* Menghasilkan indeks tak terdefinisi (IdxUndef) jika tabel T kosong */
/* Skema Searching yang digunakan bebas */


void PrintListWahana(Wahana ListWahana[100]);
/* Prosedur untuk menampilkan daftar wahana yang tersedia */

void PrintDetailWahana(Wahana ArrayWahana[100], Kata NamaWahana);
/* Prosedur untuk menampilkan detail dari suatu wahana */

void PrintLaporanWahana(TabLaporan TL, Kata Nama);
/* Prosedur untuk menampilkan laporan wahana */

#endif