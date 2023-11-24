#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int posicao(int *v, int n, int x) {
    if (n == 0) {
        return -1;
    }
    if (v[n - 1] == x) {
        return n - 1;
    }
    return posicao(v, n - 1, x);
}

int main() {
    int n, v[100], x;
    printf("Digite o tamanho do vetor (no máximo 100): ");
    scanf("%d", &n);
    srand(time(NULL));
    printf("O vetor gerado aleatoriamente é: ");
    for (int i = 0; i < n; i++) {
        v[i] = rand() % 100;
        printf("%d ", v[i]);
    }
    printf("\nDigite o elemento a ser procurado: ");
    scanf("%d", &x);
    int p = posicao(v, n, x);
    if (p == -1) {
        printf("%d não foi encontrado no vetor\n", x);
    }
    else {
        printf("%d foi encontrado na posição %d do vetor\n", x, p);
    }
    return 0;
}
