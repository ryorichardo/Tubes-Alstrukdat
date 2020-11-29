#include "stdio.h"
#include "../boolean.h"
#include <stdlib.h>
#include "prioqueuechar.h"

/* ********* Prototype ********* */
boolean IsEmpty(PrioQueueChar Q)
/* Mengirim true jika Q kosong: lihat definisi di atas */
{
    return ((Head(Q) == -1) && (Tail(Q) == -1));
}
boolean IsFull(PrioQueueChar Q)
/* Mengirim true jika tabel penampung elemen Q sudah penuh */
/* yaitu mengandung elemen sebanyak MaxEl */
{
    if (Head(Q) > Tail(Q))
    {
        return (Head(Q) - Tail(Q) == 1);
    }
    else
    {
        return (Tail(Q) - Head(Q) == MaxEl(Q) - 1);
    }
}
int NBElmt(PrioQueueChar Q)
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong. */
{
    if (Head(Q) == -1 && Tail(Q) == -1)
    {
        return 0;
    }
    else
    {
        if (Head(Q) <= Tail(Q))
        {
            return ((1 + Tail(Q)) - Head(Q));
        }
        else
        {
            return ((MaxEl(Q) + 1 + Tail(Q)) - Head(Q));
        }
    }
}
/* *** Kreator *** */
void MakeEmpty(PrioQueueChar *Q, int Max)
/* I.S. sembarang */
/* F.S. Sebuah Q kosong terbentuk dan salah satu kondisi sbb: */
/* Jika alokasi berhasil, Tabel memori dialokasi berukuran Max */
/* atau : jika alokasi gagal, Q kosong dg MaxEl=0 */
/* Proses : Melakukan alokasi, membuat sebuah Q kosong */
{
    (*Q).T = (Antrian *)malloc((Max + 1) * sizeof(Antrian));
    if ((*Q).T != NULL)
    {
        MaxEl(*Q) = Max;
        Head(*Q) = -1;
        Tail(*Q) = -1;
    }
    else /* alokasi gagal */
    {
        MaxEl(*Q) = 0;
    }
}
/* *** Destruktor *** */
void DeAlokasi(PrioQueueChar *Q)
/* Proses: Mengembalikan memori Q */
/* I.S. Q pernah dialokasi */
/* F.S. Q menjadi tidak terdefinisi lagi, MaxEl(Q) diset 0 */
{
    MaxEl(*Q) = 0;
    free((*Q).T);
}
/* *** Primitif Add/Delete *** */
void Enqueue(PrioQueueChar *Q, Antrian X)
/* Proses: Menambahkan X pada Q dengan aturan priority queue, terurut mengecil berdasarkan prio */
/* I.S. Q mungkin kosong, tabel penampung elemen Q TIDAK penuh */
/* F.S. X disisipkan pada posisi yang tepat sesuai dengan prioritas,
        TAIL "maju" dengan mekanisme circular buffer; */
{
    if (IsEmpty(*Q))
    {
        Head(*Q) = 1;
        Tail(*Q) = 1;
        InfoTail(*Q) = X;
    }
    else
    {
        int repeat = NBElmt(*Q);
        int idx = Tail(*Q);

        while ((Prio(X) < Prio(Elmtd(*Q, idx))) && (repeat > 0))
        {
            (*Q).T[(idx % MaxEl(*Q)) + 1] = (*Q).T[idx];

            idx--;
            repeat--;

            if (idx == 0)
            {
                idx = MaxEl(*Q);
            }
        }

        (*Q).T[(idx % MaxEl(*Q)) + 1] = X;
        Tail(*Q) = (Tail(*Q) % MaxEl(*Q)) + 1;
    }
}
void Dequeue(PrioQueueChar *Q, Antrian *X)
/* Proses: Menghapus X pada Q dengan aturan FIFO */
/* I.S. Q tidak mungkin kosong */
/* F.S. X = -1ai elemen HEAD pd I.S., HEAD "maju" dengan mekanisme circular buffer;
        Q mungkin kosong */
{
    *X = InfoHead(*Q);
    if (Head(*Q) == Tail(*Q))
    { /* Set mjd queue kosong */
        Head(*Q) = -1;
        Tail(*Q) = -1;
    }
    else if (Head(*Q) == (MaxEl(*Q) - 1))
    {
        Head(*Q) = 0;
    }
    else
    {
        Head(*Q) += 1;
    }
}
/* Operasi Tambahan */
void PrintQueue(PrioQueueChar Q)
/* Mencetak isi queue Q ke layar */
/* I.S. Q terdefinisi, mungkin kosong */
/* F.S. Q tercetak ke layar dengan format:
<prio-1> <elemen-1>
...
<prio-n> <elemen-n>
#
*/
{
    Antrian A;
    int temp;
    temp = Head(Q);
    while (Head(Q) <= Tail(Q))
    {
        printf("(");
        PrintKata(Main(Q, Head(Q)));
        for (int j = 1; j < 10; j++)
        {
            if (Main(Q, j).TabKata[0] != '\0')
            {
                printf(", ");
                PrintKata(Main(Q, j));
            }
        }
        printf("), kesabaran: %d //", Info(Elmtd(Q, Head(Q))).Kesabaran);
        PrintKata(Info(Elmtd(Q, Head(Q))).Nama);
        printf("\n");
        Head(Q) += 1;
    }
    Head(Q) = temp;
}
