#include <stdio.h>
#include <stdlib.h>

//função que escreve a matriz 9x9 que o usuário digitou
void escreveSudoku(int sudoku[9][9]){
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            scanf("%d", &sudoku[i][j]);
        }//for interno
    }//for externo
}//escreveSudoku

//função que verifica se as linhas obedecem a regra do sudoku
int verificaLinha(int sudoku[9][9], int linha){
    int verifica[10] = {0}; //vetor utilizado para verificar se o numero já apareceu anteriormente na linha

    //se o numero nao estiver entre 1 e 9 ou ele já apareceu anteriormete na linha, não é sudoku
    for(int i = 0; i < 9; i++){
        int numeroAtual = sudoku[linha][i];
        if(testaNumero(numeroAtual) == 1 || verifica[numeroAtual] != 0){
            return 1;
        }//if
        verifica[numeroAtual]++; //sempre que o numero aparece na linha, adiciona 1 digito ao contador
    }//for

return 0;
}//verificaLinha

//função que verifica se as colunas obedecem a regra do sudoku
int verificaColuna(int sudoku[9][9], int coluna){
    int verifica[10] = {0}; //vetor utilizado para verificar se o numero já apareceu anteriormente na coluna

    //se o numero nao estiver entre 1 e 9 ou ele já apareceu anteriormete na coluna, não é sudoku
    for(int i = 0; i < 9; i++){
        int numeroAtual = sudoku[coluna][i];
        if(testaNumero(numeroAtual) == 1 || verifica[numeroAtual] != 0){
            return 1;
        }//if
        verifica[numeroAtual]++; //sempre que o numero aparece na coluna, adiciona 1 digito ao contador
    }//for

return 0;
}//verificaLinha

//função que verifica se as submatrizes 3x3 obedecem a regra do sudoku
int verificaMatriz(int sudoku[9][9], int x, int y){
    int verifica[10] = {0}; //vetor utilizado para verificar se o numero já apareceu anteriormente na submatriz

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            int numeroAtual = sudoku[x+i][y+j];
            if(testaNumero(numeroAtual) == 1 || verifica[numeroAtual] != 0){
                return 1;
            }//if
            verifica[numeroAtual]++;
        }//for interno
    }//for externo

return 0;
}//verificaMatriz

//função que une as outras 3 funções de verificação do sudoku
int verificaSudoku(int sudoku[9][9]){
    
    //for que passa por todas as linhas e coluna e verifica-as
    for(int i = 0; i < 9; i++){
        if(verificaLinha(sudoku,i) == 1 || verificaColuna(sudoku,i) == 1){
            return 1;
        }//if
    }//for

    //2 for que passam pelas 9 submatrizes da matriz maior, verificando-as
    // i+3 pois passa da posição inicial sudoku[0][0] para a sudoku [0][2], mudando de submatriz
    for(int i = 0; i < 9; i = i + 3){
        for(int j = 0; j < 9; j = j + 3){
            if(verificaMatriz(sudoku, i, j) ==  1){
                return 1;
            }//if
        }//for interno
    }//for externo

return 0;
}//verificaSudoku

//função que testa se os numeros estão entre 1 e 9
int testaNumero(int numero){

    if(numero <= 0 || numero >= 10){
        return 1;
    }//if

return 0;
}//testaNumero

int main(){
    int n, sudoku[9][9];
    
    scanf("%d", &n);

    //recebe o sudoku e verifica se é valido ou não
    for(int i = 1; i <= n; i++){
        escreveSudoku(sudoku);
        printf("Instancia %d\n", i);

        if(verificaSudoku(sudoku) == 0){
            printf("NAO\n");
        }else{
            printf("SIM\n");
        }//else
    }//for

return 0;
}//main