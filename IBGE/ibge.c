#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MUNICIPIO 6000
#define MAX_LINE_SIZE 100

struct IBGE
{
    int IBGE;
    int linha;
};

int buscaSequencial(struct IBGE *vetor, int nlinhas, int IBGEbuscado) {
    for (int i = 0; i < nlinhas; ++i) {
        if (vetor[i].IBGE == IBGEbuscado) {
            return i;
        }
    }
    return -1;
}

int main() {
    FILE* arquivo = fopen("/home/douglas/EDA1/IBGE/Lista_Municípios_com_IBGE_Brasil_Versao_CSV.csv", "r");
    struct IBGE vetorIBGE[MAX_MUNICIPIO];
    int numLinhas = 0;

    char linha[MAX_LINE_SIZE];
    while (fgets(linha, sizeof(linha), arquivo) != NULL && numLinhas < MAX_MUNICIPIO) {
        // Procurar a posição de "IBGE;" na linha
        char* posicaoIBGE = strstr(linha, "IBGE;");
        
        // Se "IBGE;" estiver presente na linha, extrair o valor do IBGE e a linha correspondente
        if (posicaoIBGE != NULL) {
            char *token = strtok(posicaoIBGE + 5, ";"); // +5 para ignorar "IBGE;"
            vetorIBGE[numLinhas].IBGE = atoi(token);
            vetorIBGE[numLinhas].linha = numLinhas;
            ++numLinhas;
        }
    }

    fclose(arquivo);

    return 0;
}
