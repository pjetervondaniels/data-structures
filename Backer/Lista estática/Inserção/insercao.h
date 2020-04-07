/*
    existem 3 tipos de insercao:
    - início 
    - meio
    - final

    também existe o caso onde a inserção é feita em uma "lista"
    que está vazia...

*/

#define MAX 100
struct aluno{
    int matricula;
    char nome[30];
    float n1,n2,n3;
};

typedef struct lista Lista;

Lista *li;

Lista* criaLista();

void liberaLista(Lista *li);

int tamanhoLista(Lista* li);

int listaCheia(Lista *li);

int listaVazia(Lista *li);

int insereFinalLista(Lista *li,struct aluno al);

int insereInicioLista(Lista *li,struct aluno al);

int insereListaOrdenada(Lista *li,struct aluno al);