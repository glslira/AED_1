#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159

int main(){

    double angulo, distanciaArvore, alturaElfo;
    double alturaArvore, quantidadeCordao;


    while (scanf("%lf %lf %lf", &angulo, &distanciaArvore, &alturaElfo) != EOF){
        alturaArvore = tan(angulo * (PI / 180.0)) * distanciaArvore + alturaElfo;
        quantidadeCordao = alturaArvore * 5.0;
        
        printf("%.2f\n", quantidadeCordao);
    }//while
    return 0;
}//main