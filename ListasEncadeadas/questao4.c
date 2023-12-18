#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct TNo
{
    int Numero;
    struct Tno *Prox;
};

struct TLista
{
    struct TNo *Primeiro;
    int Qtde;
    struct TNo *Ultimo;
};

struct TNo *IncluiCabeça(struct TLista *Lista, int Numero)
{
    struct TNo *Novo;
    Novo = (struct TNo *)malloc(sizeof(struct TNo));
    Novo->Numero = Numero;
    Novo->Prox = Lista->Primeiro;
    Lista->Primeiro = Novo;
    Lista->Qtde++;
    if (Lista->Qtde == 1)
        Lista->Ultimo = Novo;
    return Novo;
}