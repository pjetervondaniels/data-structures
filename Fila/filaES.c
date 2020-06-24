#include <stdio.h>
#include <stdlib.h>
#define tamMax 100

typedef struct sFila{
	int itens[tamMax];
	int tamanho;
}Fila;

void init(Fila *f){
	f->tamanho = 0;
}

int isFull(Fila *f){
	if(f->tamanho == tamMax){
		return 1;
	}else{
		return 0;
	}
}

int isEmpty(Fila *f){
	if(f->tamanho == 0){
		return 1;
	}else{
		return 0;
	}
}

void push(Fila *f, int x){
	if(isFull(f) == 1){
		printf("\nERRO: FILA CHEIA!");
	}else{
		f->itens[f->tamanho] = x;
		f->tamanho += 1;
	}
}

void pop(Fila *f){
	int aux = 0;
	int i = 0;
	if(isEmpty(f) == 0){
		for(i = 0; i < f->tamanho; i++){
			f->itens[i] = f->itens[i + 1];
		}
		f->tamanho -= 1;
	}else{
		printf("\n ERRO: FILA VAZIA!");
	}
}

void show(Fila *f){
	int i = 0;
	if(isEmpty(f) == 0){
		printf("\n FILA: ");
		for(i = 0 ; i < f->tamanho; i++){
			printf("\n Posicao [%d] = %d ", i, f->itens[i]);
		}
	}else{
		printf("\n ERRO: FILA VAZIA!");
	}
}

void menu(){
	Fila ptrFila;
	init(&ptrFila);
    int loopMenu = 1;
	int chooseMenu;
	char input;
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




