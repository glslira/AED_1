#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>

typedef struct noPilha {
    char valor;
    struct noPilha* abaixo;
} noPilha;

typedef struct Pilha {
    int tamanho;
    struct noPilha* topo;
} Pilha;

void empilhar(Pilha* p, char valor) {
    p->tamanho += 1;
    noPilha* novoTopo = (noPilha*) malloc(sizeof(noPilha));
    
    novoTopo->valor = valor;
    novoTopo->abaixo = p->topo;
    p->topo = novoTopo;
}//empilhar

void desempilhar(Pilha* p) {
    if (p->tamanho > 0) {
        p->tamanho -= 1;
        noPilha* velhoTopo = p->topo;
        p->topo = p->topo->abaixo;
        free(velhoTopo);
    }//if
}//desempilhar

char topo(Pilha* p) {
    return p->topo->valor;
}//topo

int tamanho(Pilha* p) {
    return p->tamanho;
}//tamanho

int vazia(Pilha* p) {
    return p->tamanho == 0;
}//vazia

void inicializar(Pilha* p) {
    p->tamanho = 0;
    p->topo = NULL;
}//inicializar

void destruir(Pilha* p) {
    while (!vazia(p)) {
        desempilhar(p);
    }//while
}//destruir

int precedencia(char operador) {
    switch (operador) {
        case '+':
        case '-': return 1;
        case '*':
        case '/': return 2;
        case '^': return 3;
        default: return 0;
    }//swtich case
}//precedencia

int main() {
    int N, tam;
    Pilha p;
    char expressao[301];

    scanf("%d", &N);

    for (int k = 0; k < N; ++k) {
        scanf("%s", expressao);

        inicializar(&p);

        tam = strlen(expressao);
        for (int i = 0; i < tam; ++i) {
            if (isalpha(expressao[i]) || isdigit(expressao[i])) {
                printf("%c", expressao[i]);
            } else if (expressao[i] == '(') {
                empilhar(&p, expressao[i]);
            } else if (expressao[i] == ')') {
                while (!vazia(&p) && topo(&p) != '(') {
                    printf("%c", topo(&p));
                    desempilhar(&p);
                }//while
                if (!vazia(&p)) desempilhar(&p);
            } else {
                while (!vazia(&p) && topo(&p) != '(' && precedencia(expressao[i]) <= precedencia(topo(&p))) {
                    printf("%c", topo(&p));
                    desempilhar(&p);
                }//while
                empilhar(&p, expressao[i]);
            }//else
        }//for

        while (!vazia(&p)) {
            printf("%c", topo(&p));
            desempilhar(&p);
        }
        printf("\n");
    }//for

    return 0;
}//main