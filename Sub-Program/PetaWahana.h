#ifndef PetaWahana_H
#define PetaWahana_H

#include <stdio.h>
#include "../ADT/matriks.h"
#include "../ADT/point.h"
#include "../ADT/graph.h"

void MakeMap(Graph G[4], MATRIKS M[4]);
void W(Graph G[4], POINT P, MATRIKS * M, MATRIKS  MK[4], int idxmap);
void A(Graph G[4], POINT P, MATRIKS * M, MATRIKS  MK[4], int idxmap);
void S(Graph G[4], POINT P, MATRIKS * M, MATRIKS  MK[4], int idxmap);
void D(Graph G[4], POINT P, MATRIKS * M, MATRIKS  MK[4], int idxmap);

#endif
