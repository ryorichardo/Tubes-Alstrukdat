#include "mesinkar.h"
#include "../boolean.h"
#include <stdio.h>
#include <stdlib.h>

char CC;
boolean EOP;
static FILE *pita;
static int retval;

int main(){
    printf("Ketik kalimat :\n");
    START(stdin);
    if (CC == MARK){
        printf("inputnya titik.\n");
    }
    else {
        printf("CC :\n");
        printf("%c", CC);
        ADV();
        while (CC != MARK){
            printf(", %c", CC);
            ADV();
        }
    }
}