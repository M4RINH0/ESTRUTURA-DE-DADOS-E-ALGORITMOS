#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct no{
    char caracter;
    struct no *proximo;
}No;

int forma_par(char f, char d){
    switch(f){
    case ')':
        if(d == '(')
            return 1; // bem formada
        else
            return 0; // mal formada
        break;
    case ']':
        if(d == '[')
            return 1; // bem formada
        else
            return 0; // mal formada
        break;
    case '}':
        if(d == '{')
            return 1; // bem formada
        else
            return 0; // mal formada
    break;
    }
}


// Função identifica_formacao
// Assinatura: int identifica_formacao(char x[]);
// Retorno:
//. 0 - Caso a expressão de entrada está bem formada
//. 1 - Caso a expressão de entrada não esteja bem formada
//

int identifica_formacao(char x[]){
    No *pilha = NULL;
    int i = 0;
    while (x[i] != '\0')
    {
        if(x[i] == '(' || x[i] == '['){
            No *novo = (No*)malloc(sizeof(No));
            novo->caracter = x[i];
            novo->proximo = pilha;
            pilha = novo;
        }
        else if(x[i] == ')' || x[i] == ']' || x[i] == '}'){
            if(pilha == NULL)
                return 1;
            else if(forma_par(x[i], pilha->caracter) == 0)
                return 1;
            else{
                No *aux = pilha;
                pilha = pilha->proximo;
                free(aux);
            }
        }
    }
    while (pilha != NULL) {
        No *aux = pilha;
        pilha = pilha->proximo;
        free(aux);
    }
   return 0; 
}



int main(){
    char exp[50];

    printf("\tDigite um expressao: ");
    scanf("%49[^\n]", exp);
    printf("\nExpressao: %s\nRetorno: %d\n", exp, identifica_formacao(exp));

    return 0;
}
