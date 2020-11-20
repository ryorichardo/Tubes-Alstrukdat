#include"matriks.h"
#include"point.h"

void W(POINT *P, MATRIKS M) {
  //Cek melewati batas map
  if (Ordinat(*P)-1<0) {
    printf("Operasi tidak dapat dilakukan\n");
    return ;
  }

  //Cek Jalan atau Gedung atau Tembok
  if (Elmt(M,Absis(P),Ordinat(P)-1)=='-') {
    Ordinat(*P)=Ordinat(*P)-1;
  }
  else {
    printf("Operasi tidak dapat dilakukan\n");
    return;
  }
}

void A(POINT P, MATRIKS M) {
  //Cek melewati batas map
  if (Absis(*P)-1<0) {
    printf("Operasi tidak dapat dilakukan\n");
    return ;
  }

  //Cek Jalan atau Gedung atau Tembok
  if (Elmt(M,Absis(P)-1,Ordinat(P))=='-') {
    Absis(*P)=Absis(*P)-1;
  }
  else {
    printf("Operasi tidak dapat dilakukan\n");
    return;
  }
}
void S(POINT P, MATRIKS M) {
  //Cek melewati batas map
  if (Ordinat(*P)+1<0) {
    printf("Operasi tidak dapat dilakukan\n");
    return ;
  }

  //Cek Jalan atau Gedung atau Tembok
  if (Elmt(M,Absis(P),Ordinat(P)+1)=='-') {
    Ordinat(*P)=Ordinat(*P)+1;
  }
  else {
    printf("Operasi tidak dapat dilakukan\n");
    return;
  }
}
void D(POINT P, MATRIKS M){
  //Cek melewati batas map
  if (Absis(*P)+1<0) {
    printf("Operasi tidak dapat dilakukan\n");
    return ;
  }

  //Cek Jalan atau Gedung atau Tembok
  if (Elmt(M,Absis(P)+1,Ordinat(P))=='-') {
    Absis(*P)=Absis(*P)+1;
  }
  else {
    printf("Operasi tidak dapat dilakukan\n");
    return;
  }
}
