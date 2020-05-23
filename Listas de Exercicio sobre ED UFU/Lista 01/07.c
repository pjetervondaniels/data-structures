#include <stdio.h>
#include <stdlib.h>
#include "07.h"

typedef struct Cubo{
   double a;
}cb;

cb* criaCubo(double a){
    cb* cube = (cb*)malloc(sizeof(cb));
    cube->a = a;
    return cube;
}

void tamanhoLado(cb* cube){
    printf("/n tamanho dos lados : %.2f",cube->a);
}
void calculaArea(cb* cube){
    double calcula = 6*(cube->a* cube->a);
    printf("/n a area do cubo eh de %.2f",calcula);
}
void calculaVolume(cb* cube){
    double calcula = (cube->a)*(cube->a)*(cube->a);
    printf("/n o volume do cubo eh de %.2f",calcula);
}
void liberaCubo(cb* cube){
    free(cube);
}


int main (){
    cb* a1;
    a1 = criaCubo(2);
    tamanhoLado(a1);
    calculaArea(a1);
    calculaVolume(a1);
    liberaCubo(a1);
}