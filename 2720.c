#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int indice;
    int valor;
} Elemento;

int comparar(const void *a, const void *b) {
    Elemento *elementoA = (Elemento *)a;
    Elemento *elementoB = (Elemento *)b;
    if (elementoA->valor == elementoB->valor) {
        return elementoA->indice - elementoB->indice;
    } else {
        return elementoB->valor - elementoA->valor;
    } //else
} //comparar

int compararIndices(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
} //compararIndices

int main() {
    int numTestes;
    
    scanf("%d", &numTestes);

    for (int g = 0; g < numTestes; g++) {
        int n, k;
        
        scanf("%d %d", &n, &k);

        Elemento elementos[1000];

        for (int q = 0; q < n; q++) {
            int e1, e2, e3, e4;
            scanf("%d %d %d %d", &e1, &e2, &e3, &e4);
            elementos[q].indice = e1;
            elementos[q].valor = e2 * e3 * e4;
        } //for

        qsort(elementos, n, sizeof(Elemento), comparar);

        int indicesSelecionados[1000];

        for (int q = 0; q < k; q++) {
            indicesSelecionados[q] = elementos[q].indice;
        } //for

        qsort(indicesSelecionados, k, sizeof(int), compararIndices);

        for (int q = 0; q < k; q++) {
            printf("%d", indicesSelecionados[q]);
            if (q < k - 1) {
                printf(" ");
            } else {
                printf("\n");
            } //if
        } //for
    } //for

    return 0;
} //main
