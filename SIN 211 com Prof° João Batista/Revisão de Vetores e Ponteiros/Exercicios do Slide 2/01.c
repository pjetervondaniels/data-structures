/*
Codifique, compile e execute um programa em C que contenha uma
estrutura data com os campos: dia (inteiro), mês (inteiro) e ano
(inteiro). Crie uma única estrutura e armazene a data do seu
aniversário. Em seguida crie uma função separada para imprimir as
informações armazenas na estrutura.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct sDia{
	int dia;
	int mes;
	int ano;
}Dia;

void printaData(Dia d1){
	printf("dia %d, mes %d e ano %d",d1.dia,d1.mes,d1.ano);
}

int main(){
	Dia d1;
	
	scanf("%d",&d1.dia);
	scanf("%d",&d1.mes);
	scanf("%d",&d1.ano);
	
	fflush(stdin);
	
	printaData(d1);
	
	return 0;
}