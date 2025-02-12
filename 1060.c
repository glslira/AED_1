#include <stdio.h>

int main() {
    double numero;
    int contagemPositivos = 0;

    for (int i = 0; i < 6; ++i) {
        scanf("%lf", &numero);

        if (numero > 0) {
            ++contagemPositivos;
        } //if
    } //for

    printf("%d valores positivos\n", contagemPositivos);

    return 0;
} //main
