#include <stdio.h>
#include <stdlib.h>

struct NoPilha {
    int valor;
    struct NoPilha* abaixo;
};

struct Pilha {
    int tamanho;
    struct NoPilha* topo;
};

void empilhar(struct Pilha* p, int valor) {
    p->tamanho += 1;
    struct NoPilha* novoTopo = (struct NoPilha*) malloc(sizeof(struct NoPilha));
    novoTopo->valor = valor;
    novoTopo->abaixo = p->topo;
    p->topo = novoTopo;
} //empilhar

void desempilhar(struct Pilha* p) {
    if (p->tamanho > 0) {
        p->tamanho -= 1;
        struct NoPilha* velhoTopo = p->topo;
        p->topo = p->topo->abaixo;
        free(velhoTopo);
    } //if
} //desempilhar

int topo(struct Pilha* p) {
    return p->topo->valor;
} //topo

int tamanho(struct Pilha* p) {
    return p->tamanho;
} //tamanho

int vazia(struct Pilha* p) {
    return p->tamanho == 0;
} //vazia

void inicializar(struct Pilha* p) {
    p->tamanho = 0;
    p->topo = NULL;
} //inicializar

void destruir(struct Pilha* p) {
    while (!vazia(p)) {
        desempilhar(p);
    } //while
} //destruir

int main() {
    int numVagoes, valor;
    struct Pilha A, estacao, B;

    while (scanf("%d", &numVagoes) != EOF) { //while
        if (!numVagoes) {
            break;
        } //if

        while (scanf("%d", &valor)) { //while
            if (!valor) {
                printf("\n");
                break;
            } //if

            inicializar(&A);
            inicializar(&estacao);
            inicializar(&B);

            empilhar(&A, valor);
            empilhar(&B, 1);
            for (int i = 2; i <= numVagoes; ++i) { //for
                scanf("%d", &valor);
                empilhar(&A, valor);
                empilhar(&B, i);
            } //for

            while (!vazia(&A) || !vazia(&estacao) || !vazia(&B)) { //while
                if (!vazia(&A) && !vazia(&B) && topo(&A) == topo(&B)) {
                    desempilhar(&A);
                    desempilhar(&B);
                } else if (!vazia(&estacao) && !vazia(&B) && topo(&estacao) == topo(&B)) {
                    desempilhar(&estacao);
                    desempilhar(&B);
                } else if (!vazia(&A)) {
                    empilhar(&estacao, topo(&A));
                    desempilhar(&A);
                } else {
                    break;
                } //else
            } //while

            if (vazia(&A) && vazia(&estacao) && vazia(&B)) {
                printf("Yes\n");
            } else {
                printf("No\n");
            } //else

            destruir(&A);
            destruir(&estacao);
            destruir(&B);
        } //while
    } //while

    return 0;
} //main
