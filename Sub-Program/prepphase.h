# ifndef prepphase_H
# define prepphase_H

#include "../ADT/stackt.h"
#include "../ADT/tipebentukan.h"
#include "../ADT/point.h"
#include "../ADT/array.h"
#include "../ADT/mesinkata.h"


void Build (Stack Perintah, Wahana ArrayWahana[100], POINT Posisi_Player, int Duit);
// Program 

void Upgrade (Stack Perintah, Wahana ArrayWahana[100], POINT Posisi_Player, int Duit);

void Buy (Stack Perintah, Material ArrayMat[3], int Duit);
# endif