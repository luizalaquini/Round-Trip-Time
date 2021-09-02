#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include "../headers/vertex.h"
#include "../headers/adjacencyMatrix.h"
#include "../headers/graph.h"
#include "../headers/PQ.h"
#include "../headers/dijkstra.h"
#include "../headers/rtt.h"

struct rtt {
    int numS;
    int numC;
    int numM;
    int* servers;
    int* clients;
    int* monitors;
    AdjMatrix* m;
};

typedef struct inflation {
    Idx source;
    Idx destiny;
    Weight inflation;
} Inflation;

RTT* rttInit(Graph* g) {

    int N = getGraphNumVertices(g);
    int numS = 0, numC = 0, numM = 0;
    int sS[N]; int cS[N]; int mS[N];
    for (int i = 0; i < getGraphNumVertices(g); i++) {
        char label;
        label = getGraphVertexLabel(g, i);

        if (label == 'c')
            cS[numC++] = i;

        else if (label == 's')
            sS[numS++] = i;

        else if (label == 'm')
            mS[numM++] = i;
    }
    int numMax;
    if (numS > numC && numS > numM) numMax = numS;
    else if (numC > numS && numC > numM) numMax = numC;
    else numMax = numM;
    
    int *servers, *clients, *monitors;
    servers = (int*)malloc(sizeof(int) * numS);
    clients = (int*)malloc(sizeof(int) * numC);
    monitors = (int*)malloc(sizeof(int) * numM);
    
    for (int i = 0; i < numMax; i++) {
        if (i < numS) servers[i] = sS[i];
        if (i < numC) clients[i] = cS[i];
        if (i < numM) monitors[i] = mS[i];
    }

    AdjMatrix* m;
    m = adjMatrixInit(N);
    for (int i = 0; i < N; i++) {
        dijkstra(g, m, i);
    }

    RTT* rtt;
    rtt = (RTT*)malloc(sizeof(RTT));
    rtt->numS = numS;
    rtt->numM = numM;
    rtt->numC = numC;
    rtt->clients = clients;
    rtt->monitors = monitors;
    rtt->servers = servers;
    rtt->m = m;

    return rtt;
}

Weight calculateInAndOut(AdjMatrix* m, Idx source, Idx destiny) {
    return getAdjMatrixWeight(m, source, destiny) + getAdjMatrixWeight(m, destiny, source);
}

Weight calculateRealRTT(AdjMatrix* m, Idx source, Idx destiny) {
    return calculateInAndOut(m, source, destiny);
}

Weight calculateApproxRTT(AdjMatrix* m, Idx server, Idx monitor, Idx client) {
    return calculateInAndOut(m, server, monitor) + calculateInAndOut(m, monitor, client);
}

Weight** getInflations(RTT* rtt) {
    Weight** inflations;
    inflations = (Weight**)malloc(sizeof(Weight*) * rtt->numS);
    for (int i = 0; i < rtt->numS; i++) {
        inflations[i] = (Weight*)malloc(sizeof(Weight) * rtt->numC);
        for (int j = 0; j < rtt->numC; j++) {
            Weight smallestInflation;
            smallestInflation = INFINITY;

            for (int k = 0; k < rtt->numM; k++) {
                Weight thisInflation, approxRTT, realRTT;
                approxRTT = calculateApproxRTT(rtt->m, rtt->servers[i], rtt->monitors[k], rtt->clients[j]);
                realRTT = calculateRealRTT(rtt->m, rtt->servers[i], rtt->clients[j]);
                thisInflation = approxRTT / realRTT;

                if (thisInflation < smallestInflation)
                    smallestInflation = thisInflation;
            }

            inflations[i][j] = smallestInflation;

        }
    }

    return inflations;
}

int inflationCompare(const void* inflA, const void* inflB) {
    Inflation *a, *b;
    a = *(Inflation**)inflA;
    b = *(Inflation**)inflB;

    return (a->inflation > b->inflation);
}

int serverCompare(const void* inflA, const void* inflB) {
    Inflation *a, *b;
    a = *(Inflation**)inflA;
    b = *(Inflation**)inflB;

    return (a->source > b->source);
}

int clientCompare(const void* inflA, const void* inflB) {
    Inflation *a, *b;
    a = *(Inflation**)inflA;
    b = *(Inflation**)inflB;

    return (a->destiny > b->destiny);
}

void inflationsShow(FILE* output, RTT* rtt) {
    Weight** inflations;
    inflations = getInflations(rtt);

    int N = rtt->numS * rtt->numC;
    Inflation** inflationsArray;
    inflationsArray = (Inflation**)malloc(sizeof(Inflation*) * N);
    for (int i = 0; i < rtt->numS; i++) {
        for (int j = 0; j < rtt->numC; j++) {
            Inflation* k;
            k = (Inflation*)malloc(sizeof(Inflation));
            k->source = rtt->servers[i];
            k->destiny = rtt->clients[j];
            k->inflation = inflations[i][j];
            inflationsArray[i * rtt->numC + j] = k;
        }
        free(inflations[i]);
    }
    free(inflations);

    qsort(inflationsArray, N, sizeof(Inflation*), *clientCompare);
    qsort(inflationsArray, N, sizeof(Inflation*), *serverCompare);
    qsort(inflationsArray, N, sizeof(Inflation*), *inflationCompare);

    for (int i = 0; i < N; i++) {
        Inflation* k;
        k = inflationsArray[i];
        fprintf(output, "%d %d %.16lf\n", k->source, k->destiny, k->inflation);
        free(k);
    }
    free(inflationsArray);
}

void rttDelete(RTT* rtt) {
    free(rtt->clients);
    free(rtt->monitors);
    free(rtt->servers);
    adjMatrixDelete(rtt->m);
    free(rtt);
}