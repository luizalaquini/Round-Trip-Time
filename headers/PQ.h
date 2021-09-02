#ifndef PQ_H
#define PQ_H

#include <stdbool.h>
#include "item.h"

/* Estrutura opaca */
typedef struct heap Heap;

/* INICIALIZA UMA HEAP VAZIA DE CAPACIDADE MAXN
INPUTs: Capacidade.
OUTPUTs: Heap inicializada.
Pré-condição: -
Pós-condição: Heap existe.
*/
Heap* PQ_init(int maxN); 

/* INSERE ITEM NA HEAP - A MAIOR PRIORIDADE É A DO ITEM COM MENOR CAMPO 'VALUE'
INPUTs: Heap e item a ser inserido.
OUTPUTs: -
Pré-condição: Heap e item devem existir.
Pós-condição: Item inserido na heap.
*/
void PQ_insert(Item v, Heap* heap);  

/* REMOVE ITEM DE MENOR CAMPO 'VALUE' (MAIOR PRIORIDADE) DA HEAP
INPUTs: Heap.
OUTPUTs: Item.
Pré-condição: Heap deve existir.
Pós-condição: -
*/
Item PQ_delmin(Heap* heap);     

/* MUDA A PRIORIDADE DE UM NÓ
INPUTs: Identificador do nó, novo valor de prioridade e Heap.
OUTPUTs: -
Pré-condição: Heap deve existir.
Pós-condição: Prioridade do nó atualizada.
*/
void PQ_decrease_key(int id, double value, Heap* heap); 

/* RETORNA O ITEM COM MENOR CAMPO 'VALUE' (MAIOR PRIORIDADE)
INPUTs: Heap.
OUTPUTs: Item de maior prioridade.
Pré-condição: Heap deve existir.
Pós-condição: -
*/
Item PQ_min(Heap* heap);          

/* RETORNA TRUE SE A HEAP ESTIVER VAZIA
INPUTs: Heap.
OUTPUTs: True caso não haja itens / False caso contrário.
Pré-condição: Heap deve existir.
Pós-condição: -
*/
bool PQ_empty(Heap* heap);        

/* RETORNA NÚMERO DE ELEMENTOS NA HEAP
INPUTs: Heap.
OUTPUTs: Número de itens atual na heap.
Pré-condição: Heap deve existir.
Pós-condição: -
*/
int PQ_size(Heap* heap);         

/* LIBERA MEMÓRIA DA HEAP
INPUTs: Heap a ser liberada.
OUTPUTs: -
Pré-condição: Heap deve existir.
Pós-condição: Heap não existe mais.
*/
void PQ_finish(Heap* heap);

#endif