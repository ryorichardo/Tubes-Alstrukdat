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