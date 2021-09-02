#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "../headers/vertex.h"
#include "../headers/adjacencyMatrix.h"

struct adjMatrix {
    Weight** matrix;
    int N;
};

AdjMatrix* adjMatrixInit(int N) {
    AdjMatrix* matrix;
    matrix = (AdjMatrix*)malloc(sizeof(AdjMatrix));

    matrix->matrix = (Weight**)malloc(sizeof(Weight*) * N);
    for (int i = 0; i < N; i++)
        matrix->matrix[i] = (Weight*)malloc(sizeof(Weight) * N);

    matrix->N = N;

    return matrix;
}

void setAdjMatrixWeight(AdjMatrix* matrix, Idx source, Idx destiny, Weight value) {
    matrix->matrix[source][destiny] = value;
}

Weight getAdjMatrixWeight(AdjMatrix* matrix, Idx source, Idx destiny) {
    return matrix->matrix[source][destiny];
}

void adjMatrixDelete(AdjMatrix* matrix) {
    for (int i = 0; i < matrix->N; i++)
        free(matrix->matrix[i]);
    free(matrix->matrix);
    free(matrix);
}