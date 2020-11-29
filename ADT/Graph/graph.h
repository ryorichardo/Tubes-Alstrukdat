#include "../Point/point.h"
#include "../boolean.h"

#ifndef GRAPH_H
#define GRAPH_H

#define NilGraph NULL

typedef POINT infotypeGraph;

typedef struct tNodeGraph *adrNode;
typedef struct tSuccNode *adrSuccNode;
typedef struct tNodeGraph
{
    infotypeGraph Id;
    int NPred;
    adrSuccNode Trail;
    adrNode Next;
} NodeGraph;
typedef struct tSuccNode
{
    adrNode Succ;
    adrSuccNode Next;
} SuccNode;

typedef struct
{
    adrNode First;
} Graph;

/* ----- SELEKTOR ----- */
#define First(G) (G).First
#define Id(Pn) (Pn)->Id
#define Trail(Pn) (Pn)->Trail
#define Succ(Pn) (Pn)->Succ
#define NPred(Pn) (Pn)->NPred
#define Next(Pn) (Pn)->Next

/* ----- KONSTRUKTOR ----- */
void CreateGraph(infotypeGraph X, Graph *G); // membuat graph baru

/* ----- MANAJEMEN MEMORI ----- */
adrNode AlokNodeGraph(infotypeGraph X); // mengembalikan hasil alokasi simpul
void DeAlokNodeGraph(adrNode P);        // mengembalikan simpul ke sistem
adrSuccNode AlokSuccNode(adrNode Pn);   // mengembalikan hasil alokasi succ simpul
void DealokSuccNode(adrSuccNode P);     // mengembalikan succ simpul ke sistem

/* ----- OPERASI GRAF ----- */
adrNode SearchAbsis(Graph G, int X);
adrNode SearchOrdinat(Graph G, int Y);
void InsertNode(Graph *G, infotypeGraph X, adrNode *Pn);           // memasang X ke akhir G
void InsertEdge(Graph *G, infotypeGraph prec, infotypeGraph succ); // memasang succ ke akhir prec
infotypeGraph GetFirstSuccInfo(Graph G, infotypeGraph prec);       // mencari info succ simpul pertama dari node

#endif
