/*
Crie um vetor de inteiros com X posições, onde X é um valor fornecido pelo usuário.
Preencha as posições desse vetor com números consecutivos.
*/

#include <stdio.h>
#include <stdlib.h>

int main (){
	int n,*vetor;
	
	scanf("%d",&n);
	
	vetor = (int*)malloc(sizeof(n));
	
	if(vetor==NULL){
		printf("Não foi possível alocar dinâmica.");
		return 0;
	}
	
	printf("\nEntre com os valores....");
	for(int i=0;i<n;i++){
		scanf("%d",vetor[i])
	}
	
	printf("\nPrintando os Valores....");
	for(int i=0;i<n;i++){
		printf("%d",vetor[i]);
	}
	
	return 0;
}