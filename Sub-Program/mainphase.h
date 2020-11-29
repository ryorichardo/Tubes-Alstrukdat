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

void InitCustomer(Antrian Pelanggan[25]);

void RandomAntrian(PrioQueueChar *Customer, Antrian Pelanggan[25], Wahana ArrayWahana[100], int *Banyak);

void Serve(Wahana ArrayWahana[100], Kata NamaWahana, int *Uang, PrioQueueChar *Customer, JAM *CurrentTime, int Banyak, TabLaporan *TL, boolean *isMain);

void Repair(Wahana ArrayWahana[100], Kata NamaWahana, JAM *CurrentTime);

void Detail(Wahana ArrayWahana[100], Kata NamaWahana,  List ListUpgradeOwnedWahana[100]);
// Program
void Office(Wahana ArrayWahana[100], TabLaporan TL);

void Prepare(boolean *isMain, PrioQueueChar *Customer);

void PrintAntrian(int Banyak, PrioQueueChar Customer);

void save(Kata Player, int day, int Money, JAM Close, int Banyak, int X, int Y);

void saveWahana(Wahana ListOwnedWahana[]);

#endif
