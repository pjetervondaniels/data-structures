#include <stdio.h>
#include <stdlib.h>

typedef struct sCelula{
	int info;
	struct sCelula *next;
}Celula;

Celula *init(Celula *lista){
	/*
	-> Inicia o ponteiro para uma lista encadeada
	-> lista é o endereço do ponteiro externo para uma lista encadeada 
	*/
	lista = NULL;
	printf("Lista Circular iniciada com sucesso!");
	return lista;
}

Celula *getNode(){
	/*
		A função getnode() aloca/cria um nó para uma lista encadeada.
	*/
	return (Celula *)malloc(sizeof(Celula));
}

void freeNode(Celula *q){
	/* Liberar o espaço de memória ocupado por um nó, aonde q é o endereço do nó a ser liberado */
	free(q);
}

int isEmpty(Celula *lista){
	/*
	->  Verificar se a lista encadeada está vazia 
	-> lista é o endereço do primeiro nó da lista encadeada 
	-> 1 para lista vazia e 0 para lista não vazia...
	*/
	if(lista == NULL){
		return 1;
	}else
		return 0;
}

Celula *insertEnd(Celula *lista, int x){
	Celula *q;
	Celula *aux;
	aux = lista;
	q = getNode();
	
	if(q != NULL){
		if(isEmpty(lista) == 1){		
			// o final de uma lista encadeada sempre é o primeiro membro...
			q->info = x;
			q->next = q;
			lista = q;
			printf("Primeiro membro da lista circular!");
			return lista;	
		}else{
			aux = lista;
			
			q->info = x;
			q->next = aux;
			do{
				aux = aux->next;
			}while(aux->next->info != lista->info);
			
			aux->next = q;
			q->next = lista;
			return lista;
		}		
	}else{
		printf("\nErro na alocacao do no!");
		return NULL;
	}
}

Celula *insertFirst(Celula *lista,int x){
	Celula* q;
	Celula *aux;
	
	q = getNode();
	if(q != NULL){
		if(isEmpty(lista) == 1){
			q->info = x;
			q->next = q;
			// caso não tenha nada na lista...
			printf("Primeiro membro da lista circular!");
			lista = q;
			return lista;	
		}else{
			aux = lista;
			q->info = x;
			q->next = lista;
			
			do{
				aux = aux->next;
			}while(aux->next->info != lista->info);
			
			// procura o final e coloca a referência do novo cabeçalho...
			aux->next = q;
			q->next = lista;
			lista = q;
			printf("Insercao feita no inicio com sucesso!");
			return lista;
		}
	}else{
		printf("\nErro na alocacao do no!");
		return NULL;
	}
}

Celula *removeEnd(Celula *lista){
	Celula* q;
	Celula *aux;
	
	q = getNode();
	if(q != NULL){
		if(isEmpty(lista) == 1){
			printf("Lista Vazia!");
			return NULL;
		}else{
			q = lista->next;
			if(q->next == lista->next){
				printf("\n o valor eh o unico removido da lista circular! ");
				free(q);
			}else{
				do{
					q = q->next;
				}while(q->next->next->info != lista->info);
				// procura penúltimo....
				
				free(q->next);
				q->next = lista;
				printf("\n o valor foi removido do final da lista circular! ");
			}
		}
	}else{
		printf("\nErro na alocacao do no!");
		return NULL;
	}
}

Celula *removeFirst(Celula *lista){
	Celula *aux;
	Celula *q;
	q = lista;
	
	if(isEmpty(lista) == 0){
		if(lista == lista->next){
			return NULL;
		}else{
			lista->info = q->next->info;
			lista->next = q->next->next;
			return lista;
		}		
	}else{
		printf("Lista Vazia!");
	}
}

void printList(Celula *lista){
	Celula *aux;
	if(isEmpty(lista) == 0){
		int i = 0;
		printf("\nPrintando Lista Circular.....\n");
		aux = lista;
		do{
			printf("\nposicao [%d] = %d", i, aux->info);
			aux = aux->next;
			i++;
		}while(aux != lista);
	}else{
		printf("\n Lista Vazia!");
	}
}

int main(){
	Celula *l;
	l = init(l);
	int loopMenu = 1;
	int chooseMenu;
	int input;
	while (loopMenu == 1){
		printf("\n===============================================================================");
		printf("\n				  MENU 							");
		printf("\n 1) Mostra Lista Circular.......");
		printf("\n 2) Insere no Inicio.......");
		printf("\n 3) Insere no Final .......");		
		printf("\n 4) Remove a Primeira Posicao.......");
		printf("\n 5) Remove a Posicao Final.......");
		printf("\n 6) Sair.......");
		printf("\n===============================================================================");
		printf("\nDigite o Valor para a Operacao: ");
		scanf("%d",&chooseMenu);
		switch(chooseMenu){
			case 1:
				// case 1
				printList(l);
				break;
			case 2:
				// case 2
				printf("\nValor a ser colocado no inicio da Lista Circular: ");
				scanf("%d",&input);
				l = insertFirst(l, input);
				break;
			case 3:
				// case 3
				printf("\nValor a ser colocado no final da Lista Circular: ");
				scanf("%d",&input);
				l = insertEnd(l, input);
				break;
			case 4:
				// case 4
				removeFirst(l);
				break;
			case 5:
				// case 5
				removeEnd(l);
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


