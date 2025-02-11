#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Nome{
    char nome[50];
    struct Nome *prox;
} Nome;

Nome* criaLista(char *nome){
    Nome *amigo = malloc(sizeof(Nome));
    strcpy(amigo->nome, nome);
    amigo->prox = NULL;

return amigo;
}//criaLista

void novaLista(Nome **cabeca, char *nome){
    Nome *novoAmigo = criarLista(nome);
        if (*cabeca == NULL) {
            *cabeca = novoAmigo;
        } else {
            Nome *var = *cabeca;
            while (var->prox != NULL) {
                var = var->prox;
            }//while
            var->prox = novoAmigo;
        }//else
}//novaLista

Nome* encontraUltimo(Nome *cabeca) {
    if (cabeca == NULL) return NULL;
    while (cabeca->prox != NULL) {
        cabeca = cabeca->prox;
    }//while
return cabeca;
}//encontraUltimo

void nomeAntes(Nome **cabeca, char *indicado, Nome *novaLista) {
    if (*cabeca == NULL) return;

    if (strcmp((*cabeca)->nome, indicado) == 0) {
        Nome *ultimoLista = encontrarUltimo(novaLista);
        ultimoLista->prox = *cabeca;
        *cabeca = novaLista;
        return;
    }//if

    Nome *anterior = *cabeca;
    Nome *atual = (*cabeca)->prox;

    while (atual != NULL && strcmp(atual->nome, indicado) != 0) {
        anterior = atual;
        atual = atual->prox;
    }//while

    if (atual != NULL) {
        Nome *ultimoLista = encontrarUltimo(novaLista);
        ultimoLista->prox = atual;
        anterior->prox = novaLista;
    } else {
        Nome *ultimo = encontrarUltimo(*cabeca);
        ultimo->prox = novaLista;
    }//else
}//nomeAntes

void imprimeLista(Nome *cabeca) {
    int primeiro = 1;
    while (cabeca != NULL) {
        if (!primeiro) {
            printf(" ");
        }//if
        printf("%s", cabeca->nome);
        primeiro = 0;
        cabeca = cabeca->prox;
    }//while
    printf("\n");
}//imprimeLista

int main(){
    Nome *lista = NULL;
    Nome *listaIndica = NULL;
    char primeiraLista[500], segundaLista[500], indicado[50];
    
    fgets(primeiraLista, sizeof(primeiraLista), stdin);
    primeiraLista[strcspn(primeiraLista, "\n")] = '\0';

    char *var = strtok(primeiraLista, " ");
    while (var != NULL) {
        novaLista(&lista, var);
        var = strtok(NULL, " ");
    }

    fgets(segundaLista, sizeof(segundaLista), stdin);
    segundaLista[strcspn(segundaLista, "\n")] = '\0';

    var = strtok(segundaLista, " ");
    while (var != NULL) {
        novaLista(&listaIndica, var);
        var = strtok(NULL, " ");
    }

    fgets(indicado, sizeof(indicado), stdin);
    indicado[strcspn(indicado, "\n")] = '\0';

    if (strcmp(indicado, "nao") == 0) {
        Nome *ultimo = encontraUltimo(lista);
        if (ultimo != NULL) {
            ultimo->prox = listaIndica;
        } else {
            lista = listaIndica;
        }
    } else {
        nomeAntes(&lista, indicado, listaIndica);
    }//else

    imprimeLista(lista);

return 0;
}//main