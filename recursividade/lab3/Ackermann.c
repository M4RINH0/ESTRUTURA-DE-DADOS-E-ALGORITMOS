#include <stdio.h>

int AckermannRecursivo(int m, int n){
    if(m == 0){
        return n + 1;
    }else if (n == 0){
        return AckermannRecursivo(m-1, 1);
    }else{
        return AckermannRecursivo(m-1, AckermannRecursivo(m, n-1));
    }
}


int main()
{
    int m, n;
    int result;

    printf("Digite o valor de M e N inteiros para ahcar o Ackermann:\n");
    scanf("%d %d", &m,&n);
    result = AckermannRecursivo(m,n);
    printf("O resultado da função é: %d\n", result);
    return 0;
}
