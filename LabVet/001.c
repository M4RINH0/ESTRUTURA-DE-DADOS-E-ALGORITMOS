#include <stdio.h>
#include <stdlib.h>
#include "VetoresC.c"


int main()
{
    const int ptammax = 100;
    int *pvetint;
    float *pvetfloat;
    //001
    pvetint = CriaVetInt(ptammax);
    pvetfloat = CriaVetFloat(ptammax);

    for (int i = 0; i < ptammax; i++){
        printf("%d\n", pvetint + i);
        printf("%f\n", pvetfloat + i);
    }
    return 1;
}
