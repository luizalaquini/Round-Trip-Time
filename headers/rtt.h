#ifndef RTT_H
#define RTT_H

typedef struct rtt RTT;

/* INICIA O STRUCT RTT
INPUTs: Grafo a ser analisado
OUTPUTs: O struct RTT inicializado
Pré-condição: O struct RTT existe
Pós-condição: - 
*/
RTT* rttInit(Graph* g);

/* CALCULA A ROUND TRIP TIME REAL
INPUTs: A matriz de adjacências, índice do vétice de origem(servidor) 
e índice do vétice de destino(cliente)
OUTPUTs: Distância de ida e volta entre dois vértices
Pré-condição: A matriz de adjacências existe
Pós-condição: -
*/
Weight calculateRealRTT(AdjMatrix* m, Idx source, Idx destiny);

/* CALCULA A ROUND TRIP TIME APROXIMADA
INPUTs: A matriz de adjacências, índice do vétice de origem(servidor), índice do vétice do monitor 
e índice do vétice de destino(cliente)
OUTPUTs: Distância de ida e volta entre dois vértices passando pelo monitor;
Pré-condição: A matriz de adjacências existe
Pós-condição: -
*/
Weight calculateApproxRTT(AdjMatrix* m, Idx server, Idx monitor, Idx client);

/* FAZ O CÁLCULO DA INFLAÇÃO
INPUTs: O struct rtt
OUTPUTs: -
Pré-condição: O struct RTT existe
Pós-condição: Arquivo foi escrito 
*/
Weight** getInflations(RTT* rtt);

/* ESCREVE O ARQUIVO DE SAÍDA
INPUTs: Arquivo de saída e o struct rtt
OUTPUTs: -
Pré-condição: O struct RTT existe e o arquivo existe
Pós-condição: Arquivo foi escrito 
*/
void inflationsShow(FILE* output, RTT* rtt);

/* LIBERA A MEMÓRIA DO STRUCT RTT
INPUTs: O struct RTT 
OUTPUTs: -
Pré-condição: O struct RTT existe
Pós-condição: O struct RTT não existe
*/
void rttDelete(RTT* rtt);

#endif /* RTT_H */