typedef struct NumeroComplexo nc;

// cria número complexo
nc* criaNumero(double inteiro,double imaginário);

// destroi número complexo
void destroiNumero(nc* numeroComplexo);

// soma dois números complexos
double somaNumero(nc* n1,nc*n2);

// subtrai dois números complexos
double subtraiNumero(nc* n1,nc*n2);

// multiplica dois números complexos
double multiplicaNumero(nc* n1,nc*n2);

// divide dois números complexos
double divideNumero(nc* n1,nc*n2);