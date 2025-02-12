#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FRUTAS 100
#define MAX_NOME 50

int main() {
    int teste, numFrutas, numCompras, quantidade;
    char nomeFruta[MAX_NOME], listaFrutas[MAX_FRUTAS][MAX_NOME];
    double custoTotal, precos[MAX_FRUTAS];

    scanf("%d", &teste);

    int i, j, k;
    for (i = 0; i < teste; i++){
        scanf("%d", &numFrutas);

        for (j = 0; j < numFrutas; j++){
            scanf("%s %lf", listaFrutas[j], &precos[j]);
        }//for

        scanf("%d", &numCompras);

        custoTotal = 0.0;
        for (j = 0; j < numCompras; j++){
            scanf("%s %d", nomeFruta, &quantidade);

            for (k = 0; k < numFrutas; k++){
                if (strcmp(nomeFruta, listaFrutas[k]) == 0){
                    custoTotal += quantidade * precos[k];
                    break;
                }//if
            }//for
        }//for

        printf("R$ %.2lf\n", custoTotal);
    }//for

    return 0;
}//main
