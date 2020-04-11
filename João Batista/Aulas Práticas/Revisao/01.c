#include <stdio.h>
#include <stdlib.h>
/*
Codifique, compile e execute um programa em C para ler um vetor de 10 posições e em
seguida ler também dois valores X e Y quaisquer correspondentes a duas posições no
vetor. Depois escreva uma função que retorne a soma dos valores encontrados nas
respectivas posições X e Y. Ao final imprima os valores das posições X e Y e o resultado
da soma na função principal (main).
*/
int preencheVetor(int *vetor){
	int i;
	for(i=0;i<10;i++){
		scanf("%d",&vetor[i]);
	}
}

int somaVetor(int *vetor,int x,int y){
	return vetor[x]+vetor[y];
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