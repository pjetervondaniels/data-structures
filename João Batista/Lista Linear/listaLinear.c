#include <stdio.h>
#include <stdlib.h>
#include "info.h"
#define MAX 100

struct aluno{
    // Struct aluno
    int matricula;
    char nome[30];
    float n1,n2,n3;
};

struct  lista
{
    // Struct lista
    int qtd;
    struct aluno dados[MAX];
};

Lista* criaLista(){
    // instancia a Lista
    Lista *li;
    li = (Lista *)malloc(sizeof(struct lista));
    if(li != NULL){
        li->qtd = 0;
    }
    return li;
}

void liberaLista(Lista *li){
    // libera a memória alocada com a lista
    free(li);
}
int tamanhoLista(Lista *li){
    // conta o tamanho da lista
    if(li==NULL){
        return -1;
    }else{
        return li->qtd;
    }
}

int listaCheia(Lista *li){
    // verifica se a lista está cheia
    if(li==NULL){
        return 1;
    }else{
        return 0;
    }
}

int listaVazia(Lista *li){
    // verifica se a lista está vazia
    if(li==NULL){
        return 1;
    }else{
        return 0;
    }
}

int insereFinalLista(Lista *li,struct aluno al){
    // insere na última posição da lista
    if(li == NULL){
        return 0;
    }
    if(listaCheia(li)==1){
        return 0;
    }
    if(listaCheia(li)==0){
        li->dados[li->qtd] = al;
        li->qtd++;
        return 1;
    }
}
int insereInicioLista(Lista *li,struct aluno al){
    // insere no início da lista
    if(li == NULL){
        return 0;
    }
    if(listaCheia(li)==1){
        return 0;
    }
    if(listaCheia(li)==0){
        int i;
        for(i= li->qtd;i>=0;i--){
            li->dados[i+1] = li->dados[i];
        }
        li->dados[0]= al;
        li->qtd++;
        return 1;
    }
}

int insereListaOrdenada(Lista *li,struct aluno al){
    // insere em uma posição ordenada
    if(li == NULL){
        return 0;
    }
    if(listaCheia(li)==1){
        return 0;
    }
    if(listaCheia(li)==0){
        int k,i=0;
        while(i<li->qtd && li->dados[i].matricula < al.matricula){
            i++;
        }
        for(k= li->qtd-1;k>=i;k--){
            li->dados[k+1] = li->dados[k];
        }
        li->dados[i]= al;
        li->qtd++;
        return 1;
    }
}

int removeFinalLista(Lista *li){
    // remove o valor que está na ultima posição da lista...
    if(li == NULL){
        return 0;
    }
    if(li->qtd==0){
        return 0;
    }
    if(li->qtd>=1){
        li->qtd--;
        return 1;
    }
}

int removeInicioLista(Lista *li){
    // remove o valor que está na posição inicial da lista...
    if(li == NULL){
        return 0;
    }
    if(li->qtd == 0){
        return 0;
    }
    if(li->qtd>=1){
        int k;
        for(k=0;k<li->qtd-1;k++){
            li->dados[k] = li->dados[k+1];
        }
        li->qtd--;
        return 1;
    }
}

int removeMeioLista(Lista *li,int n){
    // remove o valor que está na posição n da lista...
    if(li == NULL){
        return 0;
    }
    if(li->qtd == 0){
        return 0;
    }
    if(li->qtd > 0){
        int k,i;
        i=0;
        while(i< li->qtd && li->dados[i].matricula != n){
            i++;
            if(i == li->qtd){
                return 0;
            }
        }
        for(k=i; k<li->qtd-1;k++){
            li->dados[k] = li->dados[k+1];
        }
        li->qtd--;
        return 1;
    }
}

void main (){
    Lista *li;
    // cria ponteiro tipo lista..

    li = criaLista();
    // chama função criaLista e retorna uma lista....

    int x = tamanhoLista(li);
    // variável que recebe como retorno o tamanho da lista...
    printf("A lista tem tamanho %d",x);

    int y = listaCheia(li);
    // variável que recebe como retorno a condicional se a lista está cheia..
    if(y==1){
        printf("A lista está cheia...");
    }else{
        printf("A lista está vazia...")
    }

    int z = listaVazia(li);
    // variável que recebe como retorno a condicional se a lista está vazia..
    if(z==1){
        printf("A lista está vazia...")
    }else{
        printf("A lista não está vazia...")
    }

    int a = insereFinalLista(li,dados_aluno);
    // inserceção feita no final de uma lista...
    if(a==1){
        printf("Inserção no final da lista feita com sucesso..");
    }else{
        printf("Não foi feita inserção no final da lista...")
    }

    int b = insereInicioLista(li,dados_aluno);

    // inserceção feita no inicio da lista...
    if(b==1){
        printf("Inserção no inicio da lista feita com sucesso..");
    }else{
        printf("Não foi feita inserção no inicio da lista...");
    }

    int c = insereListaOrdenada(li,dados_aluno);
    // inserceção feita no meio da lista...
    if(b==1){
        printf("Inserção no meio da lista feita com sucesso..");
    }else{
        printf("Não foi feita inserção no meio da lista...");
    }
    
    int a1 = removeFinalLista(li);
    // remoção feita no final de uma lista...
    if(a1==1){
        printf("Remoção no final da lista feita com sucesso..");
    }else{
        printf("Não foi feita Remoção no final da lista...");
    }

    int a2 = removeInicioLista(li);
    // remoção feita no inicio de uma lista...
    if(a2==1){
        printf("Remoção no inicio da lista feita com sucesso..");
    }else{
        printf("Não foi feita Remoção no inicio da lista...");
    }

    int n;
    int a3 = removeMeioLista(li,n);
     // remoção feita no meio de uma lista...
    if(a3==1){
        printf("Remoção no meio da lista feita com sucesso..");
    }else{
        printf("Não foi feita Remoção no meio da lista...");
    }
    liberaLista(li);
}