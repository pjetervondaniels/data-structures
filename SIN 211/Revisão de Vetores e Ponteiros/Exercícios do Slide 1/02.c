/*
Leia um vetor de 16 posições e troque os 8 primeiros
valores pelos 8 últimos e vice-versa Escreva ao final o vetor
obtido
*/


#include <stdio.h>

void preencheVetor(int *vetor){
	int i;
	for(i=0;i<16;i++){
		scanf("%d",&vetor[i]);
	}
}

void inverteVetor(int *vetor){
	int i,k;
	i=0;
	k=15;
	while(i<8){
		int guarda = vetor[i];
		vetor[i] = vetor[k];
		vetor[k] = guarda;
		k--;
		i++;
	}
}

void printaVetor(int *vetor){
	int i;
	printf("\n printando o vetor..\n");
	for(i=0;i<16;i++){
		printf("%d \n",vetor[i]);
	}
}

int main(){
	int vetor[16];
	preencheVetor(vetor);
	inverteVetor(vetor);
	printaVetor(vetor);
	return 0;
}