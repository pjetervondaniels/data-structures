#include <stdio.h>
#include <stdlib.h>
#include "Lista Sequencial.h"
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