#include "tree.h"
#include "../Array/array.h"
#include "../Mesinkata/mesinkata.h"
#include <stdio.h>

int main(){
    Wahana A, B, C;
    int Mat[3];
    Mat[0] = 15;
    Mat[1] = 10;
    Mat[2] = 10;
    POINT Ukuran = MakePOINT(2, 2);
    POINT Point = MakePOINT(0,0);
    Kata nama;
    Kata Empty;
    Kata new;
    MakeKataEmpty(&Empty);
    MakeKataBuild(&nama);
    MakeKataNew(&new);
    A = MakeWahana(nama, 200, 10, 0, 30, 100, 60, Mat, nama, Ukuran, 1, Point, false);
    B = MakeWahana(new, 200, 10, 0, 30, 100, 60, Mat, new, Ukuran, 1, Point, false);
    C = MakeWahana(Empty, 200, 10, 0, 30, 100, 60, Mat, Empty, Ukuran, 1, Point, false);
    printf("Nama wahana A : ");
    PrintKata(A.Nama); printf("\n");

    BinTree P, L = AlokNode(A), R = AlokNode(B);
    MakeTree(A, L, R, &P);
    printf("Harga wahana pada akar pohon (wahana A) : %d\n", Akar(P).Harga);
    printf("IsTreeEmpty : %d\n", IsTreeEmpty(P));
    printf("IsTreeOneElmt : %d\n", IsTreeOneElmt(P));
    printf("IsUnerLeft : %d\n", IsUnerLeft(P));
    printf("IsUnerRight : %d\n", IsUnerRight(P));
    printf("IsBiner : %d\n", IsBiner(P));
    return 0;
}
