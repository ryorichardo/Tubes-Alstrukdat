#include"matriks.h"
#include"point.h"
#include"graph.h"
#include <string.h>

void MakeMap(Graph G[4], MATRIKS M[4]){
  char filename[] = "map1.txt";
  BacaMATRIKS(&G[0], &M[0], 12, 12, filename);
  char filename[] = "map2.txt";
  BacaMATRIKS(&G[1], &M[1], 12, 12, filename);
  char filename[] = "map3.txt";
  BacaMATRIKS(&G[2], &M[2], 12, 12, filename);
  char filename[] = "map4.txt";
  BacaMATRIKS(&G[3], &M[3], 12, 12, filename);
  // posisi Map:
  // 1  2
  // 3  4
}

void W(POINT *P, MATRIKS M) {
  //Cek melewati batas map
  if (Ordinat(*P)-1<0) {
    printf("Operasi tidak dapat dilakukan\n");
    return ;
  }

  //Cek Jalan atau Gedung atau Tembok
  if (Elmt(M,Absis(*P),Ordinat(*P)-1)=='-') {
    Ordinat(*P)=Ordinat(*P)-1;
  }
  else {
    printf("Operasi tidak dapat dilakukan\n");
    return;
  }
}

void A(POINT *P, MATRIKS M) {
  //Cek melewati batas map
  if (Absis(*P)-1<0) {
    printf("Operasi tidak dapat dilakukan\n");
    return ;
  }

  //Cek Jalan atau Gedung atau Tembok
  if (Elmt(M,Absis(*P)-1,Ordinat(*P))=='-') {
    Absis(*P)=Absis(*P)-1;
  }
  else {
    printf("Operasi tidak dapat dilakukan\n");
    return;
  }
}
void S(POINT *P, MATRIKS M) {
  //Cek melewati batas map
  if (Ordinat(*P)+1<0) {
    printf("Operasi tidak dapat dilakukan\n");
    return ;
  }

  //Cek Jalan atau Gedung atau Tembok
  if (Elmt(M,Absis(*P),Ordinat(*P)+1)=='-') {
    Ordinat(*P)=Ordinat(*P)+1;
  }
  else {
    printf("Operasi tidak dapat dilakukan\n");
    return;
  }
}
void D(POINT *P, MATRIKS M){
  //Cek melewati batas map
  if (Absis(*P)+1<0) {
    printf("Operasi tidak dapat dilakukan\n");
    return ;
  }

  //Cek Jalan atau Gedung atau Tembok
  if (Elmt(M,Absis(*P)+1,Ordinat(*P))=='-') {
    Absis(*P)=Absis(*P)+1;
  }
  else {
    printf("Operasi tidak dapat dilakukan\n");
    return;
  }
}
