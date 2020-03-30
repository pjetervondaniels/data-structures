
#include <stdio.h>
#include <stdlib.h>
#include "06.h"


typedef struct numeroRacional{
    double x;
}nr;

nr* criaRacional(double x){
    nr* numeroR = (nr*) malloc(sizeof(nr));
    numeroR->x=x;
    return numeroR;
}

double somaRacional(nr* a,nr* b){
    return a->x+b->x;
}

double multiplicaRacional(nr* a,nr* b){
    return a->x*b->x;
}

void comparaRacional(nr* a,nr* b){
    if(a->x==b->x){
        printf("os dois numeros racionais são iguais!");
    }else{
        printf("os dois numeros racionais são diferentes!");
    }
}

int main (){
    nr *a,*b;

    a = criaRacional(1);
    b = criaRacional(2);

    printf("Soma racional: %f",somaRacional(a,b));
    printf("Multiplicação racional: %f",multiplicaRacional(a,b));
    comparaRacional(a,b);

    return 0;
}