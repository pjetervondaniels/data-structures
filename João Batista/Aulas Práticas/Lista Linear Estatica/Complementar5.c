  
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

void insereInvertido(Lista *li1,Lista *li2){
	int i,j = 9;
	for(i = 0; i<10;i++){
		li2->n[i].numeroInteiro = li1->n[j].numeroInteiro;
		j--;
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
		printf("2 - Insere L1 invertido na lista l2: \n");
		printf("3 - Mostra lista:\n");
		printf("4 - Sair do loop:\n");
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
				insereInvertido(li1,li2);
				printf("Insercao Inversa feita com sucesso!");
				break;	
			case 3:
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
			case 4:
				LiberaLista(li1);
				LiberaLista(li2);
				exit(1);
				break;
			default:
				printf("Opcao Invalida!");
		}
		
	}while(boolMenu == 1);
	
}
