#include <stdio.h>
//Escreva uma função recursiva que calcule o máximo divisor comum (MDC) de dois números inteiros.

int mdc(int a, int b) {
    if (b == 0) {
        return a;
    }
    return mdc(b, a % b);
}

int main()
{
    int a = 20, b = 24;
    int result;
    result = mdc(a,b);

    printf("o resultado é: %d\n", result);

    return 0;
}
