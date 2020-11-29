#ifndef PetaWahana_H
#define PetaWahana_H

#include <stdio.h>
#include "../ADT/Matriks/matriks.h"
#include "../ADT/Point/point.h"
#include "../ADT/Graph/graph.h"

void MakeMap(Graph *G, MATRIKS *M);
void W(Graph G[4], POINT *P, MATRIKS *M, MATRIKS  *MK, int *idxmap);
void A(Graph G[4], POINT *P, MATRIKS *M, MATRIKS  *MK, int *idxmap);
void S(Graph G[4], POINT *P, MATRIKS *M, MATRIKS  *MK, int *idxmap);
void D(Graph G[4], POINT *P, MATRIKS *M, MATRIKS  *MK, int *idxmap);

#endif
