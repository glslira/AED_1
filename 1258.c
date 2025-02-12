#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome[100], cor[10], tamanho[10];
} Camiseta;

int comparar(const void *a, const void *b) {
    Camiseta *cA = (Camiseta *)a;
    Camiseta *cB = (Camiseta *)b;

    if (strcmp(cA->cor, cB->cor) == 0) {
        if (strcmp(cA->tamanho, cB->tamanho) == 0) {
            return strcmp(cA->nome, cB->nome);
        } //if
        return -strcmp(cA->tamanho, cB->tamanho);
    } //if
    return strcmp(cA->cor, cB->cor);
} //comparar

int main() {
    int numCamisetas, primeiro;
    Camiseta camisetas[60];

    primeiro = 1;
    while (scanf("%d", &numCamisetas) && numCamisetas != 0) { //while
        if (primeiro) {
            primeiro = 0;
        } else {
            printf("\n");
        } //else

        for (int i = 0; i < numCamisetas; ++i) { //for
            scanf("%[^\n]\n", &(camisetas[i].nome));
            scanf("%s %s", &(camisetas[i].cor), &(camisetas[i].tamanho));
        } //for

        qsort(camisetas, numCamisetas, sizeof(Camiseta), comparar);

        for (int i = 0; i < numCamisetas; ++i) { //for
            printf("%s %s %s\n", camisetas[i].cor, camisetas[i].tamanho, camisetas[i].nome);
        } //for
    } //while

    return 0;
} //main
