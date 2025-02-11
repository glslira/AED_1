#include <stdio.h>
#include <stdlib.h>

#define TAMANHO_PILHA 20 //define o tamanho da pilha para 20

//cria a pilha
typedef struct {
    int vetor[TAMANHO_PILHA]; //tamanho da pilha
    int topo;
}Pilha;

//cabeçalho
void empilha(int valor, Pilha *pilha);
void desempilha(Pilha *pilha);
int isCheia(Pilha *pilha);
int isVazia(Pilha *pilha);

//Limpa o buffer do teclado
void flush_in(){ 
    int ch;
    while( (ch = fgetc(stdin)) != EOF && ch != '\n' ){} 
}//flush_in

//declaracao da função empilha
void empilha(int valor, Pilha *pilha){

    //testa se tem espaço
    if(pilha->topo < TAMANHO_PILHA){
        //empilhar
        pilha->vetor[pilha->topo] = valor;
        pilha->topo++;
    } else {
        //pilha cheia
        printf("Nao ha mais espaco na pilha\n");
    }//else

}//empilha

//declaração da função desempilha
void desempilha(Pilha *pilha){

    //testar se a pilha nao esta vazia
    if(pilha->topo > 0){
        //desempilhar
        pilha->topo--;
        printf("Elemento retirado: %d\n", pilha->vetor[pilha->topo]);
    } else {
        //pilha vazia
        printf("A pilha esta vazia\n");
    }//else

}//desempilha

//declaração da função isCheia
int isCheia(Pilha *pilha){

    if(pilha->topo < TAMANHO_PILHA){
        return 1;
    } else {
        return 0;
    }//else

}//isCheia

int isVazia(Pilha *pilha){

    if(pilha->topo > 0){
        return 1;
    } else {
        return 0;
    }//else

}//isVazia

void imprimePilha(Pilha *pilha){

    int i;
    for(i=(pilha->topo); i--; i>=0){
        printf("%d\n", pilha->vetor[i]);
    }//for
}//imprimePilha

int main(){

    char c = 'a'; //declara a variavel que da opcao ao usuario
    int valor; //variavel que recebe os valores a serem empilhados

    //declarar uma pilha
    Pilha p;    //cria a pilha, com tamanho 20
    p.topo = 0; //inicializa o topo da pilha na posição 0

    //criando um menu para o usuario
    while(c!='x'){  //encerra o programa se o usuario pressionar 'x'

        printf("\n\na - empilhar elemento\nr - remover elemento\ns - exibe elementos\nt - numero de elementos\nx - sair\n");
        printf("Digite um caractere:\n");
        scanf("%c", &c); //captura o caractere pressionado
        flush_in();

        switch(c){
            case 'a':
                printf("Digite o valor a ser empilhado: ");
                scanf("%d", &valor);
                empilha(valor, &p);
            break;

            case'r':
                desempilha(&p);
            break;

            case's':
                imprimePilha(&p);
            break;

            case't':
                printf("Numero de elementos: %d", p.topo);
            break;

            case'x':

            break;

            default:

            break;
        }//switch
    }//while

    return 0;
}//main