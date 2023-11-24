#include <stdio.h>

int main(void)
{
    // Ponteiro "*" é um valor que “aponta” para um local na memória
    int n = 50;
    //Podemos usar o operador * (de uma forma infelizmente confusa) para declarar uma variável que queremos que seja um pointer
    int *p = &n;
    printf("%p\n", p);
    /*Aqui, usamos int * p para declarar uma variável, p , que tem o tipo * , um ponteiro, para um valor do tipo int , um inteiro.
    Então, podemos imprimir seu valor (um endereço, algo como 0x12345678 ), ou imprimir o valor em sua localização com printf ("%i\n", *p); .*/
    printf ("%i\n", *p);
}