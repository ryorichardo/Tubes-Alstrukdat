#include <stdio.h>
#include "../ADT/Matriks/matriks.h"
#include "../ADT/Point/point.h"
#include "../ADT/Graph/graph.h"
#include "PetaWahana.h"

void MakeMap(Graph *G, MATRIKS *M)
{
  char filename[] = "File-Eksternal/map1.txt";
  BacaMATRIKS(G, M, 12, 12, filename);
  G++;
  M++;
  char filename2[] = "File-Eksternal/map2.txt";
  BacaMATRIKS(G, M, 12, 12, filename2);
  G++;
  M++;
  char filename3[] = "File-Eksternal/map3.txt";
  BacaMATRIKS(G, M, 12, 12, filename3);
  G++;
  M++;
  char filename4[] = "File-Eksternal/map4.txt";
  BacaMATRIKS(G, M, 12, 12, filename4);
  G++;
  M++;
  char filename8[] = "File-Eksternal/saveMap.txt";
  BacaMATRIKS(G, M, 12, 12, filename8);
  G++;
  M++;
  // posisi Map:
  // 0 1
  // 2 3
  // Kalo ketemu simbol '>' maka idx matriks +1
  // Kalo '<' -1
  // Kalo '^' -2
  // Kalo 'v' +2
}

void A(Graph G[5], POINT *P, MATRIKS *M, MATRIKS *MK, int *idxmap)
{
  //MK itu arrray of matriks (isi map 1 sampe 4)
  //G itu list graph dri masing2 map
  //map itu index map

  //Cek Posisi sebelum pindah
  if (Absis(*P) == 9 && Ordinat(*P) == 9 && *idxmap == 0)
  {
    Elmt(*M, Absis(*P), Ordinat(*P)) = 'O';
  }
  else
  {
    Elmt(*M, Absis(*P), Ordinat(*P)) = '-';
  }
  // Cek posisi setelah pindah
  if (Elmt(*M, Absis(*P), Ordinat(*P) - 1) == '-' || Elmt(*M, Absis(*P), Ordinat(*P) - 1) == 'O')
  {
    Ordinat(*P) = Ordinat(*P) - 1;
  }

  else if (Elmt(*M, Absis(*P), Ordinat(*P) - 1) == '<')
  {
    CopyMATRIKS(*M, MK + *idxmap);
    *idxmap -= 1;
    CopyMATRIKS(*(MK + *idxmap), M);

    adrNode T = SearchOrdinat(G[*idxmap], 11);
    Absis(*P) = Absis(Id(T));
    Ordinat(*P) = Ordinat(Id(T)) - 1;
  }

  else
  {
    printf("Operasi tidak dapat dilakukan\n");
  }
  Elmt(*M, Absis(*P), Ordinat(*P)) = 'P';
}

void W(Graph G[5], POINT *P, MATRIKS *M, MATRIKS *MK, int *idxmap)
{
  //Cek Posisi sebelum pindah
  if (Absis(*P) == 9 && Ordinat(*P) == 9 && *idxmap == 0)
  {
    Elmt(*M, Absis(*P), Ordinat(*P)) = 'O';
  }
  else
  {
    Elmt(*M, Absis(*P), Ordinat(*P)) = '-';
  }
  //Cek Posisi setelah pindah
  if (Elmt(*M, Absis(*P) - 1, Ordinat(*P)) == '-' || Elmt(*M, Absis(*P) - 1, Ordinat(*P)) == 'O')
  {
    Absis(*P) = Absis(*P) - 1;
  }

  else if (Elmt(*M, Absis(*P) - 1, Ordinat(*P)) == '^')
  {
    CopyMATRIKS(*M, MK + *idxmap);
    *idxmap -= 2;
    CopyMATRIKS(*(MK + *idxmap), M);
    adrNode T = SearchAbsis(G[*idxmap], 11);
    Absis(*P) = Absis(Id(T)) - 1;
    Ordinat(*P) = Ordinat(Id(T));
  }

  else
  {
    printf("Operasi tidak dapat dilakukan\n");
  }
  Elmt(*M, Absis(*P), Ordinat(*P)) = 'P';
}

void D(Graph G[5], POINT *P, MATRIKS *M, MATRIKS *MK, int *idxmap)
{
  //Cek Jalan atau Gedung atau Tembok
  if (Absis(*P) == 9 && Ordinat(*P) == 9 && *idxmap == 0)
  {
    Elmt(*M, Absis(*P), Ordinat(*P)) = 'O';
  }
  else
  {
    Elmt(*M, Absis(*P), Ordinat(*P)) = '-';
  }

  if (Elmt(*M, Absis(*P), Ordinat(*P) + 1) == '-' || Elmt(*M, Absis(*P), Ordinat(*P) + 1) == 'O')
  {
    Ordinat(*P) = Ordinat(*P) + 1;
  }

  else if (Elmt(*M, Absis(*P), Ordinat(*P) + 1) == '>')
  {
    CopyMATRIKS(*M, MK + *idxmap);
    *idxmap += 1;
    CopyMATRIKS(*(MK + *idxmap), M);

    adrNode T = SearchOrdinat(G[*idxmap], 0);

    Absis(*P) = Absis(Id(T));
    Ordinat(*P) = Ordinat(Id(T)) + 1;
  }

  else
  {
    printf("Operasi tidak dapat dilakukan\n");
  }
  Elmt(*M, Absis(*P), Ordinat(*P)) = 'P';
}
void S(Graph G[5], POINT *P, MATRIKS *M, MATRIKS *MK, int *idxmap)
{
  //Cek Jalan atau Gedung atau Tembok
  if (Absis(*P) == 9 && Ordinat(*P) == 9 && *idxmap == 0)
  {
    Elmt(*M, Absis(*P), Ordinat(*P)) = 'O';
  }
  else
  {
    Elmt(*M, Absis(*P), Ordinat(*P)) = '-';
  }

  if (Elmt(*M, Absis(*P) + 1, Ordinat(*P)) == '-' || Elmt(*M, Absis(*P) + 1, Ordinat(*P)) == 'O')
  {
    Absis(*P) = Absis(*P) + 1;
  }
  else if (Elmt(*M, Absis(*P) + 1, Ordinat(*P)) == 'v')
  {
    CopyMATRIKS(*M, MK + *idxmap);
    *idxmap += 2;
    CopyMATRIKS(*(MK + *idxmap), M);
    adrNode T = SearchAbsis(G[*idxmap], 0);
    Absis(*P) = Absis(Id(T)) + 1;
    Ordinat(*P) = Ordinat(Id(T));
  }

  else
  {
    printf("Operasi tidak dapat dilakukan\n");
  }
  Elmt(*M, Absis(*P), Ordinat(*P)) = 'P';
}
