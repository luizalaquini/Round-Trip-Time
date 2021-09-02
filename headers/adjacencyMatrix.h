#ifndef ADJMATRIX_H
#define ADJMATRIX_H

/* Estrutura opaca */
typedef struct adjMatrix AdjMatrix;

/* INICIALIZA MATRIZ DE ADJACÊNCIAS
INPUTs: Tamanho da matriz
OUTPUTs: A matriz de adjacências
Pré-condição: - 
Pós-condição: Matriz deve existir
*/
AdjMatrix* adjMatrixInit(int N);

/* DEFINE A DISTÂNCIA DE UM ÍNDICE ATÉ O OUTRO
INPUTs: A matriz de adjacências, índice do vétice de origem e índice do vétice de destino
OUTPUTs: -
Pré-condição: Matriz deve existir
Pós-condição: - 
*/
void setAdjMatrixWeight(AdjMatrix* matrix, Idx source, Idx destiny, Weight value);

/* RETORNA A DISTÂNCIA DE UM ÍNDICE ATÉ O OUTRO
INPUTs: A matriz de adjacências, índice do vétice de origem e índice do vétice de destino
OUTPUTs: A distância entre os vértices
Pré-condição: Matriz deve existir
Pós-condição: - 
*/
Weight getAdjMatrixWeight(AdjMatrix* matrix, Idx source, Idx destiny);

/* LIBERA A MEMÓRIA DA MATRIZ DE ADJACÊNCIAS
INPUTs: A matriz de adjacências
OUTPUTs: -
Pré-condição: Matriz deve existir
Pós-condição: Matriz não deve existir
*/
void adjMatrixDelete(AdjMatrix* matrix);

#endif /* ADJMATRIX_H */