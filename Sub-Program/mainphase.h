#ifndef mainphase_H
#define mainphase_H

#include "../ADT/stackt.h"
#include "../ADT/tipebentukan.h"
#include "../ADT/point.h"
#include "../ADT/mesinkata.h"

void Serve(Wahana * ArrayWahana[100], Kata NamaWahana, int Uang, Antrian Pengunjung[5]);

void Repair(Wahana * ArrayWahana[100], Kata NamaWahana);

void Detail(Wahana * ArrayWahana[100]);
// Program
void Office(Wahana * ArrayWahana[100]);

void Prepare();

#endif