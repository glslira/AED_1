#include <stdio.h>
#include <stdlib.h>

int comparar(const void *a, const void *b) {
    int valorA = *(int *)a, valorB = *(int *)b;

    if (valorA % 2 == 0) {
        if (valorB % 2 == 0) {
            return valorA - valorB;
        } else {
            return -1;
        } //else
    } else if (valorB % 2 == 0) {
        return 1;
    } else {
        return valorB - valorA;
    } //else if
} //comparar

int main() {
    int quantidadeNumeros, numeros[100000];

    scanf("%d", &quantidadeNumeros);

    for (int i = 0; i < quantidadeNumeros; ++i) { //for
        scanf("%d", &numeros[i]);
    } //for

    qsort(numeros, quantidadeNumeros, sizeof(int), comparar);

    for (int i = 0; i < quantidadeNumeros; ++i) { //for
        printf("%d\n", numeros[i]);
    } //for

    return 0;
} //main
