/* File : stackt.c */


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
    InfoTop(*S).Biaya = X.Biaya;
    InfoTop(*S).Durasi = X.Durasi;
    InfoTop(*S).Fire= X.Fire;
    InfoTop(*S).perintah = X.perintah;
    InfoTop(*S).Point.X = X.Point.X;
    InfoTop(*S).Point.Y = X.Point.Y;
    InfoTop(*S).Primogem = X.Primogem;
    InfoTop(*S).Target = CopyKata(X.Target);
    InfoTop(*S).Wood = X.Wood;
    InfoTop(*S).idxmap = X.idxmap;
    InfoTop(*S).Ukuran.X = X.Ukuran.X;
    InfoTop(*S).Ukuran.Y = X.Ukuran.Y;
}
/* ************ Menghapus sebuah elemen Stack ************ */
void Pop(Stack *S, Element *X)
/* Menghapus X dari Stack S. */
/* I.S. S  tidak mungkin kosong */
/* F.S. X adalah -1ai elemen TOP yang lama, TOP berkurang 1 */
{
    (*X).Biaya = InfoTop(*S).Biaya;
    (*X).Durasi = InfoTop(*S).Durasi;
    (*X).Fire = InfoTop(*S).Fire;
    (*X).perintah = InfoTop(*S).perintah;
    (*X).Point.X = InfoTop(*S).Point.X;
    (*X).Point.Y = InfoTop(*S).Point.Y;
    (*X).Primogem = InfoTop(*S).Primogem;
    (*X).Target = CopyKata(InfoTop(*S).Target);
    (*X).Wood = InfoTop(*S).Wood;
    (*X).idxmap = InfoTop(*S).idxmap;
    (*X).Ukuran.X = InfoTop(*S).Ukuran.X;
    (*X).Ukuran.Y = InfoTop(*S).Ukuran.Y;
    Top(*S)--;
}
