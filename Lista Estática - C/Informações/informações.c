#include <stdio.h>
#include <stdlib.h>
#include "informações.h"
#define MAX 100

struct aluno{
    int matricula;
    char nome[30];
    float n1,n2,n3;
};

struct  lista
{
    int qtd;
    struct aluno dados[MAX];
};

Lista* criaLista(){
    Lista *li;
    li = (Lista *)malloc(sizeof(struct lista));
    if(li != NULL){
        li->qtd = 0;
    }
    return li;
}

void liberaLista(Lista *li){
    free(li);
}
int tamanhoLista(Lista *li){
    if(li==NULL){
        return -1;
    }else{
        return li->qtd;
    }
}

int listaCheia(Lista *li){
    if(li==NULL){
        return 1;
    }else{
        return 0;
    }
}
int listaVazia(Lista *li){
    if(li==NULL){
        return 1;
    }else{
        return 0;
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

    liberaLista(li);
}