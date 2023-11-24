#include <stdio.h>

/*
Implemente um menu com três opções: C - Fahrenheit para
Celsius, F - Celsius para Fahrenheit e S - Sair. Depois que o
usuário optar por uma das duas primeiras opções, leia um valor
float e mostre seu valor na respectiva escala. Caso o usuário
opte pela opção S, encerre o programa.
*/
void celsiusFahrenheit(){
    float temp, resultado;
    printf("Digite o valor que deseja converter: ");
    scanf("%f", &temp);
    resultado = ((temp - 32)*5)/9;
    printf("O valor em Celsius é %1.f °C\n", resultado);
}

void fahrenheitCelsius(){
    float temp, resultado;
    printf("Digite o valor que deseja converter: ");
    scanf("%f", &temp);
    resultado = ((temp*9)+160)/5;
    printf("O valor em Fahrenheit é %1.f °C\n", resultado);
}

int main()
{
    char opcao;
    
    printf("Bem-Vindo ao Coversor Celsius para Fahrenheit\n");
    printf(" C - Fahrenheit para Celsius\n F - Celsius para Fahrenheit\n S - Sair.\n");
    printf("Digite a opção desejada: ");
    scanf("%c", &opcao);

    switch (opcao)
    {
    case 'S':
        return 0;
    case 'C':
        celsiusFahrenheit();
        break;
    case 'F':
        fahrenheitCelsius();          
    default:
        printf("opcão Invalida\n");
        break;
    }

    return 0;
}
