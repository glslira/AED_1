#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main() {
    double consumoMedio;
    int contadorCidade, numResidencias, numMoradores, consumo, totalMoradores, totalConsumo, primeiro, consumosPorPessoa[201];

    contadorCidade = 0;
    while (scanf("%d", &numResidencias) && numResidencias != 0) { //while
        if (contadorCidade) {
            printf("\n");
        } //if

        for (int i = 0; i < 201; ++i) {
            consumosPorPessoa[i] = 0;
        } //for

        totalMoradores = 0;
        totalConsumo = 0;
        for (int i = 0; i < numResidencias; ++i) { //for
            scanf("%d %d", &numMoradores, &consumo);

            totalMoradores += numMoradores;
            totalConsumo += consumo;
            consumosPorPessoa[consumo / numMoradores] += numMoradores;
        } //for

        printf("Cidade# %d:\n", ++contadorCidade);
        primeiro = 1;
        for (int i = 0; i < 201; ++i) { //for
            if (consumosPorPessoa[i] > 0) {
                if (primeiro) {
                    primeiro = 0;
                } else {
                    printf(" ");
                } //else

                printf("%d-%d", consumosPorPessoa[i], i);
            } //if
        } //for

        consumoMedio = ((100 * totalConsumo) / totalMoradores) / 100.0;
        printf("\nConsumo medio: %.2lf m3.\n", consumoMedio);
    } //while

    return 0;
} //main