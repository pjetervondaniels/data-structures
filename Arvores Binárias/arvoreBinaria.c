#include <stdio.h>
#include <stdlib.h>

typedef struct sNode{
	int info;
	struct sNode *esq;
	struct sNode *dir;
}Node;

Node *getNode(){
	return (Node*)malloc(sizeof(Node));
}

void freeNode(Node *ptrArvore){
	free(ptrArvore);
}

int isEmpty(Node *ptrArvore){
	if(ptrArvore == NULL){
		return 1;
	}else{
		return 0;
	}
}

void init(Node **ptrArvore){
	*ptrArvore = NULL;
}

Node* search(Node *ptrRaiz, int x){
	Node *aux;
	aux = ptrRaiz;
	if(aux == NULL){
		printf("\n ERRO: Valor nao encontrado na Arvore!");
		return NULL;
	}else{
		if(x < aux->info){
			return search(aux->esq, x);
		}else{
			if(x > aux->info){
				return search(aux->dir, x);
			}else{
				return aux;
			}
		}
	}
}

Node *largestRight(Node **n1) { 
    if((*n1)->dir != NULL){
    	return largestRight(&(*n1)->dir);
	}else{
        Node *aux = *n1;
        if((*n1)->esq != NULL){
            *n1 = (*n1)->esq;
		}else{
            *n1 = NULL;
            return aux;
        }
    }
    return *n1;
}

Node *lowestLeft(Node **n1) {
    if((*n1)->esq != NULL){
        return lowestLeft(&(*n1)->esq);
	}else{
        Node *aux;
		aux = *n1;
        if((*n1)->dir != NULL){
            *n1 = (*n1)->dir;
		}else{
			*n1 = NULL;
		}
        return aux;
    }
}

void pushR(Node **ptrRaiz, int x) {
    if(*ptrRaiz == NULL){
        (*ptrRaiz)->esq = NULL;
        (*ptrRaiz)->dir = NULL;
        (*ptrRaiz)->info = x;
    }else{
        if(x < ((*ptrRaiz)->info)){
            pushR(&((*ptrRaiz)->esq), x);
    	}else{
            pushR(&((*ptrRaiz)->dir), x);
    	}
	}
}

void push(Node **ptrRaiz, int x){
	Node *aux;
	Node *aux2;
	Node *q;
	
	aux = *ptrRaiz;
	aux2 = NULL;
	q = getNode();
	
	if(q != NULL){
		q->info = x;
		q->dir = NULL;
		q->esq = NULL;
		if(isEmpty(*ptrRaiz) == 1){
			*ptrRaiz = q;
			printf("\n Primeiro membro da Arvore!");
		}else{
			while(aux != NULL){
				aux2 = aux;
				if(x < aux2->info){
					aux = aux->esq;
				}else{
					aux = aux->dir;
				}
			}
			if(x < aux2->info){
				aux2->esq = q;
			}else{
				aux2->dir = q;
			}
			printf("\n Valor colocado na arvore!");
		}
	}else{
		printf("\nERRO: No nao alocado! ");
	}
}

void pop(Node **ptrRaiz, int x){
	if(isEmpty(*ptrRaiz) == 1){
		printf("\n ERRO: Arvore vazia!");
	}else{
		Node *aux;
		aux = *ptrRaiz;
		if(x < aux->info){
			pop(&aux->esq, x);
		}
		if(x > aux->info){
			pop(&aux->dir, x);
		}else{
			if((*ptrRaiz)->esq == NULL && (*ptrRaiz)->dir == NULL){
				// caso o nó não tenha sub-nós...
				freeNode(aux);
				(*ptrRaiz) == NULL;
			}else{
				if((*ptrRaiz)->esq == NULL) {
					// caso ainda tenha um nó direito..
                    (*ptrRaiz) = (*ptrRaiz)->dir;
                    aux->dir = NULL;
                    free(aux);
                    aux = NULL;
				}else{
                	if((*ptrRaiz)->dir == NULL){
                		// caso ainda tenha um nó esquerdo
	                    (*ptrRaiz) = (*ptrRaiz)->esq;
	                    aux->esq = NULL;
	                    free(aux);
	                    aux = NULL;
                    }else{ 
	                    aux = largestRight(&(*ptrRaiz)->esq); 
	                    aux->esq = (*ptrRaiz)->esq;
	                    aux->dir = (*ptrRaiz)->dir;
	                    (*ptrRaiz)->esq = (*ptrRaiz)->dir = NULL;
	                    free((*ptrRaiz));
	                    *ptrRaiz = aux;
	                    aux = NULL;
                    } 				
				}         
			}	
		}
		printf("\n Valor removido da arvore!");
	}
}

void biggestValue(Node* ptrRaiz) {
    if((ptrRaiz->dir != NULL) && (ptrRaiz->dir->info > ptrRaiz->info)){
        biggestValue(ptrRaiz->dir);
    }else{
        printf("\nMaior Valor: %d\n", ptrRaiz->info);    	
	}
}

void smallestValue(Node* ptrRaiz) {
    if((ptrRaiz->esq != NULL) && (ptrRaiz->esq->info < ptrRaiz->info)){
        smallestValue(ptrRaiz->esq);
    }else{
        printf("\nMenor Valor: %d\n", ptrRaiz->info);
	}
}

void printTrace(int level) {
	int i;
    for(i = 0; i < level; i++){
		printf("-");
	}
}

void print(Node* ptrRaiz, int level) {
    if(ptrRaiz == NULL) {
        printTrace(level);
        printf("*\n");
    }else{
	    print(ptrRaiz->dir, level+1);
	    printTrace(level);
	    printf("%d\n", ptrRaiz->info);
	    print(ptrRaiz->esq, level+1);
	}
}

void visit(Node* ptrRaiz) {
    printf("%d\n",ptrRaiz->info);
}

void showInOrder(Node *ptrRaiz) { 
    if(ptrRaiz != NULL) {
        showInOrder(ptrRaiz->esq);
        visit(ptrRaiz);
        showInOrder(ptrRaiz->dir);
    }
}

void showPreOrder(Node *ptrRaiz) { 
    if(ptrRaiz != NULL) {
        visit(ptrRaiz);
        showPreOrder(ptrRaiz->esq);
        showPreOrder(ptrRaiz->dir);
    }
}

void showPosOrder(Node *ptrRaiz) { 
    if(ptrRaiz != NULL) {
        showPosOrder(ptrRaiz->esq);
        showPosOrder(ptrRaiz->dir);
        visit(ptrRaiz);
    }
}

int countNodes(Node *ptrRaiz) { 
    if(ptrRaiz == NULL){
        return 0;
	}else{
		return 1 + countNodes(ptrRaiz->esq) + countNodes(ptrRaiz->dir);
	}
}

int countLeafs(Node *ptrRaiz) {
    if(ptrRaiz == NULL){
        return 0;  	
	}
    if(ptrRaiz->esq == NULL && ptrRaiz->dir == NULL){
    	return 1;
	}
    return countLeafs(ptrRaiz->esq) + countLeafs(ptrRaiz->dir);
}

int compare(int a, int b) {
    if(a > b){
        return a;    	
	}else{
        return b;
	}
}

int heightTree(Node *ptrRaiz){
    if((ptrRaiz == NULL) || (ptrRaiz->esq == NULL && ptrRaiz->dir == NULL)){
        return 0;    	
	}else{
        return 1 + compare(heightTree(ptrRaiz->esq), heightTree(ptrRaiz->dir));		
	}
}

void menu(){
	Node *ptrArvore;
	init(&ptrArvore);
	int input, chooseMenu, loopMenu = 1;
	while (loopMenu == 1){
		printf("\n==============================================================================");
		printf("\n				  MENU 							");
		printf("\n 1) Insere valor na Arvore.......");
		printf("\n 2) Insere valor na Arvore com recursao.......");
		printf("\n 3) Remover valor na Arvore.......");
		printf("\n 4) Exibir em pre-ordem.......");		
		printf("\n 5) Exibir em ordem.......");		
		printf("\n 6) Exibir em pos-ordem.......");		
		printf("\n 7) Contar Folhas da Arvore.......");		
		printf("\n 8) Contar Nos da Arvore.......");		
		printf("\n 9) Mostra a Altura da Arvore.......");		
		printf("\n 10) Procura elemento na Arvore.......");
		printf("\n 11) Mostra arvore lateralmente.......");				
		printf("\n 12) Maior valor da arvore.......");				
		printf("\n 13) Menor valor da arvore.......");				
		printf("\n 14) Sair.......");
		printf("\n==============================================================================");
		printf("\nDigite o Valor para a Operacao: ");
		scanf("%d", &chooseMenu);
		switch(chooseMenu){
			case 1:
				printf("\nInsere valor na Arvore: ");
				scanf("%d", &input);
				push(&ptrArvore, input);
				break;
			case 2:
				printf("\nInsere valor na Arvore: ");
				scanf("%d", &input);
				pushR(&ptrArvore, input);
				break;
			case 3:				
				printf("\nRemove valor na Arvore: ");
				scanf("%d", &input);
				pop(&ptrArvore, input);
				break;		
			case 4:
				showPreOrder(ptrArvore);
				break;
			case 5:
				showInOrder(ptrArvore);
				break;
			case 6:
				showPosOrder(ptrArvore);
				break;
			case 7:
				printf("\nQuantidade de folhas: %d", countLeafs(ptrArvore));
				break;
			case 8:
				printf("\nQuantidade de Nos: %d", countNodes(ptrArvore));
				break;
			case 9:
				printf("\nAltura da Arvore: %d", heightTree(ptrArvore));
				break;
			case 10:
				printf("\n Valor a ser procurado: ");
				scanf("%d", &input);
				if(search(ptrArvore, input) != NULL){
					printf("\nElemento %d encontrado", input);
				}else{
					printf("\nElemento nao %d encontrado", input);
				}
				break;
			case 11:
				print(ptrArvore, 0);
				break;
			case 12:
				biggestValue(ptrArvore);
				break;
			case 13:
				smallestValue(ptrArvore);
				break;
			case 14:							
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
