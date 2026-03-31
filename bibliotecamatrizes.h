#ifndef BIBLIOTECAMATRIZES_H_INCLUDED
#define BIBLIOTECAMATRIZES_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>

float buscarElementoMatriz(float vetor[], int linha, int coluna);
void adicionarElementoMatriz(float vetor[], float elemento, int linha, int coluna);
void removerElementoMatriz(float vetor[], int linha, int coluna);
void multiplicarMatrizes(float vetorA[], float vetorB[], float vetorC[]);
void dimensionarMatriz(float vetor[], int linhas, int colunas);
void criarCopia(float vetor[], float vetorCopia[]);
void criarTransposta(float vetor[], float vetorTransposto[]);
void multiplicarMatriz(float vetorA[], float vetorB[], float vetorC[]);

void dimensionarMatriz(float vetor[], int linhas, int colunas){
    vetor[0] = linhas; vetor[1] = colunas;
}

void preencherMatriz(float vetor[])
{
    for(int linha=1; linha <= (int)vetor[0]; linha++){
        for(int coluna=1; coluna <= (int)vetor[1]; coluna++){
            printf("Digite um elemento %dx%d: ",linha,coluna);
            float elemento; scanf("%f",&elemento);
            adicionarElementoMatriz(vetor, elemento, linha, coluna);
        }
    }
}

void anularMatriz(float vetor[])
{
    for(int linha=1; linha <= (int)vetor[0]; linha++){
        for(int coluna=1; coluna <= (int)vetor[1]; coluna++){
            removerElementoMatriz(vetor, linha, coluna);
        }
    }
}

void exibirMatriz(float vetor[])
{
    for(int linha=1; linha <= (int)vetor[0]; linha++){
        for(int coluna=1; coluna <= (int)vetor[1]; coluna++){
            printf("%6.2f ", buscarElementoMatriz(vetor, linha, coluna));
        }
        putchar('\n');
    }
}

void adicionarElementoMatriz(float vetor[], float elemento, int linha, int coluna)
{
    vetor[2 + (linha - 1) * (int)vetor[1] + (coluna - 1)] = elemento;
}

void removerElementoMatriz(float vetor[], int linha, int coluna)
{
    vetor[2 + (linha - 1) * (int)vetor[1] + (coluna - 1)] = 0;
}

float buscarElementoMatriz(float vetor[], int linha, int coluna)
{

    return vetor[2 + (linha - 1) * (int)vetor[1] + (coluna - 1)];
}

void somarMatrizes(float vetorA[], float vetorB[], float vetorC[])
{
    if (vetorA[0] != vetorB[0] || vetorA[1] != vetorB[1])
    {
        puts("Não é possível efetuar a soma dessas matrizes. A ordem é diferente.");
        return;
    }
    for(int linha=1; linha <= vetorA[0]; linha++){
        for(int coluna=1; coluna <= vetorA[1]; coluna++){
            adicionarElementoMatriz(vetorC, buscarElementoMatriz(vetorA, linha, coluna) + buscarElementoMatriz(vetorB, linha, coluna), linha, coluna);
        }
    }
}
void subtrairMatriz(float vetorA[], float vetorB[], float vetorC[])
{
    if (vetorA[0] != vetorB[0] || vetorA[1] != vetorB[1])
    {
        puts("Não é possível efetuar a soma dessas matrizes. A ordem é diferente.");
        return;
    }
    for(int linha=1; linha <= vetorA[0]; linha++){
        for(int coluna=1; coluna <= vetorA[1]; coluna++){
            adicionarElementoMatriz(vetorC, buscarElementoMatriz(vetorA, linha, coluna) - buscarElementoMatriz(vetorB, linha, coluna), linha, coluna);
        }
    }
}

//Funções de teste
void criarCopia(float vetor[], float vetorCopia[]){
    for(int linha=1; linha <= (int)vetor[0]; linha++){
        for(int coluna=1; coluna <= (int)vetor[1]; coluna++){
            adicionarElementoMatriz(vetorCopia, buscarElementoMatriz(vetor, linha, coluna), linha, coluna);
        }
    }
}

void criarTransposta(float vetor[], float vetorTransposto[]){
    for(int linha=1; linha <= (int)vetor[0]; linha++){
        for(int coluna=1; coluna <= (int)vetor[1]; coluna++){
            adicionarElementoMatriz(vetorTransposto, buscarElementoMatriz(vetor, coluna, linha), linha, coluna);
        }
    }
}

int matrizIdentidade(float vetor[]){
    for(int linha = 1; linha <= vetor[0]; linha++){
        for(int coluna = 1; coluna <= vetor[0]; coluna++){
            if(linha==coluna){
                if(buscarElementoMatriz(vetor,linha,coluna)!=1) return 0;
            }else if(buscarElementoMatriz(vetor,linha,coluna)!=0) return 0;
        }
    }
    return 1;
}
void multiplicarMatriz(float vetorA[], float vetorB[], float vetorC[]){
    if(vetorA[1] != vetorB[0]){
        puts("É impossível realizar essa multiplicação.");
        return ;
    }

    float vetorCopia[2 + (int)vetorB[1] * (int)vetorB[0]];
    dimensionarMatriz(vetorCopia, (int)vetorB[1], (int)vetorB[0]);
    criarTransposta(vetorB, vetorCopia);

    for(int linha = 1; linha <= vetorA[0]; linha++){
        for(int coluna = 1; coluna <= vetorB[1]; coluna++){
            float resultado = 0;
            for(int i = 1; i <= vetorA[1]; i++){
                resultado += buscarElementoMatriz(vetorA, linha, i) * buscarElementoMatriz(vetorCopia, coluna, i);
            }
            adicionarElementoMatriz(vetorC, resultado, linha, coluna);
        }
    }
}


// void multiplicarMatrizRafael(float vetorA[], float vetorB[], float **vetorC){
//     if(vetorA[1]!=vetorB[0]){
//         puts("É impossível realizar essa multiplicação.");
//         return ;
//     }
//     int novoTamanhoMatriz = 2+(vetorA[0]*vetorB[1]);
//     float *vetorTemporario = realloc(*vetorC,novoTamanhoMatriz*sizeof(float));
//     if(vetorTemporario==NULL){
//         puts("Erro na realocação de memória");
//         return ;
//     }
//     *vetorC = vetorTemporario;
//     (*vetorC)[0] = (float)vetorA[0];
//     (*vetorC)[1] = (float)vetorB[1];
//     printf("teste realoc | l: %d | c: %d",(int)(*vetorC)[0],(int)(*vetorC)[1]);
    
// }

#endif // BIBLIOTECAMATRIZES_H_INCLUDED;
