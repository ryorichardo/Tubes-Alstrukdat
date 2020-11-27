/* File : listlinier.h */
/* contoh ADT list berkait dengan representasi fisik pointer  */
/* Representasi addressList dengan pointer */
/* infotypeList adalah integer */

#include "listlinier.h"
#include <stdio.h>
#include <stdlib.h>

//#define Nil NULL

//typedef int infotypeList;
//typedef struct tElmtlist *addressList;
//typedef struct tElmtlist {
//	infotypeList info;
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
boolean IsEmptyList (List L){
/* Mengirim true jika list kosong */
    return (FirstList(L) == Nil);
}

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmptyList (List *L){
/* I.S. sembarang             */
/* F.S. Terbentuk list kosong */
    FirstList(*L) = Nil;
}

/****************** Manajemen Memori ******************/
addressList Alokasi (infotypeList X){
/* Mengirimkan addressList hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka addressList tidak nil, dan misalnya */
/* menghasilkan P, maka InfoList(P)=X, NextList(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */
    addressList P;
    P = (addressList) malloc(sizeof(infotypeList));
    if (P == Nil){
        return Nil;
    }
    else{
        InfoList(P) = X;
        NextList(P) = Nil;
        return P;
    }
}

void Dealokasi (addressList *P){
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian addressList P */
    NextList(*P) = Nil;
    free(*P);
}

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
addressList Search (List L, infotypeList X){
/* Mencari apakah ada elemen list dengan InfoList(P)= X */
/* Jika ada, mengirimkan addressList elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */
    addressList P = FirstList(L);
    while (P != Nil && InfoList(P) != X){
        P = NextList(P);
    }
    return P;
}

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsVFirst (List *L, infotypeList X){
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
    addressList P = Alokasi(X);
    if (P != Nil){
        InsertFirst(L, P);
    }
}

void InsVLast (List *L, infotypeList X){
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
    addressList P = Alokasi(X);
    if (P != Nil){
        InsertLast(L, P);
    }
}

/*** PENGHAPUSAN ELEMEN ***/
void DelVFirst (List *L, infotypeList *X){
/* I.S. List L tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen pertama di-dealokasi */
    addressList P;
    DelFirst(L, &P);
    *X = InfoList(P);
    Dealokasi(&P);
}

void DelVLast (List *L, infotypeList *X){
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */
    addressList P;
    DelLast(L, &P);
    *X = InfoList(P);
    Dealokasi(&P);
}

/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirst (List *L, addressList P){
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-addressList P sebagai elemen pertama */
    NextList(P) = FirstList(*L);
    FirstList(*L) = P;
}

void InsertAfter (List *L, addressList P, addressList Prec){
/* I.S. Prec pastilah elemen list dan bukan elemen terakhir, */
/*      P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
    NextList(P) = NextList(Prec);
    NextList(Prec) = P;
}

void InsertLast (List *L, addressList P){
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */
    if (IsEmptyList(*L)){
        InsertFirst(L, P);
    }
    else{
        addressList P1 = FirstList(*L);
        while (NextList(P1) != Nil){
            P1 = NextList(P1);
        }
        NextList(P1) = P;
    }
}

/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirst (List *L, addressList *P){
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */
    *P = FirstList(*L);
    FirstList(*L) = NextList(*P);
    NextList(*P) = Nil;
}

void DelP (List *L, infotypeList X){
/* I.S. Sembarang */
/* F.S. Jika ada elemen list beraddressList P, dengan InfoList(P)=X  */
/* Maka P dihapus dari list dan di-dealokasi */
/* Jika ada lebih dari satu elemen list dengan Info bernilai X */
/* maka yang dihapus hanya elemen pertama dengan Info = X */
/* Jika tidak ada elemen list dengan InfoList(P)=X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */
    if (!IsEmptyList(*L)){
        if (InfoList(FirstList(*L)) == X){
            addressList P = FirstList(*L);
            FirstList(*L) = NextList(P);
            NextList(P) = Nil;
            free(P);
        }
        else{
            addressList P = FirstList(*L);
            while (NextList(P) != Nil && InfoList(NextList(P)) != X){
                P = NextList(P);
            }
            if (NextList(P) != Nil){
                addressList P1 = NextList(P);
                NextList(P) = NextList(P1);
                NextList(P1) = Nil;
                free(P1);
            }
        }
    }
}

void DelLast (List *L, addressList *P){
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen terakhir yg lama, */
/* jika ada */
    if (NbElmt(*L) == 1){
        *P = FirstList(*L);
        FirstList(*L) = Nil;
    }
    else{
        addressList P1 = FirstList(*L);
        while (NextList(NextList(P1)) != Nil){
            P1 = NextList(P1);
        }
        *P = NextList(P1);
        NextList(P1) = Nil;
    }
}

void DelAfter (List *L, addressList *Pdel, addressList Prec){
/* I.S. List tidak kosong. Prec adalah anggota list  */
/* F.S. Menghapus NextList(Prec): */
/*      Pdel adalah alamat elemen list yang dihapus  */
    *Pdel = NextList(Prec);
    NextList(Prec) = NextList(*Pdel);
    NextList(*Pdel) = Nil;
}

/****************** PROSES SEMUA ELEMEN LIST ******************/
void PrintInfo (List L){
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, iai list dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
    printf("[");
    addressList P = FirstList(L);
    if (P != Nil){
        printf("%d", InfoList(P));
        P = NextList(P);
    }
    while (P != Nil){
        printf(",%d", InfoList(P));
        P = NextList(P);
    }
    printf("]");
}

int NbElmt (List L){
/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */
    int sum = 0;
    addressList P = FirstList(L);
    while (P != Nil){
        sum++;
        P = NextList(P);
    }
    return sum;
}

/*** Prekondisi untuk Min: List tidak kosong ***/
infotypeList Min (List L){
/* Mengirimkan nilai InfoList(P) yang minimum */
    addressList P = FirstList(L);
    infotypeList min = InfoList(P);
    while (P != Nil){
        if (InfoList(P) < min){
            min = InfoList(P);
        }
        P = NextList(P);
    }
    return min;
}

/*** Prekondisi untuk Max: List tidak kosong ***/
infotypeList Max (List L){
/* Mengirimkan nilai InfoList(P) yang maksimum */
    addressList P = FirstList(L);
    infotypeList max = InfoList(P);
    while (P != Nil){
        if (InfoList(P) > max){
            max = InfoList(P);
        }
        P = NextList(P);
    }
    return max;
}

/****************** PROSES TERHADAP LIST ******************/
void Konkat1 (List *L1, List *L2, List *L3){
/* I.S. L1 dan L2 sembarang */
/* F.S. L1 dan L2 kosong, L3 adalah hasil konkatenasi L1 & L2 */
/* Konkatenasi dua buah list : L1 dan L2    */
/* menghasilkan L3 yang baru (dengan elemen list L1 dan L2) */
/* dan L1 serta L2 menjadi list kosong.*/
/* Tidak ada alokasi/dealokasi pada prosedur ini */
    if (IsEmptyList(*L1)){
        FirstList(*L3) = FirstList(*L2);
    }
    else{
        FirstList(*L3) = FirstList(*L1);
        InsertLast(L3, FirstList(*L2));
    }
    FirstList(*L1) = Nil;
    FirstList(*L2) = Nil;
}
