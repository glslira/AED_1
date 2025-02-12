#include <stdio.h>
#include <stdlib.h>

int comparar(const void *a, const void *b){
    return (*(int *)b - *(int *)a);
}//comparar

int main() {
    int casos, quantidade, i, iguais;

    scanf("%d", &casos);

    while (casos--){
        scanf("%d", &quantidade);

        int notas[quantidade], ordenadas[quantidade];
        iguais = 0;

        for (i = 0; i < quantidade; i++){
            scanf("%d", &notas[i]);
            ordenadas[i] = notas[i];
        }//for

        qsort(ordenadas, quantidade, sizeof(int), comparar);

        for (i = 0; i < quantidade; i++) {
            if (notas[i] == ordenadas[i]) {
                iguais++;
            }//if
        }//for

        printf("%d\n", iguais);
    }//while

return 0;
}//main