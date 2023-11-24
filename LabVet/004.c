#include <stdio.h>
#include <stdlib.h>
#include "VetoresC.c"


int main() {
    float *valores;
    int capacidade = 100;
    int tamanho = 0;

    valores = CriaVetFloat(capacidade);

    if (incluirValor(valores, 5.0, capacidade, tamanho)) {
        printf("Insercao bem-sucedida.\n");
        tamanho++;
        printf("%f\n",valores[0]);
    } else {
        printf("Nao foi possivel inserir o valor.\n");
    }

    return 0;
}