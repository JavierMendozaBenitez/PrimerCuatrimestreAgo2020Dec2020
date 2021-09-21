#include <stdio.h>
#include <stdlib.h>

#define TAM 10

int main()
{
    int numeros[TAM]={4,3,2,5,4,1,6,5,1,9};
    int cant = 0;
    int indice = 0;

    for(int i=0; i < TAM; i++)
    {
        //if(!(numeros[i] % 2))
        if(numeros[i] > 3)
        {
            cant++;
        }
    }

    int pares[cant];

    for(int i=0; i < TAM; i++)
    {
        //if(!(numeros[i] % 2))
        if( numeros[i] > 3)
        {
            pares[indice] = numeros[i];
            indice++;
        }
    }

    for(int i=0; i < cant; i++)
    {
        printf("%d, ", pares[i]);
    }

    printf("\n\n");

    return 0;
}
