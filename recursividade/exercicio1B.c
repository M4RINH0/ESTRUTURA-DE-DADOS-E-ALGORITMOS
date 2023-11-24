#include <stdio.h>

int comparaString(char str1[], char str2[], int i) {
    
    if(str1[i] == str2[i]){
        if (str1[i] == '\0' && str2[i] == '\0') {
            return 1;
        }
    }
    if (str1[i] != str2[i]) {
        return 0;
    }
    return comparaString(str1, str2, i + 1);
}

int main(void)
{
    int compare = 0;
    char *str1, *str2;
    str1 = "Douglas";
    str2 = "douglas";

    compare = comparaString(str1, str2,0);

    if(compare == 1){
        printf("As duas strings são iguais\n");
    }else{
        printf("As duas strings são diferentes\n");
    }

    return 0;
}
