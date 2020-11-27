#ifndef prepphase_H
#define prepphase_H

#include "../ADT/stackt.h"
#include "../ADT/tipebentukan.h"
#include "../ADT/point.h"
#include "../ADT/array.h"
#include "../ADT/mesinkata.h"
#include "../ADT/jam.h"
#include "../ADT/matriks.h"

long durasi = 0;
long countaksi = 0;
long totalbiaya = 0;
long Sisa = 720;
void Build(Stack Perintah, Wahana ArrayWahana[10], POINT Posisi_Player, int Duit);
// Program

void Upgrade(Stack Perintah, Wahana ArrayUpgrade[100], Wahana DaftarUpgrade[10], POINT Posisi_Player, int Duit);

void Buy(Stack Perintah, Material *ArrayMat[3], int Duit);

void Undo(Stack Perintah, int Duit);

void Execute(Stack Perintah, Wahana Wahanaskrg[100], Wahana DaftarWahana[100], Wahana DaftarUpgrade[100], int Wood, int Fire, int Primogem, boolean isMain, MATRIKS * Peta);

void Main(Stack Perintah, boolean isMain);
#endif