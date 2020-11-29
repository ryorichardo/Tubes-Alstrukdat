#ifndef tipe_bentukan_H
#define tipe_bentukan_H

#include "Jam/jam.h"
#include "Point/point.h"
#include "boolean.h"
#include "Matriks/matriks.h"

#define NMax 50
#define BLANK ' '

typedef struct
{
    char TabKata[NMax]; /* container penyimpan kata, indeks yang dipakai [0..NMax-1] */
    int Length;
} Kata;

#define String(K) K.TabKata

// Tipe
typedef struct
{
    Kata Nama;       //nama wahana
    int Harga;       //harga main
    int Kapasitas;   //kapasitas maksimum
    int Pemain;      //jumlah pemain
    int Durasi;      //durasi main dlm menit
    int HargaBuild;  //harga build
    int DurasiBuild; //durasi build dlm menit
    int Mat[3];      //material buat build
    Kata Deskripsi;
    POINT Ukuran;
    int Peta;
    POINT Point; // buat lokasi wahana
    boolean Rusak;
} Wahana; //upgrade samain aja adtnya

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

typedef struct
{
    Kata Nama;
    int Harga;
} Material;

typedef struct
{
    Kata Player;
    int Day;
    int Money;
    int Close;
    int Banyak;
    int Absis;
    int Ordinat;
    // MATRIKS CurrentMap;
    // JAM CurrentTime;
} Save;

// Selektor
#define Nama(P) (P.Nama)
#define Harga(P) P.Harga
#define Kapasitas(P) P.Kapasitas
#define Pemain(P) P.Pemain
#define Durasi(P) P.Durasi
#define HargaBuild(P) P.HargaBuild
#define DurasiBuild(P) P.DurasiBuild
#define Deskripsi(P) P.Deskripsi
#define Point(P) P.Point
#define Rusak(P) P.Rusak
#define Wood(P) P.Mat[0]
#define Fire(P) P.Mat[1]
#define Primogem(P) P.Mat[2]
#define IndexPeta(P) P.Peta
#define PanjangWahana(P) (P.Ukuran).X
#define LebarWahana(P) (P.Ukuran).Y
#define Daftar(P) (P.*Q).Main

#endif
