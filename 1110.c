#include <stdio.h>
#include <stdlib.h>

typedef struct No{
    int valor;
    struct No *anterior, *proximo;
}No;

typedef struct Deck{
    int tamanho;
    No *frente, *tras;
}Deck;

void insereTras(Deck *d, int valor){
    d->tamanho++;
    No *novoTras = (No *)malloc(sizeof(No));
    novoTras->valor = valor;
    novoTras->anterior = d->tras;

    if (d->tras){
        d->tras->proximo = novoTras;
    }//if

    d->tras = novoTras;

    if (!d->frente){
        d->frente = d->tras;
    }//if
}//insereTras

void removeFrente(Deck *d){
    if (d->tamanho > 0){
        d->tamanho--;
        No *aux = d->frente;
        d->frente = d->frente->proximo;
        free(aux);
    }//if
}//removeFrente

int pegaFrente(Deck *d){
    return d->frente->valor;
}//pegaFrente

int pegaTamanho(Deck *d){
    return d->tamanho;
}//pegaTamanho

void inicializaBaralho(Deck *d){
    d->tamanho = 0;
    d->frente = d->tras = NULL;
}//inicializaBaralho

void destroiBaralho(Deck *d){
    while (!d->tamanho == 0){
        removeFrente(d);
    }//while
}//destroiBaralho

int main(){
    int n, primeiro, i;
    Deck cartas;

    while (scanf("%d", &n) && n) {
        inicializaBaralho(&cartas);

        for (i = 1; i <= n; i++){
            insereTras(&cartas, i);
        }//for

        primeiro = 1;
        printf("Discarded cards: ");
        while (pegaTamanho(&cartas) > 1) {
            if (!primeiro) printf(", ");
            else primeiro = 0;

            printf("%d", pegaFrente(&cartas));
            removeFrente(&cartas);
            insereTras(&cartas, pegaFrente(&cartas));
            removeFrente(&cartas);
        }//while interno
        printf("\nRemaining card: %d\n", pegaFrente(&cartas));

        destroiBaralho(&cartas);
    }//while externo

return 0;
}//main