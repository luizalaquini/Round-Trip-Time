#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include "../headers/vertex.h"

#define PATCHSIZE 5

/**
 * About "PATCHES"
 * 
 *   In order to reduce the number of reallocs necessary to include
 * every adjacent vertex id in the array, the program reallocs
 * PATCHSIZE positions of the array per time. Each set of new positions
 * is called a "patch".
 **/

struct vertex {
    Idx     id; // índice do nó atual
    bool    visited; // condição "visitado" -> auxiliar pro algoritmo de Dijkstra 
    Idx     previous; // índice do nó anterior
    Idx*    adjacent; // vetor de índices dos nós adjacentes
    Weight* weights; // vetor de distâncias("pesos") entre o nó atual e nós adjacentes
    int     numAdjacents; // número ATUAL de adjacentes 
    int     patchesAllocated; // número LIMITE de adjacentes do nó atual
    Weight  distance;
};

// Getters & Setters

Idx getVertexId(Vertex* vertex){
    return vertex->id;
}

void setVertexId(Vertex* vertex, Idx id){
    vertex->id = id;
}

bool getIfVertexWasVisited(Vertex* vertex) {
    return vertex->visited;
}

void setVertexVisited(Vertex* vertex) {
    vertex->visited = true;
}

Idx getVertexPrevious(Vertex* vertex) {
    return vertex->previous;
}

void setVertexPrevious(Vertex* vertex, Idx previous) {
    vertex->previous = previous;
}

Idx* getVertexAdjacents(Vertex* vertex) {
    // Alocando dinamicamente um vetor de índices
    Idx* adjacents;
    adjacents = (Idx*)malloc(sizeof(Idx) * vertex->numAdjacents);

    // Inserindo elementos
    for (int i = 0; i < vertex->numAdjacents; i++) {
        adjacents[i] = vertex->adjacent[i];
    }

    return adjacents;
}

Weight* getVertexWeights(Vertex* vertex) {
    // Alocando dinamicamente um vetor de distâncias entre os nós 
    Weight* weights;
    weights = (Weight*)malloc(sizeof(Weight) * vertex->numAdjacents);

    // Inserindo elementos
    for (int i = 0; i < vertex->numAdjacents; i++) {
        weights[i] = vertex->weights[i];
    }

    return weights;
}

Weight getVertexWeightToVertex(Vertex* vertex, Idx sndVertex) {
    for (int i = 0; i < vertex->numAdjacents; i++) {
        if (vertex->adjacent[i] == sndVertex)
            return vertex->weights[i];
    }
    return INFINITY;
}

//Idx id(Vertex* v) {
//     return v->id;
// }

// //Weight value(Vertex* v) {
//     return v->distance;
// }

void setValue(Vertex* v, Weight value) {
    v->distance = value;
}

// //bool more(Vertex* a, Vertex* b) {
//     return a->distance > b->distance;
// }

int getVertexNumAdjacents(Vertex* vertex) {
    return vertex->numAdjacents;
}

void setVertexNumAdjacents(Vertex* vertex, int num){
    vertex->numAdjacents = num;
}

int getVertexPatchesAllocated(Vertex* vertex){
    return vertex->patchesAllocated;
}

void setVertexPatchesAllocated(Vertex* vertex, int num){
    vertex->patchesAllocated = num;
}

Weight* getVertexDistances(Vertex* vertex, int arrayLength) {
    Weight* distances;
    distances = (Weight*)malloc(sizeof(Weight) * arrayLength);

    for (int i = 0; i < arrayLength; i++) {
        if (i == vertex->id)
            distances[i] = 0;
        else
            distances[i] = INFINITY;
    }

    for (int i = 0; i < getVertexNumAdjacents(vertex); i++) {
        distances[vertex->adjacent[i]] = vertex->weights[i];
    }

    return distances;
}

void idArrayShow(FILE* out, Idx* ids, int length) {
    fprintf(out, "[");
    for (int i = 0; i < length - 1; i++) {
        fprintf(out, "%d, ", ids[i]); // ?? 
    }
    fprintf(out, "%d]", ids[length - 1]);
}

void wgtArrayShow(FILE* out, Weight* wgts, int length) {
    fprintf(out, "[");
    for (int i = 0; i < length - 1; i++) {
        fprintf(out, "%.2lf, ", wgts[i]); // ??
    }
    fprintf(out, "%.2lf]", wgts[length - 1]);
}

// Methods

Vertex* vertexInit(Idx id) {
    
    // Alocando dinamicamente espaço do nó
    Vertex* vertex;
    vertex = (Vertex*)malloc(sizeof(Vertex));
    
    // Inicializando valores já conhecidos (índice e condição "visitado")
    setVertexId(vertex, id);
    vertex->visited = false;

    // Inicializando valores ainda desconhecidos
    // [SUGESTÃO] Terminar de criar funções set e fazer substituições aqui!
    setVertexPrevious(vertex, -1);
    vertex->adjacent = NULL;
    vertex->weights = NULL;
    vertex->distance = INFINITY;
    setVertexNumAdjacents(vertex, 0);
    setVertexPatchesAllocated(vertex, 0);
}

void vertexDelete(Vertex* vertex) {
    free(vertex->adjacent);
    free(vertex->weights);
    free(vertex);
}

void vertexAddNeighbor(Vertex* vertex, Idx neighbor, Weight distance) {
    // Caso ainda não há espaço para inserção do vizinho
    if (vertex->numAdjacents >= vertex->patchesAllocated * PATCHSIZE) {
        // Se não há espaço é necessario alocar!
        vertex->patchesAllocated++;

        if (vertex->patchesAllocated == 1) {
            vertex->adjacent = (Idx*)malloc(sizeof(Idx) * PATCHSIZE); // [SUGESTÃO] Substituição por funções
            vertex->weights = (Weight*)malloc(sizeof(Weight) * PATCHSIZE); //set aqui também!
        } else {
            int newSize;
            newSize = PATCHSIZE * vertex->patchesAllocated;
            vertex->adjacent = (Idx*)realloc(vertex->adjacent, sizeof(Idx) * newSize);
            vertex->weights = (Weight*)realloc(vertex->weights, sizeof(Weight) * newSize);
        }
    }

    // Havendo espaço, basta adicionar o vizinho
    vertex->adjacent[vertex->numAdjacents] = neighbor;  // [SUGESTÃO] Aqui tbm
    vertex->weights[vertex->numAdjacents] = distance;
    vertex->numAdjacents++;
}

void vertexShow(FILE* out, Vertex* vertex) {
    fprintf(out, "Vertex %d:\n", vertex->id);
    fprintf(out, "\tAdjs.: "); idArrayShow(out, vertex->adjacent, vertex->numAdjacents);
    fprintf(out, "\n\tDists.: "); wgtArrayShow(out, vertex->weights, vertex->numAdjacents);
    fprintf(out, "\n");
}