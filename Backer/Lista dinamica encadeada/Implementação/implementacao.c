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

int main(){
	Lista *li;
	// ponteiro para ponteiro...
	li = cria_lista();
	
	
	
	li = liberaLista(li);
}
