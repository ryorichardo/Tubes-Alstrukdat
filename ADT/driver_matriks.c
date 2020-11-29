#include<stdio.h>
#include "matriks.h"

 int main () {
   int i,j;
   MATRIKS M,MCopy;
   MakeMATRIKS(12,12,&M);
   printf("%Baris : %d\n", NBrsEff(M));
   printf("%Kolom : %d\n", NKolEff(M));
   for (i = 0; i < NBrsEff(M); i++) {
     for (j = 0; j < NKolEff(M); j++) {
       if (i==0) {
         Elmt(M, i, j)='1';
       }
       else if (i==5) {
         Elmt(M, i, j)='2';
       }
       else if (i==11) {
         Elmt(M, i, j)='3';
       }
       else {
         Elmt(M, i, j)='-';
       }
     }
   }
   TulisMATRIKS(M);
   int a=15;
   int b=1;
   if (IsIdxEff(M,b,a)) {
     printf("Baris %d Kolom%d ", a,b);
     printf("efektif\n");
   }
   a=5;
   b=5;
   if (IsIdxEff(M,b,a)) {
     printf("Baris %d Kolom%d ", a,b);
     printf("efektif\n");
   }
   CopyMATRIKS(M,&MCopy);
   for (i=0;i<NBrsEff(M);i++) {
     printf("Elmt Diagonal-%d adalah %c\n", i,Elmt(M,i,i));
     Elmt(MCopy,i,i)='*';
   }
   TulisMATRIKS(MCopy);
   printf("First Idx Baris %d\n", GetFirstIdxBrs(M));
   printf("First Idx Kolom %d\n", GetFirstIdxKol(M));
   printf("Last Idx Baris %d\n", GetLastIdxBrs(M));
   printf("Last Idx Kolom %d\n", GetLastIdxBrs(M));
 }
