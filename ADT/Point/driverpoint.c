#include "point.h"
#include <stdio.h>

int main(){
    POINT P1 = MakePOINT(0,0);
    POINT P2 = MakePOINT(3,4);
    printf("Point P1 adalah (%d,%d).\n", P1.X, P1.Y);
    printf("Point P2 adalah (%d,%d).\n", P2.X, P2.Y);
    printf("Jarak antara P1 dan P2 adalah %d\n", (int)Panjang(P1,P2));
    return 0;
}