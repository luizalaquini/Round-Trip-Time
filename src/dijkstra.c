#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include "../headers/vertex.h"
#include "../headers/adjacencyMatrix.h"
#include "../headers/graph.h"
#include "../headers/PQ.h"
#include "../headers/dijkstra.h"

void dijkstra(Graph* g, AdjMatrix* m, Idx sourceIdx) {
    Idx* prev; Weight* dist; int N;
    N = getGraphNumVertices(g);
    prev = (Idx*)malloc(sizeof(Idx) * N);
    dist = (Weight*)malloc(sizeof(Weight) * N);

    Heap* heap;
    heap = PQ_init(N); // create vertex priority queue Q

    for (int i = 0; i < N; i++) { /* for each vertex v in Graph */

        if (i != sourceIdx){ /* if v != source */
            dist[i] = INFINITY; // dist[v] <- INFINITY
            prev[i] = -1; // prev[v] <- UNDEFINED
        } else {
            dist[i] = 0;
        }

        Item k;
        id(k) = i;
        value(k) = dist[i];

        // Q.add_with_priority(v, dist[v])
        PQ_insert(k, heap);
    }
    
    while (!PQ_empty(heap)) { /* while Q is not empty */
        
        // u <- Q.extract_min()
        Item u;
        u = PQ_delmin(heap);

        Vertex* uVert;
        uVert = getGraphVertex(g, id(u));

        Weight* lengths;
        lengths = getVertexDistances(uVert, N);
        
        for (int i = 0; i < getGraphNumVertices(g); i++) { /* for each neighbor v of u */
            Vertex* vVert;
            vVert = getGraphVertex(g, i);

            Weight alt;
            alt = value(u) + lengths[i]; // lengths[i];

            if (alt < dist[i]) {
                prev[i] = id(u);
                dist[i] = alt;
                PQ_decrease_key(i, alt, heap);
            }
        }

        free(lengths);
    }

    PQ_finish(heap);

    // Retornando os caminhos:
    for (int i = 0; i < N; i++) {
        setAdjMatrixWeight(m, sourceIdx, i, dist[i]);
    }

    free(prev);
    free(dist);
}