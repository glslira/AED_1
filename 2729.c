#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct No {
    char compra[21];
    struct No *prox;
} No;

No* criaNo(char *compra) {
    No *novoNo = (No*) malloc(sizeof(No));
    strcpy(novoNo->compra, compra);
    novoNo->prox = NULL;
    return novoNo;
}//criaNo

void adicionaCompra(No **cabeca, char *compra) {
    No *novoNo = criaNo(compra);
    if (*cabeca == NULL) {
        *cabeca = novoNo;
    } else {
        No *var = *cabeca;
        while (var->prox != NULL) {
            var = var->prox;
        }
        var->prox = novoNo;
    }//else
}//adicionaCompra

int compraExiste(No *cabeca, char *compra) {
    No *var = cabeca;
    while (var != NULL) {
        if (strcmp(var->compra, compra) == 0) {
            return 1;
        }//if
        var = var->prox;
    }//while
    return 0;
}//compraExiste

void ordenaLista(No *cabeca) {
    No *i, *j;
    char var[50];
    for (i = cabeca; i != NULL; i = i->prox) {
        for (j = i->prox; j != NULL; j = j->prox) {
            if (strcmp(i->compra, j->compra) > 0) {
                strcpy(var, i->compra);
                strcpy(i->compra, j->compra);
                strcpy(j->compra, var);
            }//if
        }//for interno
    }//for externo
}//ordenaLista

void imprimeLista(No *cabeca) {
    int primeiro = 1;
    while (cabeca != NULL) {
        if (!primeiro) {
            printf(" ");
        }//if
        printf("%s", cabeca->compra);
        primeiro = 0;
        cabeca = cabeca->prox;
    }//while
    printf("\n");
}//imprimeLista

void apagaLista(No *cabeca) {
    No *var;
    while (cabeca != NULL) {
        var = cabeca;
        cabeca = cabeca->prox;
        free(var);
    }//while
}//apagaLista

int main() {
    int N;
    scanf("%d", &N);
    getchar();

    for (int i = 0; i < N; i++) {
        No *lista = NULL;
        char compra[50];

        while (scanf("%s", compra) == 1) {
            if (!compraExiste(lista, compra)) {
                adicionaCompra(&lista, compra);
            }//if
            if (getchar() == '\n') break;
        }//while

        ordenaLista(lista);
        imprimeLista(lista);
        apagaLista(lista);
    }//for

return 0;
}//main
