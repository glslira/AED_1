#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome[100];
    int valor;
} Elemento;

int comparar(const void *a, const void *b) {
    Elemento *elementoA = (Elemento *)a;
    Elemento *elementoB = (Elemento *)b;
    return elementoA->valor - elementoB->valor;
} //comparar

int main() {
    int n;
    Elemento elementos[100];

    while (1) {
        if (scanf("%d", &n) == EOF) {
            break;
        } //if

        for (int i = 0; i < n; i++) {
            scanf("%s %d", elementos[i].nome, &elementos[i].valor);
        } //for

        qsort(elementos, n, sizeof(Elemento), comparar);

        for (int i = 0; i < n; i++) {
            printf("%s", elementos[i].nome);
            if (i < n - 1) {
                printf(" ");
            } //if
        } //for
        printf("\n");
    } //while

    return 0;
} //main
