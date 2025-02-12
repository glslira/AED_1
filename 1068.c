#include <string.h>
#include <stdio.h>

int main() {
    char expressao[1001];
    int indice, tamanho, contadorParenteses;

    while (scanf("%s", expressao) != EOF){
        contadorParenteses = 0;
        tamanho = strlen(expressao);

        for (indice = 0; indice < tamanho; ++indice) {
            if (expressao[indice] == '(') {
                ++contadorParenteses;
            } else if (expressao[indice] == ')') {
                if (contadorParenteses > 0) {
                    --contadorParenteses;
                } else {
                    break;
                } //else
            } //else if
        } //for

        if (indice == tamanho && contadorParenteses == 0) {
            printf("correct\n");
        } else {
            printf("incorrect\n");
        } //else
    } //while

    return 0;
} //main
