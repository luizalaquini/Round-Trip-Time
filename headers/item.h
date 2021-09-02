#ifndef ITEM_H
#define ITEM_H

#include "vertex.h"

typedef struct {
  Idx    vertexId;     // identificador do nó
  Weight distance;     // valor associado ao nó
} Item;

#define id(A)          (A.vertexId)                     // retorna identificador do nó
#define value(A)        (A.distance)                    // retorna valor do nó
#define more(A, B)      (value(A) > value(B))           // compara nós, por valor
#define exch(A, B)      { Item t = A; A = B; B = t; }   // troca dois nós

#endif