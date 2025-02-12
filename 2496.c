#include <stdio.h>
#include <stdlib.h>

int main(void) {
    short numTestes, numCaracteres, i, j, contagemErros;
    char caracterLido;

    scanf("%hd", &numTestes);

    for (j = 0; j < numTestes; ++j) { //for
        scanf("%hd", &numCaracteres);
        while (getchar() != '\n');

        contagemErros = 0;

        for (i = 0; i < numCaracteres; ++i) { //for
            scanf("%c", &caracterLido);
            if (caracterLido != i + 65) {
                ++contagemErros;
            } //if
        } //for

        printf((contagemErros == 2) ?
            "There are the chance.\n" :
            "There aren't the chance.\n");
    } //for

    return 0;
} //main