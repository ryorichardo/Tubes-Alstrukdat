/* Ryo Richardo */
/* 13519193 */
/* Realisasi Program Point */

#include "point.h"
#include <stdio.h>
#include <math.h>
#include "boolean.h"

/* *** DEFINISI PROTOTIPE PRIMITIF *** */
/* *** Konstruktor membentuk POINT *** */
POINT MakePOINT (float X, float Y){
/* Membentuk sebuah POINT dari komponen-komponennya */
    POINT P;
        Absis(P) = X;
        Ordinat(P) = Y;
        return P;
}

float Panjang (POINT P1, POINT P2){
/* Menghitung panjang garis yang dibentuk P1 dan P2 */
/* Perhatikanlah bahwa di sini spec fungsi kurang baik sebab menyangkut ADT Garis. */
/* Tuliskan spec fungsi yang lebih tepat. */
    return sqrt(((Absis(P1) - Absis(P2)) * (Absis(P1) - Absis(P2))) + ((Ordinat(P1) - Ordinat(P2)) * (Ordinat(P1) - Ordinat(P2))));
}