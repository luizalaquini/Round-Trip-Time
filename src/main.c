#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "../headers/vertex.h"
#include "../headers/graph.h"
#include "../headers/adjacencyMatrix.h"
#include "../headers/item.h"
#include "../headers/io.h"
#include "../headers/dijkstra.h"
#include "../headers/rtt.h"
//#include "../headers/heap.h"

int main(int argc, char** argv) {

    if (argc <= 2)
        return 0;

    // char* inputPath;
    // inputPath = (char*)malloc(sizeof(char) * (strlen(argv[1]) + 1));
    // strcpy(inputPath, argv[1]);

    FILE* f; // Inicializa arquivo de entrada
    f = fopen(argv[1], "r"); // Abre e faz leitura do arquivo

    // free(inputPath);

    Graph* g; // Inicialização de um grafo
    g = fileToGraph(f); // Recebendo grafo do arquivo de entrada

    fclose(f); // Fecha arquivo

    RTT* rtt;
    rtt = rttInit(g);

    // char* outputPath;
    // outputPath = (char*)malloc(sizeof(char) * (strlen(argv[2]) + 1));
    // strcpy(outputPath, argv[2]);

    FILE* output;
    output = fopen(argv[2], "w");
    // free(outputPath);

    inflationsShow(output, rtt);

    fclose(output);
    
    rttDelete(rtt);
    graphDelete(g);
}