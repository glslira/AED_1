//feito em grupo!

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    char **nomes = malloc(n * sizeof(char *));
    for (int i = 0; i < n; i++){
        nomes[i] = malloc(21 * sizeof(char));
        scanf("%s", nomes[i]);
    }//for

    for (int i = 0; i < n - 1; i++){
        for (int j = 0; j < n - i - 1; j++) {
            if (strcmp(nomes[j], nomes[j + 1]) > 0) {
                char *temp = nomes[j];
                nomes[j] = nomes[j + 1];
                nomes[j + 1] = temp;
            }//if
        }//for interno
    }//for externo

    printf("%s\n", nomes[k - 1]);

    for (int i = 0; i < n; i++){
        free(nomes[i]);
    }//for
    free(nomes);

    return 0;
}//main