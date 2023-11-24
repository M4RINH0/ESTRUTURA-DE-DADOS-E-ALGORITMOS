#include <stdio.h>
#include <stdlib.h>
#include "VetoresC.c"


int main()
{
    const int ptammax = 100;
    char *pvetcar;
    int pqtde = 0;

    //003
    pvetcar = CriaVetChar(ptammax);
    char caractere1 = 'A';
    char caractere2 = 'B';
    ColocarPrimeiraPosicao(pvetcar, ptammax, &pqtde, caractere1);
    ColocarPrimeiraPosicao(pvetcar, ptammax, &pqtde, caractere2);

    printf("o pvetcar e: ");
    for(int i = 0; i < pqtde; i++) {
        printf("%c", pvetcar[i]);
    }

    printf("\nA quantidade atual de elementos e: %d\n", pqtde);

    excluirCaractere(pvetcar, &pqtde, caractere1);

    printf("Vetor atual apos exclusao: ");  
    for (int i = 0; i < pqtde; i++) {
        printf("%c ", pvetcar[i]);
    }
    printf("\n");

    return 0;
}
