#include <stdio.h>
#include <stdlib.h>
#include "VetoresC.c"

int main() {
    float valores[] = {1.0, 2.0, 3.0, 4.0, 5.0};
    int tamanho = 5;

    // Exemplo de uso da função para excluir o valor 3.0 do vetor ordenado
    if (excluirElemento(valores, tamanho, 3.0)) {
        printf("Exclusao bem-sucedida.\n");
        tamanho--; // Você pode reduzir o tamanho aqui, se necessário
    } else {
        printf("Nao foi possivel excluir o valor.\n");
    }
    for(int i = 0; i < tamanho; i++){
        printf("%f\n", valores[i]);
    }

    return 0;
}