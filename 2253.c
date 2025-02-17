#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main() {
    char S[101];
    int n, errado, maiuscula, minuscula, numero;

    while (gets(S) != NULL) {
        n = strlen(S);

        if (n < 6 || n > 32) {
            printf("Senha invalida.\n");
            continue;
        } //if

        errado = 0;
        maiuscula = 0;
        minuscula = 0;
        numero = 0;

        for (int i = 0; i < n; ++i) {
            if (isalpha(S[i])) {
                if (S[i] == tolower(S[i])) {
                    minuscula = 1;
                } else {
                    maiuscula = 1;
                } //else
            } else if (isdigit(S[i])) {
                numero = 1;
            } else {
                errado = 1;
                break;
            } //else if
        } //for

        if (errado || !(maiuscula && minuscula && numero)) {
            printf("Senha invalida.\n");
        } else {
            printf("Senha valida.\n");
        } //else
    } //while

    return 0;
} //main
