       /*int main(void)
        {
            int *x;
            int *y;
            x = malloc(sizeof(int));
            *x = 42;
            *y = 13;
            y = x;
            *y = 13;
        }ERRO : falha de segmentação (imagem do núcleo gravada)

Declaramos dois ponteiros para inteiros, x e y , mas não atribuímos valores a eles.
Usamos malloc para alocar memória suficiente para um inteiro com sizeof(int) e armazená-lo em x.
*x = 42 vai para o endereço x aponta para e define esse local na memória para o valor 42.
Com *y = 13, estamos tentando colocar o valor 13 no endereço que y aponta. Mas, como nunca atribuímos um valor a y ,ele tem um garbage value (“valor lixo”),
ou qualquer valor desconhecido que estava na memória, de qualquer programa que estava em execução em nosso computador antes.
Então, quando tentamos ir para o valor lixo em y como um endereço, estamos indo para algum endereço esconhecido,
que provavelmente causará uma falha de segmentação ou segfault.*/

//Podemos imprimir valores inúteis, declarando uma matriz, mas não definindo nenhum de seus valores:
    #include <stdio.h>

    int main(void)
    {
        int scores[3];
        for (int i = 0; i < 3; i++)
        {
            printf("%i\n", scores[i]);
        }
    }//Quando compilamos e executamos este programa, vemos vários valores impressos.

