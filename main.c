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
	dimensionarMatriz(matrizA, linha, coluna);
	printf("Digite a ordem de uma matriz (formato: linhaxcoluna): ");
	scanf("%dx%d",&linha,&coluna);
	tamanho = linha*coluna+2;
	dimensionarMatriz(matrizB, linha, coluna);
	dimensionarMatriz(matrizC, linha, coluna);

	//main rafael
	//float *matrizD = (float *)malloc(tamanho*sizeof(float));
	//multiplicarMatrizRafael(matrizA, matrizB, &matrizD);
	/*
	preencherMatriz(matrizA);
	anularMatriz(matrizB);
	adicionarElementoMatriz(matrizB, 5, 1, 1);
	somarMatrizes(matrizA, matrizB, matrizC);
	exibirMatriz(matrizC);
	*/
/*
	preencherMatriz(matrizA);
	criarTransposta(matrizA, matrizB);
	printf("\n\n\n");
	exibirMatriz(matrizB);
*/




	preencherMatriz(matrizA);
	exibirMatriz(matrizA);

	preencherMatriz(matrizB);
	exibirMatriz(matrizB);

	multiplicarMatriz(matrizA, matrizB, matrizC);

	putchar('\n');

	if(matrizC[0]==matrizA[0]&&matrizC[1]==matrizA[1])7
		exibirMatriz(matrizC);

		if(matrizIdentidade(matrizC)) printf("EH IDENTIDADE");
		else printf("NAO EH IDENETIDADE");
	return 0;
}

/*
 *
 * HÁ MAIS FUNÇÕES DISPONÍVEIS QUE O USUÁRIO PODE EXPLORAR À VONTADE.
 *
 */
