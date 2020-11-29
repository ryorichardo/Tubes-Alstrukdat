/* File : listlinier.h */
/* contoh ADT list berkait dengan representasi fisik pointer  */
/* Representasi addressList dengan pointer */
/* Kata adalah integer */

#include "listlinier.h"
#include <stdio.h>
#include <stdlib.h>

//#define Nil NULL

//typedef int Kata;
//typedef struct tElmtlist *addressList;
//typedef struct tElmtlist {
//	Kata info;
//	addressList next;
//} ElmtList;
//typedef struct {
//	addressList First;
//} List;

/* Definisi list : */
/* List kosong : FirstList(L) = Nil */
/* Setiap elemen dengan addressList P dapat diacu InfoList(P), NextList(P) */
/* Elemen terakhir list : jika addressListnya Last, maka NextList(Last)=Nil */

//#define InfoList(P) (P)->info
//#define NextList(P) (P)->next
//#define FirstList(L) ((L).First)

/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean IsEmptyList(List L)
{
    /* Mengirim true jika list kosong */
    return (FirstList(L) == Nil);
}

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmptyList(List *L)
{
    /* I.S. sembarang             */
    /* F.S. Terbentuk list kosong */
    FirstList(*L) = Nil;
}

/****************** Manajemen Memori ******************/
addressList Alokasi(Kata X)
{
    /* Mengirimkan addressList hasil alokasi sebuah elemen */
    /* Jika alokasi berhasil, maka addressList tidak nil, dan misalnya */
    /* menghasilkan P, maka InfoList(P)=X, NextList(P)=Nil */
    /* Jika alokasi gagal, mengirimkan Nil */
    addressList P;
    P = (addressList)malloc(sizeof(Kata));
    if (P == Nil)
    {
        return Nil;
    }
    else
    {
        InfoList(P) = CopyKata(X);
        NextList(P) = Nil;
        return P;
    }
}

void Dealokasi(addressList *P)
{
    /* I.S. P terdefinisi */
    /* F.S. P dikembalikan ke sistem */
    /* Melakukan dealokasi/pengembalian addressList P */
    NextList(*P) = Nil;
    free(*P);
}

void InsVLast(List *L, Kata X)
{
    /* I.S. L mungkin kosong */
    /* F.S. Melakukan alokasi sebuah elemen dan */
    /* menambahkan elemen list di akhir: elemen terakhir yang baru */
    /* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
    addressList P = Alokasi(X);
    if (P != Nil)
    {
        InsertLast(L, P);
    }
}
/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirst(List *L, addressList P)
{
    /* I.S. Sembarang, P sudah dialokasi  */
    /* F.S. Menambahkan elemen ber-addressList P sebagai elemen pertama */
    NextList(P) = FirstList(*L);
    FirstList(*L) = P;
}

void InsertAfter(List *L, addressList P, addressList Prec)
{
    /* I.S. Prec pastilah elemen list dan bukan elemen terakhir, */
    /*      P sudah dialokasi  */
    /* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
    NextList(P) = NextList(Prec);
    NextList(Prec) = P;
}

void InsertLast(List *L, addressList P)
{
    /* I.S. Sembarang, P sudah dialokasi  */
    /* F.S. P ditambahkan sebagai elemen terakhir yang baru */
    if (IsEmptyList(*L))
    {
        InsertFirst(L, P);
    }
    else
    {
        addressList P1 = FirstList(*L);
        while (NextList(P1) != Nil)
        {
            P1 = NextList(P1);
        }
        NextList(P1) = P;
    }
}

void AddWahanaToListUpgrade(List L[100], Kata Whn, POINT Lokasi, int idxmap)
{
    int i = 0;
    while (!IsEmptyList(L[i]))
    {
        i++;
    }
    addressList P;
    P = (addressList)malloc(sizeof(ElmtList));
    if (P != Nil)
    {
        InfoList(P) = CopyKata(Whn);
        P->Lokasi = Lokasi;
        P->idxmap = idxmap;
        NextList(P) = Nil;
    }
    FirstList(L[i]) = P;
}

/****************** PROSES SEMUA ELEMEN LIST ******************/
void PrintInfo(List L)
{
    /* Ngeprint daftar upgrade: dimulai dari elemen ke dua*/
    addressList P = NextList(FirstList(L));
    while (P != Nil)
    {
        printf("- ");
        PrintKata(InfoList(P));
        printf("\n");
        P = NextList(P);
    }
}
