#include <stdio.h>
#include <stdlib.h>

int *AlocaVetInt(int pqtde){
    int *ptr = (int *)malloc(pqtde*sizeof(int));
    return ptr;
}

void GeraValoresAleatorios(int *pvetor, int ptamanho){
    int ppos;
    for(ppos=0;ppos<ptamanho;ppos++)
        pvetor[ppos] = rand() % 9999;
}

long int somavet(int *a, int qtde){
    if (qtde>0)
        return a[qtde-1] + somavet(a, qtde-1);
    else 
        return 0;
    
}

int main()
{
    int *vet, tamanho;
    long int soma;
    printf("Qual o tamanho do vetor?");
    scanf("%d",&tamanho);
    vet = AlocaVetInt(tamanho);
    if(vet == NULL){
        printf("Vetor não alocado!!!");
        return 1;
    }
    GeraValoresAleatorios(vet, tamanho);    
    soma = somavet(vet, tamanho);
    printf("Soma: %ld", soma);
    free(vet);
    return 0;
}