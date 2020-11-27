/* File : stackt.c */
/* deklarasi stack yang diimplementasi dengan tabel kontigu dan ukuran sama */
/*
    Nama = Kadek Dwi Bagus Ananta Udayana
    Nim = 13519057
    Kelas = K1
    Tanggal = 20 Oktober 2020
    Deskripsi = body dari stackt
*/

#include "stackt.h"

void CreateEmpty(Stack *S)
/* I.S. sembarang; */
/* F.S. Membuat sebuah stack S yang kosong berkapasitas MaxEl */
/* jadi indeksnya antara 0.. MaxEl */
/* Ciri stack kosong : TOP ber-1ai -1 */
{
    Top(*S) = -1;
}
/* ************ Predikat Untuk test keadaan KOLEKSI ************ */
boolean IsEmptyStack(Stack S)
/* Mengirim true jika Stack kosong: lihat definisi di atas */
{
    return Top(S) == -1;
}
boolean IsFullStack(Stack S)
/* Mengirim true jika tabel penampung -1ai elemen stack penuh */
{
    return (Top(S) == MaxEls - 1);
}
/* ************ Menambahkan sebuah elemen ke Stack ************ */
void Push(Stack *S, Element X)
/* Menambahkan X sebagai elemen Stack S. */
/* I.S. S mungkin kosong, tabel penampung elemen stack TIDAK penuh */
/* F.S. X menjadi TOP yang baru,TOP bertambah 1 */
{
    Top(*S)++;
    InfoTop(*S) = X;
}
/* ************ Menghapus sebuah elemen Stack ************ */
void Pop(Stack *S, Element *X)
/* Menghapus X dari Stack S. */
/* I.S. S  tidak mungkin kosong */
/* F.S. X adalah -1ai elemen TOP yang lama, TOP berkurang 1 */
{
    *X = InfoTop(*S);
    Top(*S)--;
}
