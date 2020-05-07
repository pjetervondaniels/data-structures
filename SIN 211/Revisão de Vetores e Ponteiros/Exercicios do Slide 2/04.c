/*
Crie um programa em C que aloque dinamicamente um vetor de
automóveis de uma concessionária de carros com os seguintes dados:
modelo, ano de fabricação e tipo de combustível.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct sAutomovel{
	char modelo[10];
	int anoFabricacao;
	char tipoCombustivel[10];
}Automovel;

void cadastraAuto(Automovel *a1,int n){
	for(int i=0; i<n;i++){
		printf("\n - Carro %d -",i);
		scanf("%d",&a1[i].anoFabricacao);
		scanf("%s",&a1[i].modelo);
		scanf("%s",&a1[i].tipoCombustivel);
	}
}
void printaAuto(Automovel *a1,int n){
	for(int i=0; i<n;i++){
		printf("\n - Carro %d -",i);
		printf("\n Ano de Fabricacao: %d",a1[i].anoFabricacao);
		printf("\n Modelo: %s",a1[i].modelo);
		printf("\n Tipo de Combustivel: %s",a1[i].tipoCombustivel);
	}
}

int main(){
	int n;
	scanf("%d",&n);
	
	Automovel *a1;
	a1 = (Automovel*)malloc(n*sizeof(Automovel));
	
	cadastraCarro(a1,n);
	printaAuto(a1,n);
	
	free(a1);
	
	return 0;
}