#include <stdio.h>
#include <stdlib.h>
#define MAX 10

typedef struct sContato{
	int numeroContato;
	char nomeContato[30];
}Contato;

typedef struct sLista{
	int qtd;
	Contato c1[MAX];
}Lista;

Lista* CriaLista(){
	Lista *li;
	li = (Lista*)calloc(1,sizeof(Lista));
	li->qtd = 0;
	return li;
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



int insereInicioLista(Lista *li,Contato c2){
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
            li->c1[i+1] = li->c1[i];
        }
        li->c1[0]= c2;
        li->qtd++;
        return 1;
    }
}

void removePosicaoLista(Lista *li,int posicao){
	li->c1[posicao].numeroContato = 0;
	int i;
	char stringVazia[1] = " ";
	for(i=0;i<30;i++){
		li->c1[posicao].nomeContato[i] = stringVazia[0]; 
	}
	if(li->c1[posicao].numeroContato == 0){
		printf("Remocao feita com sucesso!");
	}else{
		printf("Erro na Remocao!");
	}
}


void acessaElemento(Lista *li,int posicao){
	printf("========================================\n");
	printf("		posicao %d  \n",posicao);
	printf(" Numero na posicao: %d",li->c1[posicao].numeroContato);
	printf(" Nome do Contato: %s",li->c1[posicao].nomeContato);
    printf("========================================\n");
}

procuraElemento(Lista *li,int valor){
	int i=0,aux;
	while(li->c1[i].numeroContato != valor && i<10){
		i++;
	}
	if(li->c1[i].numeroContato == valor){
		printf("========================================\n");
		printf(" 	Elemento Encontrado		");
		printf("========================================\n");
		printf(" Numero do Contato = %d   \n",li->c1[i].numeroContato);
	    printf("========================================\n");
	}else{
		printf("========================================\n");
		printf(" 	Elemento nao Encontrado		");
		printf("========================================\n");
	}
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
		printf("1 - inserir um contato no inicio da lista: \n");
		printf("2 - remover um determinado contato pela posicao na lista:\n");
		printf("3 - acessar um contato de uma posição especifica:\n");
		printf("4 - procurar um contato por numero de telefone:\n");
		printf("5 - sair do loop::\n");
		printf("=================================================\n");
		printf("Digite sua Opcao:");
		int opcao;
		scanf("%d",&opcao);
		switch(opcao){
			case 1:
				printf("=================================================\n");
				printf("		Insercao                  \n");
				printf("=================================================\n");
				printf("Digite o numero e o nome da pessoa: \n");
				printf("==========================================\n");
				Contato c1;
				scanf("%d",&c1.numeroContato);
				fflush(stdin);
				gets(c1.nomeContato);
				int k;
				k = insereInicioLista(li,c1);
				if(k == 1){
					printf("Insercao feita com sucesso!");
				}else{
					printf("Nao aconteceu insercao!");
				}
				break;
				
			case 2:
				
				printf("=================================================\n");
				printf("		Remocao                  \n");
				printf("=================================================\n");
				printf("Digite uma posicao na lista: \n");
				printf("=================================================\n");
				int posicao;
				scanf("%d",&posicao);
				removePosicaoLista(li,posicao);
				break;
				
			case 3:
				printf("=================================================\n");
				printf("		Exibicao                  \n");
				printf("=================================================\n");
				printf("Digite uma posicao na lista: \n");
				printf("=================================================\n");
				scanf("%d",&posicao);
				acessaElemento(li,posicao);
				break;
				
			case 4:
				printf("=================================================\n");
				printf("		Procura Numero na Lista                  \n");
				printf("=================================================\n");
				printf("Digite um numero de telefone para ser pesquisado: \n");
				int valor;
				scanf("%d",&valor);
				procuraElemento(li,valor);
				break;
			case 5:
				exit(1);
				break;
				
			default:
				printf("Opcao Invalida!");
		}
		
	}while(boolMenu == 1);
	
	return 0;
}