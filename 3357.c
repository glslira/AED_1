#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void lerNomes(char matriz[][13], int quantidade) {
    int i;
    for (i = 0; i < quantidade; i++) { //for
        scanf("%s", matriz[i]);
    } //for
} //lerNomes

int main() {
    // Variáveis
    int quantidadeNomes, i;
    double litrosGarrafa, litrosCuia;
    char nomes[100][13];

    // Entrada
    scanf("%d %lf %lf", &quantidadeNomes, &litrosGarrafa, &litrosCuia);
    getchar();
    lerNomes(nomes, quantidadeNomes);

    // Processamento
    double litrosRestantes = litrosGarrafa;
    int contador = -1;
    while (1) { //while
        contador++;
        if (litrosRestantes - litrosCuia <= 0) {
            break;
        } else {
            litrosRestantes = round((litrosRestantes - litrosCuia) * 10.0) / 10.0;
        } //else
    } //while
    
    // Saída
    printf("%s %.1lf\n", nomes[contador % quantidadeNomes], litrosRestantes);
    return 0;
} //main