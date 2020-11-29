
#include "stdio.h"
#include "stackt.h"

int main()
{
    Stack A;
    Kata Target;
    POINT P = MakePOINT(1, 1);
    Element X, X1;

    scanf("%c", X.perintah);
    X.Target = Target;
    X.Point = P;
    scanf("%d", X.Biaya);
    scanf("%d", X.Wood);
    scanf("%d", X.Fire);
    scanf("%d", X.Primogem);
    scanf("%d", X.Durasi);

    Push(&A, X);
    POP(&A, &X1);
}