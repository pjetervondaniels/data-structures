
typedef struct VetorInteiro vet_int;

vet_int* uneConjuntos(vet_int* vetA,vet_int* vetB);
vet_int* interceConjuntos(vet_int* vetA,vet_int* vetB);
vet_int* diferencaConjuntos(vet_int* vetA,vet_int* vetB);
vet_int* verificaIgual(vet_int* vetA,vet_int* vetB);

int verificaValor(vet_int* vetA,int x);
int maiorValor(vet_int*A);
int menorValor(vet_int*A);
int verificaTamanho(vet_int*A);
int verificaVazio(vet_int* A);

void insereValor(int x);
void retiraValor(int x);
void conjuntoVazio(vet_int* vetA);


