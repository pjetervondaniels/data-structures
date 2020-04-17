#include <stdio.h>
#include <stdlib.h>
#define MAX 10

typedef struct sNumero{
	int nInteiro;
}Numero;

typedef struct sLista{
	int qtd;
	Numero n[MAX];
}Lista;

Lista* CriaLista(){
	Lista *li;
	li = (Lista*)calloc(1,sizeof(Lista));
	li->qtd = 0;
	return li;
}

void liberaLista(Lista *li){
	free(li);
}

int verificaVazia(Lista *li){
	if(li->qtd == 0){
		return 1;
	}else{
		return 0;
	}
}

int verificaCheia(Lista *li){
	if(li->qtd == MAX-1){
		return 1;
	}else{
		return 0;
	}
}



int insereInicioLista(Lista *li,Numero n2){
    // insere no inÃ­cio da lista
    if(li == NULL){
        return 0;
    }
    if(verificaCheia(li)==1){
        return 0;
    }
    if(verificaCheia(li)==0){
        int i;
        for(i= li->qtd;i>=0;i--){
            li->n[i+1] = li->n[i];
        }
        li->n[0] = n2;
        li->qtd++;
        return 1;
    }
}

int insereFinalLista(Lista *li,Numero n2){
    if(li == NULL){
        return 0;
    }
    if(verificaCheia(li)==1){
        return 0;
    }
    if(verificaCheia(li)==0){
        li->n[li->qtd] = n2;
        li->qtd++;
        return 1;
    }
}




int removeInicioLista(Lista *li){
	int i;
	for(i=0;i<10;i++){
		li->n[i] = li->n[i+1];
	}
	return 1;
}

int removeFinalLista(Lista *li){
	int i = 0;
	li->n[li->qtd].nInteiro = 0;
	return 1;
}

void printaLista(Lista *li){
	int i,j;
	for(i=0;i<10;i++){
		printf("Lista [%d] = %d \n",i,li->n[i].nInteiro);
	}
	printf("========================================\n");
}


int main (){
	Lista *li;
	li = CriaLista();
	
	if(li == NULL){
		printf("Não ha memoria!\n");
		return 0;
	}
	int boolMenu = 1;
	do{
		if(verificaCheia(li) == 1){
			printf("Lista Cheia!");
			return 0;
		}
		printf("\n=================================================\n");
		printf("|                        MENU                   |\n");
		printf("=================================================\n");
		printf(" STATUS: LISTA ALOCADA E PRONTA PARA OPERACOES!\n");
		printf("=================================================\n");
		printf("1 - Insere numero no inicio da lista: \n");
		printf("2 - Insere numero no final da lista:\n");
		printf("3 - Remove numero no inicio da lista:\n");
		printf("4 - Remove numero no final da lista:\n");
		printf("5 - Mostra lista:\n");
		printf("6 - sair do loop:\n");
		printf("=================================================\n");
		printf("Digite sua Opcao:");
		int opcao;
		scanf("%d",&opcao);
		switch(opcao){
			case 1:
				printf("=================================================\n");
				printf("		Insercao  no inicio               \n");
				printf("=================================================\n");
				printf("Digite o valor de n: \n");
				printf("==========================================\n");
				Numero n1;
				scanf("%d",&n1.nInteiro);
				int k;
				k = insereInicioLista(li,n1);
				if(k == 1){
					printf("Insercao feita com sucesso!");
				}else{
					printf("Nao aconteceu insercao!");
				}
				break;
			case 2:
				printf("=================================================\n");
				printf("		Insercao  no Final               \n");
				printf("=================================================\n");
				printf("Digite o valor de n: \n");
				printf("==========================================\n");
				scanf("%d",&n1.nInteiro);
				k = insereFinalLista(li,n1);
				if(k == 1){
					printf("Insercao feita com sucesso!");
				}else{
					printf("Nao aconteceu insercao!");
				}
				break;
				
			case 3:
				printf("=================================================\n");
				printf("		Remocao no inicio             \n");
				printf("=================================================\n");
				k = removeInicioLista(li);
				if(k == 1){
					printf("remocao feita com sucesso!");
				}else{
					printf("Nao aconteceu insercao!");
				}
				break;	
			case 4:
				printf("=================================================\n");
				printf("		Remocao no Final             \n");
				printf("=================================================\n");
				k = removeFinalLista(li);
				if(k == 1){
					printf("remocao feita com sucesso!");
				}else{
					printf("Nao aconteceu insercao!");
				}
				break;
			case 5:
				printf("=====================================================\n");
				printf("			Impressao da Lista             \n");
				printf("=====================================================\n");
				printaLista(li);
				break;
			case 6:
				liberaLista(li);
				exit(1);
				break;
				
			default:
				printf("Opcao Invalida!");
		}
		
	}while(boolMenu == 1);
	
	return 0;
}
