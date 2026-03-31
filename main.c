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

	anularMatriz(matrizA);
	exibirMatriz(matrizA);
	adicionarElementoMatriz(matrizA, 1, 1, 2);
	exibirMatriz(matrizA);
	printf("\n\n%d",buscarElementoMatriz(matrizA, 1, 2));
	return 0;
}

/*
 * 
 * HÁ MAIS FUNÇÕES DISPONÍVEIS QUE O USUÁRIO PODE EXPLORAR À VONTADE.
 *
 */