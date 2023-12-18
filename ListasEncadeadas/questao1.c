#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct TNo {
    int valor;
    struct TNo *prox;
};

bool Vazia(struct TNo *pLista)
{
    if(pLista == NULL)
        return true;
    else
        return false;
}

struct TNo *IncluiCabeca(struct TNo* pLista, int pValor) {
    struct TNo* novoNo = (struct TNo*) malloc(sizeof(struct TNo));
    novoNo->valor = pValor;
    novoNo->prox = pLista;
    pLista = novoNo;    
    return pLista;
}

struct TNo *IncluiCalda(struct TNo* *pLista, int pValor)
{
    struct TNo *pNovoNo, *pAux;
    pNovoNo = (struct TNo*) malloc(sizeof(struct TNo));
    pNovoNo->valor = pValor;
    pNovoNo->prox = NULL;
    if (Vazia(*pLista) == true)
    {
        return pNovoNo;
    }else{
        pAux = *pLista;
        while (pAux->prox != NULL)
            pAux = pAux->prox;
        pAux->prox = pNovoNo;
        return *pLista;
    }
}

struct TNo *ExcluiCabeca(struct TNo *pLista)
{   
    if (Vazia(pLista) == true)
    {
        return NULL;
    }else{
        struct TNo *pAux;
        pAux = pLista;
        pLista = pLista->prox;
        free(pAux);
        return pLista;
    }    
}

struct TNo *ExcluiCalda(struct TNo *pLista)
{   
    if (pLista == NULL) {
        return NULL;
    } else if (pLista->prox == NULL) {
        free(pLista);
        return NULL;
    } else {
        struct TNo* temp = pLista;
        while (temp->prox->prox != NULL) {
            temp = temp->prox;
        }
        free(temp->prox);
        temp->prox = NULL;
        return pLista;
    }
}


int main() {
    struct TNo* lista = NULL;

    // Testando a função IncluiCabeca
    lista = IncluiCabeca(lista, 1);
    lista = IncluiCabeca(lista, 2);
    lista = IncluiCabeca(lista, 3);

    // Testando a função IncluiCalda
    IncluiCalda(&lista, 4);
    IncluiCalda(&lista, 5);
    IncluiCalda(&lista, 6);

    // Testando a função ExcluiCabeca
    lista = ExcluiCabeca(lista);

    // Testando a função ExcluiCalda
    lista = ExcluiCalda(lista);

    // Imprimindo a lista para verificar o resultado
    struct TNo* temp = lista;
    while (temp != NULL) {
        printf("%d ", temp->valor);
        temp = temp->prox;
    }

    return 0;
}