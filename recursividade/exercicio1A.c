#include <stdio.h>

long int somavet(int *a, int qtde) {
    // Caso base: se não houver elementos no vetor, retorne 0.
    if (qtde == 0) {
        return 0;
    } 
    // Chamada recursiva para somar os elementos restantes e adicionar o elemento atual.
    return a[qtde - 1] + somavet(a, qtde - 1);
}

int main() {
    int vetor[] = {1, 2, 3, 4, 5};
    int tamanho = sizeof(vetor) / sizeof(vetor[0]); // Calculando o tamanho do vetor
    long int resultado = somavet(vetor, tamanho); // Chamando a função recursiva
    printf("A soma dos elementos do vetor é: %ld\n", resultado); // Imprimindo o resultado

    return 0;
}