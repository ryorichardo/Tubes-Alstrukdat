#include "listlinier.h"
#include <stdio.h>

int main(){
    List L;
    CreateEmptyList(&L);
    Kata Empty;
    Empty.TabKata[0] = 'e';
    Empty.TabKata[1] = 'm';
    Empty.TabKata[2] = 'p';
    Empty.TabKata[3] = 't';
    Empty.TabKata[4] = 'y';
    Empty.Length = 5;
    InsVLast(&L, Empty);
    PrintInfo(L);
    Kata Apa;
    Apa.TabKata[0] = 'a';
    Apa.TabKata[1] = 'p';
    Apa.TabKata[2] = 'a';
    Apa.Length = 3;
    PrintInfo(L);
    return 0;
}