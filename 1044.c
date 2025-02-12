#include <stdio.h>
#include <stdlib.h>

void inverte(int* a, int* b){
    int aux = *a;
    *a = *b;
    *b = aux;
}//inverte

int main(){
    int A, B;

    scanf("%d %d", &A, &B);

    if(A < B){
        inverte(&A, &B);
    }//if

    if(A % B){
        printf("Nao sao Multiplos\n");
    } else {
        printf("Sao Multiplos\n");
    }//else

    return 0;
}//main