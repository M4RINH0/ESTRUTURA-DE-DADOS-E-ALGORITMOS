/*Uma variável declarada com string s = "HI!"; será armazenado um caractere por vez na memória. E podemos acessar cada caractere com s[0], s[1], s[2] e s[3]
Mas acontece que cada caractere, por estar armazenado na memória, 
também possui algum endereço exclusivo, e s é na verdade apenas um ponteiro com o endereço do primeiro caractere
E a variável s armazena o endereço do primeiro caractere da string. O valor \0 é o único indicador do final da string

Já que o resto dos caracteres estão em um array, um apos o outro,
podemos começar no endereço indicado no s e continuar lendo um caractere de cada vez a partir da memória até chegarmos no \0.
*/

#include <stdio.h>

int main()
{
    char *s = "HI!";
    printf("%c\n", *s);
    printf("%c\n", *(s+1));
    printf("%c\n", *(s+2));
    /**s vai para o endereço armazenado em s, e *(s+1) vai para o local na memória com um endereço um byte acima, ou o próximo caractere.
    *s[1] é açúcar sintático para *(s+1), equivalente em função, mas mais amigável para ler e escrever.*/

    printf("%s\n", s);

    return 0;
}

