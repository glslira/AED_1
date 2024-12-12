#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int separa(int p, int r, int v[]){

    int c, j, k, t;

    c = v[r]; j = p;

    for (k = p; /*A*/ k < r; k++)
        if (v[k] <= c) {
            t = v[j], v[j] = v[k], v[k] = t;
            j++;
    }//for

    v[r] = v[j], v[j] = c;

    return j;
}//separa

void quickSort (int p, int r, int v[]) {
    int j;

    if (p < r) {
        j = separa (p, r, v);
        quickSort (p, j - 1, v);
        quickSort (j + 1, r, v);
    }//if
}//quickSort

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
        quickSort(0, n-1, numeros);
        clock_t final = clock();

        //calcula o tempo levado para executar Insercao
        double ciclo = (double)(final - inicial) / CLOCKS_PER_SEC;
        //exibe a escala e o tempo consumido
        printf("quickSort - %d: %.2f segundos\n", n, ciclo);
        
        free(numeros);
    }//for externo

return 0;
}//main