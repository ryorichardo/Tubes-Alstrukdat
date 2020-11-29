#include "stdio.h"
#include <stdlib.h>
#include "prioqueuechar.h"

int main()
{
    int Banyak, count;
    int i = 0;
    Kata Nama;
    int kesabaran;

    PrioQueueChar Q;
    Pengunjung P;
    Antrian A;
    P.Nama = Nama;
    P.Kesabaran = 1;

    A.prio = 1;
    A.info = P;
    PrioQueueChar Customer;

    Enqueue(&Customer, A);
    PrintQueue(Q);
    Dequeue(&Customer, &A);
}