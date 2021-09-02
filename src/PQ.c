#include <stdio.h>
#include <stdlib.h>
#include "../headers/PQ.h"

struct heap {
    Item *pq;
    int *map;
    int N;
};

void swap(int i, int j, Heap* heap) {
    exch(heap->pq[i], heap->pq[j]);
    int id1 = id(heap->pq[i]);
    int id2 = id(heap->pq[j]);
    heap->map[id1] = i;
    heap->map[id2] = j;
}

void fix_up(Item *a, int k, Heap* heap) {
    while (k > 1 && more(a[k/2], a[k])) {
        swap(k, k/2, heap);
        k = k/2;
    }
}

void fix_down(Item *a, int sz, int k, Heap* heap){
    while (2*k <= sz) {
        int j = 2*k;
        if (j < sz && more(a[j], a[j+1])){
            j++;
        }
        if (!more(a[k], a[j])) {
            break;
        }
        swap(k, j, heap);
        k = j;
    }
}

Heap* PQ_init(int maxN) {
    Heap* heap = (Heap*)malloc(sizeof(Heap));
    heap->pq = (Item *) malloc((maxN+1) * sizeof (Item));
    heap->map = (int *) malloc((maxN+1) * sizeof (int));
    heap->N = 0;
    return heap;
}

void PQ_insert(Item v, Heap* heap) {
    heap->N++;
    heap->pq[heap->N] = v;
    heap->map[id(v)] = heap->N;
    fix_up(heap->pq, heap->N, heap);
}

Item PQ_delmin(Heap* heap) {
    Item min = heap->pq[1];
    swap(1, heap->N, heap);
    heap->N--;
    fix_down(heap->pq, heap->N, 1, heap);
    return min;
}

Item PQ_min(Heap* heap) {
    return heap->pq[1];
}

void PQ_decrease_key(int id, double value, Heap* heap) {
    int i = heap->map[id];
    value(heap->pq[i]) = value;
    fix_up(heap->pq, i, heap);
}

bool PQ_empty(Heap* heap) {
    return heap->N == 0;
}

int  PQ_size(Heap* heap) {
    return heap->N;
}

void PQ_finish(Heap* heap) {
    free(heap->pq);
    free(heap->map);
    free(heap);
}