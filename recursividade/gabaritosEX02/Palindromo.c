#include <stdio.h>
#include <string.h>

int palindromo(char *s, int inicio, int fim) {
    if (inicio >= fim) {
        return 1;
    }
    if (s[inicio] != s[fim]) {
        return 0;
    }
    return palindromo(s, inicio + 1, fim - 1);
}

int main() {
    char s[100];
    printf("Digite uma string: ");
    fgets(s, 100, stdin);
    int len = strlen(s);
    if (s[len - 1] == '\n') {
        s[len - 1] = '\0';
    }
    if (palindromo(s, 0, len - 2)) {
        printf("\n%s é um palíndromo\n", s);
    }
    else {
        printf("\n%s não é um palíndromo\n", s);
    }
    return 0;
}
