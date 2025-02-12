#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct Pilha{
    int topo;
    int elementos[1000];
} Pilha;

Pilha criaPilha(){
    Pilha p;
    p.topo = -1;
return p;
}//criaPilha

bool verificaVazia(Pilha *p){
    return p->topo == -1;
}//verificaVazia

void empilhar(Pilha *p, long long int valor){
    p->topo++;
    p->elementos[p->topo] = valor;
}//empilhar

void desempilhar(Pilha *p) {
    if (!verificaVazia(p)){
        p->topo--;
    } else {
        printf("EMPTY\n");
    }//else
}//desempilhar

int buscaMenor(Pilha *p){
    if (verificaVazia(p)){
        return -1;
    }//if

    int menor = p->elementos[0];
    for (int i = 1; i <= p->topo; i++){
        if (p->elementos[i] < menor){
            menor = p->elementos[i];
        }//if
    }//for

return menor;
}//buscaMenor

int main() {
    int quantidade;
    char opcao[10];
    int numero, resultado;

    scanf("%d", &quantidade);
    Pilha pilha = criaPilha();

    while (quantidade--){
        scanf("%s", opcao);

        if (strcmp(opcao, "PUSH") == 0){
            scanf("%d", &numero);
            empilhar(&pilha, numero);
        } else if (strcmp(opcao, "POP") == 0){
            desempilhar(&pilha);
        } else {
            resultado = buscaMenor(&pilha);
            if (resultado == -1){
                printf("EMPTY\n");
            } else {
                printf("%d\n", resultado);
            }//else
        }//else
    }//while

return 0;
}//main