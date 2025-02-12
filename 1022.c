#include <stdio.h>
#include <stdlib.h>

struct Fracao {
    int numerador, denominador;
};

struct Fracao somar(struct Fracao f1, struct Fracao f2) {
    struct Fracao resultado;

    resultado.numerador = f1.numerador * f2.denominador + f2.numerador * f1.denominador;
    resultado.denominador = f1.denominador * f2.denominador;

    return resultado;
} //somar

struct Fracao subtrair(struct Fracao f1, struct Fracao f2) {
    struct Fracao resultado;

    resultado.numerador = f1.numerador * f2.denominador - f2.numerador * f1.denominador;
    resultado.denominador = f1.denominador * f2.denominador;

    return resultado;
} //subtrair

struct Fracao multiplicar(struct Fracao f1, struct Fracao f2) {
    struct Fracao resultado;

    resultado.numerador = f1.numerador * f2.numerador;
    resultado.denominador = f1.denominador * f2.denominador;

    return resultado;
} //multiplicar

struct Fracao dividir(struct Fracao f1, struct Fracao f2) {
    struct Fracao resultado;

    resultado.numerador = f1.numerador * f2.denominador;
    resultado.denominador = f2.numerador * f1.denominador;

    return resultado;
} //dividir

int calcularMDC(int a, int b) {
    return (b == 0) ? a : calcularMDC(b, a % b);
} //calcularMDC

struct Fracao irredutivel(struct Fracao f) {
    int mdc = (f.numerador < 0) ? calcularMDC(-f.numerador, f.denominador) : calcularMDC(f.numerador, f.denominador);

    f.numerador /= mdc;
    f.denominador /= mdc;

    return f;
} //irredutivel

int main() {
    int numOperacoes;
    char operador;
    struct Fracao f1, f2, resultado;

    scanf("%d", &numOperacoes);

    for (int i = 0; i < numOperacoes; ++i) { //for
        scanf("%d / %d %c %d / %d", &f1.numerador, &f1.denominador, &operador, &f2.numerador, &f2.denominador);

        switch (operador) { //switch
            case '+':
                resultado = somar(f1, f2);
                break;
            case '-':
                resultado = subtrair(f1, f2);
                break;
            case '*':
                resultado = multiplicar(f1, f2);
                break;
            case '/':
                resultado = dividir(f1, f2);
                break;
        } //switch

        printf("%d/%d = ", resultado.numerador, resultado.denominador);
        resultado = irredutivel(resultado);
        printf("%d/%d\n", resultado.numerador, resultado.denominador);
    } //for

    return 0;
} //main
