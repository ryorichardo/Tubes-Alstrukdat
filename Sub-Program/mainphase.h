#ifndef mainphase_H
#define mainphase_H

#include "../ADT/stackt.h"
#include "../ADT/array.h"
#include "../ADT/point.h"
#include "../ADT/mesinkata.h"
#include "../ADT/prioqueuechar.h"
#include "../ADT/listlinier.h"
#include "../ADT/tipebentukan.h"
#include "../ADT/array.h"

void Assign(Kata * Wahana1, Kata * Wahana2, Kata * Wahana3);

void CustomA(Antrian * CustomerA, Kata Wahana1, Kata Wahana2, Kata Wahana3);

void CustomB(Antrian * CustomerB, Kata Wahana1, Kata Wahana2, Kata Wahana3);

void CustomC(Antrian * CustomerC, Kata Wahana1, Kata Wahana2, Kata Wahana3);

void CustomD(Antrian * CustomerD, Kata Wahana1, Kata Wahana2, Kata Wahana3);

void CustomE(Antrian * CustomerE, Kata Wahana1, Kata Wahana2, Kata Wahana3);

void Serve(Wahana ArrayWahana[100], Kata NamaWahana, int * Uang, PrioQueueChar *Customer, JAM *CurrentTime, int Banyak);

void Repair(Wahana ArrayWahana[100], Kata NamaWahana, JAM *CurrentTime);

void Detail(Wahana ArrayWahana[100], Kata NamaWahana);
// Program
void Office(Wahana ArrayWahana[100], TabLaporan TL);

void Prepare(boolean * isMain, PrioQueueChar * Customer, int Banyak);

void RandomAntrian(int Banyak, PrioQueueChar * Customer, Antrian CustomerA, Antrian CustomerB, Antrian CustomerC, Antrian CustomerD, Antrian CustomerE);

void PrintAntrian(int Banyak, PrioQueueChar Customer);

#endif