#ifndef tipe_bentukan_H
#define tipe_bentukan_H

#include "jam.h"
#include "mesinkata.h"
#include "point.h"
#include "boolean.h"

// Tipe
typedef struct {
    Kata Nama; //nama wahana
    int Harga; //harga main
    int Kapasitas; //kapasitas maksimum
    int Pemain; //jumlah pemain
    int Durasi; //durasi main dlm menit
    int HargaBuild; //harga build
    int DurasiBuild; //durasi build dlm menit
    int Mat[3]; //material buat build
    Kata Deskripsi;
    POINT Point; // buat lokasi wahana
    boolean Rusak;
} Wahana;  //upgrade samain aja adtnya

/* 
di file Wahana.txt ada:
Wahana
Tipe: Wahana
Format: Nama, Harga, Kapasitas, Durasi, HargaBuild, DurasiBuild,
        JmlWood, JmlFire, JmlPrimogem, Deskripsi.

Upgrade
Tipe: Wahana
Format: Nama, Harga, Kapasitas, HargaBuild,
        JmlWood, JmlFire, JmlPrimogem.
*/

typedef struct {
    Kata Nama;
    int Harga;
} Material;

// Selektor
#define Nama(P) (P->Nama).TabKata 
#define Harga(P) P->Harga 
#define Kapasitas(P) P->Kapasitas
#define Pemain(P) P->Pemain
#define Durasi(P) P->Durasi
#define HargaBuild(P) P->HargaBuild
#define DurasiBuild(P) P->DurasiBuild
#define Deskripsi(P) P->Deskripsi 
#define Point(P) P->Point
#define Rusak(P) P->Rusak
#define Wood(P) P->Mat[0]
#define Fire(P) P->Mat[1]
#define Primogem(P) P->Mat[2]

#endif