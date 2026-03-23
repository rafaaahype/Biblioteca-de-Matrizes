/*
 * PROGRAMADORES: RAFAEL VIEIRA, JEFFERSON ALVES & TOMÁS FREITAS
 */
#include "bibliotecamatrizes.h"
#include <stdio.h>

int main(){
	printf("Digite a ordem de uma matriz (formato: linhaxcoluna): ");
	int linha, coluna; scanf("%dx%d",&linha,&coluna);
	int tamanho = linha*coluna+2;
	float matrizA[tamanho];
	matrizA[0] = linha; matrizA[1] = coluna;
	puts("Preencha a matriz: ");
	preencherMatriz(matrizA);
	printf("Digite a ordem de uma outra matriz: ");
	scanf("%dx%d",&linha,&coluna);
	tamanho = linha*coluna+2;
	float matrizB[tamanho];
	matrizB[0] = linha; matrizB[1] = coluna;
	puts("Preencha a matriz: ");
	preencherMatriz(matrizB);
	puts("Matriz A: ");
	exibirMatriz(matrizA);
	puts("Matriz B: ");
	exibirMatriz(matrizB);
	puts("Soma das duas matrizes: ");
	float matrizC[tamanho];
	somarMatrizes(matrizA, matrizB, matrizC);
	exibirMatriz(matrizC);
	return 0;
}

/*
 * 
 * HÁ MAIS FUNÇÕES DISPONÍVEIS QUE O USUÁRIO PODE EXPLORAR À VONTADE.
 *
 */
