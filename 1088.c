#include <stdio.h>
#include <stdlib.h>

int inversoes;

int comparar(int a, int b) {
    return a - b;
}//comparar

void unir(int *V, int inicio, int meio, int fim) {
    int *aux = (int *) malloc((fim - inicio) * sizeof(int));
    int i = 0, i1 = inicio, i2 = meio, n1 = meio, n2 = fim;

    while (i1 < n1 && i2 < n2) {
        if (comparar(V[i1], V[i2]) < 0) {
            aux[i++] = V[i1++];
        } else {
            aux[i++] = V[i2++];
            inversoes += (n1 - i1);
        }//else
    }//while

    while (i1 < n1)
        aux[i++] = V[i1++];
    while (i2 < n2)
        aux[i++] = V[i2++];

    for (int i = inicio; i < fim; ++i) {
        V[i] = aux[i - inicio];
    }//for

    free(aux);
}//unir

void mergeSort(int *V, int inicio, int fim) {
    if (fim - inicio > 1) {
        int meio = (inicio + fim) / 2;
        mergeSort(V, inicio, meio);
        mergeSort(V, meio, fim);
        unir(V, inicio, meio, fim);
    }//if
}//mergeSort

int main(){
    int N;

    while (scanf("%d", &N) && N > 0) {
        int *P = (int *)malloc(N * sizeof(int));
        if (P == NULL) {
            fprintf(stderr, "Erro ao alocar memória\n");
            return 1;
        }//if

        for (int i = 0; i < N; ++i) {
            scanf("%d", &P[i]);
        }//for

        inversoes = 0;
        mergeSort(P, 0, N);

        printf("%s\n", (inversoes % 2) ? "Marcelo" : "Carlos");

        free(P);
    }//while

    return 0;
}//main