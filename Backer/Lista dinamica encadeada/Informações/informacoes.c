#include <stdio.h>
#include <stdlib.h>
#include "implementacao.h"


struct elemento{
	struct aluno dados;
	struct elemento *prox;
};

typedef struct elemento Elem;

Lista* cria_lista(){
	Lista *li = (Lista*)malloc(sizeof(Lista));
	if(li != NULL){
		*li = NULL;
		return li;
	}
}
void liberaLista(Lista *li){
	id(li != NULL){
		Elem* no;
		while((*li) != NULL){
			no = *li;
			*li = (*li)->prox;
			free(no);
		}
		free(li);
	}
}

int tamanhoLista(Lista *li){
	if(li == NULL){
		return 0;
	}else{
		int cont = 0;
		Elem* no = *li;
		while(no != NULL){
			cont++;
			no = no->prox;
		}
		return cont;
	}
}

int CheiaLista(Lista *li){
	return 0;
}

int VaziaLista(Lista *li){
	if(li == NULL){
		return 1;
	}else{
	if(*li == NULL){
		return 1;
	}else{
		return 0;
	}
}

int main(){
	Lista *li;
	// ponteiro para ponteiro...
	li = cria_lista();
	int a1 = tamanhoLista(li);
	int a2 = CheiaLista(li);
	// a lista estará cheia apenas quando a memória do computador acabar...
	int a3 = VaziaLista(Lista *li);
	if(a3==1){
		printf("Lista Vazia!");
	}else{
		printf("Lista com Valor!");
	}
	li = liberaLista(li);
}
