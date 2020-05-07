#include <stdio.h>
#include <stdlib.h>
#define MAX 10
#include <string.h>

typedef struct sPlaylist{
	char nomeMusica[30];
	char nomeDisco[30];
}Playlist;

typedef struct sLista{
	int qtd;
	Playlist p[MAX];
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

int insereInicioLista(Lista *li,Playlist p2){
    // insere no inicio
    if(li == NULL){
        return 0;
    }
    if(verificaCheia(li)==1){
        return 0;
    }
    if(verificaCheia(li)==0){
        int i;
        for(i= li->qtd;i>=0;i--){
            li->p[i+1] = li->p[i];
        }
        li->p[0]= p2;
        li->qtd++;
        return 1;
    }
}

printaLista(Lista *li){
	int i,j;
	for(i=0;i<10;i++){
		printf("Lista [%d] \n",i);
		printf("Nome da musica:");
		for(j=0;j<strlen(li->p[i].nomeMusica);j++){
			printf("%c",li->p[i].nomeMusica[j]);
		}
		printf("\n");
		printf("Nome do album:");
		for(j=0;j<strlen(li->p[i].nomeDisco);j++){
			printf("%c",li->p[i].nomeDisco[j]);
		}
		printf("\n");
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
		printf("1 - Incluir musica e o Album no inicio da lista: \n");
		printf("2 - Visualizar a lista de musicas: \n");
		printf("3 - sair do loop::\n");
		printf("=================================================\n");
		printf("Digite sua Opcao:");
		int opcao;
		scanf("%d",&opcao);
		switch(opcao){
			case 1:
				printf("=================================================\n");
				printf("		Insercao                  \n");
				printf("=================================================\n");
				printf("Digite uma musica e o album: \n");
				printf("==========================================\n");
				Playlist p1;
				fflush(stdin);
				gets(p1.nomeMusica);
				fflush(stdin);
				gets(p1.nomeDisco);
				int k;
				k = insereInicioLista(li,p1);
				if(k == 1){
					printf("Insercao feita com sucesso!");
				}else{
					printf("Nao aconteceu insercao!");
				}
				break;
			case 2:
				printf("=====================================================\n");
				printf("			Exibicao da Playlist             \n");
				printf("=====================================================\n");
				printaLista(li);
				break;
			case 3:
				exit(1);
				break;
				
			default:
				printf("Opcao Invalida!");
		}
		
	}while(boolMenu == 1);
	
	return 0;
}
