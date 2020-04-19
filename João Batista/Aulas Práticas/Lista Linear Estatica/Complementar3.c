#include <stdio.h>
#include <stdlib.h>

typedef struct sNumero{
	int numeroInteiro;
}Numero;

typedef struct sLista{
	int qnt;
	Numero n[10];
}Lista;

Lista* AlocaLista(Lista *li){
	li = (Lista *)calloc(1,sizeof(Lista));
	if(li == NULL){
		printf("\nErro de alocar memoria!");
		exit(1);
	}
	if(li != NULL){
		printf("\n Alocacao feita com sucesso!");
		li->qnt = 0;
		return li;
	}
}

int ListaCheia(Lista *li){
	if(li->qnt == 10){
		return 1;
	}else{
		return 0;
	}	
}


int insereValoresFinais(Lista *li,Numero n){
	if(ListaCheia(li) == 0){
		li->n[li->qnt].numeroInteiro = n.numeroInteiro;
		li->qnt++;
		return 1;
	}else{
		return 0;
	}		
}

int concatenaListas(Lista *li1,Lista *li2){
	int i;
	for(i = 0; i<10;i++){
		li1->n[i].numeroInteiro += li2->n[i].numeroInteiro;
	}
}

void imprimeLista(Lista *li){
	int i;
	for(i=0;i<10;i++){
		printf("Lista [%d] = %d \n",i,li->n[i].numeroInteiro);
	}
	printf("========================================\n");
	
}

void LiberaLista(Lista *li){
	free(li);
}

int main(){
	Lista *li1;
	li1 = AlocaLista(li1);
	Lista *li2;
	li2 = AlocaLista(li2);
	
	int boolMenu = 1;
	do{
		printf("\n=================================================\n");
		printf("|                        MENU                   |\n");
		printf("=================================================\n");
		printf(" STATUS: LISTA ALOCADA E PRONTA PARA OPERACOES!\n");
		printf("=================================================\n");
		printf("1 - Insere numero na lista l1: \n");
		printf("2 - Insere numero na lista l2: \n");
		printf("3 - Concatena lista l1 e l2:\n");
		printf("4 - Mostra lista:\n");
		printf("5 - Sair do loop:\n");
		printf("=================================================\n");
		printf("Digite sua Opcao:");
		int opcao;
		scanf("%d",&opcao);
		switch(opcao){
			case 1:
				printf("=================================================\n");
				printf("		Insercao na lista l1            \n");
				printf("=================================================\n");
				printf("Digite o valor de n: \n");
				printf("==========================================\n");
				Numero n1;
				scanf("%d",&n1.numeroInteiro);
				int k;
				k = insereValoresFinais(li1,n1);
				if(k == 1){
					printf("Insercao feita com sucesso!");
				}else{
					printf("Nao aconteceu insercao!");
				}
				break;
			case 2:
				printf("=================================================\n");
				printf("		Insercao na lista l2            \n");
				printf("=================================================\n");
				printf("Digite o valor de n: \n");
				printf("==========================================\n");
				scanf("%d",&n1.numeroInteiro);
				k = insereValoresFinais(li2,n1);
				if(k == 1){
					printf("Insercao feita com sucesso!");
				}else{
					printf("Nao aconteceu insercao!");
				}
				break;	
			case 3:
				printf("=================================================\n");
				printf("		Concatena Listas            \n");
				printf("=================================================\n");
				concatenaListas(li1,li2);
				break;
			case 4:
				printf("=====================================================\n");
				printf("			Impressao da Lista             \n");
				printf("=====================================================\n");
				printf("\n1 -  Imprimir Lista l1:");
				printf("\n2 -  Imprimir Lista l2:\n");
				int imprime;
				scanf("%d",&imprime);
				switch(imprime){
					case 1:
						imprimeLista(li1);
						break;
					case 2:
						imprimeLista(li2);
						break;
					default:
						printf("Opcao invalida!");
				}
				break;
			case 5:
				LiberaLista(li1);
				LiberaLista(li2);
				exit(1);
				break;
			default:
				printf("Opcao Invalida!");
		}
		
	}while(boolMenu == 1);
	
}
