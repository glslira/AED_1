#include <stdio.h>
#include <stdlib.h>

int contarNumeros(int vetor[], int tamanhoVetor, int numero) {
    int i, contagem = 0;
    for (i = 0; i < tamanhoVetor; i++) { //for
        if (vetor[i] == numero) {
            contagem++;
        } //if
    } //for
    return contagem;
} //contarNumeros

void ordenacaoPorSelecao(int vetor[], int tamanhoVetor) {
    int i, j;
    for (i = 0; i < tamanhoVetor - 1; i++) { //for
        int min = i;
        for (j = i + 1; j < tamanhoVetor; j++) { //for
            if (vetor[j] < vetor[min]) {
                min = j;
            } //if
        } //for
        int aux = vetor[i];
        vetor[i] = vetor[min];
        vetor[min] = aux;
    } //for
} //ordenacaoPorSelecao

void copiarVetor(int vetorOrigem[], int vetorDestino[], int tamanhoVetorDestino, int limiteInferior) {
    int i, j;
    for (i = 0, j = limiteInferior; i < tamanhoVetorDestino; i++, j++) { //for
        vetorDestino[i] = vetorOrigem[j];
    } //for
} //copiarVetor

void lerVetor(int vetor[], int tamanhoVetor) {
    int i;
    for (i = 0; i < tamanhoVetor; i++) { //for
        scanf("%d", &vetor[i]);
    } //for
} //lerVetor

int main() {
    int tamanhoVetor, numRodadas;
    int limiteInferior, limiteSuperior, kMenor, guga, dabriel;
    int *vetor, *intervalo;
    int i;

    // Entrada
    scanf("%d %d", &tamanhoVetor, &numRodadas);
    vetor = (int*) malloc(tamanhoVetor * sizeof(int));
    lerVetor(vetor, tamanhoVetor);

    for (i = 0; i < numRodadas; i++) { //for
        scanf("%d %d %d %d %d", &limiteInferior, &limiteSuperior, &kMenor, &guga, &dabriel);

        // Processamento
        int tamanhoIntervalo = limiteSuperior - limiteInferior + 1;
        intervalo = (int*) malloc(tamanhoIntervalo * sizeof(int));
        copiarVetor(vetor, intervalo, tamanhoIntervalo, limiteInferior - 1);

        ordenacaoPorSelecao(intervalo, tamanhoIntervalo);
        int menorValor = intervalo[kMenor - 1];
        int contagemKEsimo = contarNumeros(intervalo, tamanhoIntervalo, menorValor);

        int diferencaGuga = abs(contagemKEsimo - guga);
        int diferencaDabriel = abs(contagemKEsimo - dabriel);

        char resultado = 'E';
        if (diferencaGuga < diferencaDabriel) {
            resultado = 'G';
        } else if (diferencaDabriel < diferencaGuga) {
            resultado = 'D';
        } //else if

        // Saída
        printf("%d %d %c\n", menorValor, contagemKEsimo, resultado);
        free(intervalo);
    } //for

    free(vetor);
    return 0;
} //main