#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Palavra{
    char texto[3000];
}Palavra;

void ordenaTamanho(Palavra *palavras, unsigned tam){
    int i = 1, j;
    Palavra aux;

    for(i = 1; i < tam; i++){
        aux = palavras[i];
        j = i - 1;

        while (j >= 0 && strlen(palavras[j].texto) < strlen(aux.texto)){
            palavras[j + 1] = palavras[j];
            j--;
        }//while

        palavras[j + 1] = aux;
    }//for
}//ordenaTamanho

int main(){
    int casos;
    int i, j, k;

    scanf("%d", &casos);
    getchar();

    Palavra palavras[60];
    char entrada[3000];

    while (casos--) {

        int var;

        for (var = 0; var < 60; var++){
            palavras[var].texto[0] = '\0';
        }//for

        for (var = 0; var < 3000; var++){
            entrada[var] = '\0';
        }//for

        fgets(entrada, sizeof(entrada), stdin);
        entrada[strcspn(entrada, "\n")] = '\0';

        i = 0, j = 0, k = 0;

        while (entrada[i] != '\0'){
            if (entrada[i] != ' '){
                palavras[j].texto[k++] = entrada[i];
            } else {
                palavras[j].texto[k] = '\0';
                j++;
                k = 0;
            }//else
            i++;
        }//while

        palavras[j].texto[k] = '\0';
        j++;

        ordenaTamanho(palavras, j);

        for (i = 0; i < j; i++){
            if (i != 0) printf(" ");
            printf("%s", palavras[i].texto);
        }//for
        printf("\n");
    }//while

return 0;
}//main