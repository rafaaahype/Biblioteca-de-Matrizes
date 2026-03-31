#ifndef BIBLIOTECAMATRIZES_H_INCLUDED
#define BIBLIOTECAMATRIZES_H_INCLUDED
#include <stdio.h>

float buscarElementoMatriz(float vetor[], int linha, int coluna);
void adicionarElementoMatriz(float vetor[], float elemento, int linha, int coluna);
void removerElementoMatriz(float vetor[], int linha, int coluna);

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
            adicionarElementoMatriz(vetor, 0, linha, coluna);
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
#endif // BIBLIOTECAMATRIZES_H_INCLUDED;
