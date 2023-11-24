#include <stdio.h>

int fibonacci(int n){
    if (n <= 0){
        return 0;
    }else if (n == 1){
        return 1;
    }else{
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

int main()
{   
    int n, valor;
    printf("Digite o termo que deseja saber da sequencia de fibonacci: ");
    scanf("%d", &n);

    valor = fibonacci(n);

    printf("O valor do termo que pediu é: %d\n", valor);
    
    return 0;
}
