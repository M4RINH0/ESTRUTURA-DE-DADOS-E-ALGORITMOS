#include <stdio.h>
/*
Usando as estruturas condicionais e de repetição (implemente
um menu), crie um programa de calculadora que lê operações e
valores do usuário e mostre o resultado na tela.
*/

int main()
{   
    int opcao;
    float a, b, resultado;

    do{
        printf("Que operação você deseja fazer?\n");
        printf(" 1 - Soma\n 2 - Subtração\n 3 - Multiplicação\n 4 - Divisão\n");
        printf("Digite o número da opção desejada: ");
        scanf("%d", &opcao);
    }while (opcao < 1 || opcao > 4);
    
    printf("\nOkay, agora digite o primeiro valor: ");
    scanf("%f", &a);
    printf("Belez, agora digite o segundo valor: ");
    scanf("%f", &b);

    if(opcao == 1){
        resultado = a + b;
        printf("\nO resultado da soma é : %2.f\n", resultado);
    }else if (opcao == 2){
        resultado = a - b;
        printf("\nO resultado da subtração é : %2.f\n", resultado);
    }else if (opcao == 3){
        resultado = a * b;
        printf("\nO resultado da multiplicação é : %2.f\n", resultado);
    }else if(opcao == 4){
        resultado = a / b;
        printf("\nO resultado da divisão é : %2.f\n", resultado);
    }else{
        printf("A operação é Inválida\n");
    }
    return 0;
}
