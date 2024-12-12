#include <stdio.h>
#include <stdlib.h>

int main(){

    FILE *arquivo = fopen("dados.txt", "r");

    if (arquivo == NULL){
        printf("Erro ao abrir o arquivo!\n");
        return 1;
    }//if

    int n;
    double tempo;

    FILE *saida = fopen("Analise_Ordenacao.csv", "w");
    
    if (saida == NULL){
        printf("Erro ao criar o arquivo CSV!\n");
        fclose(arquivo);
        return 1;
    }//if
    
    fprintf(saida, "n,tempo\n");
    
    while (fscanf(arquivo, "%d %lf", &n, &tempo) != EOF){
        fprintf(saida, "%d,%.2f\n", n, tempo);
    }//while
    fclose(arquivo);
    fclose(saida);
    
return 0;
}//main