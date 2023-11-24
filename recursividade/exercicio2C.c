#include <stdio.h>
//Escreva uma função recursiva que calcule o valor de x elevado à potência n, onde x e n são números inteiros positivos.

int potencia(int x, int n){
    if(n == 0){
        return 1;
    }else if (n == 1)
    {
        return x;
    }else{
        return x * potencia(x, n-1);
    }
    
}

int main()
{
    int x = 3, n = 3;
    int result;
    result = potencia(x,n);

    printf("o resultado é: %d\n", result);

    return 0;
}
