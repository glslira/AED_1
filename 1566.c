#include <stdio.h>
#include <stdlib.h>

int main(){
    int NC, N, altura, first, alturas[231];

    scanf("%d", &NC);

    int k, i, j;
    for (k = 0; k < NC; ++k){
        for (i = 0; i < 231; ++i){
            alturas[i] = 0;
        }//for

        scanf("%d", &N);

        for (int i = 0; i < N; ++i){
            scanf("%d", &altura);
            alturas[altura]++;
        }//for

        first = 1;
        for (i = 20; i < 231; ++i){
            for (j = 0; j < alturas[i]; ++j){
                if (first){
                    first = 0;
                } else {
                    printf(" ");
                }//else
                printf("%d", i);
            }//for
        }//for
        printf("\n");
    }//for

    return 0;
}//main