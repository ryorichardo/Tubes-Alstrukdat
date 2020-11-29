#include "tree.h"
#include <stdio.h>

int main(){
    Wahana A, B, C;
    A.Nama.TabKata[0] = 'A';
    B.Nama.TabKata[0] = 'B';
    C.Nama.TabKata[0] = 'C';
    BinTree P, L = AlokNode(A), R = AlokNode(B);
    MakeTree(A, L, R, &P);
    printf("%d\n", IsTreeEmpty(P));
    printf("%d\n", IsTreeOneElmt(P));
    printf("%d\n", IsUnerLeft(P));
    printf("%d\n", IsUnerRight(P));
    printf("%d\n", IsBiner(P));
    return 0;
}