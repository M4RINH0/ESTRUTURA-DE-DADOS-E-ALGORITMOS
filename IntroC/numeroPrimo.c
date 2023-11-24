#include <stdio.h>

/*
Aplique estruturas de decisão e laços para verificar se um
número fornecido pelo usuário é primo ou não.
*/


int main()
{
    int num, resultado = 0;
    printf("Bem-Vindo ao verificador de Números Primos\n");
    printf("Digite o número que deseja saber se é primo: ");
    scanf("%d", &num);

    for (int i = 2; i <= num / 2; i++) {
        if (num % i == 0) {
        resultado++;
        break;
        }
    }
 
 if (resultado == 0)
    printf("%d é um número primo\n", num);
else
    printf("%d não é um número primo\n", num);
    
    return 0;
}
