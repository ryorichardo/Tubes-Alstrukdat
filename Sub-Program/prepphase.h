#ifndef prepphase_H
#define prepphase_H

#include "../ADT/stackt.h"
#include "../ADT/tipebentukan.h"
#include "../ADT/point.h"
#include "../ADT/array.h"
#include "../ADT/mesinkata.h"
#include "../ADT/jam.h"

<<<<<<< HEAD
void Build(Stack Perintah, Wahana ArrayWahana[100], POINT Posisi_Player, int Duit);
// Program
=======
long durasi = 0;
long countaksi = 0;
long totalbiaya = 0;
long Sisa = 720;
>>>>>>> e49e88144924c6d024848cc4ce8e073547c6b2c3

void Upgrade(Stack Perintah, Wahana ArrayUpgrade[100], POINT Posisi_Player, int Duit);

void Buy(Stack Perintah, Material ArrayMat[3], int Duit);

void Undo(Stack Perintah, int Duit);

void Execute(Stack Perintah, Wahana Wahanaskrg[100], Wahana DaftarWahana[100], Wahana DaftarUpgrade[100], int Wood, int Fire, int Primogem);

void Main(boolean isMain);
#endif