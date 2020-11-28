#include <stdio.h>
#include "../ADT/matriks.h"
#include "../ADT/point.h"
#include "../ADT/graph.h"
#include "PetaWahana.h"

void MakeMap(Graph G[4], MATRIKS M[4])
{
  char filename[] = "File-Eksternal/map1.txt";
  BacaMATRIKS(&G[0], &M[0], 12, 12, filename);
  char filename2[] = "File-Eksternal/map2.txt";
  BacaMATRIKS(&G[1], &M[1], 12, 12, filename2);
  char filename3[] = "File-Eksternal/map3.txt";
  BacaMATRIKS(&G[2], &M[2], 12, 12, filename3);
  char filename4[] = "File-Eksternal/map4.txt";
  BacaMATRIKS(&G[3], &M[3], 12, 12, filename4);
  // posisi Map:
  // 0 1
  // 2 3
  // Kalo ketemu simbol '>' maka idx matriks +1
  // Kalo '<' -1
  // Kalo '^' -2
  // Kalo 'v' +2
}

void W(Graph G[4], POINT P, MATRIKS * M, MATRIKS  MK[4], int idxmap)
{
  //MK itu arrray of matriks (isi map 1 sampe 4)
  //G itu list graph dri masing2 map
  //map itu index map

  //Cek Jalan atau Gedung atau Tembok
  if (Absis(P) == 9 && Ordinat(P) == 9 && idxmap == 0){
    Elmt(*M, Absis(P), Ordinat(P)) = 'O';
  }
  else{
    Elmt(*M, Absis(P), Ordinat(P)) = '-';
  }
  if (Elmt(*M, Absis(P), Ordinat(P) - 1) == '-'|| Elmt(*M, Absis(P) + 1, Ordinat(P)) == 'O')
  {
    Ordinat(P) = Ordinat(P) - 1;
  }

  else if (Elmt(*M, Absis(P), Ordinat(P) - 1) == '^')
  {
    CopyMATRIKS(*M, &MK[idxmap]);
    idxmap -= 2;
    *M = MK[idxmap];
    adrNode T = SearchOrdinat(G[idxmap], 11);
    Ordinat(Id(T))--;
    P = Id(T);
  }

  else
  {
    printf("Operasi tidak dapat dilakukan\n");
  }
  Elmt(*M, Absis(P), Ordinat(P)) = 'P';
}

void A(Graph G[4], POINT P, MATRIKS * M, MATRIKS  MK[4], int idxmap)
{
  //Cek Jalan atau Gedung atau Tembok
  if (Absis(P) == 9 && Ordinat(P) == 9 && idxmap == 0){
    Elmt(*M, Absis(P), Ordinat(P)) = 'O';
  }
  else{
    Elmt(*M, Absis(P), Ordinat(P)) = '-';
  }
  if (Elmt(*M, Absis(P) - 1, Ordinat(P)) == '-'|| Elmt(*M, Absis(P) + 1, Ordinat(P)) == 'O')
  {
    Absis(P) = Absis(P) - 1;
  }

  else if (Elmt(*M, Absis(P) - 1, Ordinat(P)) == '<')
  {
    CopyMATRIKS(*M, &MK[idxmap]);
    idxmap -= 1;
    *M = MK[idxmap];
    adrNode T = SearchAbsis(G[idxmap], 11);
    Absis(Id(T))--;
    P = Id(T);
  }

  else
  {
    printf("Operasi tidak dapat dilakukan\n");
  }
  Elmt(*M, Absis(P), Ordinat(P)) = 'P';
}

void S(Graph G[4], POINT P, MATRIKS * M, MATRIKS  MK[4], int idxmap)
{
  //Cek Jalan atau Gedung atau Tembok
  if (Absis(P) == 9 && Ordinat(P) == 9 && idxmap == 0){
    Elmt(*M, Absis(P), Ordinat(P)) = 'O';
  }
  else{
    Elmt(*M, Absis(P), Ordinat(P)) = '-';
  }
  if (Elmt(*M, Absis(P), Ordinat(P) + 1) == '-'|| Elmt(*M, Absis(P) + 1, Ordinat(P)) == 'O')
  {
    Ordinat(P) = Ordinat(P) + 1;
  }

  else if (Elmt(*M, Absis(P), Ordinat(P) + 1) == 'v')
  {
    CopyMATRIKS(*M, &MK[idxmap]);
    idxmap += 2;
    *M = MK[idxmap];
    adrNode T = SearchOrdinat(G[idxmap], 0);
    Ordinat(Id(T))++;
    P = Id(T);
  }

  else
  {
    printf("Operasi tidak dapat dilakukan\n");
  }
  Elmt(*M, Absis(P), Ordinat(P)) = 'P';
}
void D(Graph G[4], POINT P, MATRIKS * M, MATRIKS  MK[4], int idxmap)
{
  //Cek Jalan atau Gedung atau Tembok
  if (Absis(P) == 9 && Ordinat(P) == 9 && idxmap == 0){
    Elmt(*M, Absis(P), Ordinat(P)) = 'O';
  }
  else{
    Elmt(*M, Absis(P), Ordinat(P)) = '-';
  }
  if (Elmt(*M, Absis(P) + 1, Ordinat(P)) == '-' || Elmt(*M, Absis(P) + 1, Ordinat(P)) == 'O')
  {
    Absis(P) = Absis(P) + 1;
  }

  else if (Elmt(*M, Absis(P) + 1, Ordinat(P)) == '>')
  {
    CopyMATRIKS(*M, &MK[idxmap]);
    idxmap += 1;
    *M = MK[idxmap];
    adrNode T = SearchAbsis(G[idxmap], 0);
    Absis(Id(T))++;
    P = Id(T);
  }

  else
  {
    printf("Operasi tidak dapat dilakukan\n");
  }
  Elmt(*M, Absis(P), Ordinat(P)) = 'P';
}
