#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double jurosSimples(double capital, int meses, double taxa) {
    return meses * taxa * capital;
} //jurosSimples

double jurosCompostos(double capital, int meses, double taxa) {
    return capital * (pow(1 + taxa, meses) - 1);
} //jurosCompostos

int main() {
    int meses;
    double taxa, capital, simples, compostos;

    while (scanf("%lf %lf %d", &capital, &taxa, &meses) != EOF) {
        simples = jurosSimples(capital, meses, taxa);
        compostos = jurosCompostos(capital, meses, taxa);

        printf("DIFERENCA DE VALOR = %.2lf\n", compostos - simples);
        printf("JUROS SIMPLES = %.2lf\n", simples);
        printf("JUROS COMPOSTO = %.2f\n", compostos);
    } //while

    return 0;
} //main
