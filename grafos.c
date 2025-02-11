#include <stdio.h>
#include <stdlib.h>

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

//cria o grafo com a quantidade de nos passada por parametro
Grafo *criaGrafo(int v){
    Grafo *g = (Grafo *) malloc(sizeof (Grafo));
    if(g == NULL){
        printf("Erro ao alocar memoria para o grafo\n");
        return NULL;
    }//if

    g->vertices = v;
    g->arestas = 0;

    g->adj = (Vertice *) malloc(v * sizeof (Vertice));
    if(g->adj == NULL){
        printf("Erro ao alocar memoria para os vertices\n");
        return NULL;
    }//if
    
    int i;
    for(i=0; i<v; i++){
        g->adj[i].cabeca = NULL;
    }//for
     
    return g;
}//criaGrafo

//essa funcao cria como se fosse a ponta da aresta
Adjacencia *criaAdjacencia (int v, int peso){
    Adjacencia *temp = (Adjacencia *) malloc(sizeof (Adjacencia));
    if (temp == NULL) {
    printf("Erro ao alocar memória para a aresta!\n");
    return NULL;
    }//if

    temp->vertice = v;
    temp->peso = peso;
    temp->prox = NULL;

    return temp;
}//criaAdjacencia 

//*IMPORTANTE*
//esse é o processo de criação de uma aresta DIGIRIDA (aponta do vertice inicial (vi) para o vértice final (vf))
//se quiser fazer uma não dirigida, é so chamar a função duas vezes!! (vi,vf) e (vf,vi)
//assim a aresta será "mão dupla"

//cria a propria aresta, com o peso, o vertice inicial e o vertice final
int criaAresta(Grafo *gr, int vi, int vf, int p){

    //sequência de teste de informações de valores fornecidos pelo usuário
    if (!gr) return 0; // se o grafo nao existe, o retorno é falso
    
    if ((vf<0) || (vf >= gr->vertices)) // se o usuario colocar um vertice final que nao existe (menor que 0 ou maior que o a qt de vertices (0 -> n vertices-1))
        return 0;
    
    if ((vi<0) || (vi >= gr->vertices)) // se o usuario colocar um vertice inicial que nao existe (menor que 0 ou maior que o a qt de vertices (0 -> n vertices-1))
        return 0;

    Adjacencia *novo = criaAdjacencia(vf,p);
    novo->prox = gr->adj[vi].cabeca; // o campo prox da adjacencia recebe a cabeça da lista
    gr->adj[vi].cabeca = novo; // o novo passa a ser a cabeça da lista
    gr->arestas++; // como adicionamos uma aresta, incrementamos o numero de arestas no grafo

    return 1;
}//criaAresta

//mostrando o grafo na tela!! (maneira simples)
//pode usar a criatividade pra mostrar do jeito que quiser

void imprime (Grafo *gr){
    printf("Vertices: %d. Arestas: %d.\n", gr->vertices, gr->arestas);

    int i;
    for(i=0; i < gr->vertices; i++){ //para cada vertice no grafo
        printf("v%d: ", i);

        //criar a lista de adjacência
        Adjacencia *ad = gr->adj[i].cabeca;
        while(ad){ //enquanto o ponteiro existir (nao for null)
            printf("v%d(%d) ", ad->vertice, ad->peso); // imprime o valor final da aresta e o peso da aresta
            ad = ad->prox;
        }//while
        printf("\n");
    }//for
}//imprime

//aplicando tudo isso
int main(){
    Grafo *gr = criaGrafo(5); //criar um grafo com 5 nos(vertices) (SEM ARESTA ALGUMA)

    //abastecer o grafo um por um
    criaAresta(gr, 0, 1, 2); // no grafo gr, a aresta sai do vertice 0 e vai para o vertice 1 e tem peso 2
    criaAresta(gr, 1, 2, 4);
    criaAresta(gr, 2, 0, 12);
    criaAresta(gr, 2, 4, 32);
    criaAresta(gr, 3, 1, 3);
    criaAresta(gr, 4, 3, 8);

    //imprime o grafo
    imprime(gr);
return 0;
}//main