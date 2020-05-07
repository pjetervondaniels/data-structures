#include <stdio.h>
#include <stdlib.h>
/*
Altere o exercício anterior salvando o resultado da soma de X e Y em X, com passagem de
parâmetro por referência.
*/
int preencheVetor(int *vetor){
	int i;
	for(i=0;i<10;i++){
		scanf("%d",&vetor[i]);
	}
}

int somaVetor(int *vetor,int a,int b){
	return vetor[a]+vetor[b];
}

int main (){
	int x,y,vetor[10],soma;
		
	preencheVetor(vetor);
	
	scanf("%d",&x);
	scanf("%d",&y);
	
	soma = somaVetor(vetor,x,y);
	
	printf("%d",soma);
	return 0;
}