#include <stdio.h>
#include <stdlib.h>

int calculaMaiorDivisorComum(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    } //while
    return a;
} //calculaMaiorDivisorComum

int calculaMenorDivisorComum(int a, int b) {
    return (a / calculaMaiorDivisorComum(a, b)) * b;
} //calculaMenorDivisorComum

int main() {
    int N;
    scanf("%d", &N);

    int buracos[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &buracos[i]);
        buracos[i]--;
    } //for

    int ciclos[N];
    for (int i = 0; i < N; i++) {
        int visitado[N];
        for (int j = 0; j < N; j++) {
            visitado[j] = 0;
        } //for

        int atual = i, tamanhoCiclo = 0;
        while (!visitado[atual]) {
            visitado[atual] = 1;
            atual = buracos[atual];
            tamanhoCiclo++;
        } //while

        ciclos[i] = tamanhoCiclo;
    } //for

    int mmc = ciclos[0];
    for (int i = 1; i < N; i++) {
        mmc = calculaMenorDivisorComum(mmc, ciclos[i]);
    } //for

    printf("%d\n", mmc);

    return 0;
} //main
