#include <stdio.h>
#include <stdlib.h>

int main(){
    double A, B, C;
    double perimetroTriangulo, areaTrapezio;

    scanf("%lf %lf %lf", &A, &B, &C);

    if(A < B + C && B < A + C && C < A + B){
        perimetroTriangulo = A + B + C;
        printf("Perimetro = %.1lf\n", perimetroTriangulo);
    }else{
        areaTrapezio = (A + B)/2 * C;
        printf("Area = %.1lf\n", areaTrapezio);
    }//else

    return 0;
}//main