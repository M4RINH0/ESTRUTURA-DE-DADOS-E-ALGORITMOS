#include <stdio.h>
#include <stdlib.h>

int* CriaVetInt(int tamanho) {
    int* vetor = (int*)malloc(tamanho * sizeof(int));

    if (vetor == NULL) {
        printf("Erro na alocacao de memoria.\n");
        exit(1);
    }

    return vetor;
}

float* CriaVetFloat(int tamanho) {
    float* vetor = (float*)malloc(tamanho * sizeof(float));

    if (vetor == NULL) {
        printf("Erro na alocacao de memoria.\n");
        exit(1);
    }

    return vetor;
}

char* CriaVetChar(int tamanho) {
    char* vetor = (char*)malloc(tamanho + 1);

    if (vetor == NULL) {
        printf("Erro na alocacao de memoria.\n");
        exit(1);
    }

    return vetor;
}

void ColocarPrimeiraPosicao(char pvetcar[], int ptammax, int *pqtde, char caractere) {
    if ((*pqtde) < ptammax) {
        pvetcar[(*pqtde)] = caractere;
        (*pqtde)++;
        printf("Caractere '%c' incluido na primeira posicao disponivel.\n", caractere);
    } else {
        printf("Vetor esta cheio, nao e possivel adicionar mais elementos.\n");
    }
}

void excluirCaractere(char pvetcar[], int *pqtde, char caractere) {
    for (int i = 0; i < *pqtde; i++) {
        if (pvetcar[i] == caractere) {
            for (int j = i; j < (*pqtde - 1); j++) {
                pvetcar[j] = pvetcar[j + 1]; // Desloca os elementos para a esquerda
            }
            (*pqtde)--; // Decrementa a quantidade atual de elementos
            printf("Caractere '%c' excluido do vetor.\n", caractere);
            break; // O caractere foi encontrado e exclu�do, ent�o podemos sair do loop
        }
    }
}

int incluirValor(float pvalores[], float pv, int pcapacidade, int ptamanho){
    if (ptamanho >= pcapacidade) {
        return 0;
    }

    int posicao = 0;
    while (posicao < ptamanho && pvalores[posicao] < pv) {
        posicao++;
    }

    for (int i = ptamanho; i > posicao; i--) {
        pvalores[i] = pvalores[i - 1];
    }

    pvalores[posicao] = pv;
    ptamanho++;

    return 1; 
}

int excluirElemento(float pvalores[], int ptamanho, float pv){
    if (ptamanho == 0) {
        return 0; 
    }
    for (int i = 0; i < ptamanho; i++) {
        if (pvalores[i] == pv) {
            for (int j = i; j < ptamanho - 1; j++) {
                pvalores[j] = pvalores[j + 1];
            }

            ptamanho--;
            return 1; 
        }
    }

    return 0; 
}

int eIgual(int pveta[], int pvetb[], int ptama, int ptamb){
    
}