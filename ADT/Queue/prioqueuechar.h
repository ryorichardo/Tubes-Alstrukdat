/* File : prioqueue.h */
/* Definisi ADT Priority Queue Char dengan representasi array secara eksplisit dan alokasi dinamik */
/* Model Implementasi Versi III dengan circular buffer */
/* Elemen queue terurut tidak mengecil berdasarkan elemen prio */

#ifndef prioqueuechar_H
#define prioqueuechar_H

#include "../boolean.h"
#include "../Mesinkata/mesinkata.h"

extern Kata Main[5];
/* Konstanta untuk mendefinisikan address tak terdefinisi */

typedef struct
{
    Kata Nama;
    Kata Main[10]; /* Wahana-wahana yang mau dinaikin Customer */
    int Kesabaran;
} Pengunjung;

/* Definisi elemen dan address */
typedef struct
{
    int prio;  /* [1..100], prioritas dengan -1ai 1..100 (1 adalah prioritas tertinggi) */
    Pengunjung info; /* elemen karakter */
} Antrian;

/* Contoh deklarasi variabel bertype PrioQueueChar : */
/* Versi I : tabel dinamik, Head dan Tail eksplisit, ukuran disimpan */
typedef struct
{
    Antrian *T;  /* tabel penyimpan elemen */
    int HEAD; /* alamat penghapusan */
    int TAIL; /* alamat penambahan */
    int MaxEl;    /* Max elemen queue */
} PrioQueueChar;
/* Definisi PrioQueueChar kosong: HEAD=-1; TAIL=-1. */

/* ********* AKSES (Selektor) ********* */
/* Jika e adalah infotypePQ dan Q adalah PrioQueueChar, maka akses elemen : */
#define Prio(e) (e).prio
#define Info(e) (e).info
#define Head(Q) (Q).HEAD
#define Tail(Q) (Q).TAIL
#define InfoHead(Q) (Q).T[(Q).HEAD]
#define InfoTail(Q) (Q).T[(Q).TAIL]
#define MaxEl(Q) (Q).MaxEl
#define Elmtd(Q, i) (Q).T[(i)]
#define Main(Q,i) (((Q).T[(Q).HEAD]).info).Main[i]

/* ********* Prototype ********* */
boolean IsEmpty(PrioQueueChar Q);
/* Mengirim true jika Q kosong: lihat definisi di atas */
boolean IsFull(PrioQueueChar Q);
/* Mengirim true jika tabel penampung elemen Q sudah penuh */
/* yaitu mengandung elemen sebanyak MaxEl */
int NBElmt(PrioQueueChar Q);
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong. */

/* *** Kreator *** */
void MakeEmpty(PrioQueueChar *Q, int Max);
/* I.S. sembarang */
/* F.S. Sebuah Q kosong terbentuk dan salah satu kondisi sbb: */
/* Jika alokasi berhasil, Tabel memori dialokasi berukuran Max */
/* atau : jika alokasi gagal, Q kosong dg MaxEl=0 */
/* Proses : Melakukan alokasi, membuat sebuah Q kosong */

/* *** Destruktor *** */
void DeAlokasi(PrioQueueChar *Q);
/* Proses: Mengembalikan memori Q */
/* I.S. Q pernah dialokasi */
/* F.S. Q menjadi tidak terdefinisi lagi, MaxEl(Q) diset 0 */

/* *** Primitif Add/Delete *** */
void Enqueue(PrioQueueChar *Q, Antrian X);
/* Proses: Menambahkan X pada Q dengan aturan priority queue, terurut mengecil berdasarkan prio */
/* I.S. Q mungkin kosong, tabel penampung elemen Q TIDAK penuh */
/* F.S. X disisipkan pada posisi yang tepat sesuai dengan prioritas,
        TAIL "maju" dengan mekanisme circular buffer; */
void Dequeue(PrioQueueChar *Q, Antrian *X);
/* Proses: Menghapus X pada Q dengan aturan FIFO */
/* I.S. Q tidak mungkin kosong */
/* F.S. X = -1ai elemen HEAD pd I.S., HEAD "maju" dengan mekanisme circular buffer;
        Q mungkin kosong */

/* Operasi Tambahan */
void PrintQueue(PrioQueueChar Q);
/* Mencetak isi queue Q ke layar */
/* I.S. Q terdefinisi, mungkin kosong */
/* F.S. Q tercetak ke layar dengan format:
<prio-1> <elemen-1>
...
<prio-n> <elemen-n>
#
*/

#endif
