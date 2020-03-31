#include <stdio.h>
#include <stdlib.h>
#include "08.h"

typedef struct cilindro {
    double altura,raio;
}cl;

cl* criaCilindro(double a,double r){
    cl* cil = (cl*)malloc(sizeof(cl));
    cil->altura = a;
    cil->raio = r;
    return cil;
}

void tamanhoLado(cl* cil){
    printf("/n tamanho da altura : %.2f",cil->altura);
    printf("/n tamanho da raio : %.2f",cil->raio);
}

void calculaArea(cl* cil){
    double calcula = (2*3.14*cil->altura)+(2*3.14*(cil->raio*cil->raio));
    printf("/n a area do cilindro eh de %.2f",calcula);
}
void calculaVolume(cl* cil){
    double calcula = 3.14*(cil->raio*cil->raio)*cil->altura;
    printf("/n o volume do cilindro eh de %.2f",calcula);
}
void liberaCubo(cl* cil){
    free(cil);
}

int main(){
    cl* c1;
    
    c1 = criaCilindro(3,2);
    tamanhoLado(c1);
    calculaArea(c1);
    calculaVolume(c1);
    liberaCubo(c1);

    return 0;
}