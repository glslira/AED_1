#include <stdio.h>

int main(){

    int dia, mes, ano;

    scanf("%d", &dia);

    ano = dia/365;
    dia = dia%365;
    mes = dia/30;
    dia = dia%30;

    printf("%d ano(s)\n%d mes(es)\n%d dia(s)\n", ano, mes, dia);

return 0;
}//main