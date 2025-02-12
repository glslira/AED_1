#include <stdlib.h>
#include <stdio.h>

int comparar(const void *x, const void *y){
    return *(int *)x - *(int *)y;
}//comparar

int pesquisar(int *marmores, int n, int valor){
    int inicio = 0, fim = n, meio;

    while (inicio < fim){
        meio = (inicio + fim) / 2;

        if (marmores[meio] < valor)
            inicio = meio + 1;
        else
            fim = meio;
    }//while

    return (inicio < n && marmores[inicio] == valor) ? inicio + 1 : -1;
}//pesquisar

int main(){
    int *marmores;
    int T, N, Q, teste, resultado;

    T = 1;
    while (scanf("%d %d", &N, &Q) && (N || Q)){
        marmores = (int *)malloc(sizeof(int) * N);
        if (!marmores){
            fprintf(stderr, "Erro de alocação de memória\n");
            return 1;
        }//if

        for (int i = 0; i < N; ++i){
            scanf("%d", &marmores[i]);
        }//for

        qsort(marmores, N, sizeof(int), comparar);

        printf("CASE# %d:\n", T++);
        for (int i = 0; i < Q; ++i){
            scanf("%d", &teste);
            resultado = pesquisar(marmores, N, teste);

            if (resultado == -1)
                printf("%d not found\n", teste);
            else
                printf("%d found at %d\n", teste, resultado);
        }//for

        free(marmores);
    }//while

return 0;
}//main