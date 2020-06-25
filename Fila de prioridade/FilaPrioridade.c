#include <stdio.h>
#include <stdlib.h>

typedef struct sCelula{
	int info;
	int prioridade;
	struct sCelula *next;
}Celula;

void init(Celula **filaP){
	*filaP = NULL;
}

int isEmpty(Celula *filaP){
	if(filaP == NULL){
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

void push(Celula **filaP, int x, int y){
	Celula *q;
	Celula *aux;
	
	q = getNode();
	if(q != NULL){
		q->info = x;
		q->prioridade = y;
		q->next = NULL;
		
		if(isEmpty(*filaP) == 1){
			*filaP = q;
		}else{
			aux = *filaP;
			
			if(aux->prioridade < y){
				// caso o do primeiro for menor...
				q->next = aux;
				*filaP = q;
			}else{
				// caso não seja o primeiro...
				int valid = 0;
				while(aux->next != NULL){
					if(aux->next->prioridade < y){
						valid = 1;
						break;
					}
					aux = aux->next;
				}
				if(valid == 1){
					q->next = aux->next;
					aux->next = q;
				}else{
					aux->next = q;
				}				
			}
		}
	}else{
		printf("ERRO: No Q nao alocadado!");
	}		
}


void pop(Celula **filaP){
	Celula *q;
	q = *filaP;
	if(isEmpty(*filaP) == 0){
		*filaP = q->next;
		freeNode(q);
	}else{
		printf("Erro: Lista Vazia!");
	}
}


void show(Celula **filaP){
	Celula *aux;
	aux = *filaP;
	
	int i = 0;
	
	printf("\n=============================================");
	printf("\n		Printando a Fila de Prioridade....			");
	printf("\n=============================================");

	while(aux != NULL){
		printf("\n Posicao na Fila de Prioridade [%d]",i + 1);
		printf("\n Prioridade: %d", aux->prioridade);
		printf("\n Valor da Posicao: %d \n", aux->info);
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
	int input, prioridade;
	while (loopMenu == 1){
		printf("\n===============================================================================");
		printf("\n				  MENU 							");
		printf("\n 1) Mostra Fila de Prioridade.......");
		printf("\n 2) Insere um valor na Fila de Prioridade .......");		
		printf("\n 3) Remove um valor na Fila de Prioridade.......");
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
				printf("\nValor a ser colocado na Fila: ");
				scanf("%d",&input);
				printf("\n Prioridade a ser colocado na Fila: ");
				scanf("%d",&prioridade);
				push(&ptrFila, input, prioridade);
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




