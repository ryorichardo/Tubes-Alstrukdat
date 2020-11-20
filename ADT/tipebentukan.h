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

typedef struct {
    Kata Nama;
    int Harga;
} Material;

// Selektor
#define Nama(P) (P.Nama).TabKata 
#define Harga(P) P.Harga 
#define Kapasitas(P) P.Kapasitas
#define Pemain(P) P.Pemain
#define Durasi(P) P.Durasi
#define HargaBuild(P) P.HargaBuild
#define DurasiBuild(P) P.DurasiBuild
#define Deskripsi(P) P.Deskripsi 
#define Point(P) P.Point
#define Rusak(P) P.Rusak

#endif