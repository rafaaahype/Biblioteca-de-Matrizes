/*
 * PROGRAMADORES: RAFAEL VIEIRA, JEFFERSON ALVES, TOMÁS FREITAS, RAY DAVYD
 */
#include <stdio.h>
#include <stdlib.h>
#include "bibliotecamatrizes.h" 

/*NOTA: Para maior organização e abstração, separamos as funções na
biblioteca "bibliotecamatrizes.h". Este main.c atua apenas como 
programa cliente para testar a lógica.*/


int main()
{
    int linha, coluna;
    printf("Digite a ordem da matriz A (formato: linhaxcoluna): ");
    scanf("%dx%d", &linha, &coluna);

    int tamanhoA = linha * coluna + 2;
    float matrizA[tamanhoA];
    dimensionarMatriz(matrizA, linha, coluna);

    printf("\nPreencha a matriz A:\n");
    preencherMatriz(matrizA);

    printf("\nMatriz A:\n");
    exibirMatriz(matrizA);

    // Questão 1
    printf("\n");
    cidadesIsoladas(matrizA);
    semSaidaComEntrada(matrizA);
    comSaidaSemEntrada(matrizA);
    cidadeMaisEntradas(matrizA);
    
    int k;
    printf("Digite a cidade k para o item v: ");
    scanf("%d", &k);
    saidasParaK(matrizA, k);
    
    int roteiro[] = {2, 3, 2, 1, 0};
    verificaRoteiro(matrizA, roteiro, 5);

    // Questão 2
    printf("\nQUESTAO 2 - Digite a ordem da matriz (formato: linhaxcoluna): ");
    int linhaC, colunaC;
    scanf("%dx%d", &linhaC, &colunaC);
    while (getchar() != '\n');

    int tamanhoC = linhaC * colunaC + 2;
    float matrizC[tamanhoC];
    float matrizD[tamanhoC];
    dimensionarMatriz(matrizC, linhaC, colunaC);
    dimensionarMatriz(matrizD, linhaC, colunaC);

    printf("\nPreencha a matriz C:\n");
    preencherMatriz(matrizC);

    printf("\nPreencha a matriz D:\n");
    preencherMatriz(matrizD);

    printf("\nMatriz C:\n");
    exibirMatriz(matrizC);

    printf("\nMatriz D:\n");
    exibirMatriz(matrizD);

    putchar('\n');
    if (matrizInversa(matrizD, matrizC))
    {
        printf("QUESTAO 2 = SAO INVERSAS\n");
    }
    else
    {
        printf("QUESTAO 2 = NAO SAO INVERSAS\n");
    }

    return 0;
}

