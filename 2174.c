#include <string.h>
#include <stdlib.h>
#include <stdio.h>

char pomekons[1001][151];

int busca(char* pomekon, int n) {
    for (int i = 0; i < n; ++i) {
        if (!strcmp(pomekons[i], pomekon)) {
            return i;
        } //if
    } //for

    return -1;
} //busca

int main() {
    int N, p;
    char S[1001];

    for (int i = 0; i < 1001; ++i) {
        for (int j = 0; j < 151; ++j) {
            pomekons[i][j] = '\0';
        } //for
    } //for

    scanf("%d\n", &N);
    
    p = 0;
    for (int i = 0; i < N; ++i) {
        scanf("%s\n", S);

        if (busca(S, p) == -1) {
            strcpy(pomekons[p++], S);
        } //if
    } //for

    printf("Falta(m) %d pomekon(s).\n", 151 - p);

    return 0;
} //main
