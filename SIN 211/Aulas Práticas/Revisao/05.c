#include <stdio.h>
#include <stdlib.h>

/*
Considere as estruturas Cliente, Endereço e Data. A estrutura Cliente possui os seguintes
campos: nome do cliente, endereço residencial e data de nascimento. Já a estrutura
Endereço possui os seguintes dados: nome da rua, número da casa e bairro. E por fim a
estrutura Data possui os campos dia, mês e ano. Codifique, compile e execute um
programa em C que utilize o conceito de estruturas aninhadas. O programa deve criar um
vetor de cliente de 10 posições, pedir ao usuário para fornecer os dados de cada um dos
clientes e somente depois que todos os dados forem preenchidos pelo usuário imprimi-los
na tela.
*/

typedef struct sCliente{
	Data d1;
	Endereco e1;
	char nomeCliente[20];
	char enderecoResidencial[20];
	
}Cliente;

typedef struct sEndereco{
	char nomeRua[20];
	int numeroCasa;
	char bairro[20];
}Endereco;

typedef struct sData{
	int dia;
	int mes;
	int ano;
}Data;


int main (){
	
	Cliente c1[10];
	
	for(int i=0; i<10;i++){
		printf("LOOP %d \n",i);
		printf("Nome do Cliente:\n")
		gets(c1[i].nomeCliente);
		printf("Endereco do Cliente:\n");
		gets(c1[i].enderecoResidencial);
		printf("Dia do Cliente:\n");
		scanf("%d",c1[i].d1.dia);
		printf("Mes do Cliente:\n");
		scanf("%d",c1[i].d1.mes);
		printf("Ano do Cliente:\n");
		scanf("%d",c1[i].d1.ano);
		printf("Rua do Cliente:\n");
		gets(c1[i].e1.nomeRua);
		printf("Bairro do Cliente:\n");
		gets(c1[i].e1.bairro);
		printf("Numero da caso do Cliente:\n");
		scanf("%d",c1[i].e1.numeroCasa);
	}
	
	for(int i=0; i<10;i++){
		printf("LOOP %d \n",i);
		printf("Nome do Cliente: %s",c1[i].nomeCliente);
		printf("Endereco do Cliente: %s\n",c1[i].enderecoResidencial);
		printf("Dia do Cliente: %d/%d%d\n",c1[i].d1.dia,c1[i].d1.mes,c1[i].d1.ano);
		printf("Rua do Cliente: %s , Bairro do Cliente: %s e Numero da caso do Cliente: %s\n",c1[i].e1.nomeRua,c1[i].e1.bairro,c1[i].e1.numeroCasa);
	}
	
	return 0;
}