#include <stdio.h>
#include <stdlib.h>

typedef struct sCelula{
	int info;
	struct sCelula *next;
}Celula;

Celula *init(Celula *lista){
	lista = NULL;
	printf("Lista Encadeada iniciada com sucesso!");
	return lista;
}

Celula *getNode(){
	return (Celula *)malloc(sizeof(Celula));
}

int isEmpty(Celula *lista){
	if(lista == NULL){
		return 1;
	}else
		return 0;
}

void freeNode(Celula *q){
	free(q);
}

void showList(Celula *lista){
	Celula *aux;
	aux = lista;
	
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


Celula *searchValue(Celula *lista, int x){
	Celula *q;
	int i = 0;
	if(isEmpty(lista) == 0){
		q = lista;
		while(q != NULL){
			if(q->info == x){
				printf("\nNo com valor %d encontrado na posicao %d! retornando o primeiro no com esse valor! ",x,i);
				return q;
			}else
				q = q->next;
				i += 1;
		}
	}
	printf("\nNao foi encontrado nenhum no com o valor %d!",x);
	return NULL;
}

void verifyValue(Celula *lista, int x){
	Celula *q;
	int i = 0;
	if(isEmpty(lista) == 0){
		q = lista;
		while(q != NULL){
			if(q->info == x){
				printf("\nNo com valor %d encontrado na posicao %d! retornando o primeiro no com esse valor! ",x,i);
			}else
				q = q->next;
				i += 1;
		}
	}
	printf("\nNao foi encontrado nenhum no com o valor %d!",x);
}

int countNode(Celula *lista){
	Celula *q;
	int i = 0;
	if(isEmpty(lista) == 0){
		q = lista;
		while(q != NULL){
				q = q->next;
				i += 1;
		}
		return i;
	}
}

Celula *insertFirst(Celula *lista, int x){
	Celula *q;
	
	q = getNode();
	
	if(q != NULL){
		q->info = x;
		q->next = lista;
		lista = q;
		
		printf("\n o valor %d foi inserido no inicio com sucesso!",x);
		return lista;
	}else{
		printf("Erro na alocação do nó Q.... \n");
		return NULL;
	}
}
Celula *insertLast(Celula *lista, int x){
	Celula *q;
	Celula *aux;
	
	q = getNode();
	
	if(q != NULL){
		q->info = x;
		q->next = NULL;
		if(isEmpty(lista) == 1){
			lista = q;
		}else{
			aux = lista;
			while(aux->next != NULL){
				aux = aux->next;
			}
			aux->next = q;
		}
		printf("\n o valor %d foi inserido no final com sucesso!",x);
		return lista;
	}else{
		printf("Erro na alocação do nó Q.... \n");
		return NULL;
	}	
}

Celula *removeFirst(Celula *lista){
	Celula *q;
	q = lista;
	if(isEmpty(lista) == 0){
		lista = q->next;
		printf("\n o valor %d removido do inicio da lista encadeada! ", q->info);
		freeNode(q);
		return lista;
	}else{
		printf("Lista Vazia!");
	}
}

Celula *removeLast(Celula *lista){
	Celula *q;
	Celula *aux;
	q = lista;
	int i = 0;
	if(isEmpty(lista) == 0){
		if(lista->next == NULL){
			freeNode(lista);
		}else{
			while(q->next->next != NULL){
				q = q->next;
			}
		}
		freeNode(q->next);
		q->next = NULL;
		printf("\n o valor foi removido do final da lista encadeada! ");
		return lista;
	}else{
		printf("Lista Vazia!");
	}	
}	



Celula *removeValue(Celula *lista, int x){
	Celula *q;
	Celula *aux;
	
	q = searchValue(lista,x);
	
	if (q != NULL){
		aux = lista;
		if (aux == q){
			removeFirst(lista);
		}else{
			while(aux->next != q){
				aux = aux->next;
				printf("teste!");
			}
			aux->next = q->next;
			printf("\no valor %d removido da lista encadeada!",x);
			freeNode(q);
		}
		return lista;
	}else{
		printf("\n o valor %d não foi encontrado!");
		return NULL;
	}
}

int main (){
	int loopMenu = 1;
	int chooseMenu;
	Celula *l;
	printf("=============================================\n");
	l = init(l);
	int input;
	while (loopMenu == 1){
		printf("\n=============================================");
		printf("\n				  MENU 							");
		printf("\n 1) Mostra Lista Encadeada.......");
		printf("\n 2) Pesquisa valor na Lista Encadeada.......");
		printf("\n 3) Insere valor no inicio da Lista Encadeada.......");
		printf("\n 4) Insere valor no final da Lista Encadeada.......");
		printf("\n 5) Remove valor no inicio da Lista Encadeada.......");
		printf("\n 6) Remove valor no final da Lista Encadeada.......");
		printf("\n 7) Remove determinado valor da lista Encadeada.......");
		printf("\n 8) Sair.......");
		printf("\n=============================================");
		printf("\nDigite o Valor para a Operacao: ");
		scanf("%d",&chooseMenu);
		switch(chooseMenu){
			case 1:
				// case 1
				showList(l);
				break;
			case 2:
				// case 2
				printf("\nValor a ser procurado na Lista Encadeada: ");
				scanf("%d",&input);
				verifyValue(l,input);
				break;
			case 3:
				// case 3
				printf("\nValor a ser colocado no inicio da Lista Encadeada: ");
				scanf("%d",&input);
				l = insertFirst(l,input);
				break;
			case 4:
				// case 4
				printf("\nValor a ser eliminado da Lista Encadeada: ");
				scanf("%d",&input);
				l = insertLast(l,input);
				break;
			case 5:
				// case 5
				l = removeFirst(l);
				break;
			case 6:
				l = removeLast(l);
				// case 6
				break;
			case 7:
				printf("\n valor da lista Encadeada a ser removido: ");
				scanf("%d",&input);
				l = removeValue(l,input);
				// case 7
				break;
			case 8:
				printf("Encerrando o Loop do menu!");
				loopMenu = 0;
				// case 8
				break;
			default:
				printf("Opcao Invalida!");
		}	
	}
	return 0;	
}
