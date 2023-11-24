#include <stdio.h>
#include <ctype.h>
#include <string.h>

int namefilepointposition(char *fullname){
   int i;
   for(i=0;i<strlen(fullname);i++){
       if(fullname[i]=='.')
        break;
   } 
   if(i>=strlen(fullname))
        return -1;
    else
        return i;
}

int contar_caracteres(const char *str) {
    int len = 0;
    for (int i = 0; str[i]; i++) {
        if (isalpha(str[i])) {
            len++;
        }
    }
    return len;
}



int word2vec(char *pNomeTxtEntrada){
    FILE *arqent, *arqsaida;
    char nomarq[40];
    int pointidx = namefilepointposition(pNomeTxtEntrada);
    int pp;
    char str1 [10];
    char str2[10];
//Generating Output filename    
    if(pointidx>=0){
        for(pp=0;pp<pointidx;pp++)
            nomarq[pp] = pNomeTxtEntrada[pp];
        nomarq[pp] = '\0';//End of string
    }
    else{
        strcpy(nomarq,  pNomeTxtEntrada);
    }    
    strcat(nomarq,  "_Vocabulo");
    strcat(nomarq,  ".txt");
    printf("\nRecebi no nome do arquivo: %s", nomarq);

//Generating the output:
    arqent = fopen(pNomeTxtEntrada, "r");
    arqsaida = fopen(nomarq, "w+");
    

    while (!feof(arqent))
    {
        fscanf(arqent, "%s", str1);
        int found = 0;   
        rewind(arqsaida);    // Volta ao início do arquivo arqsaida
        while (fscanf(arqsaida, "%s", str2) != EOF) {
            if (strcmp(str1, str2) == 0) {
                found = 1;
                break;
            }
        }
        fseek(arqsaida, 0, SEEK_END);   
        if(contar_caracteres(str1) > 3 && found == 0){
            fputs(str1, arqsaida);
            fputs("\n", arqsaida);
        }      
    }
    
    
    
    fclose(arqent);
    fclose(arqsaida);
    return 1;
}


int main()
{
    char nomearq[30];
    printf("Entre com nome do arquivo:");
    scanf("%s",nomearq);
    if (!word2vec(nomearq))
        printf("\nErro na geração do vocábulo!");
    else
        printf("\nGerei o vocábulo!\n");
    

    return 0;
}