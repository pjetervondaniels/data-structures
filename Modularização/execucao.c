#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "prototipo.H"

struct ponto
{
    float x,y;
};

// aloca e retorna o ponto com coordenadas x e y!
Ponto* pto_cria(float x,float y){
    Ponto* p = (Ponto*) malloc(sizeof(Ponto));
    if(p!=NULL){
        p->x = x;
        p->y = y;
    }
    return p;
}

// libera a memoria alocada ao ponto
void pto_libera(Ponto* p){
    free(p);
}

void pto_acessa(Ponto* p,float *x,float*y){
    *x = p->x;
    *y = p->y;
}

// Atribui os valores de x e y a um ponto..
void pto_atribui(Ponto* p,float x,float y){
    p->x = x;
    p->y = y;
}

// Calcula a distancia entre x e y 
float calcula_ponto(Ponto* p1,Ponto* p2){
    float dx = p1->x - p2 ->x;
    float dy = p1->y - p2 ->y;
    float pow1 = dx*dx;
    float pow2 = dy*dy;
    return pow1+pow2;
}

int main(){
    float d;
    Ponto *p,*q;

    p = pto_cria(10,21);
    q = pto_cria(7,25);

    d= calcula_ponto(p,q);

    printf("A distancia entre os dois ponto: %.2f ",d);

    pto_libera(p);
    pto_libera(q);

    return 0;
}