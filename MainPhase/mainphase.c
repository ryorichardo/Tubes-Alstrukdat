#include "stdio.h"
#include "mainphase.h"

void Serve(Wahana ArrayWahana[100], Kata NamaWahana, int Uang){
    int i;

    /* Search Wahana */
    while (i < 100){
        if (Nama(ArrayWahana[i]) == String(NamaWahana)){
            break;
        }
        i++;
    }

    /* Kasus Wahana Rusak */
    if (Rusak(ArrayWahana[i])){
        printf("Maaf, wahana sedang maintenance, wahana tidak bisa digunakan.\n");
        /* Hapus antrian wahana dari customer */
        
        /* Kasus ga ada antrian wahana dari customer */

            /* Customer dihapus dari antrian (keluar dari antrian) */
    }
    /* Wahana aman */
    else if (Pemain(ArrayWahana[i]) == Kapasitas(ArrayWahana[i])){
        printf("Maaf, wahana sudah penuh.\n");
        /* Hapus antrian wahana dari customer */
        
        /* Kasus antrian wahana dari customer sudah habis */

            /* Customer dihapus dari antrian (keluar dari antrian) */
    }
    else {
        Uang += Harga(ArrayWahana[i]);
        /* Hapus antrian wahana dari customer */
        
        /* Kasus antrian wahana dari customer sudah habis */

            /* Customer dihapus dari antrian (keluar dari antrian) */
    }
}

void Repair(Wahana ArrayWahana[100], Kata NamaWahana){
    int i;

    /* Search Wahana */
    while (i < 100){
        if (Nama(ArrayWahana[i]) == String(NamaWahana)){
            /* Repair wahana */
            Rusak(ArrayWahana[i]) = false;
            break;
        }
        i++;
    } 
}

void Detail(Wahana ArrayWahana[100]){
}

void Prepare(boolean NextDay){
    NextDay = true;
}