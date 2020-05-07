#include <stdio.h>
#include <stdlib.h>
#define MAX 10

typedef struct sLetras{
	char l;
}Letras;

typedef struct sLista{
	int qnt;
	Letras l[MAX];
	
}Lista;

Lista* criaLista(){
    // instancia a Lista
    Lista *li;
    li = (Lista *)malloc(sizeof(Lista));
    if(li != NULL){
        li->qnt = 0;
    }
    return li;
}
int tamanhoLista(Lista *li){
    // conta o tamanho da lista
    if(li==NULL){
        return -1;
    }else{
        return li->qnt;
    }
}

int insereFinalLista(Lista *li,Letras L2){
    // insere na ultima posicao da lista
        li->l[li->qnt] = L2;
        printf("lista %d = %c",li->qnt,li->l[li->qnt].l);
        li->qnt--;
        printf("\n inserção no final da lista feita com sucesso..");
        return 1;
}

int removeFinalLista(Lista *li){
    // remove o valor que estÃ¡ na ultima posiÃ§Ã£o da lista...
    li->l[9].l = '0';
    return 1;
}

int InserePosicaoEspecifica(Lista *li,Letras L2,int n){
    // insere em posicao específica da lista
    if(li == NULL){
        return 0;
    }
    if(li->qnt == 0){
        return 0;
    }
    if(li->qnt > 0){
        li->l[n] = L2;
        return 1;
    }
}

void printaLista(Lista *li){
	int i;
	for(i=0;i<10;i++){
		printf("\n Posicao [%d] = %c",i,li->l[i].l);
	}
}
int main(){
	Lista *li;
	li = criaLista();
    // chama função para criar Lista
    int l = 9;
    li->qnt = 9;
	if(li == NULL){
		printf(" lista não alocada!");
		return 0;
	}else{
		int sair = 0;
		do{
			printf("\n=================================================\n");
			printf("|                        MENU                   |\n");
			printf("=================================================\n");
			printf("STATUS: LISTA ALOCADA E PRONTA PARA OPERACOES!\n");
			printf("=================================================\n");
			printf("1 - Insere no final da lista: \n");
			printf("2 - Remove elemento no final da lista:\n");
			printf("3 - Altera o valor do elemento:\n");
			printf("4 - Exibe elementos do vetor:\n");
			printf("5 - Mostra tamanho da lista:\n");
			printf("6 - Sair do loop:\n");
			printf("=================================================\n");
			printf("Digite sua Opcao:");
			int opcao;
			scanf("%d",&opcao);
			fflush(stdin);
			if(opcao == 1){
				Letras l1;
				printf("\n Digite uma letra a ser inserida:");
				scanf("%c",&l1.l);
				int k = insereFinalLista(li, l1);
			}
			if(opcao == 2){
				int a1 = removeFinalLista(li);
    			// remocao feita no final de uma lista...
    			if(a1==1){
        			printf("\n Remocao no final da lista feita com sucesso..");
    			}else{
        		printf("\n Nao foi feita Remocao no final da lista...");
    			}
			}
			if(opcao == 3){
				Letras l1;
				printf("\n Digite uma letra a ser inserida:");
				scanf("%c",&l1.l);
				int n;
				printf("\n Digite uma posicao aonde pode ser inserida:");
				scanf("%d",&n);
				int a1 = InserePosicaoEspecifica(li,l1,n);
    			// remocao feita no final de uma lista...
    			if(a1==1){
        			printf("\n Insercao feita com sucesso..");
    			}else{
        			printf("\n Nao foi feita Insercao...");
        		}
			}
			if(opcao == 4){
				printaLista(li);
			}
			if(opcao == 5){
				int n = tamanhoLista(li);
				printf("\n tamanho da lista: %d",n);
				printf("\n tamanho de byes: %d",sizeof(li));
			}
			if(opcao == 6){
				sair=1;
			}		
		}while(sair==0);
	}		
}
