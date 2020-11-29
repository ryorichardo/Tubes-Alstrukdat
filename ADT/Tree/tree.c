// Nama/NIM     : Jonathan Yudi Gunawan/13518084
// Hari, Tanggal  : Selasa, 12 November 2019
// Topik/Deskripsi  : Tree/ADT Binary Tree nya Tuan Yon

#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

/* *** Konstruktor *** */
BinTree Tree(Wahana Akar, BinTree L, BinTree R)
/* Menghasilkan sebuah pohon biner dari A, L, dan R, jika alokasi berhasil */
/* Menghasilkan pohon kosong (Nil) jika alokasi gagal */
{
  BinTree T = (BinTree)malloc(sizeof(BinTree));
  if (T != Nil)
  {
    Akar(T) = Akar;
    Left(T) = L;
    Right(T) = R;
  }
  return T;
}

void MakeTree(Wahana Akar, BinTree L, BinTree R, BinTree *P)
/* I.S. Akar, L, R terdefinisi. P Sembarang */
/* F.S. Membentuk pohon P dengan Akar(P)=Akar, Left(P)=L, dan Right(P)=R
   jika alokasi berhasil. P = Nil jika alokasi gagal. */
{
  *P = Tree(Akar, L, R);
}

/* Manajemen Memory */
addrNode AlokNode(Wahana X)
/* Mengirimkan addrNode hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka addrNode tidak Nil, dan misalnya menghasilkan P,
  maka Akar(P) = X, Left(P) = Nil, Right(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */
{
  return Tree(X, Nil, Nil);
}

void DealokNode(addrNode P)
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian addrNode P */
{
  free(P);
}

/* *** Predikat-Predikat Penting *** */
boolean IsTreeEmpty(BinTree P)
/* Mengirimkan true jika P adalah pohon biner kosong */
{
  return P == Nil;
}

boolean IsTreeOneElmt(BinTree P)
/* Mengirimkan true jika P adalah pohon biner tidak kosong dan hanya memiliki 1 elemen */
{
  if (IsTreeEmpty(P))
  {
    return false;
  }
  return IsTreeEmpty(Left(P)) && IsTreeEmpty(Right(P));
}

boolean IsUnerLeft(BinTree P)
/* Mengirimkan true jika pohon biner tidak kosong P adalah pohon unerleft: hanya mempunyai subpohon kiri */
{
  if (IsTreeEmpty(P))
  {
    return false;
  }
  if (!IsTreeEmpty(Right(P)))
  {
    return false;
  }
  return !IsTreeEmpty(Left(P));
}

boolean IsUnerRight(BinTree P)
/* Mengirimkan true jika pohon biner tidak kosong P adalah pohon unerright: hanya mempunyai subpohon kanan*/
{
  if (IsTreeEmpty(P))
  {
    return false;
  }
  if (!IsTreeEmpty(Left(P)))
  {
    return false;
  }
  return !IsTreeEmpty(Right(P));
}

boolean IsBiner(BinTree P)
/* Mengirimkan true jika pohon biner tidak kosong P adalah pohon biner: mempunyai subpohon kiri dan subpohon kanan*/
{
  if (IsTreeEmpty(P))
  {
    return false;
  }
  return ((!IsTreeEmpty(Left(P))) && (!IsTreeEmpty(Right(P))));
}
