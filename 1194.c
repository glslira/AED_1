#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct aux {
    char chave;
    struct aux *esquerda, *direita;
} No;

typedef No* Pont;

Pont criaNovoNo(char chave) {
    Pont no = (Pont) malloc(sizeof(No));
    no->chave = chave;

    no->esquerda = NULL;
    no->direita = NULL;

    return no;
}//criaNovoNo

Pont constroiArvore(char* prefixa, char* infixa, int inicio, int fim, int* indicePre) {
    if (inicio > fim) return NULL;

    char raizValor = prefixa[*indicePre];
    (*indicePre)++;
    Pont raiz = criaNovoNo(raizValor);

    if (inicio == fim) return raiz;

    int indiceMeio;
    for (indiceMeio = inicio; indiceMeio <= fim; indiceMeio++) {
        if (infixa[indiceMeio] == raizValor) break;
    }//for

    raiz->esquerda = constroiArvore(prefixa, infixa, inicio, indiceMeio - 1, indicePre);
    raiz->direita = constroiArvore(prefixa, infixa, indiceMeio + 1, fim, indicePre);

    return raiz;
}//constroiArvore

void imprimePosOrdem(Pont raiz) {
    if (raiz == NULL) return;

    imprimePosOrdem(raiz->esquerda);
    imprimePosOrdem(raiz->direita);

    printf("%c", raiz->chave);
}//imprimePosOrdem

void liberaArvore(Pont raiz) {
    if (raiz == NULL) return;

    liberaArvore(raiz->esquerda);
    liberaArvore(raiz->direita);

    free(raiz);
}//liberaArvore

int main() {
    int i;
    scanf("%d", &i);

    while (i--) {
        int n;
        char prefixa[100], infixa[100];
        scanf("%d %s %s", &n, prefixa, infixa);

        int indice = 0;
        Pont raiz = constroiArvore(prefixa, infixa, 0, n - 1, &indice);

        imprimePosOrdem(raiz);
        printf("\n");

        liberaArvore(raiz);
    }//while

    return 0;
}//main