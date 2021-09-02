#ifndef GRAPH_H
#define GRAPH_H

/**
 * Graph (Connected set of vertices):
 * Properties:
 * - Vertices : Set of vertices
 **/
typedef struct graph Graph;

// Gets & Sets

/* RETORNA NÚMERO DE VÉRTICES DO GRAFO
INPUTs: Grafo a ser analisado
OUTPUTs: Número de vértices
Pré-condição: Grafo existe
Pós-condição: -
*/
int getGraphNumVertices(Graph* graph);

/* DEFINE NÚMERO DE VÉRTICES DO GRAFO
INPUTs: Grafo e número de vértices do grafo
OUTPUTs: -
Pré-condição: Grafo existe
Pós-condição: Número de vértices atualizado
*/
void setGraphNumVertices(Graph* graph, int num);

/* DEFINE UMA CATEGORIA PARA O ELEMENTO DO GRAFO:
INPUTs: Grafo, Índice do vértice a ser categorizado, Categoria
OUTPUTs: -
Pré-condição: Grafo existe
Pós-condição: Vértice possui a categoria especificada
*/
void setGraphVertexLabel(Graph* graph, Idx vertex, char label);

/* RETORNA A CATEGORIA DE UM VÉRTICE DO GRAFO:
INPUTs: Grafo, Índice do vértice
OUTPUTs: Categoria do vértice especificado
Pré-condição: Grafo existe
Pós-condição: -
*/
char getGraphVertexLabel(Graph* graph, Idx vertex);

/* RETORNA UM VÉRTICE COM ÍNDICE ESPECIFICA:
INPUTs: Grafo, Índice do vértice
OUTPUTs: Vértice especificado
Pré-condição: Grafo existe
Pós-condição: -
*/
Vertex* getGraphVertex(Graph* graph, Idx vertex);

// Methods

/* INICIALIZA GRAFO
INPUTs: Número de vértices do grafo
OUTPUTs: Grafo inicializado
Pré-condição: Grafo não existe
Pós-condição: Grafo existe
*/
Graph* graphInit(int numVertices);

/* INSERE CONEXÃO NO GRAFO
INPUTs: Grafo, Primeiro vértice da conexão, Segundo vértice da conexão, Distância entre os vértices
OUTPUTs: -
Pré-condição: Os dois vértices estão desconectados
Pós-condição: Os dois vértices estão conectados
*/
void graphInsertConnection(Graph* graph, Idx vertexA, Idx vertexB, Weight distance);

/* REMOVE GRAFO
INPUTs: Grafo a ser removido
OUTPUTs: -
Pré-condição: Grafo existe
Pós-condição: Grafo não existe
*/
void graphDelete(Graph* graph);

/* EXIBE GRAFO NA SAÍDA ESPECIFICADA
INPUTs: Endereço de saída e Grafo
OUTPUTs: -
Pré-condição: Grafo existe
Pós-condição: -
*/
void graphShow(FILE* output, Graph* graph);

#endif /* GRAPH_H */