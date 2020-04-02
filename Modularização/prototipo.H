// arquivo .h do exemplo

typedef struct ponto Ponto;

// cria um ponto
Ponto* pto_cria(float x,float y);

// libera um ponto
void pto_libera(Ponto* p);

// Acessa os valores de x e y de um ponto..
void pto_acessa(Ponto* p,float *x,float *y);

// Atribui os valores de x e y a um ponto..
void pto_atribui(Ponto* p,float x,float y);

// Calcula a distancia entre x e y 
float calcula_ponto(Ponto* p1,Ponto* p2);