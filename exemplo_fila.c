#include <stdio.h>
#include <stdlib.h>

#define ELEMENTOS_FILA 4

typedef struct{
    int vetor[ELEMENTOS_FILA];
    int fim;
} Fila;

int main(){

    Fila f;
    f.fim = 0;

    //incluir o numero na fila
    f.vetor[f.fim] = 15;
    f.fim++;

    f.vetor[f.fim] = 25;
    f.fim++;

    f.vetor[f.fim] = 45;
    f.fim++;

    //retirar o elemento da fila
    printf("Elemento que sai da fila: %d\n",f.vetor[0]);
    f.vetor[0] = f.vetor[1];
    f.vetor[1] = f.vetor[2];
    f.fim--; //ultima posição recuou 1

return 0;
}//main