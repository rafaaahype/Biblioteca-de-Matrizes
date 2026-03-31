/*
 * PROGRAMADORES: RAFAEL VIEIRA, JEFFERSON ALVES, TOMÁS FREITAS, RAY DAVYD
 */
#include "bibliotecamatrizes.h"
#include <stdio.h>

int main(){
	printf("Digite a ordem de uma matriz (formato: linhaxcoluna): ");
	int linha, coluna; scanf("%dx%d",&linha,&coluna);
	int tamanho = linha*coluna+2;
	float matrizA[tamanho], matrizB[tamanho], matrizC[tamanho];
	matrizA[0] = linha; matrizA[1] = coluna;
	matrizB[0] = linha; matrizB[1] = coluna;
  	matrizC[0] = linha; matrizC[1] = coluna;

	preencherMatriz(matrizA);
  	anularMatriz(matrizB);
  	adicionarElementoMatriz(matrizB, 5, 1, 1);
	somarMatrizes(matrizA, matrizB, matrizC);
  	exibirMatriz(matrizC);

	return 0;
}

/*
 *
 * HÁ MAIS FUNÇÕES DISPONÍVEIS QUE O USUÁRIO PODE EXPLORAR À VONTADE.
 *
 */
