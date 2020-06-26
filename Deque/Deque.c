  
#include <stdio.h>
#include <stdlib.h>

typedef struct sCelula{
	int info;
	struct sCelula *next;
}Celula;

Celula *getNode(){
	return (Celula *)malloc(sizeof(Celula));
}

void freeNode(Celula *q){
	free(q);
}

int isEmpty(Celula *deque){
	if(deque == NULL){
		return 1;
	}else
		return 0;
}

void init(Celula **deque){
	*deque = NULL;
}

void insertInitial(Celula **deque, int x){
	Celula *q;
	q = getNode();
	
	if(q != NULL){
		q->info = x;
		q->next = *deque;
		*deque = q;
	}else{
		printf("ERRO: No Q nao alocadado!");
	}
}

void insertEnd(Celula **deque, int x){
	Celula *q;
	Celula *aux;
	
	q = getNode();
	if(q != NULL){
		q->info = x;
		q->next = NULL;
		if(isEmpty(*deque) == 1){
			*deque = q;
		}else{
			aux = *deque;
			while(aux->next != NULL){
				aux = aux->next;
			}
			aux->next = q;
		}
	}else{
		printf("ERRO: No Q nao alocadado!");
	}		
}

void removeInitial(Celula **deque){
	Celula *q;
	q = *deque;
	if(isEmpty(*deque) == 0){
		*deque = q->next;
		freeNode(q);
	}else{
		printf("Erro: Lista Vazia!");
	}
}

void removeEnd(Celula **deque){
	Celula *q;
	Celula *aux;
	q = *deque;
	if(isEmpty(*deque) == 0){
		aux = *deque;
		while(aux->next->next != NULL){
			aux = aux->next;
		}
		freeNode(aux->next->next);
		aux->next = NULL;
	}else{
		printf("Erro: Lista Vazia!");
	}
}

void showList(Celula **deque){
	Celula *aux;
	aux = *deque;
	int i = 0;
	if(isEmpty(*deque) == 1){
        printf("\n Erro! Deque vazio");
    }else{
		while(aux != NULL){
			printf("\n Posicao do Deque [%d] = %d\n",i,aux->info);
			aux = aux->next;
			i += 1;
		}
    }
	printf("\n");
}

void showBegin(Celula **deque){
	if(isEmpty(*deque) == 1){
        printf("\n Erro! Deque vazio");
    }else{
    	printf("\n Valor Inicial do Deque: %d", (*deque)->info);
    }
}

void showEnd(Celula **deque){
	if(isEmpty(*deque) == 1){
        printf("\n Erro! Deque vazio");
    }else{
    	Celula *aux;
    	aux = *deque;
    	while(aux->next != NULL){
    		aux = aux->next;
		}
    	printf("\n Valor Final do Deque: %d", aux->info);
    }	
}

void menu(){
	Celula *deque;
	init(&deque);
	int input, chooseMenu, loopMenu = 1;
	while (loopMenu == 1){
		printf("\n==============================================================================");
		printf("\n				  MENU 							");
		printf("\n 1) Mostra todos valores do Deque.......");
		printf("\n 2) Mostra primeiro valor do Deque.......");
		printf("\n 3) Mostra ultimo valor do Deque ......");
		printf("\n 4) Insere valor no inicio do Deque.......");
		printf("\n 5) Insere valor no final do Deque.......");
		printf("\n 6) Remove valor no inicio do Deque.......");
		printf("\n 7) Remove valor no final do Deque.......");
		printf("\n 8) Sair.......");
		printf("\n==============================================================================");
		printf("\nDigite o Valor para a Operacao: ");
		scanf("%d", &chooseMenu);
		switch(chooseMenu){
			case 1:
				showList(&deque);
				break;
			case 2:
				showBegin(&deque);
				break;
			case 3:
				showEnd(&deque);
				break;	
			case 4:
				printf("\nInsere valor no inicio da Lista Encadeada: ");
				scanf("%d", &input);
				insertInitial(&deque, input);
				break;
			case 5:
				printf("\nValor a ser colocado no final da Lista Encadeada: ");
				scanf("%d", &input);
				insertEnd(&deque, input);
				break;
			case 6:
				removeInitial(&deque);
				break;
			case 7:
				removeEnd(&deque);
				break;
			case 8:
				printf("Encerrando o Loop do menu!");
				loopMenu = 0;
				break;				
			default:
				printf("Opcao Invalida!");
		}	
	}
}

int main (){
	menu();
	return 0;	
}

