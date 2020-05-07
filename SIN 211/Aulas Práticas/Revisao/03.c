/*
Leia um vetor de 10 posições e em seguida um valor X qualquer. Seu programa deverá
fazer uma busca do valor de X no vetor lido e informar a posição em que foi encontrado
ou se não foi encontrado.
*/

#include <stdio.h>

void preencheVetor(int *vetor){
	int i;
	for(i=0;i<10;i++){
		scanf("%d",&vetor[i]);
	}
}

void procuraVetor(int *vetor,int x){
	int i;
	int v=0;
	printf("\n procurando no vetor..\n");
	for(i=0;i<10;i++){
		if(vetor[i]==x){
			printf("o valor foi encontrado na posicao: %d \n",i);
			v=1;
		}
	}
	if(v==0){
		printf("o valor nao foi encontrado!");
	}
}

int main(){
	int vetor[10];
	preencheVetor(vetor);
	int x;
	scanf("%d",&x);
	procuraVetor(vetor,x);
	return 0;
}