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

int contarSaidas(float vetor[], int cidade);
int contarEntradas(float vetor[], int cidade);
void cidadesIsoladas(float vetor[], int cidade);
void semSaidaComEntrada(float vetor[]);

int contarSaidas(float vetor[], int cidade) {
    int saidas = 0;
    for (int coluna = 1; coluna <= (int)vetor[1]; coluna++){
        if (coluna != cidade && (int)buscarElementoMatriz(vetor, cidade, coluna) == 1) saidas++;
    }
    return saidas;
}

// mesma coisa de contar as saides
//A coluna representa todas as estradad qye chegam naquela cidade


int contarEntradas(float vetor[], int cidade) {
    int entradas = 0;
    for (int linha = 1; linha <= (int)vetor[0]; linha++){
        if (linha != cidade && (int)buscarElementoMatriz(vetor, linha, cidade) == 1) entradas++;
    }
    return entradas;
}

void cidadesIsoladas(float vetor[], int cidade) {
    int encontrou = 0;
    for (int cidade = 1; cidade <= (int)vetor[0]; cidade++) {
        if (contarSaidas(vetor, cidade) == 0 && contarEntradas(vetor, cidade) == 0) {
            printf("  Cidade %d\n", cidade - 1);
            encontrou = 1;
        }
    }
    if (encontrou == 0) printf("  Nenhuma cidade isolada.\n");
}

void semSaidaComEntrada(float vetor[]) {
    int encontrou = 0;
    for (int cidade = 1; cidade <= (int)vetor[0]; cidade++) {
        if (contarSaidas(vetor, cidade) == 0 && contarEntradas(vetor, cidade) > 0) {
            printf("  Cidade %d\n", cidade - 1);
            encontrou = 1;
        }
    }
    if (encontrou == 0) printf("  Nenhuma.\n");
}

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

#endif // BIBLIOTECAMATRIZES_H_INCLUDED;
