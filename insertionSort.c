#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void Insercao(int n, int v[]){

    int i, j, x;
    for (j = 1; j < n; j++){
        x = v[j];
        for (i = j - 1; i >= 0 && v[i] > x; i--){
            v[i + 1] = v[i];
        }//for interno
        v[i + 1] = x;
    }//for externo

}//Insercao

int main(){

    int tempo = 20000;
    int tempo_max = 400000;
    int aumento = 20000;
    int n, i;

    srand(time(NULL));

    for(n = tempo; n <= tempo_max; n = n + aumento){
        int *numeros = malloc(n * sizeof(int));

        for(i = 0; i < n; i++){
            numeros[i] = rand(); //gera numeros aleatorios para o programa
        }//for interno

        //os dois clock_t sao funções da biblioteca time.h que medem o inicial e o tempo final para executar a função Insercao
        clock_t inicial = clock();
        Insercao(n, numeros);
        clock_t final = clock();

        //calcula o tempo levado para executar Insercao
        double ciclo = (double)(final - inicial) / CLOCKS_PER_SEC;
        //exibe a escala e o tempo consumido
        printf("InsertionSort - %d: %.2f segundos\n", n, ciclo);

        free(numeros);
    }//for externo


return 0;
}//main