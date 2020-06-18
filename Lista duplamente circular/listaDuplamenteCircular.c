#include <stdio.h>
#include <stdlib.h>

typedef struct sCelula{
	int info;
	struct sCelula *esq;
	struct sCelula *dir;
}Celula;

Celula *getNode(){
	return (Celula *)malloc(sizeof(Celula));
}

void freeNode(Celula *q){
	free(q);
}

int isEmpty(Celula *lista){
	if(lista == NULL){
		return 1;
	}else
		return 0;
}

void init(Celula **lista){
	*lista = NULL;
}

void insertInitial(Celula **lista, int x){
	Celula *q;
	Celula *aux;
	q = getNode();
	
	if(q != NULL){
		q->info = x;

		if(isEmpty(*lista) == 1){
			q->esq = q;
			q->dir = q;
		}


		if(isEmpty(*lista) == 0){
			// A direita de Q é a lista atual..
			q->dir = (*lista);
			// A esquerda de Q é o fim da lista...
			q->esq = (*lista)->esq;
			
			// Fim da lista á direita é o nova cabeça, O q..
			(*lista)->esq->dir = q;
			// A esquerda da lista é Q....
			(*lista)->esq = q;
			printf("Inserido o final!");
		}
		
		*lista = q;	
	}else{
		printf("ERRO: No Q nao alocadado!");
	}
}

void insertEnd(Celula **lista, int x){
	Celula *q;
	Celula *aux;
	
	q = getNode();
	if(q != NULL){
		q->info = x;
		if(isEmpty(*lista) == 1){
			q->esq = q;
			q->dir = q;
			*lista = q;
		}
		if(isEmpty(*lista) == 0){
			aux = *lista;
			q->dir = (*lista);
			q->esq = (*lista)->esq;
			(*lista)->esq->dir = q;
			(*lista)->esq = q;
		}
	}else{
		printf("ERRO: No Q nao alocadado!");
	}		
}

void removeInitial(Celula **lista){
	Celula *q;
	q = *lista;
	q = getNode();
	
	if((*lista)->dir == *lista && (*lista)->esq == *lista){
		free(*lista);
	}
	
	if(isEmpty(*lista) == 1){
		printf("Erro: Lista Vazia!");
	}
	
	if(isEmpty(*lista) == 0){
		if(q != NULL){
			q = (*lista)->dir;
			q->esq = (*lista)->esq;
			(*lista)->esq->dir = q;
			*lista = q;
			printf("Primeiro elemento removido!");
		}
	}
	
}


void removeEnd(Celula **lista){
	Celula *q;
	Celula *aux;
	q = getNode();

	if(isEmpty(*lista) == 1){
		printf("Erro: Lista Vazia!");
	}
	if((*lista)->dir == *lista && (*lista)->esq == *lista){
		free(*lista);
	}
	if(isEmpty(*lista) == 0){
		if(q != NULL){
			q = (*lista)->esq;
			(*lista)->esq = q->esq;
			q->esq->dir = *lista;
			
			free(q);
			printf("ultimo elemento removido!");
		}
	}		

}



void showList(Celula **lista){
	Celula *aux;
	aux = *lista;
	
	int i = 0;
	
	printf("\n=============================================");
	printf("\n		Printando a Lista....			");
	printf("\n=============================================");

	// enquanto aux não encontrar o final, ele printa o conteúdo do próximo....
	do{
		printf("\n Posicao da lista encadeada [%d] = %d\n",i,aux->info);
		aux = aux->dir;
		i += 1;
	}while(aux != *lista);

	printf("\n=============================================");
	
}

int main (){
	Celula *l;
	init(&l);
	int input, chooseMenu, loopMenu = 1;
	while (loopMenu == 1){
		printf("\n==============================================================================");
		printf("\n				  MENU 							");
		printf("\n 1) Mostra Lista Duplamente Circular.......");
		printf("\n 2) Insere valor no inicio da Lista Duplamente Circular.......");
		printf("\n 3) Insere valor no final da Lista Duplamente Circular......");
		printf("\n 4) Remove valor no inicio da Lista Duplamente Circular.......");
		printf("\n 5) Remove valor no final da Lista Duplamente Circular.......");
		printf("\n 6) Sair.......");
		printf("\n==============================================================================");
		printf("\nDigite o Valor para a Operacao: ");
		scanf("%d", &chooseMenu);
		switch(chooseMenu){
			case 1:
				// case 1
				showList(&l);
				break;
			case 2:
				// case 2
				printf("\nInsere valor no inicio da Lista Encadeada: ");
				scanf("%d", &input);
				insertInitial(&l, input);
				break;
			case 3:
				// case 3
				printf("\nValor a ser colocado no final da Lista Encadeada: ");
				scanf("%d", &input);
				insertEnd(&l, input);
				break;
			case 4:
				// case 4
				removeInitial(&l);
				break;
			case 5:
				// case 5
				removeEnd(&l);
				break;
			case 6:
				// case 6
				printf("Encerrando o Loop do menu!");
				loopMenu = 0;
				break;	
			default:
				printf("Opcao Invalida!");
		}	
	}
	return 0;	
}
