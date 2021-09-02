#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../headers/vertex.h"
#include "../headers/graph.h"

struct graph {
    Vertex** vertices;
    char* labels; // Classes dos vértices ('s', 'c' ou 'm')
    int numVertices;
};

// Gets & Sets

int getGraphNumVertices(Graph* graph) {
    return graph->numVertices;
}

void setGraphNumVertices(Graph* graph, int num) {
    graph->numVertices = num;
}

void setGraphVertexLabel(Graph* graph, Idx vertex, char label) {
    graph->labels[vertex] = label;
}

char getGraphVertexLabel(Graph* graph, Idx vertex) {
    return graph->labels[vertex];
}

Vertex* getGraphVertex(Graph* graph, Idx vertex) {
    return graph->vertices[vertex];
}

// Methods

Graph* graphInit(int numVertices) {
    Graph* graph;
    graph = (Graph*)malloc(sizeof(Graph));
    graph->vertices = (Vertex**)malloc(sizeof(Vertex*) * numVertices);
    graph->labels = (char*)malloc(sizeof(char) * numVertices);
    setGraphNumVertices(graph, numVertices);

    // Initializing the vertices:
    for (int i = 0; i < graph->numVertices; i++) {
        graph->vertices[i] = vertexInit(i);
        graph->labels[i] = 'u'; // Label initial value is 'undefined'
    }

    return graph;
}

void graphInsertConnection(Graph* graph, Idx vertexA, Idx vertexB, Weight distance) {
    Vertex* vertexAPtr; // Pointer to vertex A
    vertexAPtr = graph->vertices[vertexA];

    vertexAddNeighbor(vertexAPtr, vertexB, distance);
}

void graphDelete(Graph* graph) {
    // Deleting each vertex:
    for (int i = 0; i < graph->numVertices; i++)
        vertexDelete(graph->vertices[i]);
    
    // Deleting the structure:
    free(graph->labels);
    free(graph->vertices);
    free(graph);
}

void graphShow(FILE* output, Graph* graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        vertexShow(output, graph->vertices[i]);
        fprintf(output, "\tLabel: '%c'\n\n", graph->labels[i]);
    }
}