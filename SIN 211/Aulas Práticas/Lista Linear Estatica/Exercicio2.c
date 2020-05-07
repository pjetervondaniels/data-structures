#include <stdio.h>
#include <stdlib.h>
#define MAX 10

typedef struct sDisciplina{
	int codigoDisciplina;
	char nomeDisciplina[12];
	int numeroCreditos;
	int cargaHoraria;
}Disciplina;

typedef struct sLista{
	int qnt;
	Disciplina d1[MAX];
	
}Lista;

Lista* criaLista(){
    // instancia a Lista
    Lista *li;
    li = (Lista *)malloc(sizeof(Lista));
    li->qnt = 9;
    return li;
}
int verificaListaCheia(Lista *li){
	// como está inserida de trás para frente...
	if(li->qnt >= 0){
		return 0;
	}else{
		return 1;
	}
}


void insereFinalLista(Lista *li,Disciplina d2){
    // insere na ultima posicao da lista
    	if(verificaListaCheia(li) == 0){
    		// lista não cheia...
    		li->d1[li->qnt] = d2;
        	printf("========================================\n");
       		printf("		DADOS INCLUIDOS NA POSICAO %d        \n",li->qnt);
        	printf("========================================\n");
        	printf("Nome da Disciplina: %s \n",li->d1[li->qnt].nomeDisciplina);
        	printf("Carga horaria: %d \n",li->d1[li->qnt].cargaHoraria);
        	printf("Codigo da Disciplina: %d \n",li->d1[li->qnt].codigoDisciplina);
        	printf("Numero de Creditos: %d \n",li->d1[li->qnt].numeroCreditos);
        	printf("========================================\n");
        	li->qnt--;
        	printf("\n insercao no final da lista feita com sucesso..\n");
    	}else{
    		printf("========================================\n");
	    	printf("		ERRO!      \n");
	    	printf("========================================\n");
			printf("\n insercao nao foi feita!");
			printf("========================================\n");
    		
		}	
}

void removeCodigoLista(Lista *li,int codigoDisciplina){
    int aux,i=0;
    while(li->d1[i].codigoDisciplina != codigoDisciplina && i < 10){
    	i++;
	}
	if(li->d1[i].codigoDisciplina != codigoDisciplina){
		printf("========================================\n");
    	printf("		ERRO!      \n");
    	printf("========================================\n");
		printf("Codigo de Materia nao encontrado! \n");
		printf("========================================\n");
	}
	
	if(li->d1[i].codigoDisciplina == codigoDisciplina){
		printf("========================================\n");
    	printf("		DADOS REMOVIDOS NA POSICAO %d        \n",i);
    	printf("========================================\n");
    	printf("Nome da Disciplina: %s \n",li->d1[i].nomeDisciplina);
    	printf("Carga horaria: %d \n",li->d1[i].cargaHoraria);
    	printf("Codigo da Disciplina: %d \n",li->d1[i].codigoDisciplina);
    	printf("Numero de Creditos: %d \n",li->d1[i].numeroCreditos);
    	printf("========================================\n");
    	char stringVazia[1]= " ";
    	int j;
		for(j=0;j<12;j++){
			li->d1[i].nomeDisciplina[j] = stringVazia[0];
		} 
    	li->d1[i].cargaHoraria = 0;
    	li->d1[i].codigoDisciplina = 0;
    	li->d1[i].numeroCreditos = 0;
    	printf("========================================\n");
    	printf("		DADOS COLOCADOS APOS REMOCAO NA POSICAO %d        \n",i);
    	printf("========================================\n");
	    printf("Nome da Disciplina: %s \n",li->d1[i].nomeDisciplina);
	    printf("Carga horaria: %d \n",li->d1[i].cargaHoraria);
	    printf("Codigo da Disciplina: %d \n",li->d1[i].codigoDisciplina);
	    printf("Numero de Creditos: %d \n",li->d1[i].numeroCreditos);
	    printf("========================================\n");   
	}
}

void printaLista(Lista *li){
	int i;
	printf("========================================\n");
    printf("		INICIO DA IMPRESSAO DE DADOS    \n");
    printf("========================================\n");
	for(i=0;i<10;i++){
		printf("========================================\n");
    	printf("		DADOS NA POSICAO %d        \n",i);
    	printf("========================================\n");
    	printf("Nome da Disciplina: %s \n",li->d1[i].nomeDisciplina);
    	printf("Carga horaria: %d \n",li->d1[i].cargaHoraria);
    	printf("Codigo da Disciplina: %d \n",li->d1[i].codigoDisciplina);
    	printf("Numero de Creditos: %d \n",li->d1[i].numeroCreditos);
    	printf("========================================\n");
	}
	printf("========================================\n");
    printf("		FIM DA IMPRESSAO DE DADOS    \n");
    printf("========================================\n");
	
}

int main(){
	Lista *li;
	li = criaLista();
    // chama função para criar Lista
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
			printf("2 - Procura e Remove Matéria por Codigo:\n");
			printf("3 - Exibe elementos do vetor:\n");
			printf("4 - Sair do loop:\n");
			printf("=================================================\n");
			printf("Digite sua Opcao:");
			int opcao;
			scanf("%d",&opcao);
			fflush(stdin);
			if(opcao == 1){
				Disciplina d2;
				printf("\n Digite o nome da disciplina:");
				gets(d2.nomeDisciplina);
				printf("\n Digite o codigo da disciplina:");
				scanf("%d",&d2.codigoDisciplina);
				printf("\n Digite a carga horaria da disciplina:");
				scanf("%d",&d2.cargaHoraria);
				printf("\n Digite o numero de creditos da disciplina:");
				scanf("%d",&d2.numeroCreditos);
				insereFinalLista(li, d2);		
			}
			if(opcao == 2){
				int codigoDisciplina;
				printf("\n Digite o codigo da disciplina a ser procurado:");
				scanf("%d",&codigoDisciplina);
				removeCodigoLista(li,codigoDisciplina);
    		}
			if(opcao == 3){
				printaLista(li);
			}
			if(opcao == 6){
				sair=1;
			}		
		}while(sair==0);
	}		
}
