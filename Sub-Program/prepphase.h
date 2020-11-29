#ifndef prepphase_H
#define prepphase_H

#include "../ADT/stackt.h"
#include "../ADT/tipebentukan.h"
#include "../ADT/point.h"
#include "../ADT/array.h"
#include "../ADT/mesinkata.h"
#include "../ADT/jam.h"
#include "../ADT/matriks.h"
#include "../ADT/listlinier.h"

extern long durasi;
extern long countaksi;
extern long totalbiaya;
extern long Sisa;

void Build(Stack *Perintah, Wahana ArrayWahana[10], Wahana ListOwnedWahana[10], POINT *Posisi_Player, MATRIKS *Peta, int idxpeta, int *Duit, int *Wood, int *Fire, int *Primogem);

// Program

void Upgrade(Stack * Perintah, Wahana ArrayUpgrade[100], Wahana DaftarUpgrade[10], POINT Posisi_Player, int * Duit, int *Wood, int *Fire, int *Primogem, int idxmap);

void Buy(Stack * Perintah, Material ArrayMat[3], int * Duit);

void Undo(Stack *Perintah,MATRIKS *Peta, int *Duit, int *Wood, int *Fire, int *Primogem, Wahana ListOwnedWahana[10]);

void Execute(Stack * Perintah, Wahana Wahanaskrg[100], TabLaporan *TL, Wahana DaftarWahana[10], Wahana DaftarUpgrade[10], int * Wood, int * Fire, int * Primogem, boolean * isMain, MATRIKS *Peta, POINT * Posisi, List UpWahana[100]);

void Mainphase(Stack * Perintah, boolean * isMain, Wahana ArrayWahana[10], int * Duit);
#endif
