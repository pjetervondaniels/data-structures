#include <stdio.h>

void neoStart() { // Neo vai para a Matrix
    printf("\nMatrix inciando...\n");
}

int main() {
    int valorNum, i;

    printf("Digite um valor: ");
    scanf("%d", &valorNum);

    for (i = 0; i < valorNum; i++) {
        printf("\nOi mundo: %d", valorNum);
    }

    if (valorNum == 9) {
        printf("\nBem-vindo a Matrix\n");
        neoStart();
    } else {
        printf("\nFim do Programa\n");
    }

    return 0;
}
