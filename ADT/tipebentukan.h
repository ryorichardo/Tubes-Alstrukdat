#ifndef tipe_bentukan_H
#define tipe_bentukan_H

#include "jam.h"
#include "mesinkata.h"

// Tipe
typedef struct {
    Kata Nama; //nama wahana
    int ID;
    int Harga; //harga main
    int Kapasitas; //kapasitas
    int Durasi; //durasi main dlm menit
    int HargaBuild; //harga build
    int DurasiBuild; //durasi build dlm menit
    int Mat[3]; //material buat build
    Kata Deskripsi;
} Wahana;  //upgrade samain aja adtnya

typedef struct {
    Kata Nama;
    int Harga;
} Material;

// Selektor
#define Nama(P) P.Nama 
#define ID(P) P.ID
#define Harga(P) P.Harga 
#define Kapasitas(P) P.Kapasitas 
#define Durasi(P) P.Durasi
#define HargaBuild(P) P.HargaBuild
#define DurasiBuild(P) P.DurasiBuild
#define Deskripsi(P) P.Deskripsi 
#define HargaUp(P) P.HargaUp
#define Wood(P) P.Mat[0]
#define Fire(P) P.Mat[1]
#define Primogem(P) P.Mat[2]

#endif