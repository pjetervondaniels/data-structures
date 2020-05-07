#include <stdio.h>
#include <stdlib.h>

typedef struct sNumero{
	int numeroInteiro;
}Numero;

typedef struct sLista{
	int qnt;
	Numero n[10];
}Lista;

typedef struct sListaM{
	int qnt;
	Numero n[20];
}ListaM;

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

Lista* AlocaListaM(ListaM *li){
	li = (ListaM *)calloc(1,sizeof(ListaM));
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

int ListaMCheia(ListaM *li){
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

int concatenaListas(Lista *li1,Lista *li2,ListaM *li3){
	int i = 0,j = 0,k = 0;
	while(i<20){
		li3->n[i].numeroInteiro = li1->n[j].numeroInteiro;
		i++;
		j++;
		li3->n[i].numeroInteiro = li2->n[k].numeroInteiro;
		i++;
		k++;		
	}
	
}

void imprimeLista(Lista *li){
	int i;
	for(i=0;i<10;i++){
		printf("Lista [%d] = %d \n",i,li->n[i].numeroInteiro);
	}
	printf("========================================\n");
	
}

void imprimeListaM(ListaM *li){
	int i;
	for(i=0;i<20;i++){
		printf("Lista [%d] = %d \n",i,li->n[i].numeroInteiro);
	}
	printf("========================================\n");
	
}

void LiberaLista(Lista *li){
	free(li);
}

void LiberaListaM(ListaM *li){
	free(li);
}

int main(){
	
	Lista *li1;
	li1 = AlocaLista(li1);
	Lista *li2;
	li2 = AlocaLista(li2);
	ListaM *li3;
	li3 = AlocaListaM(li3);
	
	int boolMenu = 1;
	do{
		printf("\n=================================================\n");
		printf("|                        MENU                   |\n");
		printf("=================================================\n");
		printf(" STATUS: LISTA ALOCADA E PRONTA PARA OPERACOES!\n");
		printf("=================================================\n");
		printf("1 - Insere numero na lista l1: \n");
		printf("2 - Insere numero na lista l2: \n");
		printf("3 - Concatena lista l1 e l2 em l3:\n");
		printf("4 - Mostra lista (l1 ou l2):\n");
		printf("5 - Mostra lista (l3):\n");
		printf("6 - Sair do loop:\n");
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
				printf("		Concatena Listas em l3           \n");
				printf("=================================================\n");
				concatenaListas(li1,li2,li3);
				printf("Concatenacao feita com sucesso!");
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
						printf("=====================================================\n");
						printf("			Impressao da Lista l1          \n");
						printf("=====================================================\n");
						imprimeLista(li1);
						break;
					case 2:
						printf("=====================================================\n");
						printf("			Impressao da Lista l2          \n");
						printf("=====================================================\n");
						imprimeLista(li2);
						break;
					default:
						printf("Opcao invalida!");
				}
				break;
			case 5:
				printf("=====================================================\n");
				printf("			Impressao da Lista l3            \n");
				printf("=====================================================\n");
				imprimeListaM(li3);
			case 6:
				LiberaLista(li1);
				LiberaLista(li2);
				LiberaListaM(li3);
				exit(1);
				break;
			default:
				printf("Opcao Invalida!");
		}
		
	}while(boolMenu == 1);
	
	return 0;
}

