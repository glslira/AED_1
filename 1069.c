#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char expressao[1001];
    int numTestes, tamanho, numPares, contador;

    scanf("%d", &numTestes);

    for (int teste = 0; teste < numTestes; ++teste) {
        scanf("%s", expressao);

        numPares = 0;
        contador = 0;
        tamanho = strlen(expressao);

        for (int i = 0; i < tamanho; ++i) {
            if (expressao[i] == '<') {
                ++contador;
            } else if (expressao[i] == '>' && contador > 0) {
                --contador;
                ++numPares;
            }//else if
        }//for

        printf("%d\n", numPares);
    }//for

    return 0;
}//main
