//Depth-First Search ou DFS tem a ideia de buscar mais FUNDO no gráfico sempre
//A busca só para quando encontramos o que procurávamos ou quando rodamos todos os vértices sem achar

#include <stdio.h>
#include <stdlib.h>

//definindo cores para nossos vertices, a fim de facilitar o entendimento ao ler o codigo
#define BRANCO 0
#define AMARELO 1
#define VERMELHO 2

typedef struct adjacencia {
    int vertice;
    int peso;
    struct adjacencia *prox;
} Adjacencia;

typedef struct vertice {
    // dados armazenados entram aqui
    Adjacencia *cabeca;
} Vertice;

typedef struct grafo {
    int vertices;
    int arestas;
    Vertice *adj;
} Grafo;

//função que perpassa por todos os filhos do vertice pai (segue o caminho do grafo)
void visitaProfundidade(Grafo *g, int i, int *cor){
    cor[i] = AMARELO;

    Adjacencia *v = g->adj[i].cabeca;
    while(v){
        if(cor[v->vertice] == BRANCO){
            visitaP(g, v->vertice, cor);
        }//if
        v = v->prox;
    }//while
    cor[i] = VERMELHO;
}//visitaProfudindade

//implementação do algoritmo de busca em profundidade
void iniciaProfundidade (Grafo *g){
    //definir o arranjo de cores (1 cor por vertice)
    int cor[g->vertices];

    int i;
    for(i=0; i<g->vertices; i++){
        cor[i] = BRANCO; //inicializamos todos os vertices como BRANCO
    }//for

    for(i=0; i<g->vertices; i++){
        if(cor[i] == BRANCO){
        }//if
            visitaProfundidade(g, i, cor); //chamada da função que visita todos os vertices (nesse caso, que estão brancos (não foram visitados))
    }//for
}//iniciaProfundidade


