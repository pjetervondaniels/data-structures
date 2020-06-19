#include <stdio.h>
#include <stdlib.h>

typedef struct sCelula{
    int conteudo;
    struct sCelula *next;
}Celula;

void init(Celula **pilha){
	*pilha = NULL;
}

Celula *getNode(){
	return (Celula *)malloc(sizeof(Celula));
}

void freeNode(Celula *q){
	free(q);
}

int isEmpty(Celula *pilha){
	if(pilha == NULL){
		return 1;
	}else
		return 0;
}

void push(Celula **pilha, int x){
	Celula *q;
	Celula *aux;
	
	q = getNode();
	if(q != NULL){
		q->conteudo = x;
		q->next = NULL;
		if(isEmpty(*pilha) == 1){
			*pilha = q;
		}else{
			aux = *pilha;
			while(aux->next != NULL){
				aux = aux->next;
			}
			aux->next = q;
		}
	}else{
		printf("ERRO: No Q nao alocadado!");
	}		
}


void pop(Celula **pilha){
	Celula *q;
	Celula *aux;
	q = *pilha;
	if(isEmpty(*pilha) == 0){
		aux = *pilha;
		while(aux->next->next == NULL){
			aux = aux->next;
		}
        aux->next = NULL;
		freeNode(aux->next->next);
	}else{
		printf("Erro: pilha Vazia!");
	}
}

void show(Celula **pilha){
    Celula *aux;
	aux = *pilha;
    if(isEmpty(*pilha) == 1){
        printf("\n erro! pilha vazia");
    }else{
        int i = 0;
        while (aux != NULL){
            printf("\n Posicao da pilha [%d] = [%d]", i, aux->conteudo);
            i += 1;
            aux = aux->next;
        }
        
    }
}

void seeTop(Celula **pilha){
    if(isEmpty(*pilha) == 1){
        printf("\n erro! pilha vazia");
    }else{
        Celula *auxilar;
	    auxilar = *pilha;
        while (auxilar->next != NULL){
            auxilar = auxilar->next;
        }

        printf("\n Topo da pilha: %d", auxilar->conteudo);
    }
}

int main(){
    Celula *p1;
    init(&p1);
    int loopMenu = 1;
	int chooseMenu;
int input;
	while (loopMenu == 1){
		printf("\n===============================================================================");
		printf("\n				  MENU 							");
		printf("\n 1) Mostra Pilha Inteira.......");
		printf("\n 2) Mostra o topo da Pilha.......");
		printf("\n 3) Insere um valor na Pilha .......");		
		printf("\n 4) Remove um valor na Pilha.......");
		printf("\n 5) Sair.......");
		printf("\n===============================================================================");
		printf("\nDigite o Valor para a Operacao: ");
		scanf("%d",&chooseMenu);
		switch(chooseMenu){
			case 1:
				// case 1
				show(&p1);
				break;
			case 2:
				// case 2
				seeTop(&p1);
				break;
			case 3:
				// case 3
				printf("\nValor a ser colocado na Pilha: ");
				scanf("%d",&input);
				push(&p1, input);
				break;
			case 4:
				// case 4
				pop(&p1);
				break;
			case 5:
				printf("Encerrando o Loop do menu!");
				loopMenu = 0;
				break;
			default:
				printf("Opcao Invalida!");
		}	
	}
    return 0;
}
