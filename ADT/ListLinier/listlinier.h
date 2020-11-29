/* File : listlinier.h */
/* contoh ADT list berkait dengan representasi fisik pointer  */
/* Representasi addressList dengan pointer */
/* infotypeList adalah integer */

#ifndef listlinier_H
#define listlinier_H

#include "../boolean.h"
#include "../tipebentukan.h"
#include "../Mesinkata/mesinkata.h"
#include "../Array/array.h"

#define Nil NULL

typedef struct tElmtlist *addressList;
typedef struct tElmtlist {
	Kata Nama;
	POINT Lokasi;
	int idxmap;
	addressList next;
} ElmtList;
typedef struct {
	addressList First;
} List;

/* Definisi list : */
/* List kosong : First(L) = Nil */
/* Setiap elemen dengan addressList P dapat diacu InfoList(P), NextList(P) */
/* Elemen terakhir list : jika addressListnya Last, maka NextList(Last)=Nil */

#define InfoList(P) (P)->Nama
#define NextList(P) (P)->next
#define FirstList(L) ((L).First)

/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean IsEmptyList (List L);
/* Mengirim true jika list kosong */

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmptyList (List *L);
/* I.S. sembarang             */
/* F.S. Terbentuk list kosong */

/****************** Manajemen Memori ******************/
addressList Alokasi (Kata X);
/* Mengirimkan addressList hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka addressList tidak nil, dan misalnya */
/* menghasilkan P, maka InfoList(P)=X, NextList(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */
void Dealokasi (addressList *P);
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian addressList P */

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/


void InsVLast (List *L, Kata X);
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */



/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirst (List *L, addressList P);
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-addressList P sebagai elemen pertama */
void InsertAfter (List *L, addressList P, addressList Prec);
/* I.S. Prec pastilah elemen list dan bukan elemen terakhir, */
/*      P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
void InsertLast (List *L, addressList P);
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */

void AddWahanaToListUpgrade(List L[100], Kata Upgrade, POINT Lokasi, int idxmap);

/****************** PROSES SEMUA ELEMEN LIST ******************/
void PrintInfo (List L);
/* Ngeprint daftar upgrade: dimulai dari elemen ke dua*/


#endif
