#include <stdio.h>
#include <stdlib.h>

typedef struct sCelula{
	int info;
	struct sCelula *next;
}Celula;

void init(Celula **lista){
	*lista = NULL;
}

int isEmpty(Celula *lista){
	if(lista == NULL){
		return 1;
	}else
		return 0;
}

Celula *getNode(){
	return (Celula *)malloc(sizeof(Celula));
}

void freeNode(Celula *q){
	free(q);
}

void push(Celula **lista, int x){
	Celula *q;
	Celula *aux;
	
	q = getNode();
	if(q != NULL){
		q->info = x;
		q->next = NULL;
		if(isEmpty(*lista) == 1){
			*lista = q;
		}else{
			aux = *lista;
			while(aux->next != NULL){
				aux = aux->next;
			}
			aux->next = q;
		}
	}else{
		printf("ERRO: No Q nao alocadado!");
	}		
}

void pop(Celula **lista){
	Celula *q;
	Celula *aux;
	q = *lista;
	if(isEmpty(*lista) == 0){
		aux = *lista;
		while(aux->next->next != NULL){
			aux = aux->next;
		}
		freeNode(aux->next->next);
		aux->next = NULL;
	}else{
		printf("Erro: Lista Vazia!");
	}
}

void show(Celula **lista){
	Celula *aux;
	aux = *lista;
	
	int i = 0;
	
	printf("\n=============================================");
	printf("\n		Printando a Lista....			");
	printf("\n=============================================");

	while(aux != NULL){
		printf("\n Posicao da lista encadeada [%d] = %d\n",i,aux->info);
		aux = aux->next;
		i += 1;
	}
	printf("\n=============================================");
}


void menu(){
	Celula *ptrFila;
	init(&ptrFila);
    int loopMenu = 1;
	int chooseMenu;
	int input;
	while (loopMenu == 1){
		printf("\n===============================================================================");
		printf("\n				  MENU 							");
		printf("\n 1) Mostra Fila Inteira.......");
		printf("\n 2) Insere um valor na Fila .......");		
		printf("\n 3) Remove um valor na Fila.......");
		printf("\n 4) Sair.......");
		printf("\n===============================================================================");
		printf("\nDigite o Valor para a Operacao: ");
		scanf("%d",&chooseMenu);
		switch(chooseMenu){
			case 1:
				// case 1
				show(&ptrFila);
				break;
			case 2:
				fflush(stdin);
				printf("\nValor a ser colocado na Pilha: ");
				scanf("%d",&input);
				push(&ptrFila, input);
				break;
			case 3:
				// case 4
				pop(&ptrFila);
				break;
			case 4:
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
}




