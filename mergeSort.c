#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void intercala(int p, int q, int r, int v[]){

    int i, j, k, *w;

    w = malloc ((r-p) * sizeof (int));
    i = p; j = q; k = 0;

    while (i < q && j < r){
        if (v[i] <= v[j]) w[k++] = v[i++];
        else w[k++] = v[j++];
    }//while

    while (i < q){
        w[k++] = v[i++];
    }//whiçe
    while (j < r){
        w[k++] = v[j++];
    }//while

    for (i = p; i < r; i++){
        v[i] = w[i-p];
    }//for

    free (w);
}//intercala

void mergeSort(int p, int r, int v[]){

    if (p < r - 1) {
        int q = (p + r)/2;
        mergeSort (p, q, v);
        mergeSort (q, r, v);
        intercala (p, q, r, v);
    }//if
}//mergeSort

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
        mergeSort(0, n, numeros);
        clock_t final = clock();

        //calcula o tempo levado para executar Insercao
        double ciclo = (double)(final - inicial) / CLOCKS_PER_SEC;
        //exibe a escala e o tempo consumido
        printf("mergeSort - %d: %.2f segundos\n", n, ciclo);
        
        free(numeros);
    }//for externo

return 0;
}//main