#ifndef VERTEX_H
#define VERTEX_H

/**
 * Vertex (Basic node of a graph)
 * Properties:
 * - Idx : Vertex ID in an array of vertices
 * - Visited : Boolean informed if this vertex has been visited (useful for Djikstra's algorithm)
 * - Adjacent : Set of adjacent vertices
 * - Weights : Set of weights, 1:1 correspondence with the 'Adjacent' set
 * - Previous : Previous Vertex (useful for Djikstra's algorithm)
 **/
typedef struct vertex Vertex;

typedef int Idx;
typedef double Weight;

// Idx id(Vertex* v);

// Weight value(Vertex* v);

void setValue(Vertex* v, Weight value);

// bool more(Vertex* a, Vertex* b);

// Gets & Sets

/* RETORNA ÍNDICE DO NÓ ATUAL
INPUTs: Nó a ser analisado
OUTPUTs: Índice do nó
Pré-condição: Nó deve existir
Pós-condição: - 
*/
Idx getVertexId(Vertex* vertex);

/* DEFINE ÍNDICE DO NÓ ATUAL
INPUTs: Nó a ser modificado
OUTPUTs: -
Pré-condição: Nó deve existir
Pós-condição: Índice do nó atualizado
*/
void setVertexId(Vertex* vertex, Idx id);

/* RETORNA SE O NÓ JÁ FOI VISITADO OU NÃO
INPUTs: Nó a ser analisado
OUTPUTs: True(1) or False(0)
Pré-condição: Nó deve existir
Pós-condição: - 
*/
bool getIfVertexWasVisited(Vertex* vertex);

/* DEFINE A CONDIÇÃO "VISITADO" AO NÓ
INPUTs: Nó a ser modificado
OUTPUTs: -
Pré-condição: Nó deve existir
Pós-condição: Nó possui condição "visitado" 
*/
void setVertexVisited(Vertex* vertex);

/* RETORNA O ÍNDICE DO NÓ ANTERIOR AO ATUAL
INPUTs: Nó atual
OUTPUTs: Índice do nó anterior ao nó atual
Pré-condição: Nó atual e anterior devem existir 
Pós-condição: - 
*/
Idx getVertexPrevious(Vertex* vertex);

/* DEFINE ÍNDICE DO NÓ ANTERIOR AO ATUAL
INPUTs: Nó atual
OUTPUTs: -
Pré-condição: Nó atual e anterior devem existir 
Pós-condição: Índice do nó anterior atualizado  
*/
void setVertexPrevious(Vertex* vertex, Idx previous);

/* RETORNA VETOR DE ADJACENTES DO NÓ
INPUTs: Nó a ser analisado
OUTPUTs: Vetor de adjacentes do nó
Pré-condição: Nó deve existir
Pós-condição: - 
*/
Idx* getVertexAdjacents(Vertex* vertex);

/* RETORNA VETOR DE "PESOS"(DISTÂNCIAS) DO NÓ PARA COM SEUS ADJACENTES
INPUTs: Nó a ser analisado
OUTPUTs: Vetor de "pesos"(distâncias) do nó para com seus adjacentes
Pré-condição: Nó deve existir
Pós-condição: - 
*/
Weight* getVertexWeights(Vertex* vertex);

/* RETORNA O PESO ("DISTÂNCIA") DO NÓ PARA UM DOS ADJACENTES
INPUTs: Nó a ser analisado, Idx do outro vértice
OUTPUTs: "Peso"(distância) do nó para com seu adjacente
Pré-condição: Nó deve existir
Pós-condição: - 
*/
Weight getVertexWeightToVertex(Vertex* vertex, Idx sndVertex);

/* RETORNA O VETOR "PESO"(DISTÂNCIAS) DO NÓ ATUAL
INPUTs: Nó a ser analisado, tamanho do vetor de distâncias
OUTPUTs: Vetor de "Peso"(distância) 
Pré-condição: Nó deve existir
Pós-condição: - 
*/
Weight* getVertexDistances(Vertex* vertex, int arrayLength);

/* RETORNA NÚMERO DE ADJACENTES DO NÓ
INPUTs: Nó a ser analisado
OUTPUTs: Número de adjacentes existentes
Pré-condição: Nó deve existir
Pós-condição: -
*/
int getVertexNumAdjacents(Vertex* vertex);

/* DEFINE NÚMERO DE ADJACENTES PARA O NÓ ATUAL
INPUTs: Nó atual e número de adjacentes
OUTPUTs: -
Pré-condição: Nó deve existir
Pós-condição: Número de adjacentes do nó atualizado
*/
void setVertexNumAdjacents(Vertex* vertex, int num);

/* RETORNA NÚMERO DE CAMINHOS ALOCADOS PARA O NÓ ATUAL
INPUTs: Nó a ser analisado
OUTPUTs: Número de caminhos alocados para o nó atual (máximo de adjacentes)
Pré-condição: Nó deve existir
Pós-condição: -
*/
int getVertexPatchesAllocated(Vertex* vertex);

/* DEFINE NÚMERO DE CAMINHOS ALOCADOS PARA O NÓ ATUAL
INPUTs: Nó aatual e número de caminhos
OUTPUTs: -
Pré-condição: Nó deve existir
Pós-condição: Número de caminhos para o nó atual atualizado
*/
void setVertexPatchesAllocated(Vertex* vertex, int num);

// Methods

/* INICIALIZA UM NÓ VAZIO
INPUTs: índice do nó a ser inicializado
OUTPUTs: nó inicializado
Pré-condição: Nó não existe
Pós-condição: Nó existe
*/
Vertex* vertexInit(Idx id);

/* APAGA UM NÓ EXISTENTE
INPUTs: nó a ser apagado
OUTPUTs: -
Pré-condição: Nó existe
Pós-condição: Nó não existe
*/
void vertexDelete(Vertex* vertex);

//void vertexShow(FILE* out, Vertex* vertex); ==>> p/ essa funcionar #include <stdio.h>

/* ADICIONA VIZINHO DO NÓ
INPUTs: nó atual, índice do vizinho e distância entre os dois (atual e vizinho)
OUTPUTs: -
Pré-condição: Nó atual e Vizinho existem
Pós-condição: Conjunto de condições atualizadas
*/
void vertexAddNeighbor(Vertex* vertex, Idx neighbor, Weight distance);

/* EXIBE VÉRTICE NA SAÍDA ESPECIFICADA
INPUTs: Saída, Vértice
OUTPUTs: -
Pré-condição: Vértice existe
Pós-condição: -
*/
void vertexShow(FILE* output, Vertex* vertex);

#endif /* VERTEX_H */