struct aluno{
	int matricula;
	char nome[30];
	float n1,n2,n3;
};
typedef struct elemento* Lista;

Lista* cria_lista();

void liberaLista(Lista *li);

int tamanhoLista(Lista *li);

int CheiaLista(Lista *li);

int VaziaLista(Lista *li);
