#include <stdio.h>
#include "array.h"

int main(){
    Wahana ListWahana[100];
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
    MakeTabWahanaEmpty(ListWahana, 100);
    PrintKata(ListWahana[0].Nama); printf("\n");
    printf("%d\n", ListWahana[0].Harga);
    PrintKata(ListWahana[99].Nama); printf("\n");
    printf("%d\n", ListWahana[99].Harga);
    Wahana W = MakeWahana(nama, 200, 10, 0, 30, 100, 60, Mat, nama, Ukuran, 1, Point, false);
    ListWahana[0] = W;
    printf("Banyaknya wahana = %d\n", NbElmtTabWahana(ListWahana));
    PrintListWahana(ListWahana);
    Wahana Wnew = MakeWahana(new, 200, 10, 0, 30, 100, 60, Mat, new, Ukuran, 1, Point, false);
    AddWahana(ListWahana, Wnew);
    printf("Banyaknya wahana = %d\n", NbElmtTabWahana(ListWahana));
    PrintListWahana(ListWahana);

    Wahana Wsearch = SearchWahana(ListWahana, new);
    printf("Wahana yang dicari adalah : "); PrintKata(Wsearch.Nama);
    printf("\n");

    PrintDetailWahana(ListWahana, new);
    return 0;
}