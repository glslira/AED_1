#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char morse(char *s) {
    if (strcmp(s, ".-") == 0) return 'a';
    if (strcmp(s, "-...") == 0) return 'b';
    if (strcmp(s, "-.-.") == 0) return 'c';
    if (strcmp(s, "-..") == 0) return 'd';
    if (strcmp(s, ".") == 0) return 'e';
    if (strcmp(s, "..-.") == 0) return 'f';
    if (strcmp(s, "--.") == 0) return 'g';
    if (strcmp(s, "....") == 0) return 'h';
    if (strcmp(s, "..") == 0) return 'i';
    if (strcmp(s, ".---") == 0) return 'j';
    if (strcmp(s, "-.-") == 0) return 'k';
    if (strcmp(s, ".-..") == 0) return 'l';
    if (strcmp(s, "--") == 0) return 'm';
    if (strcmp(s, "-.") == 0) return 'n';
    if (strcmp(s, "---") == 0) return 'o';
    if (strcmp(s, ".--.") == 0) return 'p';
    if (strcmp(s, "--.-") == 0) return 'q';
    if (strcmp(s, ".-.") == 0) return 'r';
    if (strcmp(s, "...") == 0) return 's';
    if (strcmp(s, "-") == 0) return 't';
    if (strcmp(s, "..-") == 0) return 'u';
    if (strcmp(s, "...-") == 0) return 'v';
    if (strcmp(s, ".--") == 0) return 'w';
    if (strcmp(s, "-..-") == 0) return 'x';
    if (strcmp(s, "-.--") == 0) return 'y';
    if (strcmp(s, "--..") == 0) return 'z';
    return ' ';
}//morse

void traduzirMorse(char *frase) {
    char *token = strtok(frase, ".......");
    int primeiraPalavra = 1;

    while (token != NULL) { 
        char *letra = strtok(token, "...");
        while (letra != NULL) { 
            char x[10];
            int i, j = 0;

            for (i = 0; i < strlen(letra); i++) { 
                if (letra[i] == '.') {
                    x[j++] = '*';
                } else if (letra[i] == '=') {
                    x[j++] = '.';
                } else if (letra[i] == '-') {
                    x[j++] = '-';
                } //else if
            } //for
            x[j] = '\0';

            printf("%c", morse(x));
            letra = strtok(NULL, "...");
        } //while

        if (!primeiraPalavra) {
            printf(" ");
        } //if
        primeiraPalavra = 0;
        token = strtok(NULL, ".......");
    } //while
    printf("\n");
} //traduzirMorse

int main() {
    int q;
    char entrada[1000];
    
    scanf("%d", &q);
    getchar();
    
    for (int p = 0; p < q; p++) {
        fgets(entrada, sizeof(entrada), stdin);
        entrada[strcspn(entrada, "\n")] = '\0';
        traduzirMorse(entrada);
    } //for

    return 0;
} //main
