#include <stdio.h>

int main(int argc, char const *argv[])
{
    int n = 15;

    printf("%d\n", n);
    // %p é o codigo para formato de endereço
    //Em C, podemos realmente ver o endereço com o operador &, que significa “obter o endereço desta variável”
    printf("%p\n", &n);
    //O operador * , ou operador de desreferência, nos permite “ir para” o local para o qual um ponteiro está apontando.
    //Por exemplo, podemos imprimir *&n , onde “vamos para” o endereço de n , e isso imprimirá o valor de n, 15, já que esse é o valor no endereço de n:
    printf("%d\n", *&n);

    return 0;
}
