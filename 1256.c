#include <stdio.h>
#include <stdlib.h>

typedef struct No{
    int chave;
    struct No* prox;
}No;

No* criaNo(int valor){
    No* novo = (No*) malloc(sizeof(No));
    novo->chave = valor;
    novo->prox = NULL;

return novo;
}//criaNo

void insereElemento(No** cabeca, int valor){
    No* elemento = criaNo(valor);

    if (*cabeca == NULL){
        *cabeca = elemento;
    } else {
        No* atual = *cabeca;
        while (atual->prox != NULL){
            atual = atual->prox;
        }//while
        atual->prox = elemento;
    }//else

}//insereElemento

void imprimeTabela(No** tabela, int tamanho){

    int i;
    for (i = 0; i < tamanho; i++){
        printf("%d ->", i);
        No* atual = tabela[i];
        while (atual != NULL){
            printf(" %d ->", atual->chave);
            atual = atual->prox;
        }//while
        printf(" \\\n");
    }//for

}//imprimeTabela

void liberaTabela(No** tabela, int tamanho){

    int i;
    for (i = 0; i < tamanho; i++){
        No* atual = tabela[i];
        while (atual != NULL){
            No* temp = atual;
            atual = atual->prox;
            free(temp);
        }//while
    }//for

}//liberaTabela

int main() {
    int casos, i;
    scanf("%d", &casos);

    while (casos--){
        int M, C;
        scanf("%d %d", &M, &C);

        No* tabela[M];
        for (i = 0; i < M; i++){
            tabela[i] = NULL;
        }//for

        for (i = 0; i < C; i++){
            int chave;
            scanf("%d", &chave);
            insereElemento(&tabela[chave % M], chave);
        }//for

        imprimeTabela(tabela, M);

        if (casos > 0){
            printf("\n");
        }//if

        liberaTabela(tabela, M);
    }//while

return 0;
}//main