#include <stdio.h>
#include <stdlib.h>
#include "../Mesinkata/mesinkata.h"
#include "../tipebentukan.h"
#include "../boolean.h"
#include "mesintoken.h"

/* State Mesin Kata */
boolean EndToken;
int CToken;

int main(){
    printf("Ketik token : ");
    STARTTOKEN(stdin);
    printf("CToken :\n");
    printf("%d", CToken);
    if (CC == MARK){
        printf("inputnya titik.\n");
    }
    else {
        while (CC != MARK){
            ADV();
            SalinToken();
            printf(", %d", CToken);
        }
    }     
}