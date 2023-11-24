#include <stdio.h>

int somaDigitos(int n){
    if (n < 10) {
        return n;
    }
    return n % 10 + somaDigitos(n / 10);
}


int main()
{
    int numero, result;

    printf("Digite o numero que deseja saber a soma de seus digitos: ");
    scanf("%d", &numero);

    result = somaDigitos(numero);

    printf("O resultado da soma dos digitos é: %d\n", result);

    return 0;
}
