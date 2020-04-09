/*
Leia um vetor de 10 posições e em seguida um valor X
qualquer. Seu programa deverá fazer uma busca do valor
de X no vetor lido. Caso encontre o valor deverá ser
removido do vetor.
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
	printf("procurando no vetor..\n");
	for(i=0;i<10;i++){
		if(vetor[i]==x){
			printf("\no valor foi encontrado e removido! \n",i);
			v=1;
			vetor[i]=0;
		}
	}
	if(v==0){
		printf("\n o valor nao foi encontrado!");
	}
}
void printaVetor(int *vetor){
	int i;
	printf("\n printando o vetor..\n");
	printf(" vetor[10] = { ");
	for(i=0;i<10;i++){
		printf("%d, ",vetor[i]);
	}
	printf("; }");
}

int main(){
	int vetor[10];
	preencheVetor(vetor);
	int x;
	scanf("%d",&x);
	procuraVetor(vetor,x);
	printaVetor(vetor);
	return 0;
}