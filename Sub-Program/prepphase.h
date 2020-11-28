#ifndef prepphase_H
#define prepphase_H

#include "../ADT/stackt.h"
#include "../ADT/tipebentukan.h"
#include "../ADT/point.h"
#include "../ADT/array.h"
#include "../ADT/mesinkata.h"
#include "../ADT/jam.h"
#include "../ADT/matriks.h"

extern long durasi;
extern long countaksi;
extern long totalbiaya;
extern long Sisa;

void Build(Stack * Perintah, Wahana ArrayWahana[10], POINT Posisi_Player, int * Duit);
// Program

void Upgrade(Stack * Perintah, Wahana ArrayUpgrade[100], Wahana DaftarUpgrade[10], POINT Posisi_Player, int * Duit);

void Buy(Stack * Perintah, Material ArrayMat[3], int * Duit);

void Undo(Stack * Perintah, int * Duit);

void Execute(Stack * Perintah, Wahana Wahanaskrg[100], Wahana DaftarWahana[10], Wahana DaftarUpgrade[10], int * Wood, int * Fire, int * Primogem, boolean * isMain, MATRIKS *Peta);

void Mainphase(Stack * Perintah, boolean * isMain, Wahana ArrayWahana[10], int * Duit);
#endif
