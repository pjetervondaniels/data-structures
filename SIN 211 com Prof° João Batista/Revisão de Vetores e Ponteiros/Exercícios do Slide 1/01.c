/*
Faça um programa para ler um vetor de 12 posições e em
seguida ler também dois valores X e Y quaisquer
correspondentes a duas posições no vetor. Ao final seu
programa deverá escrever a soma dos valores encontrados
nas respectivas posições X e Y
*/


#include <stdio.h>

void preencheVetor(int *vetor){
	int i;
	for(i=0;i<12;i++){
		scanf("%d",&vetor[i]);
	}
}

void somaValor(int x,int y, int *vetor){
	int soma = vetor[x]+vetor[y];
	printf("Soma da posicao eh %d",soma);
}

int main(){
	int vetor[12];
	preencheVetor(vetor);
	
	int x,y;
	scanf("%d",&x);
	scanf("%d",&y);
	somaValor(x,y,vetor);
	
	
}