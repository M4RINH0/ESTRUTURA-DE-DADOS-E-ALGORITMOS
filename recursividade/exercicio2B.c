#include <stdio.h>
//Escreva uma função recursiva que calcule o produto de dois números inteiros positivos a e b, usando apenas somas e subtrações.

int produto(int a, int b){
    if(a == 0 || b == 0){
        return 0;
    }
    if (a == 1){
        return b;
    }else if (b == 1)
    {
        return a;
    }else{
        return a + produto(a, b - 1);
    }  
}

int main()
{
    int a = 2, b = 5;
    int result;
    result = produto(a,b);

    printf("o produto de A e B é: %d\n", result);

    return 0;
}
