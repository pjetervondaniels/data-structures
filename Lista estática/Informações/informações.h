/*
    Algumas Informações básicas sobre a lista
    - Tamanho?
    - Está Cheia?
    - Está Vazia?

*/

#define MAX 100
struct aluno{
    int matricula;
    char nome[30];
    float n1,n2,n3;
};

typedef struct lista Lista;

lista *li;

Lista* criaLista();

void liberaLista(Lista *li);

int tamanhoLista(Lista* li);

int listaCheia(Lista *li);

int listaVazia(Lista *li);
