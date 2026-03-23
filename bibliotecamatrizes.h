#ifndef BIBLIOTECAMATRIZES_H_INCLUDED
#define BIBLIOTECAMATRIZES_H_INCLUDED
#include <stdio.h>

void preencherMatriz(float vetor[]){
    int linha=1, coluna=1;
    for(int i=2; i<vetor[0]*vetor[1]+2; i++) {
        printf("Digite o valor do elemento %dx%d: ", linha, coluna++);
        if(coluna>vetor[1]){
            coluna=1; linha++;
        }
        float elemento; scanf("%f",&elemento);
        vetor[i]=elemento;
    }  
}

void anularMatriz(float vetor[]){
    for(int i=2; i<vetor[0]*vetor[1]+2; i++){
        vetor[i]=0;
    }
}

void exibirMatriz(float vetor[]){
    int cont=0;
    for(int i=2; i<vetor[0]*vetor[1]+2; i++){
        printf("%6.2f ", vetor[i]);
        if(++cont%(int)vetor[1]==0) printf("\n");
    }
    putchar('\n');
}

void adicionarElementoMatriz(float vetor[], float elemento, int linha, int coluna){
    vetor[(linha*coluna)+1]=elemento;
}

void removerElementoMatriz(float vetor[], int linha, int coluna){
    vetor[(linha*coluna)+1]=0;
}

int pegarElementoMatriz(float vetor[], int linha, int coluna){
    return vetor[(linha*coluna)+1];
}

void somarMatrizes(float vetorA[], float vetorB[], float vetorC[]){ 
	if(vetorA[0]!=vetorB[0]&&vetorA[1]!=vetorB[1]){
		printf("Não é possível efetuar a soma dessas matrizes. A ordem é diferente.");
		return ;
	}
	int tamanho = vetorA[0]*vetorA[1]+2;
	vetorC[0]=vetorA[0]; vetorC[1]=vetorA[1]; //recebe a ordem
	for(int i=2; i<tamanho; i++){
		vetorC[i]=vetorA[i]+vetorB[i];
	}
}
void subtrairMatriz(float vetorA[], float vetorB[], float vetorC[]){ 
	if(vetorA[0]!=vetorB[0]&&vetorA[1]!=vetorB[1]) return ;
	int tamanho = vetorA[0]*vetorA[1]+2;
	vetorC[0]=vetorA[0]; vetorC[1]=vetorA[1]; //recebe a ordem
	for(int i=2; i<tamanho; i++){
		vetorC[i]=vetorA[i]-vetorB[i];
	}
}
#endif // BIBLIOTECAMATRIZES_H_INCLUDED

