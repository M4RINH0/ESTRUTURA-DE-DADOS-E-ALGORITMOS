#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct TNo {
    int Valor;
    struct TNo *Prox;
};

struct TNo *IncluiAntes(struct TNo *pLista, int pChave, int pValor)
{
    if (pLista == NULL) {
        printf("A lista está vazia.\n");
        return NULL;
    }
    struct TNo *pNovoNo, *pAux;
    pNovoNo = (struct TNo *) malloc(sizeof(struct TNo));
    pNovoNo->Valor = pValor;
    pAux = pLista;
    while (pAux->Prox != NULL && pAux->Prox->Valor != pChave)
        pAux = pAux->Prox;
    if (pAux->Prox == NULL) {
        printf("Chave não encontrada na lista.\n");
        free(pNovoNo);
        return pLista;
    }
    pNovoNo->Prox = pAux->Prox;
    pAux->Prox = pNovoNo;
    return pLista;
}

struct TNo *ExcluiChave(struct TNo *pLista, int pChave)
{
    if (pLista == NULL) {
        printf("A lista está vazia.\n");
        return NULL;
    }
    struct TNo *pAnt, *pPost;
    pAnt = pLista;
    while (pAnt->Prox != NULL && pAnt->Prox->Valor != pChave)
        pAnt = pAnt->Prox;
    if (pAnt->Prox == NULL) {
        printf("Chave não encontrada na lista.\n");
        return pLista;
    }
    pPost = pAnt->Prox->Prox;
    free(pAnt->Prox);
    pAnt->Prox = pPost ;
    return pLista;
}

int main() {
    struct TNo *lista = NULL;

    // Adicionando alguns nós à lista
    for (int i = 1; i <= 5; i++) {
        struct TNo *novoNo = (struct TNo *) malloc(sizeof(struct TNo));
        novoNo->Valor = i;
        novoNo->Prox = lista;
        lista = novoNo;
    }

    // Testando a função IncluiAntes
    printf("Incluindo o valor 10 antes do valor 3...\n");
    lista = IncluiAntes(lista, 3, 10);

    // Imprimindo a lista após a inclusão
    struct TNo *aux = lista;
    while (aux != NULL) {
        printf("%d ", aux->Valor);
        aux = aux->Prox;
    }
    printf("\n");

    // Testando a função ExcluiChave
    printf("Excluindo o valor 3...\n");
    lista = ExcluiChave(lista, 3);

    // Imprimindo a lista após a exclusão
    aux = lista;
    while (aux != NULL) {
        printf("%d ", aux->Valor);
        aux = aux->Prox;
    }
    printf("\n");

    return 0;
}