#include <stdio.h>
#include <stdlib.h>
#define tamMax 10

typedef struct sDeque{
	int itens[tamMax];
    int tam;
}Deque;


void init(Deque *d1){
	d1->tam = 0;
	printf("\n Deque inicializada com sucesso!");
}

int isEmpty(Deque *d1){
	if(d1->tam == 0){
		return 1;
	}else{
		return 0;
	}
}

int isFull(Deque *d1){
	if(d1->tam == tamMax - 1){
		return 1;
	}else{
		return 0;
	}
}

void insertBegin(Deque *d1, int x){
	if(isFull(d1) == 1){
		printf("\n Erro: Deque Cheio!");
	}else{
		if(isEmpty(d1) == 1){
			d1->itens[d1->tam] = x;
			d1->tam += 1;
		}else{
			int i;
			for(i = 0; i < d1->tam; i++){
				d1->itens[i+1] = d1->itens[i];
			}
			d1->itens[0] = x;
			d1->tam += 1;
		}
		printf("\n Valor colocado no inicio!");
	}
}

void insertLast(Deque *d1, int x){
	if(isFull(d1) == 1){
		printf("\n Erro: Deque Cheio!");
	}else{
		d1->itens[d1->tam] = x;
		d1->tam += 1;
		printf("\n Valor colocado no final!");
	}
}	

void removeFirst(Deque *d1){
	if(isEmpty(d1) == 1){
		printf("\n Erro: Deque vazio! ");
	}else{
		int i;
		for(i = 0; i < d1->tam; i++){
			d1->itens[i] = d1->itens[i+1];
		}
		d1->tam -= 1;
		printf("\n Valor inicial removido!");
	}
}

int removeLast(Deque *d1){
	if(isEmpty(d1) == 1){
		printf("\n Erro: Deque vazio! ");
	}else{
		int aux;
		aux = d1->itens[d1->tam]; 
		d1->tam -= 1;
		printf("\n Valor final removido!");
		return aux;
	}	
	
}

void show(Deque *d1){
	Deque *aux = d1;
    if(isEmpty(d1) == 1){
        printf("\n Erro! Deque vazio");
    }else{
        int i = 0;
        while (i < aux->tam){
            printf("\n Posicao do Deque [%d] = [%d]", i, aux->itens[i]);
            i += 1;
        }
	}
}

void showTop(Deque *d1){
	if(isEmpty(d1) == 1){
        printf("\n Erro! Deque vazio");
    }else{
    	printf("\n Valor Inicial do Deque: %d", d1->itens[0]);
    }
}

void showEnd(Deque *d1){
	if(isEmpty(d1) == 1){
        printf("\n Erro! Deque vazio");
    }else{
    	printf("\n Valor Final do Deque: %d", d1->itens[d1->tam-1]);
    }	
}

void menu(){
	Deque d1;
    init(&d1);
    int loopMenu = 1;
	int chooseMenu;
	int input;
	while (loopMenu == 1){
		printf("\n===============================================================================");
		printf("\n				  MENU 							");
		printf("\n 1) Mostra todos valores do Deque.......");
		printf("\n 2) Mostra o ultimo valor do Deque.......");
		printf("\n 3) Mostra a primeiro valor do Deque....");
		printf("\n 4) Insere um valor no inicio do Deque .......");
		printf("\n 5) Insere um valor no final do Deque .......");	
		printf("\n 6) Remove o valor no inicio do Deque .......");		
		printf("\n 7) Remove o valor no final do Deque .......");		
		printf("\n 8) Sair.......");
		printf("\n===============================================================================");
		printf("\nDigite o Valor para a Operacao: ");
		scanf("%d",&chooseMenu);
		switch(chooseMenu){
			case 1:
				show(&d1);
				break;
			case 2:
				showTop(&d1);
				break;
			case 3:
				showEnd(&d1);
				break;
			case 4:
				printf("\nValor a ser colocado no Inicio do Deque: ");
				scanf("%d",&input);
				insertBegin(&d1, input);
				break;
			case 5:
				printf("\nValor a ser colocado no Final do Deque: ");
				scanf("%d", &input);
				insertLast(&d1, input);
				break;
			case 6:
				removeFirst(&d1);
				break;
			case 7:
				removeLast(&d1);
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

int main(){
	menu();
	return 0;
}





