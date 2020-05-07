#include <stdio.h>
#include <stdlib.h>
#define MAX 10

typedef struct sNumero{
	int n;
}Numero;

typedef struct sLista{
	int qtd;
	Numero n1[MAX];
}Lista;

Lista* CriaLista(){
	Lista *li;
	li = (Lista*)malloc(sizeof(Lista));
	li->qtd = 9;
	return li;
}
void insereQualquerElemento(Lista *li,int valor,int posicao){
	li->n1[posicao].n = valor;
	if(li->n1[posicao].n == valor){
		printf("Insercao feita com sucesso!");
	}else{
		printf("Erro na Insercao!");
	}
}

void removePosicaoLista(Lista *li,int posicao){
	li->n1[posicao].n = 0;
	if(li->n1[posicao].n == 0){
		printf("Remocao feita com sucesso!");
	}else{
		printf("Erro na Remocao!");
	}
}

void acessaElemento(Lista *li,int posicao){
	printf("========================================\n");
	printf("		Lista [%d] = %d   \n",posicao,li->n1[posicao].n);
    printf("========================================\n");
}

procuraElemento(Lista *li,int valor){
	int i=0,aux;
	while(li->n1[i].n != valor && i<10){
		i++;
	}
	if(li->n1[i].n == valor){
		printf("========================================\n");
		printf(" 	Elemento Encontrado		");
		printf("========================================\n");
		printf("		Lista [%d] = %d   \n",i,li->n1[i].n);
	    printf("========================================\n");
	}else{
		printf("========================================\n");
		printf(" 	Elemento nao Encontrado		");
		printf("========================================\n");
	}
}

printaTodaLista(Lista *li){
	int i;
	printf("=================================================\n");
	printf("        PRINT DA LISTA   \n");
	printf("=================================================\n");
	for(i=0;i<10;i++){
		printf("		Lista [%d] = %d   \n",i,li->n1[i].n);
	}
	printf("========================================\n");
}




int main (){
	Lista *li;
	li = CriaLista();
	
	if(li == NULL){
		printf("Não ha memoria!\n");
		return 0;
	}
	int boolMenu = 1;
	do{
		printf("\n=================================================\n");
		printf("|                        MENU                   |\n");
		printf("=================================================\n");
		printf("STATUS: LISTA ALOCADA E PRONTA PARA OPERACOES!\n");
		printf("=================================================\n");
		printf("1 - inserir um elemento em uma posicao especifica: \n");
		printf("2 - remover um elemento de uma posição especifica:\n");
		printf("3 - acessar um elemento de uma posição especifica:\n");
		printf("4 - procurar um determinado elemento.:\n");
		printf("5 - exibir os elementos do vetor:\n");
		printf("6 - sair do loop:\n");
		printf("=================================================\n");
		printf("Digite sua Opcao:");
		int opcao;
		scanf("%d",&opcao);
		switch(opcao){
			case 1:
				printf("=================================================\n");
				printf("		Insercao                  \n");
				printf("=================================================\n");
				printf("Digite um valor e uma posicao na lista: \n");
				printf("==========================================\n");
				int valor,posicao;
				scanf("%d %d",&valor,&posicao);
				insereQualquerElemento(li,valor,posicao);
				break;
			case 2:
				printf("=================================================\n");
				printf("		Remocao                  \n");
				printf("=================================================\n");
				printf("Digite uma posicao na lista: \n");
				printf("=================================================\n");
				scanf("%d",&posicao);
				removePosicaoLista(li,posicao);
				break;
			case 3:
				printf("=================================================\n");
				printf("		Exibicao                  \n");
				printf("=================================================\n");
				printf("Digite uma posicao na lista: \n");
				printf("=================================================\n");
				scanf("%d",&posicao);
				acessaElemento(li,posicao);
				break;
			case 4:
				printf("=================================================\n");
				printf("		Procura Valor na Lista                  \n");
				printf("=================================================\n");
				printf("Digite um valor: \n");
				scanf("%d",&valor);
				procuraElemento(li,valor);
				break;
			case 5:
				printaTodaLista(li);
				break;
			case 6:
				exit(1);
				break;
			default:
				printf("Opcao Invalida!");
		}
		
	}while(boolMenu == 1);
	
	return 0;
}