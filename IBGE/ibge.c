#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MUNICIPIO 6000
#define MAX_LINE_SIZE 256

typedef struct IBGE
{
    int IBGE;
    int linha;
} IBGE;

int buscaSequencial(IBGE *vetor, int nlinhas, int IBGEbuscado) {
    for (int i = 0; i < nlinhas; ++i) {
        if (vetor[i].IBGE == IBGEbuscado) {
            return vetor[i].linha;
        }
    }
    return -1;
}

int main() {
    FILE *arquivo = fopen("Lista_Municípios_com_IBGE_Brasil_Versao_CSV.csv", "r");
    struct IBGE vetorIBGE[MAX_MUNICIPIO];
    int numLinhas = 0, ibgebuscado;
    const int colunaIBGE = 1;
    char linha[MAX_LINE_SIZE];

    printf("Digite o IBGE a ser buscado: ");
    scanf("%d", &ibgebuscado);
    
    // Ignorar o cabeçalho
    fgets(linha, sizeof(linha), arquivo);

    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        char *token = strtok(linha, ";");
        vetorIBGE[numLinhas].IBGE = atoi(token);
        vetorIBGE[numLinhas].linha = numLinhas + 1;
        numLinhas++;
    }

    int linhaencontrada = buscaSequencial(vetorIBGE, numLinhas, ibgebuscado);
    if (linhaencontrada != -1)
        printf("IBGE encontrado na linha %d\n", linhaencontrada);
    else
        printf("IBGE não encontrado\n");

    fclose(arquivo);

    return 0;
}
