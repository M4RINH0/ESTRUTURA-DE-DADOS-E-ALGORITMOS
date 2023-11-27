#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define TAM_LINHA_MAX 256
#define TAM_MAX 539384

typedef struct airport
{
    int linha;
    int tempo;
    int delay;
} airport;


void quicksort(airport vet[], int esq, int dir){
    airport ch;
    int pivo = esq, i,j;
    for(i=esq+1;i<=dir;i++){
        j = i;
        if(vet[j].tempo < vet[pivo].tempo){
            ch = vet[j];
            while(j > pivo){
                vet[j] = vet[j-1];
                j--;
            }
            vet[j] = ch;
            pivo++;
        }
    }
    if(pivo-1 >= esq){
        quicksort(vet,esq,pivo-1);
    }
    if(pivo+1 <= dir){
        quicksort(vet,pivo+1,dir);
    }
}

int main() {
    FILE *arquivo = fopen("Airlines.csv", "r");
    FILE *saida = fopen("saida.txt", "w");
    char linha[TAM_LINHA_MAX];
    int indiceColunaTempo = 7;
    airport *aeroportos = malloc(TAM_MAX * sizeof(airport));

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo Airlines.csv\n");
        return 1;
    }

    int j = 0;
    // Coletar todos os valores da coluna tempo
    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        char *token = strtok(linha, ",");
        for (int i = 0; token != NULL; ++i) {
            if (i == indiceColunaTempo) {
                aeroportos[j].linha = j+1;
                aeroportos[j].tempo = atoi(token);
            }else if (i == indiceColunaTempo + 1)
            {
                aeroportos[j].delay = atoi(token);
                break;
            }      
            token = strtok(NULL, ",");
        }
        j++;
    }

    // Medir o tempo antes de chamar o Quicksort
    clock_t inicio = clock();

    // Ordenar os valores da coluna tempo
    quicksort(aeroportos, 0, j - 1);

    // Medir o tempo depois de chamar o Quicksort
    clock_t fim = clock();
    double tempoGasto = ((double)(fim - inicio)) / CLOCKS_PER_SEC;

    // Escrever os valores ordenados no arquivo de saída
    for (int n = 0; n < j; n++) {
        fprintf(saida, "%d, %d, %d\n", aeroportos[n].linha,aeroportos[n].tempo, aeroportos[n].delay);
    }

    // Exibir o tempo gasto
    printf("Tempo gasto: %.6f segundos\n", tempoGasto);


    fclose(arquivo);
    fclose(saida);

    return 0;
}