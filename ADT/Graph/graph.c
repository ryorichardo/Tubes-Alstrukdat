#include "../Graph/graph.h"
#include "../Point/point.h"
#include <stdlib.h>
#include <stdio.h>

/* ----- KONSTRUKTOR ----- */
void CreateGraph(infotypeGraph X, Graph *G)
{
	First(*G) = NilGraph;
	adrNode dummy;
	InsertNode(G, X, &dummy);
}

/* ----- MANAJEMEN MEMORI ----- */
adrNode AlokNodeGraph(infotypeGraph X)
{
	adrNode P = (adrNode)malloc(sizeof(NodeGraph));
	if (P != NilGraph)
	{
		Id(P) = X;
		NPred(P) = 0;
		Trail(P) = NilGraph;
		Next(P) = NilGraph;
	}
	return P;
}

void DeAlokNodeGraph(adrNode P)
{
	free(P);
}

adrSuccNode AlokSuccNode(adrNode Pn)
{
	adrSuccNode P = (adrSuccNode)malloc(sizeof(SuccNode));
	if (P != NilGraph)
	{
		Succ(P) = Pn;
		Next(P) = NilGraph;
	}
	return P;
}

void DealokSuccNode(adrSuccNode P)
{
	free(P);
}

/* ----- OPERASI GRAF ----- */
adrNode SearchAbsis(Graph G, int X)
{
	adrNode P = First(G);
	while (P != NilGraph)
	{
		if (Absis(Id(P)) == X)
			return P;
		else
			P = Next(P);
	}
	return P;
}

adrNode SearchOrdinat(Graph G, int Y)
{
	adrNode P = First(G);
	while (P != NilGraph)
	{
		if (Ordinat(Id(P)) == Y)
			return P;
		else
			P = Next(P);
	}
	return P;
}

void InsertNode(Graph *G, infotypeGraph X, adrNode *Pn)
{
	*Pn = AlokNodeGraph(X);
	adrNode P = First(*G);
	if (P == NilGraph)
		First(*G) = *Pn;
	else
	{
		while (Next(P) != NilGraph)
			P = Next(P);
		Next(P) = *Pn;
	}
}

// void InsertEdge(Graph *G, infotypeGraph prec, infotypeGraph succ)
// {
// 	if (SearchEdge(*G, prec, succ) == NilGraph)
// 	{
// 		adrNode Pn = SearchNode(*G, prec);
// 		if (Pn == NilGraph)
// 			InsertNode(G, prec, &Pn);
// 		adrNode Ps = SearchNode(*G, succ);
// 		if (Ps == NilGraph)
// 			InsertNode(G, succ, &Ps);

// 		adrSuccNode P = Trail(Pn);
// 		if (P == NilGraph)
// 			Trail(Pn) = AlokSuccNode(Ps);
// 		else
// 		{
// 			while (Next(P) != NilGraph)
// 				P = Next(P);
// 			Next(P) = AlokSuccNode(Ps);
// 		}
// 	}
// }

// infotypeGraph GetFirstSuccInfo(Graph G, infotypeGraph prec)
// {
// 	infotypeGraph fal;
// 	Absis(fal) = -1;
// 	Ordinat(fal) = -1;

// 	adrNode Pn = SearchNode(G, prec);
// 	if (Pn == NilGraph)
// 		return fal;

// 	adrSuccNode Ps = Trail(Pn);
// 	if (Ps == NilGraph)
// 		return fal;

// 	return Id(Succ(Ps));
// }
