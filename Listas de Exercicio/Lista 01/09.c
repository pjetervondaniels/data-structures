#include <stdio.h>
#include <stdlib.h>
#include "09.h"

typedef struct esfera{
    double raio;
}es;

es* criaEsfera(double r){
    es* esf = (es*)malloc(sizeof(es));
    esf->raio = r;
    return esf;
};

void tamanhoRaio(es* esf){
    printf("/n tamanho da raio : %.2f",esf->raio);
}

void calculaArea(es* esf){
    double calcula = 4*3.14*(esf->raio*esf->raio);
    printf("/n a area da esfera eh de %.2f",calcula);
}

void calculaVolume(es* esf){
    double calcula = (4*(3.14)*(esf->raio*esf->raio*esf->raio))/3;
    printf("/n o volume do esfera eh de %.2f",calcula);
}
void liberaCubo(es* esf){
    free(esf);
}

void main(){
    es* esf;
    
    esf=criaEsfera(5);

    tamanhoLado(esf);
    calculaArea(esf);
    calculaVolume(esf);
    liberaCubo(esf);

}






