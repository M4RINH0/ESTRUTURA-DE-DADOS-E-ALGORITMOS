#include <stdio.h>
#include <string.h>

int isPalindrome(char str[], int start, int end) {
    if (start >= end) {
        return 1;
    }
    if (str[start] != str[end]) {
        return 0;
    }
    return isPalindrome(str, start + 1, end - 1);
}

int main() {
    char str[100];
    printf("Digite a string: ");
    scanf("%s", str);

    int length = strlen(str);

    if (isPalindrome(str, 0, length - 1)) {
        printf("%s é um palíndromo.\n", str);
    } else {
        printf("%s não é um palíndromo.\n", str);
    }

    return 0;
}
