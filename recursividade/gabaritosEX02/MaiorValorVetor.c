#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int maior(int *v, int n) {
    if (n == 1) {
        return v[0];
    }
    int m = maior(v, n - 1);
    return v[n - 1] > m ? v[n - 1] : m;
}

int main() {
    int n, v[100];
    printf("Digite o tamanho do vetor (no máximo 100): ");
    scanf("%d", &n);
    srand(time(NULL));
    printf("O vetor gerado aleatoriamente é: ");
    for (int i = 0; i < n; i++) {
        v[i] = rand() % 100;
        printf("%d ", v[i]);
    }
    printf("\nO maior elemento do vetor é %d\n", maior(v, n));
    return 0;
}
