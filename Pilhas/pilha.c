#include <stdio.h>
#include <stdlib.h>
#define tamMax 100

typedef struct sPilha{
    int conteudo[tamMax];
    int topo;
}Pilha;

void init(Pilha *s){
    // inicializa pilha marcando -1.
    s->topo = -1;
    printf("\n Pilha iniciada com sucesso!");
}

int isEmpty(Pilha *s){
    // verifica se a pilha está vazia...
    if(s->topo == -1){
        return -1;
    }else{
        return 0;
    }
}
int isFull(Pilha *s){
    if(s->topo == tamMax - 1){
        return 1;
    }else{
        return 0;
    }
}

void push(Pilha *s, int x){
    if(isFull(s) == 1){
        printf("\n Pilha cheia!");
    }else{
        s->topo += 1;
        s->conteudo[s->topo] = x;
        printf("\n Item colocado no topo da pilha!");
    }
}

int pop(Pilha *s){
    int aux;
    if(isEmpty(s) == 1){
        printf("\n erro! pilha vazia");
        return -1;
    }else{
        aux = s->conteudo[s->topo];
        s->topo -= 1;
        return aux;
    }
}

void show(Pilha *s){
    Pilha *aux = s;
    if(isEmpty(s) == 1){
        printf("\n erro! pilha vazia");
    }else{
        int i = 0;
        while (i <= aux->topo){
            printf("\n Posicao da pilha [%d] = [%d]", i, aux->conteudo[i]);
            i += 1;
        }
        
    }
}

void seeTop(Pilha *s){
    if(isEmpty(s) == 1){
        printf("\n erro! pilha vazia");
    }else{
        printf("\n Topo da pilha: %d", s->conteudo[s->topo]);
    }
}

int main(){
    Pilha p1;
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
