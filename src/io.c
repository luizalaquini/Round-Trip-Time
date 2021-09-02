#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../headers/vertex.h"
#include "../headers/graph.h"
#include "../headers/io.h"

Graph* fileToGraph(FILE* input) {
    // Leitura de V e E
    int V, E; // V : Número de vértices do grafo
              // E : Número de arestas do grafo
    fscanf(input, "%d %d", &V, &E);

    // Inicializando grafo
    Graph* graph;        
    graph = graphInit(V);

    // Leitura de S, C e M
    int S, C, M; // S : Número de servidores
                 // C : Número de clientes
                 // M : Número de monitores
    fscanf(input, "%d %d %d", &S, &C, &M);

    // Leitura dos servidores:
    Idx vertexId; // DUMMY | TODO: REPLACE IT
    for (int i = 0; i < S; i++) {
        fscanf(input, "%d", &vertexId);
        setGraphVertexLabel(graph, vertexId, 's');
    }

    // Leitura dos clientes:
    for (int i = 0; i < C; i++) {
        fscanf(input, "%d", &vertexId);
        setGraphVertexLabel(graph, vertexId, 'c');
    }

    // Leitura de monitores:
    for (int i = 0; i < M; i++) {
        fscanf(input, "%d", &vertexId);
        setGraphVertexLabel(graph, vertexId, 'm');
    }

    // Lendo as arestas:
    Idx vertexA, vertexB; Weight distance;
    for (int i = 0; i < E; i++) {
        fscanf(input, "%d %d %lf", &vertexA, &vertexB, &distance);
        graphInsertConnection(graph, vertexA, vertexB, distance);
    }

    // Leitura finalizada
    return graph;
}