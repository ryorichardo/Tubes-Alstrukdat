/* MODUL TABEL INTEGER DENGAN ELEMEN POSITIF */
/* Berisi definisi dan semua primitif pemrosesan tabel integer dengan elemen positif */
/* Penempatan elemen selalu rapat kiri */
/* Banyaknya elemen didefinisikan secara implisit, memori tabel statik */

#ifndef ARRAY_H
#define ARRAY_H

#include "../boolean.h"
#include "../Jam/jam.h"
#include "../tipebentukan.h"
#include "../Point/point.h"
#include "../Mesinkata/mesinkata.h"

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
/* Membuat Tipe Kata dengan isi 'empty' */

void MakeKataBuild(Kata *Kata);
/* Membuat Tipe Kata dengan isi 'build' */

void MakeKataUpgrade(Kata *Kata);
/* Membuat Tipe Kata dengan isi 'upgrade' */

void MakeKataBuy(Kata *Kata);
/* Membuat Tipe Kata dengan isi 'buy' */

void MakeKataUndo(Kata *Kata);
/* Membuat Tipe Kata dengan isi 'undo' */

void MakeKataExecute(Kata *Kata);
/* Membuat Tipe Kata dengan isi 'execute' */

void MakeKataMain(Kata *Kata);
/* Membuat Tipe Kata dengan isi 'main' */

void MakeKataServe(Kata *Kata);
/* Membuat Tipe Kata dengan isi 'serve' */

void MakeKataRepair(Kata *Kata);
/* Membuat Tipe Kata dengan isi 'repair' */

void MakeKataDetail(Kata *Kata);
/* Membuat Tipe Kata dengan isi 'detail' */

void MakeKataOffice(Kata *Kata);
/* Membuat Tipe Kata dengan isi 'office' */

void MakeKataPrepare(Kata *Kata);
/* Membuat Tipe Kata dengan isi 'prepare' */

void MakeKataExit(Kata *Kata);
/* Membuat Tipe Kata dengan isi 'exit' */

void MakeKataNew(Kata *Kata);
/* Membuat Tipe Kata dengan isi 'new' */

void MakeKataLoad(Kata *Kata);
/* Membuat Tipe Kata dengan isi 'load' */

void MakeTabWahanaEmpty(Wahana ListWahana[], int max);
/* Membuat array MARK bertipe wahana */

void MakeTabSaveEmpty(Save ListSave[3]);

void MakeTabMaterialEmpty(Material ListMaterial[3]);
/* Membuat array MARK bertipe Material */

void InitTabAction(Kata ListAksi[16]);
/* Prosedur menginisialasi suatu array berisi daftar aksi dan durasi yang dibutuhkan dari file eksternal */

Wahana GetTabWahana(char namafile[]);
/* Fungsi menginisialasi suatu array berisi daftar wahana dan spesifikasinya dari file eksternal */

Material GetTabMaterial(char namafile[]);
/* Fungsi menginisialasi suatu array berisi daftar material beserta harganya dari file eksternal */

void MakeTabLaporanEmpty(TabLaporan *TLap);
/* Fungsi untuk inisialisasi array laporan wahana */

Wahana MakeWahana(Kata Nama, int Harga, int Kapasitas, int Pemain, int Durasi, int HargaBuild, int DurasiBuild, int Mat[3], Kata Deskripsi, POINT Ukuran, int Peta, POINT Point, boolean Rusak);
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

int NbElmtTabLaporan(TabLaporan TLap);
/* Mengirimkan banyaknya elemen efektif TabLaporan */

int NbElmtTabMaterial(Material ListMaterial[3]);
/* Mengirimkan banyaknya elemen efektif tabel */
/* Mengirimkan nol jika tabel kosong */
/* *** Daya tampung container *** */

void AddWahana(Wahana ListWahana[10], Wahana W);
/* Prosedur menambahkan suatu wahana beserta spesifikasinya ke daftar wahana */

void RefreshLaporan(TabLaporan *TLap);
/* I.S. TLap tidak kosong */
/* Prosedur untuk "refresh" laporan ketika memulai hari baru */

void AddLaporan(TabLaporan *TLap, Wahana W);
/* Prosedur menambahkan laporan ke array laporan ketika wahana baru dibangun */
void DelWahana(Wahana ListWahana[10]);

Wahana SearchWahana(Wahana ListWahana[10], Kata Nama);
/* Fungsi untuk mencari apakah suatu wahana ada di daftar wahana */
/* Mengembalikan Wahana kosong jika tidak ada */

Wahana SearchWahanaFromPoint(Wahana ListWahana[10], POINT posisi, int IdxMap);
/* Fungsi untuk mencari apakah suatu wahana ada di sekitar pemain */
/* Mengembalikan Wahana kosong jika tidak ada */

int SearchMaterial(Material ListMaterial[3], Kata X);
/* Search apakah ada elemen tabel T yang bernilai X */
/* Jika ada, menghasilkan indeks i terkecil, dengan elemen ke-i = X */
/* Jika tidak ada, mengirimkan IdxUndef */
/* Menghasilkan indeks tak terdefinisi (IdxUndef) jika tabel T kosong */
/* Skema Searching yang digunakan bebas */

void PrintListWahana(Wahana ListWahana[100]);
/* Prosedur untuk menampilkan daftar wahana yang tersedia */

void PrintDetailWahana(Wahana ArrayWahana[100], Kata NamaWahana);
/* Prosedur untuk menampilkan detail dari suatu wahana */

void PrintLaporanWahana(TabLaporan TLap, Kata Nama);
/* Prosedur untuk menampilkan laporan wahana */

#endif
