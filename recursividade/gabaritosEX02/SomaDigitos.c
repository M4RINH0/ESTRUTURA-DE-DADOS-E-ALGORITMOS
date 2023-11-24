#include <stdio.h>

int somaDigitos(int n) {
    if (n < 10) {
        return n;
    }
    return n % 10 + somaDigitos(n / 10);
}

int main() {
    int n;
    printf("Digite um número inteiro: ");
    scanf("%d", &n);
    printf("A soma dos dígitos de %d é %d\n", n, somaDigitos(n));
    return 0;
}
